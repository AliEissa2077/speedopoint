#include "user.h"

user::user() {
	username = "";
	password = "";
	points = 0;
	email = "";
}
user::user(std::string usrname, std::string pwd, std::string email_) : username(usrname), password(pwd), email(email_) {
    points = 0;
    wallt = new wallet(0);
}
void user::setName(std::string usrname) {
	username = usrname;
}
void user::setEmail(std::string m) {
    email = m;
}
void user::setPass(std::string pwd) {
	password = pwd;
}
void user::changePass(std::string pwd) {
	password = pwd;
}
std::string user::getName() {
	return username;
}

int user::getPoints() {
	return points;
}
void user::updatePoints(int pts) {
	if (pts > 0) {
		points += pts;
	}
}
void user::updateReservations(reservation* r) {
    reservations.push_back(r);
}
void user::updateCruiseReservations(cruisereservation* r) {
    cruisereservations.push_back(r);
}
void user::updateTickets(flightticket* t) {
    tickets.push_back(t);
}
bool user::checkPass(string pass) {
    if (pass.compare(password) == 0) {
        return true;
    }
    return false;
}
int user::redeem() {
    return wallt->redeem();
}

string user::getEmail() {
    return email;
}
string user::getPassword() {
    return password;
}
wallet* user::getWallet() {
    return wallt;
}
std::vector<reservation*>* user::getReservations() {
    return &reservations;
}
std::vector<flightticket*>* user::getTickets() {
    return &tickets;
}
std::vector<cruisereservation*>* user::getCruisereservations() {
    return &cruisereservations;
}
