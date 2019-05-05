# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <iomanip>
# include <algorithm>
//# include <bits/stdc++.h>
# include "Calculate.h"
# include "Subject.h"
# include "Student.h"

using namespace std;

# define FILE_DATA 83

int main()
{
	char choice, choice2;
	string nama, matrik, kod, kodSub, grade;
	float mark, _tpv, pointer;
	int credit, choose, numSem, numSub;
	int a = 0;
	float gpa = 0;
	float cgpa = 0; 
	
	Student student ("", "");
	
	ofstream outFile;
	outFile.open("Result.txt");
	
	if (!outFile.is_open())
	{
		cout<<"Error! File is not open!"<<endl;
		exit (1);
	}
	
	outFile << setw(70) << "UNIVERSITY TECHNOLOGY MALAYSIA" << endl
			<< setw(64) << "School of Computing" << endl << endl << endl;
	
	cout << "[1] Calculate GPA" << endl;
	cout << "[2] Calculate CGPA" << endl;
	cout << "What do you want to calculate? ";
	cin >> choose;
	cout << endl;
	cin.ignore();
		
	switch (choose)
	{ 
		case 1:
		{
			do
			{
				int tolCre = 0;
				float tol_tpv = 0.0;
				Subject subject ("", "", 0, 0);
				Calculate c(0,0);
				
				cout << "Please enter student's name: ";
				getline(cin, nama);
				
				outFile << left << setw(9) << "Name" 
						<< setw(1) << ": "
						<< nama << endl;
						
				outFile << "Matric No: ";
				
				cout << "Please enter student's matric number: ";
				getline(cin, matrik);
				
				outFile << matrik << endl << endl;
				
				student.setInfo(nama, matrik);
				
				if (student.addStudent(&student) == true)
				{
					cout << "Student successfully recorded." << endl << endl;
		
					cout << "How many subject(s) are there for this student? ";
					cin >> numSub;
					cout << endl;
					cin.ignore();
					
					outFile << "----------------------------------------------------------------------------------------------------------------------" << endl
							<< left << setw(16) << "Subject Code"
							<< setw(47) << "Subject Name"
							<< setw(9) << "Mark"
							<< setw(10) << "Grade"
							<< setw(16) << "Credit Hour"
							<< setw(10) << "Pointer"
							<< setw(8) << "TPV" << endl
							<< "----------------------------------------------------------------------------------------------------------------------" << endl;
					
					for (int i = 0; i < numSub; i++)
					{
						cout << "Subject (" << i + 1 << "):" << endl;
						
						cout << "Please enter subject code (Exp: SCSR1013): ";
						getline(cin, kod);
						
						kodSub = subject.getSubName(kod); 
						
						credit = c.extractCredit(kod);
						
						cout << "Please enter the mark of this subject (0-100): ";
						cin >> mark;
						
						grade = c.calGrad(mark);
						pointer = c.calcGradePt(mark);
						_tpv = c.calcTPV(pointer, credit);
						
						subject.setInfo(kodSub, grade, credit, _tpv);
					
						if (student.addSubject(&subject) == true)
						{
							cout << "Subject recorded!" << endl << endl;
							
							c.calctolCre(credit);
							c.calctolTPV(_tpv);
	
							outFile << left << setw(57) << kodSub 
									<< setw(11) << setprecision(2) << fixed << mark
									<< setw(13) << grade
									<< setw(11) << credit
									<< setw(10) << setprecision(2) << fixed << pointer
									<< setw(1) << setprecision(2) << fixed << _tpv
									<< endl;
						}
								
						else
						{
							cout << "Failed to record subject. (Do not enter same subject code!)" << endl << endl;
							i--;
						}
							
						cin.ignore();
					}
					
					tolCre = c.gettolcredit();
					tol_tpv = c.gettolTPV();
					
					gpa = tol_tpv / tolCre;
					
					cout << student.returnNM(a) << endl;
					cout << "GPA = " << setprecision(2) << fixed << gpa << endl;
					
					outFile << "----------------------------------------------------------------------------------------------------------------------" << endl
							<< right << setw(82) << "Total"
							<< setw(6) << tolCre
							<< setw(25) << setprecision(2) << fixed << tol_tpv 
							<< endl << endl;
							
					outFile << "GPA = " << setprecision(2) << fixed << gpa << endl << endl << endl;
				}
				
				else
					cout << "Failed to record student. (Do not enter student with same matric number)" << endl << endl;
				
				cout << endl << "Do you want to calculate GPA for another student [Y / N] -> ";
				cin >> choice;
				cout << endl << endl;
				cin.ignore();
				a++;
				
			} while (choice == 'y' || choice == 'Y');
			break;
		}
		
		case 2:
		{
			int sumTolCre = 0;
			float sumTolTPV = 0.0;
			
			do
			{
				Subject subject ("", "", 0, 0);
				
				cout << "Please enter student's name: ";
				getline(cin, nama);
				
				outFile << left << setw(9) << "Name" 
						<< setw(1) << ": "
						<< nama << endl;
						
				outFile << "Matric No: ";
				
				cout << "Please enter student's matric number: ";
				getline(cin, matrik);
				
				outFile << matrik << endl << endl;
				
				student.setInfo(nama, matrik);
				
				if (student.addStudent(&student) == true)
					cout << "Student successfully recorded." << endl << endl;
		
				else
					cout << "Failed to record student." << endl << endl;
					
				cout << "Please key in the number of semester you wish to calculate CGPA: ";
				cin >> numSem;
				cout << endl;
				cin.ignore();
				
				for (int i = 0; i < numSem; i++)
				{
					outFile << endl << endl
							<< right << setw(63) << "Semester " << i + 1
							<< endl << endl;
							
					outFile << "----------------------------------------------------------------------------------------------------------------------" << endl
						<< left << setw(16) << "Subject Code"
						<< setw(47) << "Subject Name"
						<< setw(9) << "Mark"
						<< setw(10) << "Grade"
						<< setw(16) << "Credit Hour"
						<< setw(10) << "Pointer"
						<< setw(8) << "TPV" << endl
						<< "----------------------------------------------------------------------------------------------------------------------" << endl;
					
					int tolCre = 0;
					float tol_tpv = 0.0;
					Calculate c(0,0);
					
					cout << "Semester [" << i + 1 << "]" << endl;
					cout << "Number of subjects in semester " << i + 1 << " : ";
					cin >> numSub;
					cout << endl;
					cin.ignore();
					
					for (int j = 0; j < numSub; j++)
					{
						cout << "Subject (" << j + 1 << "):" << endl;
						
						cout << "Please enter subject code (Exp: SCSR1013): ";
						getline(cin, kod);
						
						kodSub = subject.getSubName(kod);
						credit = c.extractCredit(kod);
						
						cout << "Please enter the mark of this subject (0-100): ";
						cin >> mark;
						
						grade = c.calGrad(mark);
						pointer = c.calcGradePt(mark);
						_tpv = c.calcTPV(pointer, credit);
						
						subject.setInfo(kodSub, grade, credit, _tpv);
						
						if (student.addSubject(&subject) == true)
						{
							cout << "Subject recorded!" << endl << endl;
							
							c.calctolCre(credit);
							c.calctolTPV(_tpv);
	
							outFile << left << setw(57) << kodSub 
									<< setw(11) << setprecision(2) << fixed << mark
									<< setw(13) << grade
									<< setw(11) << credit
									<< setw(10) << setprecision(2) << fixed << pointer
									<< setw(1) << setprecision(2) << fixed << _tpv
									<< endl;
						}
			
						else
						{
							cout << "Failed to record subject. (Do not enter same subject code!)" << endl << endl;
							j--;
						}
							
						cin.ignore();
					}
				
					tolCre = c.gettolcredit();
					tol_tpv = c.gettolTPV();
					gpa = tol_tpv / tolCre;
					
					cout << student.returnNM(a) << endl;
					cout << "GPA (Semester " << i + 1 << ") = " << setprecision(2) << fixed << gpa << endl << endl;
					
					sumTolCre += tolCre;
					sumTolTPV += tol_tpv;
					
					outFile << "----------------------------------------------------------------------------------------------------------------------" << endl
						<< right << setw(82) << "Total"
						<< setw(6) << tolCre
						<< setw(25) << setprecision(2) << fixed << tol_tpv 
						<< endl << endl;
						
					outFile << "GPA = " << setprecision(2) << fixed << gpa << endl;
				}
				
				cgpa = sumTolTPV / sumTolCre;
				cout << "CGPA = " << setprecision(2) << fixed << cgpa << endl;
				
				outFile << "CGPA = " << setprecision(2) << fixed << cgpa << endl << endl << endl;
				
				cout << endl << "Do you want to calculate CGPA for another student [Y / N] -> ";
				cin >> choice;
				cout << endl << endl;
				cin.ignore();
				a++;
				
			} while (choice == 'y' || choice == 'Y');
		}
		break;
	}
	
	outFile.close();

	cout << "Thank you for using Fancy CGPA Calculator" << endl;
	cout << "By	Yee Zi Wei" << endl;
	cout <<	"	Toon Shu Hui" << endl;
	cout << "	Vivian Amelissa Anak Jenuang" << endl;
	
	return 0;
}