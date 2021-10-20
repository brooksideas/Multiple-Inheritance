#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "underGrad.h"
#include "student.h"
#include "money.h"
using namespace std;
underGrad::underGrad(std::string ltName, std::string ftName, std::string stID, std::string majCodes, double grpa, double charg, double finAid, std::string advisor, sStat status)
{
    // declare for composition use
    money m;
    student s;

    s.setName(ltName, ftName);
    s.setID(stID); 
    s.setGPA(grpa);
    s.expandMajorCode(majCodes);
    m.setCharges(charg, finAid);
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
    return sStatus;
}
void underGrad::setAdvisor(string sAdvisor)
{
    advisor = sAdvisor;
}
void underGrad::setStatus(sStat status)
{

    if (status == 0)
        sStatus = PROBATION;
    if (status == 1)
        sStatus = GOOD;
    if (status == 2)
        sStatus = SPECIAL;
    if (status == 3)
        sStatus = NONE;

    // sStatus = status;
}
void underGrad::showStudent()
{
    // declare for composition use
    money m;
    student s;

    std::string indent(5, ' ');
    std::string bars;
    bars.append(70, '-');

    std::cout << endl
              << bars << endl;

    std::cout << "Student Summary" << endl;
    std::cout << indent << " Name: " << getName() << endl;
    std::cout << indent << " ID: " << getID() << endl;
    std::cout << indent << " Major: " << getMajor() << endl;
    std::cout << fixed << showpoint << setprecision(2);
    std::cout << indent << " GPA: " << getGPA() << endl;
    std::cout << indent << "Charges: " << setw(8) << m.getCharge() << indent
              << indent << indent << "Financial Aid: " << setw(8) << m.getAid() << endl;
    std::cout << indent << "Balance: " << setw(8) << m.getBalance() << endl;
    // set status as probation based on GPA
    if (s.getGPA() <= 1.7)
    {
        sStat status = PROBATION;
        setStatus(status);
    }
    else
    {
        sStat status = GOOD;
        setStatus(status);
    }

    // Print the Status based on the Enum value returned
    if (sStatus == 0)
    {
        string statusName = "PROBATION";
        string indent(5, ' ');
        cout << indent << "Advisor: " << left << setw(17) << advisor;
        cout << indent << " Status: " << statusName;
        cout << endl;
    }
    if (sStatus == 1)
    {
        string statusName = "GOOD";
        string indent(5, ' ');
        cout << indent << "Advisor: " << left << setw(17) << advisor;
        cout << indent << " Status: " << statusName;
        cout << endl;
    }
    if (sStatus == 2)
    {
        string statusName = "SPECIAL";
        string indent(5, ' ');
        cout << indent << "Advisor: " << left << setw(17) << advisor;
        cout << indent << " Status: " << statusName;
        cout << endl;
    }
}