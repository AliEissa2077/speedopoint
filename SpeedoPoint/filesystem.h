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
	string hotellisting;
	string cruiselisting;
	string flightlisting;
public:
	filesystem();
	filesystem(string users, string country, string hotel, string flight, string cruise, string hl, string cl, string fl);
	string getUsers();
	string getCountries();
	string getHotels();
	string getFlights();
	string getCruises();
	string getHotelListing();
	string getCruiseListing();
	string getFlightListing();
	void addUser(string data);
};