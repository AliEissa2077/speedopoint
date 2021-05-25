#pragma once
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "reservation.h"
#include "flightticket.h"
#include "cruisereservation.h"
#include "wallet.h"
#include <iostream>
class user {
private:
	std::string username;
	std::string password;
    wallet* wallt;
    std::vector<reservation*> reservations;
    std::vector<flightticket*> tickets;
    std::vector<cruisereservation*> cruisereservations;
	int points;
	std::string email;
public:
	user();
	user(std::string usrname, std::string pwd, std::string email_);
	void setName(std::string usrname);
	void setPass(std::string pwd);
	void changePass(std::string pwd);
	std::string getName();
    bool checkPass(string pass);
	int getPoints();
	void updatePoints(int pts);
    void updateReservations(reservation* r);
    void updateTickets(flightticket* t);
    void updateCruiseReservations(cruisereservation* r);
    int redeem();
    string getEmail();
    string getPassword();
    wallet* getWallet();
    void setEmail(std::string m);
    std::vector<reservation*>* getReservations();
    std::vector<flightticket*>* getTickets();
    std::vector<cruisereservation*>* getCruisereservations();
};

#endif USER_H
