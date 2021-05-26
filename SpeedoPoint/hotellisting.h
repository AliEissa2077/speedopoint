#pragma once
#ifndef HOTELLISTING_H
#define HOTELLISTING_H
#include "hotel.h"
#include "country.h"
#include <string>
#include "reservation.h"
#include "user.h"
using namespace std;



class hotellisting {
private:
    hotel* htl;
	country loc;
    int pricePerNight;
	int cityIndex;
	int area;
	bool wifi;
	bool bfast;
	int person;
	bool refundable;
	bool dinner;
	bool pets;
	std::string roomType;
public:
	hotellisting();
    hotellisting(hotel* hot, country location, int price, int index, int area_, bool wifi_, bool breakfast, int numPeople, bool refund, bool dinner_, bool pet, std::string roomtype);
    reservation* reserve(user* acc, date d, int days, int adults, int children);
    int getPricePerNight();
    float getHotelRating();
    hotel* getHotel();
    country getLoc();
    int getCityIndex();
    bool verifyLoc(string l, string city); // if city is empty then ignore it
    bool getPets();
    bool getDinner();
    bool getRefundable();
    int getMaxPersons();
    bool getBfast();
    bool getWifi();
    int getArea();
};


#endif HOTELLISTING_H
