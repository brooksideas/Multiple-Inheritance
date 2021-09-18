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
string lastName;
string firstName;
string studentID,major;
double gpa;
ifstream majorFile;
int majorCodesCount;
string majorCodes[];
double money::finances;
int MAX_MAJORS=250;
double MAX_GPA=4.0;
bool checkID(string);
string expandMajorCode(string);
public:
student();//default constructor
student(string, string, string, string,double,double,double);
~student();
string getLastName();
string getFirstName();
string getID();
string getMajor();
double getGPA();
void getCharges(double &, double &);
double getBalance();
void setName(string, string);
void setID(string);
void setMajor(string);
void setGPA(double);
void setCharges(double, double);
void showStudent();
};
#endif