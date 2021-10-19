#ifndef student_h
#define student_h
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include "money.h"
class student:public money
{
private:
    std::string name;
    std::string lastName;
    std::string firstName;
    std::string studentID, major;
    double gpa;
    std::ifstream majorsFile;
    static constexpr int MAX_MAJORS = 250;
    int majorCodesCount;
    std::string majorCodes[MAX_MAJORS]; //size of the Array
                                        // double money::finances;
    static constexpr double MAX_GPA = 4.0;
    bool checkID(std::string);
protected:    
std::string expandMajorCode(std::string);
void getMajorsList();

public:
    student(std::string="", std::string="", std::string="", std::string="",double=0.0, double=0.0, double=0.0);
    ~student();
    std::string getName();
    std::string getLastName();
    std::string getFirstName();
    std::string getID();
    std::string getMajor();
    double getGPA();
    void getCharges(double &, double &);
    double getBalance();
    void setName(std::string, std::string);
    void setID(std::string);
    void setMajor(std::string);
    void setGPA(double);
    void setCharges(double, double);
    void showStudent();
    bool checkGPA(double);
    bool checkMajor(std::string); 
};
#endif