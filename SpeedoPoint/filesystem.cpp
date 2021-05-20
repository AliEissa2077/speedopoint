#include "filesystem.h"

filesystem::filesystem() {}
filesystem::filesystem(string users, string country, string hotel, string flight, string cruise, string hl, string cl, string fl) {
	user = users;
	countries = country;
	hotels = hotel;
	flights = flight;
	cruises = cruise;
	hotellisting = hl;
	cruiselisting = cl;
	flightlisting = fl;
}
string filesystem::getUsers() {
	return user;
}
string filesystem::getCountries() {
	return countries;
}
string filesystem::getHotels() {
	return hotels;
}
string filesystem::getFlights() {
	return flights;
}
string filesystem::getCruises() {
	return cruises;
}
string filesystem::getHotelListing() {
	return hotellisting;
}
string filesystem::getCruiseListing() {
	return cruiselisting;
}
string filesystem::getFlightListing() {
	return flightlisting;
}
void filesystem::addUser(string data) {
	ofstream outfile(user, ios::app);
	outfile.open();
	outfile << data;
	outfile.close();
}