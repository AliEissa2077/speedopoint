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
void dataStore::sortRecurrH(Node<hotellisting>* h) {
    while (h->prev != NULL) {
        Node<hotellisting>* curr = h->prev;

    }

}
void dataStore::sortRecurrF(Node<flightlisting>* n) {

}
void dataStore::sortRecurrC(Node<cruise>* n) {

}
