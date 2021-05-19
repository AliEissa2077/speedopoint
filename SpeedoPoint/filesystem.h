#include <fstream>
#include <string>
using namespace std;

class filesystem {
private:
	fstream user;
	fstream countries;
	fstream hotels;
	fstream flights;
	fstream cruises;
public:
	filesystem() {};
	filesystem(string users, string country, string hotel, string flight, string cruise);
	fstream getUsers();
	fstream getCountries();
	fstream getHotels();
	fstream getFlights();
	fstream getCruises();
	void addUser(string data);
};