#include "Information.h"

Information::Information()
{
	courseCode = '/0';
	scredit = '/0';
	credit = 0;
}

void Information::readInfo()
{
	cout<<"Please Enter Course Code: ";
	getline(cin, courseCode);
		
}

string Information::getCourseCode() 
{
	return courseCode;
}

void Information::setCourseCode(string courseCode)
{
	this->courseCode = courseCode;
}

void Information::extractCredit(string courseCode)
{
	scredit = courseCode.substr(7, 1);
}

void Information::stringToInt()
{
    credit = atoi(scredit.c_str());
}

void Information::printInfo()
{
	cout<< "Course Code: "  << this->courseCode <<endl;
	cout<< "Credit Hours: " << this->credit <<endl;
}
