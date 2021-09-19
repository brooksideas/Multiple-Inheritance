#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>
#include <regex>
#include "money.h"
#include "student.h"

using namespace std;
student::student(){}
student::student(std::string lastName, std::string firstName, std::string studentID, std::string major, double gpa, double charge, double financialAid)
{
    std::cout << "Student MAJOR " << major << endl;
    // bool correctId = checkID(studentID);
    if (!checkID(studentID))
    {
        std::cout << "Student ID is wrong!" << endl;
        std::string ID = ""; // set studentID to empty string
        setID(ID);
    }
    string expandedMajor = expandMajorCode(major);
     std::cout << "Student MAJOR  expandedMajor" <<  expandedMajor << endl;
  
    if (!checkGPA(gpa))
    {
        std::cout << "Error! The GPA displayed is out of range." << endl;
    }
    setID(studentID);
    setName(lastName,firstName);
  
    showStudent();
    std::cout << "constructor!" << endl;
}
student::~student()
{
    std::cout << "Destroyed!" << endl;
    // majorFile.close();
}

/// private functions
bool student::checkID(std::string studentID)
{

    std::smatch match;
    std::regex regex{R"(^[L][0-9]{9})"}; // regex to check correct format as L902.....
    if (std::regex_search(studentID, match, regex))
    {
        return true;
    }
    return false;
}
// Global declaration to store file read from the majorList.txt
struct Major
{
    string code;
    string courseName;
};
struct Major majorListArray[250];

void student::getMajorsList()
{
    struct Major
    {
        string code;
        string courseName;
    };
    struct Major majorList[2500];

    std::vector<string> codes;
    string fileName = "majorsList.txt";
    ifstream inputFile(fileName); // Input file stream object
                                  // Check if exists and then open the file.

    if (inputFile.good())
    {
        // Push items into a vector
        string item;
        while (inputFile >> item)
        {
            codes.push_back(item);
        }

        // Close the file.
        inputFile.close();

        std::string courseName = "";
        int majorIndex = 0;
        for (int i = 0; i < codes.size(); i++)
        {
            std::string delimiter = "-";
            size_t pos = 0;
            Major major;

            std::smatch match;
            std::regex regex{R"(^[A-Z]{2})"};

            // regex to check code found ; then store as [{code: "CSE" , major: "Computer Science Eng"}]
            if (std::regex_search(codes[i], match, regex))
            {
                majorListArray[majorIndex].code = majorList[majorIndex].code;
                majorListArray[majorIndex].courseName = majorList[majorIndex].courseName;
                majorIndex++;
                majorList[majorIndex].code = codes[i];
                courseName = courseName.empty();
            }
            else if (codes[i] == delimiter || codes[i] == " ")
            {
                codes[i].empty();
            }
            else
            {
                courseName = courseName + " " + codes[i]; // concatenate course name found and store in array
                majorList[majorIndex].courseName = courseName;
            }
        }
    }
}
string student::expandMajorCode(std::string major)
{

    int majorCodeCharacterSize = major.size();
    int counter;
    string expandedMajorCode;
    if (majorCodeCharacterSize == 2 || majorCodeCharacterSize == 3 || majorCodeCharacterSize == 4)
    {
        // read from the array if we can find the code
        // copy the majors from the majorsList file into the majors code array
        getMajorsList();
        cout << "BACK here !!";
        // set the majorCodes[] array and set the majorCodesCount variable
  
        for (int i = 0; i < MAX_MAJORS; i++)
        {

            majorCodes[i] = majorListArray[i].code + "-" + majorListArray[i].courseName;
            if (!majorListArray[i].code.empty())
            {
                counter++;
            }
            // if specified major code was found store the expanded form
            if (major == majorListArray[i].code)
            {
                expandedMajorCode = majorListArray[i].code + "-" + majorListArray[i].courseName;
            }
        }
        if (expandedMajorCode.empty())
        {
            std::cout << "Error, Major code not found!" << endl;
        }
        majorCodesCount = counter; 
        setMajor(expandedMajorCode);
        return expandedMajorCode;
    }
    else
    {
        std::cout << "Error, invalid major code" << endl; 
        return expandedMajorCode;
    }
}

/// Public Functions
std::string student::getName()
{
    return name;
}
std::string student::getLastName()
{
    return lastName;
}
std::string student::getFirstName()
{
    return firstName;
}
std::string student::getID()
{
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
    name = lastName + ", " + firstName;
}

void student::setID(std::string ID)
{
    studentID = ID;
}

void student::setMajor(std::string maj)
{
    cout << "SET MAJOR" << maj;
    major = maj;
}
void student::setGPA(double gradepoint)
{
    gpa = gradepoint;
}
bool student::checkGPA(double gpa)
{
    if (0.0 < gpa && gpa <= MAX_GPA)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void student::showStudent()
{
    std::string indent(5, ' ');
    std::string bars;
    bars.append(70, '-');

    std::cout << endl
              << bars << endl;
    std::cout << "Student Summary" << endl;
    std::cout << indent << " Name: " << getName() << endl;
    std::cout << indent << " ID: " << getID() << endl;
    std::cout << indent << " Major: " << getMajor() << endl;
    // std::cout << fixed << showpoint << setprecision(2);
    std::cout << indent << " GPA: " << getGPA() << endl;
    // std::cout << indent << "Charges: " << setw(8) << ch << indent
    // << indent << indent << "Financial Aid: " <<
    // setw(8) << fn << endl;
    // std::cout << indent << "Balance: " << setw(8) <<
    // finances.getBalance() << endl;
}
