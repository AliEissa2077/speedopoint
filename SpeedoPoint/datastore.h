#ifndef DATASTORE_H
#define DATASTORE_H
#include <vector>
#include <map>
#include "user.h"
#include "hotellisting.h"
#include "flightlisting.h"
#include "cruise.h"

using namespace std;

template <typename T>
struct Node {
  T data;
  int priceRankIndex;
  int ratingRankIndex;
  int DistRankIndex;
  Node *next;
  Node* prev;
};

class dataStore
{
private:
    vector<user> users;
    Node<hotellisting>* HotelListingsHead;
    Node<flightlisting>* FlightListingsHead;
    Node<cruise>* CruiseListingsHead;
public:
    dataStore();
    void SortListings();
    void sortRecurrH(Node<hotellisting>* n);
    void sortRecurrF(Node<flightlisting>* n);
    void sortRecurrC(Node<cruise>* n);
    bool userAuth(string uName, string uPass);
    void AddUser(user u);
    vector<hotellisting> GetHotelsInLoc(string loc, string city);
    vector<hotellisting> GetCruisesInLoc(string loc, string city);
    vector<hotellisting> GetFlightsInLoc(string locdep, string citydep, string locArrive, string cityArrive);
};

#endif // DATASTORE_H
