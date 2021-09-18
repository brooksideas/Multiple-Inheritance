#ifndef student_h
#define student_h
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<fstream>
#include"money.h"
class student
{
private:
std::string lastName;
std::string firstName;
std::string studentID,major;
double gpa;
std::ifstream majorsFile;
int majorCodesCount;
std::string majorCodes[1000]; //size of the Array
// double money::finances;
int MAX_MAJORS=250;
double MAX_GPA=4.0;
bool checkID(std::string);
std::string expandMajorCode(std::string);
public:
student();//default constructor
student(std::string, std::string, std::string, std::string,double,double,double);
~student();
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
};
#endif