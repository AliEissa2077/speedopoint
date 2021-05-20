#include <fstream>
#include <string>
using namespace std;

class filesystem {
private:
	string user;
	string countries;
	string hotels;
	string flights;
	string cruises;
public:
	filesystem();
	filesystem(string users, string country, string hotel, string flight, string cruise);
	string getUsers();
	string getCountries();
	string getHotels();
	string getFlights();
	string getCruises();
	void addUser(string data);
};