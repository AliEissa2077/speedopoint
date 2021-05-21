#include "cruise.h"
#include <QMessageBox>

cruise::cruise()
{

}

cruise::cruise(date start_, date end_, std::string model, int price, country dep, country arr, int index, stop* stp, std::string type)
{
	start = start_;
	end = end_;
	std::string cruisemodel = model;
	pricePerPerson = price;
	depCountry = dep;
	arrCountry = arr;
	arrivalCityIndex = index;
    stops = stp;
	std::string suiteType = type;

}
cruisereservation* cruise::reserve(user* acc, int adult, int child) {
    QMessageBox* confirm = new QMessageBox(0);
    QMessageBox::StandardButton reply1;
    //confirm->exec();
    reply1 = QMessageBox::question(confirm, "Confirm?", "Are you sure you want to pay " + QString::number(pricePerPerson*adult + pricePerPerson/2 * child) + "LE" + " from Wallet: " + QString::number(acc->getWallet()->getAmount()),
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

    if (deduct > (pricePerPerson*adult + pricePerPerson/2 * child)) {
        deduct = (pricePerPerson*adult + pricePerPerson/2 * child);
    }

    payment newp((pricePerPerson*adult + pricePerPerson/2 * child)- deduct, 0, start, acc);
    acc->getWallet()->pay((pricePerPerson*adult + pricePerPerson/2 * child)- deduct);

    cruisereservation*  test = new cruisereservation(this, newp, adult, child, acc);

    acc->updatePoints(((pricePerPerson*adult + pricePerPerson/2 * child) - deduct) / 4);
    return test;
}

int cruise::getPricePerPerson()
{
	return pricePerPerson;
}


int cruise::getDuration()
{
    return subtract(start, end);
}
country cruise::getDepCountry()
{
	return depCountry;
}
int cruise::getDepIndex()
{
	return depCityIndex;
}
country cruise::getArrCountry()
{
	return arrCountry;
}

int cruise::getArrIndex()
{
	return arrivalCityIndex;
}
float cruise::subtract(date d, date f) {
    float var1 = 0;
        var1 += d.getMonth() * 30;
        var1 += d.getDay();


        float var2 = f.getMonth()*30 + f.getDay();

        return var2 - var1;
}

cruisecompany cruise::getCompany()
{
	return company;
}

bool cruise::verifyLoc(string loc, string city)
{
    if (loc.compare(stops->getLoc().getName()) == 0)
	{
		if (city.length() > 1)
		{
            if (city.compare(stops->getLoc().getCities()[stops->getIndex()]) == 0)
            {
                return true;
            }
			return false;
		}
		else return true;
	}
	else { return false; }
}
