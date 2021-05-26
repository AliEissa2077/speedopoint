#include "hotellisting.h"
#include "date.h"
#include <QMessageBox>
#include "user.h"
#include <QDebug>

hotellisting::hotellisting()
{
    htl = new hotel;
	cityIndex = -1;
	area = -1;
	wifi = false;
	bfast = false;
	person = -1;
	refundable = false;
    pricePerNight = 0;
	dinner = false;
	pets = false;
	roomType = "";
}

hotellisting::hotellisting(hotel* hot, country location, int price, int index, int area_, bool wifi_, bool breakfast, int numPeople, bool refund, bool dinner_, bool pet, std::string roomtype): htl(hot), loc(location), cityIndex(index), area(area_), wifi(wifi_), bfast(breakfast), person(numPeople), refundable(refund), dinner(dinner_), pets(pet), roomType(roomtype)
{
    htl = hot;
    loc = location;
    cityIndex = index;
    area = area_;
    pricePerNight = price;
    wifi = wifi_;
    bfast = breakfast;
    person = numPeople;
    refundable = refund;
    dinner = dinner_;
    pets = pet;
    std::string roomType = roomtype;

}



reservation* hotellisting::reserve(user* acc, date d, int days, int adults, int children)
{
    if (acc->getWallet()->getAmount() < pricePerNight*(days)) {
        QMessageBox* confirm = new QMessageBox(0);
        QMessageBox::StandardButton reply1;
        //confirm->exec();
        reply1 = QMessageBox::information(confirm, "Insufficient funds", "Insufficient funds, make sure to deposit money into your wallet.",
            QMessageBox::Ok);
        return NULL;
    }
    QMessageBox* confirm = new QMessageBox(0);
    QMessageBox::StandardButton reply1;
    //confirm->exec();
    reply1 = QMessageBox::question(confirm, "Confirm?", "Are you sure you want to pay " + QString::number(pricePerNight*(days)) + "LE" + " from Wallet: " + QString::number(acc->getWallet()->getAmount()),
        QMessageBox::Yes | QMessageBox::No);
    if (reply1 == QMessageBox::No) {
        return NULL;
    }
    /*QMessageBox Msgbox;
    Msgbox.setText("would you like to redeem your "+acc->getPoints() + " Points?");
    Msgbox.exec();*/

    QMessageBox* msgbx = new QMessageBox(0);

    QMessageBox::StandardButton reply;
    //msgbx->exec();

    int deduct = 0;
    reply = QMessageBox::question(msgbx, "Redeem", "Do you want to Redeem your " + QString::number(acc->getPoints()) + " points?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        deduct = acc->redeem();
    }

    if (deduct > pricePerNight*(days)) {
        deduct = pricePerNight*(days);
    }
    payment newp(pricePerNight*(days) - deduct, 0, d, acc);

    acc->getWallet()->pay(pricePerNight*(days) - deduct);
    reservation* result = new reservation(this, d, days, newp, acc, adults, children);

    acc->updatePoints((pricePerNight*(days) - deduct) / 4);
    return result;



}

bool hotellisting::verifyLoc(string l, string city)
{
    if (l.compare(loc.getName()) == 0)
    {
        if (city.length() > 1) 
        {
            qDebug() <<"entered";
            vector<string> list = loc.getCities();
            if (city.compare(list[getCityIndex()]) == 0)
            {
                return true;
            }

            return false;
        }
        else return true;
    }
    else { return false;}
}

int hotellisting::getPricePerNight()
{
    return pricePerNight;
}
float hotellisting::getHotelRating()
{
    return htl->getRating();
}
hotel* hotellisting::getHotel()
{
    return htl;
}
bool hotellisting::getPets()
{
    return pets;
}
bool hotellisting::getDinner()
{
    return dinner;
}
bool hotellisting::getRefundable()
{
    return refundable;
}
int hotellisting::getMaxPersons() 
{
    return person;
}
bool hotellisting::getBfast() 
{
    return bfast;
}
bool hotellisting::getWifi() 
{
    return wifi;
}
int hotellisting::getArea() 
{
    return area;
}
country hotellisting::getLoc() {
    return loc;
}
int hotellisting::getCityIndex() {
    return cityIndex;
}

