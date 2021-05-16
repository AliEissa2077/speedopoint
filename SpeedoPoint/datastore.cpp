#include "datastore.h"

dataStore::dataStore()
{
    //import from file or data base and store into vector and linked lists
    // sort indeces start as the node count
    SortListings();

}

void dataStore::AddUser(user u) {
    users.push_back(u);
    // write into file;
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
    sortRecurrC(CruiseListingsHead);
}
void dataStore::sortRecurrH(Node<hotellisting>* n) {
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
    sortRecurrH(n->next);

}
void dataStore::sortRecurrF(Node<flightlisting>* n) {
    Node<flightlisting>* curr = n;
    while (n->prev != NULL) {
        curr = curr->prev;
        if (curr->data.getPriceperTraveller() > n->data.getPriceperTraveller()) {
            n->priceRankIndex = curr->priceRankIndex  - 1;
        }
        if (curr->data.getAirlineRating() < n->data.getAirlineRating()) {
            n->ratingRankIndex = curr->ratingRankIndex  - 1;
        }

    }
    sortRecurrF(n->next);
}
void dataStore::sortRecurrC(Node<cruise>* n) {
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
    sortRecurrC(n->next);
}


vector<hotellisting> dataStore::GetHotelsInLoc(string loc, string city) {
    Node<hotellisting>* curr = HotelListingsHead;
    vector<hotellisting> output;
    while (curr != NULL) {
        if (curr->data.verifyLoc(loc, city)) {
            output.push_back(curr->data);
        }
        curr = curr->next;
    }
}
vector<hotellisting> dataStore::GetCruisesInLoc(string loc, string city) {

}
vector<hotellisting> dataStore::GetFlightsInLoc(string locdep, string citydep, string locArrive, string cityArrive) {

}
