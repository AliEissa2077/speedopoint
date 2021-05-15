#pragma once
#ifndef HOTELLISTING_H
#define HOTELLISTING_H
#include "hotel.h"
#include "country.h"
#include <string>
#include "reservation.h"
#include "user.h"

class hotellisting {
	hotel hotel;
	country loc;
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
	hotellisting(hotel hot, country location, int index, int area_, bool wifi_, bool breakfast, int numPeople, bool refund, bool dinner_, bool pet, std::string roomtype);
	reservation reserve(user acc);

};


#endif HOTELLISTING_H