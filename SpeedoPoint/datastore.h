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
#include "airline.h"
#include "airport.h"

using namespace std;

template <typename T>
struct Node {
  T data;

  int initialIndex;

  int priceRankIndex = 20;
  int ratingRankIndex = 20;
  int DistRankIndex = 20;
  Node *next = NULL;
  Node* prev = NULL;
  Node() : next(NULL) , prev(NULL) {}
};
//djikistra, sorting, updating rating, cancelation, invoices, user page
class dataStore
{
private:
    vector<user*> users;
    vector<country> countries;
    vector<hotel*> hotels;
    vector<airline*> airlines;
    vector<airport> airports;
    Node<hotellisting*>* HotelListingsHead;
    Node<flightlisting*>* FlightListingsHead;
    Node<cruise*>* CruiseListingsHead;
    vector<cruisecompany*> cruisecompanies;
    vector<cruise*> cruises;

    float countryDist(country a, country b);
    float* dijkstra (vector<vector<float>> graph, int src, vector<vector<Coords>> &out);
    int minDistance(float dist[], bool sptSet[]);

public:
    dataStore();
    dataStore(fileSystem filesy);
    void SortListings();
    void sortRecurrH(Node<hotellisting*>* n);
    void sortRecurrF(Node<flightlisting*>* n);
    void sortRecurrC(Node<cruise*>* n);
    bool userAuth(string uName, string uPass);
    void AddUser(user* u);
    void updatePoints();
    vector<country> getCountries();
    vector<Node<hotellisting*>*> GetHotelsInLoc(string loc, string city, int persons, bool pool, bool pets, bool beach, bool bfast, bool dinner);
    vector<Node<cruise*>*> GetCruisesInLoc(string loc, string city);
    vector<Node<flightlisting*>*> GetFlightsInLoc(string locdep, string citydep, string locArrive, string cityArrive, bool ref, bool onew);

    vector<flightlisting*> GetSortedFlights(int type);
    vector<cruise*> GetSortedCruises(int type);
    vector<hotellisting*> GetSortedHotels(int type);

    void deleteHlisting(int index);
    void deleteFlisting(int index);
    void deleteClisting(int index);

    user* verifyUser(string email, string pass);
    bool UserExists(string email);
};

#endif // DATASTORE_H
