#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "undergrad.h"
#include "student.h"
#include "money.h"
using namespace std;
underGrad::underGrad(){}
underGrad::underGrad(std::string ltName, std::string ftName, std::string stID, std::string majCodes, double grpa, double charg, double finAid, std::string advisor, sStat status)
{
        student::setName(ltName, ftName);
        student::setID(stID);
        student::expandMajorCode(majCodes);
        student::setGPA(grpa);
        //  student::setCharges(charg,finAid);
        underGrad::setAdvisor(advisor);
        underGrad::setStatus(status);
        showStudent();
}
string underGrad::getAdvisor() const
{
    return advisor;
}
underGrad::sStat underGrad::getStatus() const
{
    return Status;
}
void underGrad::setAdvisor(string sAdvisor)
{
    advisor = sAdvisor;
}
void underGrad::setStatus(sStat status)
{
    Status = status;
}
void underGrad::showStudent()
{
        std::string indent(5, ' ');
    std::string bars;
    bars.append(70, '-');

    std::cout << endl
              << bars << endl;
      cout << "UNDERGRAD " << getName();
    std::cout << "Student Summary" << endl;
    std::cout << indent << " Name: " << getName() << endl;
    std::cout << indent << " ID: " << getID() << endl;
    std::cout << indent << " Major: " << getMajor() << endl;
    // std::cout << fixed << showpoint << setprecision(2);
    std::cout << indent << " GPA: " << getGPA() << endl;

    // set status as probation based on GPA
    if (student::getGPA() <= 1.7)
    {
       sStat status = PROBATION;
       setStatus(status);
    }else{
       sStat status = GOOD;
       setStatus(status); 
    }

   // Print the Status based on the Enum value returned 
   if (Status == 0)
    {
        string statusName = "PROBATION";
        string indent(5, ' ');
        cout << indent << "Advisor: " << left << setw(17) << advisor;
        cout << indent << " Status: " << statusName;
        cout << endl;
    }
    if (Status == 1)
    {
        string statusName = "GOOD"; 
        string indent(5, ' ');
        cout << indent << "Advisor: " << left << setw(17) << advisor;
        cout << indent << " Status: " << statusName;
        cout << endl;
    }
    if (Status == 2)
    {
        string statusName = "SPECIAL"; 
        string indent(5, ' ');
        cout << indent << "Advisor: " << left << setw(17) << advisor;
        cout << indent << " Status: " << statusName;
        cout << endl;
    } 
}