# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <iomanip>
# include <algorithm>
//# include <bits/stdc++.h>
using namespace std;


# include "Subject.h"
# ifndef STUDENT_H
# define STUDENT_H

# define FILE_DATA 83

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
			}

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
};

# endif