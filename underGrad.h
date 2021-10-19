#ifndef underGrad_h
#define underGrad_h
#include<string>
#include<iostream>
#include"student.h"
using namespace std;
class underGrad:public student
{ 
    protected:
    enum sStat{PROBATION, GOOD, SPECIAL, NONE};

    public: 
    underGrad (std::string="", std::string="", std::string="",std::string="", double=0.0, double=0.0,double=0.0, std::string="", sStat=NONE);
    string getAdvisor()const;
    sStat getStatus()const;
    void setAdvisor(string);
    void setStatus(sStat);
    void showStudent();
        private:
    string advisor = "";
    sStat sStatus = NONE;
};
#endif
