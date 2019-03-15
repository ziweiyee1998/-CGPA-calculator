# include "project.h"

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

void Student::display()
{
	cout<<"Name: "<<name<<endl;
	cout<<"Matric: "<<matric; 
}
