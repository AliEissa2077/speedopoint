#include "fileSystem.h"

fileSystem::fileSystem() {}
fileSystem::fileSystem(string users, string country, string hotel, string flight, string cruise, string hl, string cl, string fl) {
	user = users;
	countries = country;
	hotels = hotel;
	flights = flight;
	cruises = cruise;
	hotellisting = hl;
	cruiselisting = cl;
	flightlisting = fl;
}
string fileSystem::getUsers() {
	return user;
}
string fileSystem::getCountries() {
	return countries;
}
string fileSystem::getHotels() {
	return hotels;
}
string fileSystem::getFlights() {
	return flights;
}
string fileSystem::getCruises() {
	return cruises;
}
string fileSystem::getHotelListing() {
	return hotellisting;
}
string fileSystem::getCruiseListing() {
	return cruiselisting;
}
string fileSystem::getFlightListing() {
	return flightlisting;
}
void fileSystem::addUser(string data) {
	ofstream outfile(user, ios::app);
    outfile.open(user);
	outfile << data;
	outfile.close();
}
