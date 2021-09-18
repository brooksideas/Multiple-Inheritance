#include<iostream>
#include<string.h>
#include<string>
#include<cstring>
#include<fstream>
#include"money.h"
#include"student.h"
 
student::student(string Last,string First, string ID, string Majco, double gradePoint, double charge, double finaid)
{
      majorFile("majorsList.txt");
      while (true)
      {
          if ()
  {
      if (majorFile,open())
    {
      while(majorFile>>majorCodes[])
      {
        
      }

    break;
    }
    else{cout<<"Error"<<endl; continue;}
  }
  else 
  {
      cout<<"Error, Invalid"<<endl;
      continue
  }
   
      }
 
}
~student()
{
    majorFile.close();
}
student::string getLastName()
{
   cin>>lastName;
return LastName;
}
string student::getFirstName()
{
    cin>>firstName;
    return firstName;
}
string student::getID()
{
cin>>studentID;
return studentID;
}
student::getMajor()
{
 return major;
}
student::getGPA()
{
return gpa;
}
void student::setName(string lastName, string firstName)
{
     lastName=string student::getFirstName();
     firstName=string student::getLastName();
    cout<<lastName<<", "<<firstName<<endl;
}
void student::setID(string ID)
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
      cout<<"Error, invalid"<<endl;
      continue;
  }
  }
  
}
void student::setMajor(string maj)
{
maj=major;
}
void student::setGPA(double gradepoint)
{
gradepoint=gpa;
}
void showStudent()
{
    string indent(5, ' ');
    string bars;
    bars.append(70, '-');

    cout << endl << bars << endl;
cout << "Student Summary" << endl;
cout << indent << " Name: " << lastName << ", " <<
firstName << endl;
cout << indent << " ID: " << studentID << endl;
cout << indent << " Major: " << major << endl;
cout << fixed << showpoint << setprecision(2);
cout << indent << " GPA: " << setw(8) << gpa << endl;
cout << indent << "Charges: " << setw(8) << ch << indent
<< indent << indent << "Financial Aid: " <<
setw(8) << fn << endl;
cout << indent << "Balance: " << setw(8) <<
finances.getBalance() << endl;

}