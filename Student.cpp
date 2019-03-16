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

void Student::display()
{
	ofstream outFile ("CGPA.txt");
	
	outFile	<<"Student's name: /t"<<name<<endl;
		<<"Matric Number: /t"<<matric<<endl;
}
