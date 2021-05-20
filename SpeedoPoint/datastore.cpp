#include "datastore.h"
#include "user.h"
dataStore::dataStore(filesystem filesystem)
{
    //import from file or data base and store into vector and linked lists
    // sort indeces start as the node count

    //load users 
    string user_ = filesystem.getUsers();
    ifstream u(user_);
    u.open();
    while (!u.eof()) {
        string username;
        string pwd;
        string email;
        u >> username >> pwd >> email;
        user user__(username, pwd, email);
        users.push_back(user__);
    }
    u.close();


    // load countries
    string country_ = filesystem.getCountries();
    ifstream c(country_);
    c.open();
    while (!c.eof()) {
        string name;
        bool banned;
        string c1;
        string c2;
        string c3;
        c >> name >> banned >> c1 >> c2 >> c3;
        string city;
        country country__(name, banned);
        country__.addCity(c1);
        country__.addCity(c2);
        country__.addCity(c3);
        countries.push_back(country__);
    }
    c.close();



    //load hotels

    string hotel_ = filesystem.getHotels();
    ifstream h(hotel_);
    h.open();
    while (!h.eof()) {
        string name;
        string country_;
        int index;
        int range;
        bool pool;
        h >> name >> country_ >> index >> range >> pool;
        country ctry;
        for (auto x : countries) {
            if (country == x.getName()) {
                ctry = x;
            }
        }
        hotel h1(name, ctry, index, range, pool);
        hotels.push_back(h1);
    }
    h.close();

    // load hotellisting

    string hlisting = filesystem.getHotelListing();
    ifstream hl(hlisting);
    hl.open();
    while (!hl.eof()) {
        string hname;
        hlline << hname;
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
        hl >> area >> price >> wifi >> bfast >> num >> refund >> dinner >> pet;
        hotellisting* hotellisting_;
        hotellisting_ = new hotellisting(h, ctry, price, index, area, wifi, bfast, num, refund, dinner, pet, roomtype);
        // append to linked lsit


    }
    hl.close();

    // load flighttickets 

















    string flightfile = filesystem.getFlights();
    ifstream f(flightfile);
    f.open();
    string fline;
    while (getline(f, fline)) {

    }





















<<<<<<< HEAD
=======
    HotelListingsHead = NULL;
    FlightListingsHead = NULL;
    CruiseListingsHead = NULL;
>>>>>>> dbd3f0109d14e6544a856270681351d0a4a826ea
 
    SortListings();

}

void dataStore::AddUser(user u) {
    users.push_back(u);
    // write into file;
}
vector<country> dataStore::getCountries() {
    return countries;
}
bool dataStore::userAuth(string uName, string uPass) {
    for (int i = 0; i < users.size(); i++) {
        if (uName.compare(users[i].getName()) == 0) {
            return users[i].checkPass(uPass);
        }
    }
    return false;
}

void dataStore::SortListings() {
    sortRecurrH(HotelListingsHead);
    sortRecurrF(FlightListingsHead);
    //sortRecurrC(CruiseListingsHead);
}
void dataStore::sortRecurrH(Node<hotellisting>* n) {
    if (n ==NULL) {
        return;
    }

    Node<hotellisting>* curr = n;
    while (n->prev != NULL) {
        curr = curr->prev;
        if (curr->data.getPricePerNight() > n->data.getPricePerNight()) {
            n->priceRankIndex = curr->priceRankIndex  - 1;
        }
        if (curr->data.getHotelRating() < n->data.getHotelRating()) {
            n->ratingRankIndex = curr->ratingRankIndex  - 1;
        }

    }
    if (n->next != NULL) {
        sortRecurrH(n->next);
    }
}
void dataStore::sortRecurrF(Node<flightlisting>* n) {
    if (n ==NULL) {
        return;
    }
    Node<flightlisting>* curr = n;
    while (n->prev != NULL) {
        curr = curr->prev;
        if (curr->data.getPriceperTraveller() > n->data.getPriceperTraveller()) {
            n->priceRankIndex = curr->priceRankIndex  - 1;
        }
        if (curr->data.getAirlineRating() < n->data.getAirlineRating()) {
            n->ratingRankIndex = curr->ratingRankIndex  - 1;
        }
        if (curr->data.CalculateFlightDur() > n->data.CalculateFlightDur()) {
            n->DistRankIndex = curr->DistRankIndex  - 1;
        }

    }
    if (n->next != NULL) {
        sortRecurrF(n->next);
    }
}
/*  TEMPORARY COMMENT
void dataStore::sortRecurrC(Node<cruise>* n) {
    if (n ==NULL) {
        return;
    }
    Node<cruise>* curr = n;
    while (n->prev != NULL) {
        curr = curr->prev;
        if (curr->data.getPricePerPerson() > n->data.getPricePerPerson()) {
            n->priceRankIndex = curr->priceRankIndex  - 1;
        }
        if (curr->data.getDuration() < n->data.getDuration()) {
            n->ratingRankIndex = curr->ratingRankIndex  - 1;
        }

    }
    if (n->next == NULL) {
        return;
    }
    if (n->next != NULL) {
        sortRecurrC(n->next);
    }
}
*/

vector<Node<hotellisting>*> dataStore::GetHotelsInLoc(string loc, string city, int persons, bool pool, bool pets, bool beach, bool bfast, bool dinner) {
    Node<hotellisting>* curr = HotelListingsHead;
    vector<Node<hotellisting>*> output;
    while (curr != NULL) {
        if (curr->data.verifyLoc(loc, city) && curr->data.getMaxPersons() <= persons) {
            bool valid = true;
            if (pool) {
                if (!curr->data.getHotel().getPool()) {
                    valid = false;
                }
            }
            if (pets) {
                if (!curr->data.getPets()) {
                    valid = false;
                }
            }
            if (beach) {
                if (!curr->data.getHotel().getBeach()) {
                    valid = false;
                }
            }
            if (bfast) {
                if (!curr->data.getBfast()) {
                    valid = false;
                }
            }
            if (dinner) {
                if (!curr->data.getDinner()) {
                    valid = false;
                }
            }
            if (valid) {
                output.push_back(curr);
            }
        }
        curr = curr->next;
    }
    return output;
}
/*  TEMPORARY COMMENT
vector<Node<cruise>*> dataStore::GetCruisesInLoc(string loc, string city) {
    Node<cruise>* curr = CruiseListingsHead;
    vector<Node<cruise>*> output;
    while (curr != NULL) {
        if (curr->data.verifyLoc(loc, city)) {
            output.push_back(curr);
        }
        curr = curr->next;
    }
    return output;
}
*/
vector<Node<flightlisting>*> dataStore::GetFlightsInLoc(string locdep, string citydep, string locArrive, string cityArrive) {
    Node<flightlisting>* curr = FlightListingsHead;
    vector<Node<flightlisting>*> output;
    while (curr != NULL) {
        if (curr->data.verifyFromAndToLocs(locdep, citydep, locArrive, cityArrive)) {
            output.push_back(curr);
        }
        curr = curr->next;
    }
    return output;
}

vector<flightlisting> dataStore::GetSortedFlights(int type) {
    Node<flightlisting>* curr = FlightListingsHead; //1 price : 2 rating : 3 distance
    vector<flightlisting> output;
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

vector<cruise> dataStore::GetSortedCruises(int type) {
    Node<cruise>* curr = CruiseListingsHead; //1 price : 2 rating : 3 distance
    vector<cruise> output;
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
vector<hotellisting> dataStore::GetSortedHotels(int type) {
    Node<hotellisting>* curr = HotelListingsHead; //1 price : 2 rating : 3 distance
    vector<hotellisting> output;
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
/*
 FOR FLIGHTLISTING CPP
float flightlisting::CalculateFlightDur() {
    return _CalculateFlightDur(stops);
}


float subtract(date d, date f) {
    float var1 = 0;
        var1 += d.day*24;
        var1 += d.hour;
        var1 += d.minute/60.0;

        float var2 = f.day*24 + f.hour + f.minute / 60.0;
        cout << var1;
        cout <<endl;
        return var2 - var1;
}


float _CalculateFlightDur(stop* stp) {
    stop* last = stp;
    while (last->next != NULL) {
        last = last->next;
    }
    return abs(subtract(stp->getTime(), last->getTime()));
} //recursive
*/
