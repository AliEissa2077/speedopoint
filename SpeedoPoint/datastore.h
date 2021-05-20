#ifndef DATASTORE_H
#define DATASTORE_H
#include <vector>
#include <map>
#include "user.h"
#include "hotellisting.h"
#include "flightlisting.h"
#include "cruise.h"
#include "filesystem.h"
#include "country.h"

using namespace std;

template <typename T>
struct Node {
  T data;

  int initialIndex;

  int priceRankIndex;
  int ratingRankIndex;
  int DistRankIndex;
  Node *next = NULL;
  Node* prev = NULL;
};

class dataStore
{
private:
    vector<user> users;
    vector<country> countries;
    vector<hotel> hotels;
    Node<hotellisting*>* HotelListingsHead;
    Node<flightlisting*>* FlightListingsHead;
    Node<cruise*>* CruiseListingsHead;

public:
    dataStore();
    dataStore(fileSystem filesy);
    void SortListings();
    void sortRecurrH(Node<hotellisting*>* n);
    void sortRecurrF(Node<flightlisting*>* n);
    void sortRecurrC(Node<cruise*>* n);
    bool userAuth(string uName, string uPass);
    void AddUser(user u);
    vector<country> getCountries();
    vector<Node<hotellisting*>*> GetHotelsInLoc(string loc, string city, int persons, bool pool, bool pets, bool beach, bool bfast, bool dinner);
    vector<Node<cruise*>*> GetCruisesInLoc(string loc, string city);
    vector<Node<flightlisting*>*> GetFlightsInLoc(string locdep, string citydep, string locArrive, string cityArrive);

    vector<flightlisting*> GetSortedFlights(int type);
    vector<cruise*> GetSortedCruises(int type);
    vector<hotellisting*> GetSortedHotels(int type);

    void deleteHlisting(int index);
    void deleteFlisting(int index);
    void deleteClisting(int index);
};

#endif // DATASTORE_H
