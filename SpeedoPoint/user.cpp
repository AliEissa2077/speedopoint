#include "user.h"

user::user() {
	username = "";
	password = "";
	points = 0;
	email = "";
}
user::user(std::string usrname, std::string pwd, std::string email_) : username(usrname), password(pwd), email(email_) {
	points = 0;
	wallet new_wallet(0);
    wallt = new_wallet;
}
void user::setName(std::string usrname) {
	username = usrname;
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
    return wallt.redeem();
}

string user::getEmail() {
    return email;
}
string user::getPassword() {
    return password;
}
