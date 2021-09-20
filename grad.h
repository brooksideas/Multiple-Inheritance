#ifndef grad_h
#define grad_h
#include<string>
#include "student.h" 
#include "underGrad.h"
using namespace std;

class grad:public underGrad //inheritance from underGrad
{
private:
bool isGA;
double Fees;
double MAX_FEES=5000.0;
grad();
grad(string,string,string,string,double,double,double,string,underGrad::sStat,bool,double);
public:
bool getGAstatus()const;
double getGradFees() const;
void setGAstatus(bool);
void setGradFees(double);
void showStudent();
};
#endif