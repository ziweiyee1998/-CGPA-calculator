# include "Student.h"

Student::Student ()
{
	name = '/0';
	matric = '/0';
}

void Student::readDetail()
{
	cout<<"Please Enter Student Name: ";
	getline(cin,name);
	
	cout<<"Please Enter Student Matric Number: ";
	getline(cin,matric);
}

void Student::setName(string n)
{
	name = n;
}

string Student::getName()
{
	return name;
}

void Student::setMatric(string m)
{
	matric = m;
}

string Student::getMatric()
{
	return matric;
}
