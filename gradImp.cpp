#include <iostream>
#include <string>
#include <iomanip>     //set precision library
#include "grad.h"      //grad header
#include "underGrad.h" //underGrad header
#include "student.h"   //student header
using namespace std;
grad::grad(string ltname, string ftname, string stID, string majcod, double grapoint, double chrgs, double aid, string advi,  sStat stats, bool gradflag, double gradfees)
{ //constructor

    // declare for composition use
    money m;
    student s;
    underGrad u;

    if (0.0 <= gradfees && gradfees <= MAX_FEES) //error checking based on fees amount
    {
        /*Details for construtor values*/
        s.setName(ltname, ftname);  
        s.setID(stID);              
        s.setGPA(grapoint);        //from student
        s.expandMajorCode(majcod);

        m.setCharges(chrgs, aid);    //from money

        u.setAdvisor(advi);       
        u.setStatus(stats);      //from underGrad

        grad::setGAstatus(gradflag);      //from grad
        grad::setGradFees(gradfees);      //from grad
        showStudent();
    }
    else
    {
        cout << "Error graduate fees are incorrect" << endl; //output error when incorrect fee is entered
        Fees = 0.0;                                          //set default
    }
}

void grad::setGAstatus(bool flag)
{
    isGA = flag; //set the flag by the passed value
}
void grad::setGradFees(double gradFees)
{
    /*set grad value after checking*/
    if (0.0 <= Fees && Fees <= MAX_FEES) //check fees
    {
        Fees = gradFees; //
    }
    else
    {
        cout << "Error, incorrect amount of fee" << endl; //error
        Fees = 0.0;                                       //default
    }
}
bool grad::getGAstatus() const
{
    return isGA; //return flag value
}
double grad::getGradFees() const
{

    return Fees; //return fee amount
}
void grad::showStudent()
{
     // declare for composition use
    money m;
    student s;
    underGrad u;

    std::string indent(5, ' ');
    std::string bars;
    bars.append(70, '-');

    std::cout << endl
              << bars << endl;

    std::cout << "Student Summary" << endl;
    std::cout << indent << " Name: " << getName() << endl;   //name on given format
    std::cout << indent << " ID: " << getID() << endl;       //ID on given format
    std::cout << indent << " Major: " << getMajor() << endl; //major on given format
    std::cout << fixed << showpoint << setprecision(2);
    std::cout << indent << " GPA: " << getGPA() << endl; //GPA on given format
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
    if (u.getStatus() == 0)
    {
        string statusName = "PROBATION";
        string indent(5, ' ');
        cout << indent << "Advisor: " << left << setw(17) << u.getAdvisor();
        cout << indent << " Status: " << statusName;
        cout << endl;
    }
    if (u.getStatus() == 1)
    {
        string statusName = "GOOD";
        string indent(5, ' ');
        cout << indent << "Advisor: " << left << setw(17) << u.getAdvisor();
        cout << indent << " Status: " << statusName;
        cout << endl;
    }
    if (u.getStatus() == 2)
    {
        string statusName = "SPECIAL";
        string indent(5, ' ');
        cout << indent << "Advisor: " << left << setw(17) << u.getAdvisor();
        cout << indent << " Status: " << statusName;
        cout << endl;
    }
    cout << " Grad Fees: " << fixed << setprecision(2) << getGradFees() << indent;
    cout << indent << indent << " Graduate Assistant: "; //display
    if (grad::getGAstatus() == true)                     //if true then yes
    {
        cout << "Yes";
        cout << endl;
    }
    else if (grad::getGAstatus() == false) //if true then no
    {
        cout << "No";
        cout << endl;
    }
    else //if not both
    {
        cout << "Error, wrong flag passed" << endl;
    }
}