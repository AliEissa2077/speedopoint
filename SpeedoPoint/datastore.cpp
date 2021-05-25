#include "datastore.h"
#include "user.h"
#include <QDebug>
#include <fstream>
//#include <bits/stdc++.h>
#include <sstream>
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
            ss >> name >> banned >> c1 >> c2 >> c3;
            string city;
            country country__(name, banned);
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
            hotel h1(name, ctry, index, range, pool);
            for (int i = 0 ; i < 10; i++) {
                h1.updateRating(rating);
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
            hotel h;
            for (auto x : hotels) {
                if (hname == x.getName()) {
                    h = x;
                }
            }
            country ctry = h.getCountry();
            int index = h.getIndex();
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
            airline airline(name, range, srt);
            airlines.push_back(airline); // add vector named airlines type airline to header
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
                            stps = new stop(ct, index, aport, dt);
                        }
                        else {
                            date dt;
                            stps->add_stop(ct, index, aport, dt);
                        }
                    }
                }
            }
            ssf >> al;
            airline airln;
            for (auto x : airlines) {
                if (x.getName() == al) {
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
            flightlisting* flist = new flightlisting(code, airln, stps, stpnum, dep, arr, price, cabin, plane_model, carryon, checkedW, additionalw, refundable, oneway);

            // add it to linked list

            if (FlightListingsHead == NULL) {
                FlightListingsHead = new Node<flightlisting*>;
                FlightListingsHead->data = flist;
                FlightListingsHead->initialIndex = Iindex;
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


    // load points

    string pointsfile = "points.txt";
    ifstream p(pointsfile);
    if (p.is_open()) {
        string pl;
        while (getline(p, pl)) {
            user u;
            int pts;
            string u_name;
            pl >> u >> pts;
            for (auto x : users) {
                if (u_name == x->getName()) {
                    u = *x;
                }
            }
            pair<user, int> p1(u, pts);
            points.push_back(p1);
        }
        p.close();
    }


















    SortListings();


    // for testing
    //qDebug() << "here";
    Node<hotellisting*>* curr = HotelListingsHead;
    while (curr != NULL) {
        qDebug() << curr->data->getHotelRating();
        curr = curr->next;
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
                if (!curr->data->getHotel().getPool()) {
                    valid = false;
                }
            }
            if (pets) {
                if (!curr->data->getPets()) {
                    valid = false;
                }
            }
            if (beach) {
                if (!curr->data->getHotel().getBeach()) {
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
        if (curr->data->verifyLoc(loc, city)) {
            output.push_back(curr);
        }
        curr = curr->next;
    }
    return output;
}

vector<Node<flightlisting*>*> dataStore::GetFlightsInLoc(string locdep, string citydep, string locArrive, string cityArrive, bool ref, bool onew) {
    Node<flightlisting*>* curr = FlightListingsHead;
    vector<Node<flightlisting*>*> output;
    while (curr != NULL) {
        qDebug() << "got here";
        if (curr->data->verifyFromAndToLocs(locdep, citydep, locArrive, cityArrive) && curr->data->isRefundable() == ref && curr->data->isOneW() == onew) {
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
