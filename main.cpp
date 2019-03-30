# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <iosmanip>

# include "Student.h"
# include "Information.h"

using namespace std;

void display(string name, string matric)
{
	ofstream outFile ("CGPA.txt");
	
	outFile	<<"Student's name	: "<<name<<endl
		<<"Matric Number	: "<<matric<<endl;
			
	outFile.close();
}

int main()
{
	Student x;
	
	x.readDetail();
	string nama = x.getName();
	string matrice = x.getMatric();
	
	int choice;
	
	cout<<"-----------------------------------------------------------"<<endl;
	cout<< right << setw(38) << "GPA & CGPA Calculator" <<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<< setw(10) <<" MENU: "<<endl;
	cout<< "1. Calculate GPA (Grade Point Average)" <<endl
	    << "2. Calculate CGPA (Cumulative Grade Point Average)" <<endl;
	cout<<endl;
	cout<<"Enter your choice: ";
	cin>>choice; 
	
	Information y;
	
	y.readInfo();
	string subjectc = y.getSubjectCode();
	y.extractCredit(subjectc);
	y.stringToInt();
	y.printInfo();
	
	display(nama, matrice); 
	
	return 0;
}
