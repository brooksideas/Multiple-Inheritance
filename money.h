#ifndef money_h
#define money_h
#include<string>
class money
{
    private:
    double balance,financialAid,charges;
    double MAX_CHARGES=10000.0;
    public:
    money(double,double);
    void getCharges(double &, double &);
    double getBalance();
    void setCharges(double, double);
};
#endif