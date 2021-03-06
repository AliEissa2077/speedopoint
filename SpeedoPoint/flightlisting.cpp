#include "flightlisting.h"
#include "country.h"
#include <QMessageBox>
#include <QtDebug>


flightlisting::flightlisting() {

}
flightlisting::flightlisting(string code_, airline* air, stop* stp, int sptnum, date departure, date arrival, int price, std::string cabin_, std::string planeModel, int carryOn, int CheckedW, int additionalWPrice, bool ref, bool onew)
{
    code = code_;
	airlne = air;
	stops = stp;
	stopnum = sptnum;
	dep = departure;
	arr = arrival;
	pricepertraveller = price;
	cabin = cabin_;
	plane = planeModel;
	carronW = carryOn;
	checkedBaggageW = CheckedW;
	additionalBagPrice = additionalWPrice;
    refundable = ref;
    oneway = onew;

}

flightticket* flightlisting::reserve(user* acc, int adults, int children, date d)
{

    QMessageBox* confirm = new QMessageBox(0);
    QMessageBox::StandardButton reply1;
    //confirm->exec();
    reply1 = QMessageBox::question(confirm, "Confirm?", "Are you sure you want to pay " + QString::number((pricepertraveller*adults + pricepertraveller/2 * children)) + "LE" + " from Wallet: " + QString::number(acc->getWallet()->getAmount()),
        QMessageBox::Yes | QMessageBox::No);
    if (reply1 == QMessageBox::No) {
        return NULL;
    }

    QMessageBox* msgbx = new QMessageBox(0);

    QMessageBox::StandardButton reply;
    //msgbx->exec();

    int deduct = 0;
    reply = QMessageBox::question(msgbx, "Redeem", "Do you want to Redeem your " + QString::number(acc->getPoints()) + " points?",
        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        deduct = acc->redeem();
    }

    if (deduct > (pricepertraveller*adults + pricepertraveller/2 * children)) {
        deduct = (pricepertraveller*adults + pricepertraveller/2 * children);
    }

    stop * curr = stops;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    payment newp((pricepertraveller*adults + pricepertraveller/2 * children)- deduct, 0, d, acc);
    flightticket* result = new flightticket(adults, children, oneway, dep, arr, stops->getAirport(), curr->getAirport(), cabin, refundable, acc, CalculateFlightDur(), newp, this);

    acc->updatePoints(((pricepertraveller*adults + pricepertraveller/2 * children) - deduct) / 4);
    return result;
}
flightticket* flightlisting::reserve(user* acc, int adults, int children, date d, date d2) {
    if (acc->getWallet()->getAmount() < (pricepertraveller*adults + pricepertraveller/2 * children)) {
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
    reply1 = QMessageBox::question(confirm, "Confirm?", "Are you sure you want to pay " + QString::number(pricepertraveller*adults + pricepertraveller/2 * children) + "LE" + " from Wallet: " + QString::number(acc->getWallet()->getAmount()),
        QMessageBox::Yes | QMessageBox::No);
    if (reply1 == QMessageBox::No) {
        return NULL;
    }

    QMessageBox* msgbx = new QMessageBox(0);

    QMessageBox::StandardButton reply;
    msgbx->exec();

    int deduct = 0;
    reply = QMessageBox::question(msgbx, "Redeem", "Do you want to Redeem your " + QString::number(acc->getPoints()) + " points?",
        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        deduct = acc->redeem();
    }

    if (deduct > (pricepertraveller*adults + pricepertraveller/2 * children)) {
        deduct = (pricepertraveller*adults + pricepertraveller/2 * children);
    }

    stop * curr = stops;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    payment newp((pricepertraveller*adults + pricepertraveller/2 * children)- deduct, 0, d, acc);
    acc->getWallet()->pay((pricepertraveller*adults + pricepertraveller/2 * children)- deduct);
    flightticket* result = new flightticket(adults, children, oneway, dep, arr, stops->getAirport(), curr->getAirport(), cabin, refundable, acc, CalculateFlightDur(), newp, this);
    result->setReturn(d2);

    acc->updatePoints(((pricepertraveller*adults + pricepertraveller/2 * children) - deduct) / 4);
    return result;
}

int flightlisting::getPriceperTraveller()
{
    return pricepertraveller;
}

int flightlisting::getAirlineRating()
{
    return airlne->getRating();
}

float flightlisting::CalculateFlightDur() {
    return _CalculateFlightDur(stops);
}


float flightlisting::subtract(date d, date f) {
    float var1 = 0;
        var1 += d.getDay()*24;
        var1 += d.getHour();
        var1 += d.getMinute()/60.0;

        float var2 = f.getDay()*24 + f.getHour() + f.getMinute() / 60.0;
        cout << var1;
        cout <<endl;
        return var2 - var1;
}


float flightlisting::_CalculateFlightDur(stop* stp) {
    stop* last = stp;
    while (last->next != NULL) {
        last = last->next;
    }
    return abs(subtract(stp->getTime(), last->getTime()));
}

country flightlisting::getDepCountry() // makes a new country objects with country name and one city in the vector (the airport city loc) and returns it
{
    return stops->getLoc();

}

country flightlisting::getArrCountry() // +1
{
    stop * curr = stops;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    return curr->getLoc();

}
airline* flightlisting::getAirline() {
    return airlne;
}

int flightlisting::getDepCityIndex() {
    return stops->getIndex();
}
int flightlisting::getArrCityIndex() {
    stop * curr = stops;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    return curr->getIndex();
}
string flightlisting::getDepTime() {
    string result;
    result += to_string(dep.getHour()) + ":" + to_string(dep.getMinute());
    result += " at " + to_string(dep.getDay()) + "/" + to_string(dep.getMonth()) + "/" + to_string(dep.getYear()) + " ";
    return result;
}
string flightlisting::getArrTime() {
    string result;
    result += to_string(arr.getHour()) + ":" + to_string(arr.getMinute());
    result += " " + to_string(arr.getDay()) + "/" + to_string(arr.getMonth()) + "/" + to_string(arr.getYear()) + " ";
    return result;
}

bool flightlisting::verifyFromLocs(string locdep, string citydep)
{
    if (stops == NULL) {
        return false;
    }
    if (locdep.compare(stops->getLoc().getName()) != 0) {
        return false;
    }
    return true;
    if (citydep.length() > 1) {
        if (locdep.compare(stops->getLoc().getCities()[stops->getIndex()]) != 0) {
            return false;
        }
    }


    return true;
}
bool flightlisting::isRefundable() {
    return refundable;
}
bool flightlisting::isOneW() {
    return oneway;
}
void flightlisting::addStop(country c, int i) {
    date d;
    if (stops == NULL) {
        stops = new stop(c, i, d);
    }
    stops->add_stop(c, i, d); //used to have airline
}
stop* flightlisting::RevstopAt(int x) {
    stop * curr = stops;
    int count  = 0;
    while (curr->next != NULL) {
        curr = curr->next;
        count++;
    }
    curr = stops;
    for (int i = 1; i < count - x; i++) {
        curr = curr->next;
    }
    return curr;
}
int flightlisting::getstopsCount() {
    stop * curr = stops;
    int count  = 0;
    while (curr->next != NULL) {
        curr = curr->next;
        count++;
    }
    return count;
}
void flightlisting::addStop(stop* s) {
    stop* curr = stops;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = s;
}
