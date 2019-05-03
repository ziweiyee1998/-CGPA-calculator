# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <iomanip>
# include <bits/stdc++.h>
using namespace std;

# define FILE_DATA 83

class Calculate
{
	float cgpa, gpa, gradePt, TPV, tolTPV;
	string grade;
	int credit, tolcredit;
	
public:
	Calculate(int tc, int tt): tolcredit(0), tolTPV(0) {	}
	
	string calGrad(float marks)
	{
		if(marks >= 90 && marks <= 100 )
	   		grade = "A+";

		else if(marks >= 80 )
			grade = "A";
			
		else if(marks >= 75 )
			grade = "A-";
	
		else if(marks >= 70 )
			grade = "B+";
			
		else if(marks >= 65 )
			grade = "B";
			
		else if(marks >= 60 )
			grade = "B-";
			
		else if(marks >= 55 )
			grade = "C+";
			
		else if(marks >= 45 )
			grade = "C-";
			
		else if(marks >= 40 )
			grade = "D+";
			
		else if(marks >= 35 )
			grade = "D";
			
		else if(marks >= 30 )
			grade = "D-";
			
		else
			grade = "E";
			
		return grade;
	}
		
	float calcGradePt(float marks)
	{
		if(marks >= 90 && marks <= 100 )
	    	gradePt = 4.00;
	
		else if(marks >= 80 )
			gradePt = 4.00;
			
		else if(marks >= 75 )
			gradePt = 3.67;
			
		else if(marks >= 70 )
			gradePt = 3.33;
			
		else if(marks >= 65 )
			gradePt = 3.00;
			
		else if(marks >= 60 )
			gradePt = 2.67;
			
		else if(marks >= 55 )
			gradePt = 2.33;
			
		else if(marks >= 45 )
			gradePt = 1.67;
			
		else if(marks >= 40 )
			gradePt = 1.33;
			
		else if(marks >= 35 )
			gradePt = 1.00;
			
		else if(marks >= 30 )
			gradePt = 0.67;
			
		else
			gradePt = 0.00;
			
		return gradePt;
	}
	
	int extractCredit(string c)
	{
		string temp;
		temp = c.substr(7, 1);
		credit = atoi(temp.c_str());
		
		return credit;
	}
	
	void calctolCre(int cre)
	{
		tolcredit += cre;
	}
	
	void calctolTPV(float tpv)
	{
		tolTPV += tpv;
	}
	
	float calcTPV(float gpt, int c)
	{
		TPV = gpt * c;
		
		return TPV;
	}

	int gettolcredit() { return tolcredit; }
	
	float gettolTPV() { return tolTPV; }
};

class Subject
{
	string sub_info, grade;
	float mark, _tpv;	
	
public:
	Subject() { }
	
	Subject(string si, string g, float tpv, float mk): sub_info(si), grade(g), _tpv(tpv), mark(mk) { }
	
	void setInfo(string si, string g, float tpv, float mk)
	{
		sub_info = si;
		grade = g;
		_tpv = tpv;
		mark = mk;
	}
	
	float getSubMark() { return mark; }
	
	string getSubInfo() { return sub_info; }
	
	string getGrade() { return grade; }
	
	float getTPV() { return _tpv; }
	
	string getSubName(string kod)
	{
		transform(kod.begin(), kod.end(), kod.begin(), ::toupper);
		
		string sub[FILE_DATA];
		
		ifstream inp("code.txt");
		
		if (!inp.is_open())
		{
			cout<<"Error! File does not exist!"<<endl;
			exit (1);
		}
		
		for (int i = 0; i < FILE_DATA; i++)
		{
			getline(inp, sub[i], '\n');
		}
	
		for (int i = 0; i < FILE_DATA; i++)
		{
			if (sub[i].compare(0,8,kod) == 0)
			{
				return sub[i];
				break;
			}
			
			else
				continue;
		}
		
		inp.close();
	}
};

class Student
{
	Subject* _subjectlist;
	Student* _studentlist;
	unsigned int student_count;
	unsigned int subject_count;
	string name;
	string matric;
	
public:
	Student() { }
	
	Student(string n, string m): name(n), matric(m), student_count(0), _studentlist(0), subject_count(0), _subjectlist(0) { }
	
	bool addStudent(Student* std)
	{
		if (student_count == 0)
		{
			if (_studentlist == 0)
			{
				_studentlist = new Student[1];
				_studentlist[0].setInfo(std->getName(), std->getMatric());
				student_count++;
			}

			else
			{
				Student* temp = new Student[ student_count + 1 ];
		
				for (int i = 0; i < student_count; i++)
					temp[i] = _studentlist[i];

				temp[student_count].setInfo(std->getName(), std->getMatric());
				student_count++;

				delete[] _studentlist;

				_studentlist = temp;
			}

			return true;
		}

		else
		{
			for (int j = 0; j < student_count; j++)
			{
				if (_studentlist[j].matric == std->getMatric())
					return false;

				else
				{
					if (_studentlist == 0)
					{
						_studentlist = new Student[1];
						_studentlist[0].setInfo(std->getName(), std->getMatric());
						student_count++;
					}

					else
					{
						Student* temp = new Student[ student_count + 1 ];
		
						for (int i = 0; i < student_count; i++)
							temp[i] = _studentlist[i];

						temp[student_count].setInfo(std->getName(), std->getMatric());
						student_count++;

						delete[] _studentlist;

						_studentlist = temp;
					}

					return true;
				}
			}
		}
	}
	
	void setInfo(string n, string m)
	{
		name = n;
		matric = m;
	}
	
	string getName() { return name; }
	
	string getMatric() { return matric; }
	
	/*friend ostream& operator << (ostream& os, Student& s)
	{
		for (int i = 0; i < s.student_count; i++)
			os << "[" << i + 1 << "] " << s._studentlist[i].getName() << " " << s._studentlist[i].getMatric() << endl;
			
		return os;
	}*/
	
	string returnNM (int a)
	{
		return _studentlist[a].getName() + " " + _studentlist[a].getMatric();
	}
	
	string returnN (int a)
	{
		return _studentlist[a].getName();
	}
	
	string returnM (int a)
	{
		return _studentlist[a].getMatric();
	}
	
	bool addSubject (Subject* s)
	{
		if (subject_count == 0)
		{
			if (_subjectlist == 0)
			{
				_subjectlist = new Subject[1];
				_subjectlist[0].setInfo(s->getSubInfo(), s->getGrade(), s->getTPV(), s->getSubMark());
				subject_count++;
			}

			else
			{
				
				Subject* temp = new Subject[ subject_count + 1 ];
		
				for (int i = 0; i < subject_count; i++)
					temp[i] = _subjectlist[i];
					

				temp[subject_count].setInfo(s->getSubInfo(), s->getGrade(), s->getTPV(), s->getSubMark());
				subject_count++;

				delete[] _subjectlist;

				_subjectlist = temp;
			}

			return true;
		}

		else
		{
			for (int j = 0; j < subject_count; j++)
			{
				if (_subjectlist[j].getSubInfo() == s->getSubInfo())
					return false;

				else
				{
					if (_subjectlist == 0)
					{
						_subjectlist = new Subject[1];
						_subjectlist[0].setInfo(s->getSubInfo(), s->getGrade(), s->getTPV(), s->getSubMark());
						subject_count++;
					}

					else
					{
						Subject* temp = new Subject[ subject_count + 1 ];
		
						for (int i = 0; i < subject_count; i++)
							temp[i] = _subjectlist[i];

						temp[subject_count].setInfo(s->getSubInfo(), s->getGrade(), s->getTPV(), s->getSubMark());
						subject_count++;

						delete[] _subjectlist;

						_subjectlist = temp;
					}

					return true;
				}
			}
		}
	}
};

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
					cout << "Student successfully recorded." << endl << endl;
		
				else
					cout << "Failed to record student." << endl << endl;
				
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
				
				cout << endl << "Do you want to calculate GPA for another student [Y / N] -> ";
				cin >> choice;
				cout << endl << endl;
				cin.ignore();
				a++;
				
				outFile << "----------------------------------------------------------------------------------------------------------------------" << endl
						<< right << setw(82) << "Total"
						<< setw(6) << tolCre
						<< setw(25) << setprecision(2) << fixed << tol_tpv 
						<< endl << endl;
						
				outFile << "GPA = " << setprecision(2) << fixed << gpa << endl << endl << endl;
				
				
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
