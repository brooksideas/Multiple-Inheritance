#include <iostream>
#include "student.h"
#include "underGrad.h"
#include "grad.h"

using namespace std;

int main(int argc, char **argv)
{
    cout << "*************************************** Multiple Inheritance ************************** \n";
    std::string lastName = "Tarekegn";
    std::string firstName = "Brook";
    std::string studentID = "L000018716", major = "MIS";
    double gpa = 2.2;

    double charges = 12.0;
    double finance = 9.0;
    std::string advisor = "Vinky";
    underGrad under;
    bool flag = false;
    double fees = 500.09;
    student studentObject(lastName, firstName, studentID, major, gpa, charges, finance);
    money moneyObject(charges, finance);

    // underGrad underGradObject(lastName, firstName, studentID, major, gpa, charges, finance, advisor, under.getStatus());
    // grad gradObject(lastName, firstName, studentID, major, gpa, charges, finance, advisor, under.getStatus(), flag, fees);
}