#include "Information.h"

Information::Information()
{
	subjectCode = '/0';
	scredit = '/0';
	credit = 0;
}

void Information::readInfo()
{
	cout<<"Please Enter Subject Code: ";
	getline(cin, subjectCode);
		
}

string Information::getSubjectCode() 
{
	return subjectCode;
}

void Information::setSubjectCode(string subjectCode)
{
	this->subjectCode = subjectCode;
}

void Information::extractCredit(string subjectCode)
{
	scredit = subjectCode.substr(7, 1);
}

void Information::stringToInt()
{
    credit = atoi(scredit.c_str());
}

void Information::printInfo()
{
	cout<< "Subject Code: " << this->subjectCode <<endl;
	cout<< "Credit Hours: " << this->credit <<endl;
}
