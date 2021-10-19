#ifndef money_h
#define money_h
#include<string>
class money
{
    private:
    double balance,financialAid,charges;
    double MAX_CHARGES=10000.0;
    public:
    money();
    money(double=0.0,double=0.0);
    void getCharges(double &, double &);
    double getBalance();
    void setCharges(double, double);
    bool checkCharges(double); 
    bool checkAid(double,double);
    bool checkBalance(double,double);
    double getCharge();
    double getAid();
};
#endif