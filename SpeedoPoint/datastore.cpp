#include "datastore.h"
#include "user.h"
#include <QDebug>
#include <fstream>
//#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
dataStore::dataStore()
{

    HotelListingsHead = NULL;
    FlightListingsHead = NULL;
    CruiseListingsHead = NULL;

    //import from file or data base and store into vector and linked lists
    // sort indeces start as the node count

    //load users 
    string user_ = "users.txt";
    ifstream u(user_);
    //u.open();
    if (u.is_open()) {
        while (!u.eof()) {
            string username;
            string pwd;
            string email;
            u >> username >> pwd >> email;
            user* user__ = new user(username, pwd, email);
            string ptsfile("points.txt");
            ifstream p(ptsfile);
            if (p.is_open()) {
                string pstring;
                while (getline(p, pstring)) {
                    stringstream sssp(pstring);
                    string u_name;
                    sssp >> u_name;
                    int pts;
                    for (auto x : users) {
                        if (u_name == x->getName()) {
                            sssp >> pts;
                            x->updatePoints(pts);
                        }
                    }
                    sssp >> pts;
                }
                p.close();
            }
            users.push_back(user__);
        }
        u.close();
    }


    // load countries
    string country_ = "countries.txt";
    ifstream c(country_);
    //c.open(country_);
    if (c.is_open()) {
        string temp;
        while (getline(c, temp)) {
            stringstream ss(temp);
            string name;
            bool banned;
            string c1;
            string c2;
            string c3;
            float x;
            float y;
            ss >> name >> banned >> x >> y>> c1 >> c2 >> c3;
            Coords cds(x, y);
            string city;
            country country__(name, banned, cds);
            country__.addCity(c1);
            country__.addCity(c2);
            country__.addCity(c3);
            countries.push_back(country__);
        }
        c.close();
    }



    //load hotels

    string hotel_ = "hotels.txt";
    ifstream h(hotel_);
    //h.open();
    if (h.is_open()) {
        string line3;
        while (getline(h, line3)) {
            string name;
            string country_;
            stringstream ssh(line3);
            int index;
            int range;
            bool pool;
            float rating;
            ssh >> name >> country_ >> index >> range >> pool >> rating;
            country ctry;
            for (auto x : countries) {
                if (country_.compare(x.getName()) == 0) {
                    ctry = x;
                }
            }
            hotel* h1 = new hotel(name, ctry, index, range, pool);
            for (int i = 0 ; i < 10; i++) {
                h1->updateRating(rating);
            }
            hotels.push_back(h1);
        }
        h.close();
    }

    // load hotellisting
    int Iindex = 0;

    string hlisting = "hl.txt";
    ifstream hl(hlisting);
    //hl.open();
    if (hl.is_open()) {
        string line;
        while (getline(hl, line)) {
            stringstream ss(line);
            string hname;
            ss >> hname;
            hotel* h;
            for (auto x : hotels) {
                if (hname == x->getName()) {
                    h = x;
                }
            }
            country ctry = h->getCountry();
            int index = h->getIndex();
            int area;
            int price;
            bool wifi;
            bool bfast;
            int num;
            bool refund;
            bool dinner;
            bool pet;
            string roomtype;
            ss >> area >> price >> wifi >> bfast >> num >> refund >> dinner >> pet;

            hotellisting* hotl = new hotellisting(h, ctry, price, index, area, wifi, bfast, num, refund, dinner, pet, roomtype);
            //hotl = new hotellisting(h, ctry, price, index, area, wifi, bfast, num, refund, dinner, pet, roomtype);
            // append to linked lsit


            if (HotelListingsHead == NULL) {
                HotelListingsHead = new Node<hotellisting*>;
                HotelListingsHead->data = hotl;
                HotelListingsHead->initialIndex = Iindex;
                HotelListingsHead->priceRankIndex = Iindex;
                HotelListingsHead->ratingRankIndex = Iindex;
                HotelListingsHead->prev = NULL;
                Iindex++;
            }
            else {
                Node<hotellisting*>* curr = HotelListingsHead;
                while (curr->next != NULL) {
                    curr = curr->next;
                }
                curr->next = new Node<hotellisting*>;
                curr->next->data = hotl;
                curr->next->initialIndex = Iindex;
                curr->next->priceRankIndex = Iindex;
                curr->next->ratingRankIndex = Iindex;
                curr->next->prev = curr;
                Iindex++;
            }


        }
        hl.close();
    }


    Iindex = 0;

    // load airlines
    string airlne = "airline.txt";
    ifstream afile(airlne);
    if (afile.is_open()) {
        string line1;
        while (getline(afile, line1)) {
            stringstream ssa(line1);
            string name;
            int range;
            float srt;
            ssa >> name >> range >> srt;
            airline* airlne = new airline(name, range, srt);
            airlines.push_back(airlne); // add vector named airlines type airline to header
        }
        afile.close();
    }

    string airportfile = "airports.txt";
    ifstream air(airportfile);
    if (air.is_open()) {
        string line2;
        while (getline(air, line2)) {
            stringstream ssair(line2);
            string ctry;
            string airport_name;
            ssair >> airport_name >> ctry;
            country cntry;
            for (auto x : countries) {
                if (x.getName() == ctry) {
                    cntry = x;
                }
            }
            int index;
            ssair >> index;
            airports.push_back(airport(airport_name, cntry, index));
        }
        air.close();
    }


    Iindex = 0;
    // load flighttickets
    string flightfile = "flights.txt";
    ifstream f(flightfile);
    //f.open();
    string line4;
    if (f.is_open()) {
        while (getline(f, line4)) {
            string stopfile = "stops.txt";
            ifstream s(stopfile);
            stringstream ssf(line4);
            string al;
            string code;
            ssf >> code;
            string line5;
            int stpnum;
            stop* stps = NULL;
            while (getline(s, line5)) {
                stringstream sss(line5);
                string cd;
                sss >> cd;
                if (code == cd) {
                    sss >> stpnum;
                    for (int i = 0; i < stpnum; i++) {
                        string ctry; 
                        sss >> ctry;
                        country ct;
                        for (auto x : countries) {
                            if (ctry == x.getName()) {
                                ct = x;
                            }
                        }
                        int index;
                        sss >> index;
                        string at;
                        airport aport;
                        for (auto x : airports) {
                            if (at == x.getName()) {
                                aport = x;
                            }
                        }
                        if (stps == NULL) {
                            date dt;
                            stps = new stop(ct, index, dt);
                            stps->setAirport(aport);
                            qDebug() << "country " << QString::fromStdString(ct.getName());
                        }
                        else {
                            //date dt;
                            //stps->add_stop(ct, index, dt);//  OLD import
                        }
                    }
                }
            }
            ssf >> al;
            airline* airln;
            for (auto x : airlines) {
                if (x->getName() == al) {
                    airln = x;
                }
            }
            int depy, depm, depd, deph, depmin, arry, arrm, arrd, arrh, arrmin, price;
            string cabin, plane_model;
            int carryon, checkedW, additionalw;
            bool refundable, oneway;
            ssf >> stpnum >> depy >> depm >> depd >> deph >> depmin >> arry >> arrm >> arrd >> arrh >> arrmin >> price >> cabin >> plane_model >> carryon >> checkedW >> additionalw >> refundable >> oneway;
            date dep(depd, depm, depy, deph, depmin);
            date arr(arrd, arrm, arry, arrh, arrm);
            //string code = "codetest";
            //qDebug() << QString::fromStdString(stps->getLoc().getName()) << "Ct";
            flightlisting* flist = new flightlisting(code, airln, stps, stpnum, dep, arr, price, cabin, plane_model, carryon, checkedW, additionalw, refundable, oneway);

            // add it to linked list

            if (FlightListingsHead == NULL) {
                FlightListingsHead = new Node<flightlisting*>;
                FlightListingsHead->data = flist;
                FlightListingsHead->initialIndex = Iindex;
                FlightListingsHead->next = NULL;
                Iindex++;
            }
            else {
                Node<flightlisting*>* curr = FlightListingsHead;
                while (curr->next != NULL) {
                    curr = curr->next;
                }
                curr->next = new Node<flightlisting*>;
                curr->next->data = flist;
                curr->next->initialIndex = Iindex;
                Iindex++;
            }
            s.close();
        }

        f.close();
    }

    // cruise company
    string ccompanyfile("cc.txt");
    ifstream ccfile(ccompanyfile);
    if (ccfile.is_open()) {
        string ccline;
        while (getline(ccfile, ccline)) {
            stringstream sscc(ccline);
            string name;
            float rt;
            float srt;
            int range;
            sscc >> name >> rt >> srt >> range;
            cruisecompany* cc = new cruisecompany(name, rt, srt, range);
            qDebug() << QString::fromStdString(name) << " n";
            cruisecompanies.push_back(cc);
        }
        ccfile.close();
    }


    // cruises 
    Iindex = 0;
    string cruisefile("cruises.txt");
    ifstream cfile(cruisefile);
    if(cfile.is_open()) {
        string cline;
        while (getline(cfile, cline)) {
            stringstream ssc(cline);
            string code;
            string cc;
            cruisecompany* company;
            ssc >> code >> cc;
            for (auto x : cruisecompanies) {
                if (x->getName().compare(cc) == 0) {
                    company = x;

                }
                qDebug() << QString::fromStdString(x->getName());
            }
            int depy, depm, depd, deph, depmin, arry, arrm, arrd, arrh, arrmin;
            ssc >> depy >> depm >> depd >> deph >> depmin >> arry >> arrm >> arrd >> arrh >> arrmin;

            date dep(depd, depm, depy, deph, depmin);
            date arr(arrd, arrm, arry, arrh, arrm);
            string model;
            int price;
            
            string c1;
            string c2;
            ssc >> model >> price >> c1 >> c2;
            country depc, arrc;
            for (auto x : countries) {
                if (x.getName() == c1) {
                    depc = x;
                }
                if (x.getName() == c2) {
                    arrc = x;
                }
            }
            int index;
            ssc >> index;
            stop* stps = NULL;
            string cstopfile = "cstops.txt";
            ifstream s(cstopfile);
            string sline;
            while (getline(s, sline)) {
                stringstream sscs(sline);
                string cruisecode;
                int stpnum;
                sscs >> cruisecode;
                if (code == cruisecode) {
                    sscs >> stpnum;
                    for (int i = 0; i < stpnum; i++) {
                        string ctry;
                        country scountry;
                        sscs >> ctry;
                        for (auto x : countries) {
                            if (ctry == x.getName()) {
                                scountry = x;
                            }
                        }
                        int indx = 0;
                        date dt;
                        sscs >> indx;
                        if (stps == NULL) {
                            stps = new stop(scountry, indx, dt);
                        }
                        else {
                            stps->add_stop(scountry, indx, dt);
                        }

                    }
                }

            }s.close();
            string suite;
            ssc >> suite;
            cruise* cr = new cruise(code, company, dep, arr, model, price, depc, arrc, index, stps, suite);

            if (CruiseListingsHead == NULL) {
                CruiseListingsHead = new Node<cruise*>;
                CruiseListingsHead->data = cr;
                CruiseListingsHead->initialIndex = Iindex;
                CruiseListingsHead->next = NULL;
                Iindex++;
            }
            else {
                Node<cruise*>* curr = CruiseListingsHead;
                while (curr->next != NULL) {
                    curr = curr->next;
                }
                curr->next = new Node<cruise*>;
                curr->next->data = cr;
                curr->next->initialIndex = Iindex;
                curr->next->next = NULL;
                Iindex++;
            }

            //cruises.push_back(cr);
        }
        cfile.close();
    }













    SortListings();


    // for testing
    //qDebug() << "here";
    Node<hotellisting*>* curr = HotelListingsHead;
    while (curr != NULL) {
        //qDebug() << curr->data->getHotelRating();
        curr = curr->next;
    }
}

void dataStore::updatePoints() {
    ofstream userpts("points.txt");
    if (userpts.is_open()) {
        for (user* x : users) {
            string user_data = x->getName() + "\t" + to_string(x->getPoints());
            userpts << user_data;
        }
        userpts.close();
    }
    
}
void dataStore::AddUser(user* u) {
    users.push_back(u);

    // write into file;
    string user_data = u->getName() + "\t" + u->getPassword() + "\t" + u->getEmail(); // add getpassword and getemail;
    ofstream usersf("users.txt", ios::app);
    usersf << user_data;
    usersf.close();
}
vector<country> dataStore::getCountries() {
    return countries;
}
bool dataStore::userAuth(string uName, string uPass) {
    for (int i = 0; i < users.size(); i++) {
        if (uName.compare(users[i]->getName()) == 0) {
            return users[i]->checkPass(uPass);
        }
    }
    return false;
}

void dataStore::SortListings() {
    //qDebug() << "sorting";

    sortRecurrH(HotelListingsHead);
    sortRecurrF(FlightListingsHead);
    sortRecurrC(CruiseListingsHead);
}
void dataStore::sortRecurrH(Node<hotellisting*>* n) {
    if (n == NULL) {
        return;
    }

    Node<hotellisting*>* curr = n;
    if (curr->prev != NULL) {
        curr = curr->prev;
    }
    while (curr != NULL) {

        if (curr->data->getPricePerNight() > n->data->getPricePerNight() && curr->priceRankIndex < n->priceRankIndex) {
            int temp = curr->priceRankIndex;
            curr->priceRankIndex = n->priceRankIndex;
            n->priceRankIndex = temp;
            sortRecurrH(HotelListingsHead);
            //return;
        }

        if (curr->data->getHotelRating() < n->data->getHotelRating() && curr->ratingRankIndex < n->ratingRankIndex) {
            int temp = curr->ratingRankIndex;
            curr->ratingRankIndex = n->ratingRankIndex;
            n->ratingRankIndex = temp;
        }
        curr = curr->prev;
    }
    if (n->next != NULL) {
        sortRecurrH(n->next);
    }
}
void dataStore::sortRecurrF(Node<flightlisting*>* n) {
    if (n ==NULL) {
        return;
    }
    Node<flightlisting*>* curr = n;
    if (curr->prev != NULL) {
        curr = curr->prev;
    }
    while (n->prev != NULL) {
        if (curr->data->getPriceperTraveller() > n->data->getPriceperTraveller()) {
            int temp = curr->priceRankIndex;
            curr->priceRankIndex = n->priceRankIndex;
            n->priceRankIndex = temp;
            sortRecurrF(FlightListingsHead);
        }
        if (curr->data->getAirlineRating() < n->data->getAirlineRating()) {
            int temp = curr->ratingRankIndex;
            curr->ratingRankIndex = n->ratingRankIndex;
            n->ratingRankIndex = temp;
        }
        if (curr->data->CalculateFlightDur() > n->data->CalculateFlightDur()) {
            int temp = curr->DistRankIndex;
            curr->DistRankIndex = n->DistRankIndex;
            n->DistRankIndex = temp;
        }

    }
    if (n->next != NULL) {
        sortRecurrF(n->next);
    }
}
//  TEMPORARY COMMENT
void dataStore::sortRecurrC(Node<cruise*>* n) {
    if (n ==NULL) {
        return;
    }
    Node<cruise*>* curr = n;
    if (curr->prev != NULL) {
        curr = curr->prev;
    }
    while (n->prev != NULL) {
        if (curr->data->getPricePerPerson() > n->data->getPricePerPerson()) {
            int temp = curr->priceRankIndex;
            curr->priceRankIndex = n->priceRankIndex;
            n->priceRankIndex = temp;
            sortRecurrC(CruiseListingsHead);
        }
        if (curr->data->getDuration() < n->data->getDuration()) {
            int temp = curr->ratingRankIndex;
            curr->ratingRankIndex = n->ratingRankIndex;
            n->ratingRankIndex = temp;
        }

    }
    if (n->next == NULL) {
        return;
    }
    if (n->next != NULL) {
        sortRecurrC(n->next);
    }
}


vector<Node<hotellisting*>*> dataStore::GetHotelsInLoc(string loc, string city, int persons, bool pool, bool pets, bool beach, bool bfast, bool dinner) {
    Node<hotellisting*>* curr = HotelListingsHead;
    vector<Node<hotellisting*>*> output;
    while (curr != NULL) {
        //qDebug() << curr->data->verifyLoc(loc, city) << "loc verify";
        if (curr->data->verifyLoc(loc, city) && curr->data->getMaxPersons() >= persons) {
            bool valid = true;
            if (pool) {
                if (!curr->data->getHotel()->getPool()) {
                    valid = false;
                }
            }
            if (pets) {
                if (!curr->data->getPets()) {
                    valid = false;
                }
            }
            if (beach) {
                if (!curr->data->getHotel()->getBeach()) {
                    valid = false;
                }
            }
            if (bfast) {
                if (!curr->data->getBfast()) {
                    valid = false;
                }
            }
            if (dinner) {
                if (!curr->data->getDinner()) {
                    valid = false;
                    qDebug() << "chc";
                }
            }
            if (valid) {
                qDebug() << "chc";
                output.push_back(curr);
            }
        }
        curr = curr->next;
    }
    return output;
}
/*  TEMPORARY COMMENT */
vector<Node<cruise*>*> dataStore::GetCruisesInLoc(string loc, string city) {
    Node<cruise*>* curr = CruiseListingsHead;
    vector<Node<cruise*>*> output;

    while (curr != NULL) {
        if (curr->data) {
            qDebug() << "exists";
        }
        if (curr->data->verifyLoc(loc, city)) {
            qDebug() << "added";
            output.push_back(curr);
        }
        curr = curr->next;
    }
    qDebug() << "returned";
    return output;
}
float dataStore::countryDist(country a, country b) {
    float result;
    result = sqrt(pow(a.get_coordinates().x - b.get_coordinates().x ,2) + pow(a.get_coordinates().y - b.get_coordinates().y ,2));
    return result;
}

vector<Node<flightlisting*>*> dataStore::GetShortest(string locdep, string citydep, string locArrive, string cityArrive, bool ref, bool onew, bool dest) { // bool dest is if there is a specified destination
    qDebug() << "before";
    vector<Node<flightlisting*>*> arr1 = GetShortestOfAll(locdep, citydep, onew);
    vector<Node<flightlisting*>*> arr2 = GetShortestOfAll(locArrive, cityArrive, onew);
qDebug() << "before";
    for (int i = 0 ; i < arr1.size(); i++) {
        for (int n = 0 ; n < arr2.size(); n++) {
            if (arr1[i]->data->getArrCountry().getName().compare(arr2[n]->data->getArrCountry().getName()) == 0) {

                for (int x = 1; x < arr2[n]->data->getstopsCount(); x++) {
                    qDebug() << "did it";
                    arr1[i]->data->addStop(arr2[n]->data->RevstopAt(x)); //push the rev stop at from arr2
                }
            }
        }
    }
    qDebug() << "before";
    for (int i = 0; i < arr1.size() ; i ++) {
        Node<flightlisting*>* temp = arr1[i];
        if (temp->data->getArrCountry().getName().compare(locArrive) != 0) {
            //qDebug() << "deleted";
            arr1.erase(arr1.begin() + i);
            //delete temp;
        }
    }
    for (int i = 0; i < arr1.size() ; i ++) {
        Node<flightlisting*>* temp = arr1[i];
        if (temp->data->getArrCountry().getName().compare(locArrive) != 0) {
            //qDebug() << "deleted";
            arr1.erase(arr1.begin() + i);
        }
    }
    if (arr1.size() > 0) {
        if (arr1[0]->data->getArrCountry().getName().compare(locArrive) != 0) {
            arr1.erase(arr1.begin());
        }
    }

    return arr1;
}
vector<Node<flightlisting*>*> dataStore::GetShortestOfAll(string locdep, string citydep, bool onew) {
    Node<flightlisting*>* curr = FlightListingsHead;
    vector<Node<flightlisting*>*> output;
    country source;
    int cityindex;
    //int iteration = 0;

    while (curr != NULL) {
        //check location and oneway,refund parameters
        //qDebug() << curr->data->isOneW();
        if ((curr->data->verifyFromLocs(locdep, citydep)) && (curr->data->isOneW() + onew > 0)) {
            output.push_back(curr);
            source = curr->data->getDepCountry();
            cityindex = curr->data->getDepCityIndex();
            //qDebug() << "got here";
            //qDebug() << "found some";
            //iteration++;
        }
        curr = curr->next;
    }
    if (source.getName().length() <= 1) {
        qDebug() << "returned";
        return output;
    }
    vector<vector<country>> cts;
    vector<vector<float>> dists;
    vector<country> c1;
    vector <float> d1;
    d1.push_back(0);
    dists.push_back(d1);

    c1.push_back(source);
    cts.push_back(c1);

    for (int i = 0 ; i < countries.size(); i++) {
        bool found = false;
        for (int n = 0 ; n < source.getBanned().size(); n++) {
            if (source.getBanned()[n].compare(countries[i].getName()) == 0) {
                //found = true;
            }
        }
        if (!found && countries[i].getName().compare(source.getName()) != 0) {
            vector <float> d;
            d.push_back(countryDist(countries[i], source));
            dists.push_back(d);

            vector<country> c;
            c.push_back(countries[i]);
            cts.push_back(c);
        }
    }
    for (int x = 0; x < cts.size(); x++) {
        for (int i = 0 ; i < countries.size(); i++) {
            bool found = false;
            for (int n = 0 ; n < cts[x][0].getBanned().size(); n++) {
                if (cts[x][0].getBanned()[n].compare(countries[i].getName()) == 0) {
                    found = true;
                    dists[x].push_back(0);
                }
            }
            if (!found) {
                dists[x].push_back(countryDist(countries[i], cts[x][0]));
                cts[x].push_back(countries[i]);
                //qDebug() << QString::fromStdString(countries[i].getName());
            }
        }
    }

    vector<vector<Coords>> out;
    vector<Coords> t;
    for (int i = 0; i < dists.size(); i++) {
        out.push_back(t);
    }
    float* dist = dijkstra(dists, 0, out);



    for (int i = 0 ; i < out.size(); i++) {
        if (output.size() > i) {
            qDebug() << "output: " << QString::fromStdString(output[i]->data->getDepCountry().getName());
            for (int n = 0; n < out[i].size(); n++) {
                if (out[i][n].x < cts.size()) {
                    if (out[i][n].y < cts[out[i][n].x].size()) {
                    qDebug() << "cts: " << QString::fromStdString(cts[out[i][n].x][out[i][n].y].getName());

                    if (output[i]->data == NULL) {
                    }

                    output[i]->data->addStop(cts[out[i][n].x][out[i][n].y], 0);
                    //qDebug() << "cts: " << QString::fromStdString(cts[out[i][n].x][out[i][n].y].getName());
                    }
                }
            }
        }
    }
    return output;
}

// OLD flights search
vector<Node<flightlisting*>*> dataStore::GetFlightsInLoc(string locdep, string citydep, string locArrive, string cityArrive, bool ref, bool onew) {
    Node<flightlisting*>* curr = FlightListingsHead;
    vector<Node<flightlisting*>*> output;
    while (curr != NULL) {
        if (curr->data->verifyFromLocs(locdep, citydep) && curr->data->getArrCountry().getName().compare(locArrive) == 0 && curr->data->isRefundable() == ref && curr->data->isOneW() == onew) {
            output.push_back(curr);
        }
        curr = curr->next;
    }
    return output;
}


vector<flightlisting*> dataStore::GetSortedFlights(int type) {
    Node<flightlisting*>* curr = FlightListingsHead; //1 price : 2 rating : 3 distance
    vector<flightlisting*> output;
    int index = 0;
    while (curr != NULL) {
        if (type == 1) {
            if (index == curr->priceRankIndex) {
                output.push_back(curr->data);
                index++;
            }
        }
        if (type == 2) {
            if (index == curr->ratingRankIndex) {
                output.push_back(curr->data);
                index++;
            }
        }
        curr = curr->next;
    }
    return output;
}

vector<cruise*> dataStore::GetSortedCruises(int type) {
    Node<cruise*>* curr = CruiseListingsHead; //1 price : 2 rating : 3 distance
    vector<cruise*> output;
    int index = 0;
    while (curr != NULL) {
        if (type == 1) {
            if (index == curr->priceRankIndex) {
                output.push_back(curr->data);
                index++;
            }
        }
        if (type == 2) {
            if (index == curr->ratingRankIndex) {
                output.push_back(curr->data);
                index++;
            }
        }
        if (type == 3) {
            if (index == curr->DistRankIndex) {
                output.push_back(curr->data);
                index++;
            }
        }
        curr = curr->next;
    }
    return output;
}
vector<hotellisting*> dataStore::GetSortedHotels(int type) {
    Node<hotellisting*>* curr = HotelListingsHead; //1 price : 2 rating : 3 distance
    vector<hotellisting*> output;
    int index = 0;
    while (curr != NULL) {
        if (type == 1) {
            if (index == curr->priceRankIndex) {
                output.push_back(curr->data);
                index++;
            }
        }
        if (type == 2) {
            if (index == curr->ratingRankIndex) {
                output.push_back(curr->data);
                index++;
            }
        }
        if (type == 3) {
            if (index == curr->DistRankIndex) {
                output.push_back(curr->data);
                index++;
            }
        }
        else {
            output.push_back(curr->data);
        }
        curr = curr->next;
    }
    return output;
}


void dataStore::deleteHlisting(int index) {
    Node<hotellisting*>* curr = HotelListingsHead;
    while (curr != NULL) {
        if (curr->initialIndex == index) {
            Node<hotellisting*>* temp = curr;
            //qDebug() << "found it";
            if (curr->prev != NULL) {
                if (curr->next != NULL) {
                    curr->prev->next = curr->next;
                    curr->prev->next->prev = curr->prev ;
                }
                else {
                    curr->prev->next = NULL;

                }
            }
            if (curr->next != NULL) {
                if (curr->prev != NULL) {
                    curr->next->prev = curr->prev;
                    curr->next->prev->next = curr->next;
                }
                else {
                    curr->next->prev = NULL;
                    HotelListingsHead = curr->next;
                }
            }
            delete temp;
            //temp = NULL;
            return;
        }
        curr = curr->next;
    }

}
void dataStore::deleteFlisting(int index) {
    Node<flightlisting*>* curr = FlightListingsHead;
    while (curr != NULL) {
        if (curr->next->initialIndex == index) {
            Node<flightlisting*>* temp = curr->next;
            if (curr->prev != NULL) {
                if (curr->next != NULL) {
                    curr->prev->next = curr->next;
                    curr->prev->next->prev = curr->prev ;
                }
                else {
                    curr->prev->next = NULL;

                }
            }
            if (curr->next != NULL) {
                if (curr->prev != NULL) {
                    curr->next->prev = curr->prev;
                    curr->next->prev->next = curr->next;
                }
                else {
                    curr->next->prev = NULL;
                    FlightListingsHead = curr->next;
                }
            }
            delete temp;
            //temp = NULL;
            return;
        }
        curr = curr->next;
    }

}
void dataStore::deleteClisting(int index) {
    Node<cruise*>* curr = CruiseListingsHead;
    while (curr != NULL) {
        if (curr->next->initialIndex == index) {
            Node<cruise*>* temp = curr->next;
            if (curr->prev != NULL) {
                if (curr->next != NULL) {
                    curr->prev->next = curr->next;
                    curr->prev->next->prev = curr->prev ;
                }
                else {
                    curr->prev->next = NULL;

                }
            }
            if (curr->next != NULL) {
                if (curr->prev != NULL) {
                    curr->next->prev = curr->prev;
                    curr->next->prev->next = curr->next;
                }
                else {
                    curr->next->prev = NULL;
                    CruiseListingsHead = curr->next;
                }
            }
            delete temp;
            //temp = NULL;
            return;
        }
        curr = curr->next;
    }
}
user* dataStore::verifyUser(string email, string pass) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->checkPass(pass) && users[i]->getEmail().compare(email) == 0) {
            return users[i];
        }
    }
    return NULL;
}

bool dataStore::UserExists(string email) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getEmail().compare(email) == 0) {
            return true;
        }
    }
    return false;
}

int V;

int dataStore::minDistance(float dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
float* dataStore::dijkstra (vector<vector<float>> graph, int src, vector<vector<Coords>> &out) //Method to implement shortest path algorithm
{
    V = graph.size();
    float dist [graph.size()];
    bool Dset[graph.size()];
    for (int i= 0; i < graph.size(); i++)
    {
        dist[i] = INT_MAX;
        Dset[i] = false;
    }
    dist[src] = 0; //Initialize the distance of the source vertec to zero
    for (int c = 0; c <graph.size(); c++)
    {
        int u = minDistance(dist, Dset); //u is any vertex that is not yet included Dset and has minimum distance
        Dset[u] = true; //If the vertex with minimum distance found include it to Dset
        for (int v = 0; v < graph[c].size(); v++)
            //Update dist[v] if not inDsetand their is a path from src to v through u that has distance minimum than current value of dist[v]
        {
            if (!Dset[v] && graph[u][v] && abs(dist[u] - INT_MAX) > 100 && dist[u] + graph[u][v] <dist[v]) {
                dist[v] =dist[u] + graph[u][v];
                Coords temp(u, v);
                out[v].push_back(temp);
            }
        }
    }
    //qDebug() << "Vertex\t\tDistance from source";

    for (int i= 0; i < graph.size(); i++) //will print the vertex with their distance from the source to the console
    {
        char c = 65 + i;
        //qDebug() << c << "\t\t"<<dist[i];
    }
    return dist;
}
