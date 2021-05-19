#ifndef DATASTORE_H
#define DATASTORE_H
#include <vector>
#include <map>
#include "user.h"
#include "hotellisting.h"
#include "flightlisting.h"
#include "cruise.h"
#include "filesystem.h"

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
    vector<country> countries;
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
    vector<country> getCountries();
    vector<hotellisting> GetHotelsInLoc(string loc, string city, bool pool, bool pets, bool beach, bool bfast, bool dinner);
    vector<cruise> GetCruisesInLoc(string loc, string city);
    vector<flightlisting> GetFlightsInLoc(string locdep, string citydep, string locArrive, string cityArrive);
};

#endif // DATASTORE_H
