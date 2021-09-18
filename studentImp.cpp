#include<iostream>
#include<string.h>
#include<string>
#include<cstring>
#include<fstream>
#include"money.h"
#include"student.h"
 
using namespace std;
 
student::student(std::string lastName,std::string firstName, std::string studentID, std::string major, double gpa, double charge, double financialAid)
{
   
 
}
student::~student()
{
    // majorFile.close();
}
std::string student:: getLastName()
{
std::cin>>lastName;
return lastName;
}
std::string student::getFirstName()
{
    std::cin>>firstName;
    return firstName;
}
std::string student::getID()
{
std::cin>>studentID;
return studentID;
}
string student::getMajor()
{
 return major;
}
double student::getGPA()
{
return gpa;
}  
void student::setName(std::string lastName, std::string firstName)
{
     lastName=getFirstName();
     firstName=getLastName();
    std::cout<<lastName<<", "<<firstName<<endl;
}
void student::setID(std::string ID)
{
  studentID=ID;
  majorCodesCount=studentID.size();
  while(true)
  {
   if(majorCodesCount==2||majorCodesCount==3||majorCodesCount==4)
  {
   
   break;
  }
  else
  {
      std::cout<<"Error, invalid"<<endl;
      continue;
  }
  }
  
}
void student::setMajor(std::string maj)
{
maj=major;
}
void student::setGPA(double gradepoint)
{
gradepoint=gpa;
}
// void showStudent()
// {
//     std::string indent(5, ' ');
//     std::string bars;
//     bars.append(70, '-');

//     std::cout << endl << bars << endl;
// std::cout << "Student Summary" << endl;
// std::cout << indent << " Name: " << lastName << ", " <<
// firstName << endl;
// std::cout << indent << " ID: " << studentID << endl;
// std::cout << indent << " Major: " << major << endl;
// std::cout << fixed << showpoint << setprecision(2);
// std::cout << indent << " GPA: " << setw(8) << gpa << endl;
// std::cout << indent << "Charges: " << setw(8) << ch << indent
// << indent << indent << "Financial Aid: " <<
// setw(8) << fn << endl;
// std::cout << indent << "Balance: " << setw(8) <<
// // finances.getBalance() << endl;

// }

std::string checkID(std::string studentID){

}