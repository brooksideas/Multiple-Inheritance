#ifndef grad_h
#define grad_h
#include <string>
#include "student.h"
#include "underGrad.h"
using namespace std;

class grad : public underGrad //inheritance from underGrad
{
private:
    bool isGA;
    double Fees;
    double MAX_FEES = 5000.0;

public:
    grad(std::string = "", std::string = "", std::string = "", std::string = "", double = 0.0, double = 0.0, double = 0.0, std::string = "", sStat = NONE, bool = false, double = 0.0);
    bool getGAstatus() const;
    double getGradFees() const;
    void setGAstatus(bool);
    void setGradFees(double);
    void showStudent();
};
#endif