#include <iostream>
#include <string.h>
#include <string>
#include "money.h"

using namespace std;
money::money(double charges, double aid)
{

    if (!checkCharges(charges))
    {
        std::cout << "Error! The charges set is out of range." << endl;
    }

    if (!checkAid(charges, aid))
    {
        std::cout << "Error! The Financial Aid entered is out of range." << endl;
    } 

    if (!checkBalance(charges, aid))
    {
        std::cout << "Error! The Balance is incorrect." << endl;
    }
}

bool money::checkCharges(double charges)
{
    if (0.0 < charges && charges <= MAX_CHARGES)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool money::checkAid(double charges, double aid)
{
    if (0.0 < aid && aid <= charges)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool money::checkBalance(double charges, double aid)
{
    double difference = charges - aid;
    if (getBalance() == difference)
    {
        return true;
    }
    else
    {
        return false;
    }
}
double money::getBalance()
{
    balance = charges - financialAid;
    return balance;
}
double money::getCharge()
{
    return charges;
}
double money::getAid()
{
    return financialAid;
}
void money::setCharges(double charged, double aid)
{ 
    charges = charged;
    financialAid = aid;
}

void money::getCharges(double &charge, double &aid)
{
    charges = charge;
    financialAid = aid;
}