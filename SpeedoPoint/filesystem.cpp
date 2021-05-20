#include "filesystem.h"

filesystem::filesystem() {}
filesystem::filesystem(string users, string country, string hotel, string flight, string cruise) {
	user = users;
	countries = country;
	hotels = hotel;
	flights = flight;
	cruise = cruise;
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
void filesystem::addUser(string data) {
	ofstream outfile(user, ios::app);
	outfile.open();
	outfile << data;
	outfile.close();
}