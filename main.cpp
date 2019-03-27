# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>

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
	
	Information y;
	
	y.readInfo();
	string coursec = y.getCourseCode();
	y.extractCredit(coursec);
	y.stringToInt();
	y.printInfo();
	
	display(nama, matrice); 
	
	return 0;
}
