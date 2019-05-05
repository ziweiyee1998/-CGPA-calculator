# include "Student.h"
# include "Subject.h"

# define FILE_DATA 83

Student::Student()
{ 
}
	
Student::Student(string n, string m): name(n), matric(m), student_count(0), _studentlist(0), subject_count(0), _subjectlist(0)
{
}
	
bool Student::addStudent(Student* std)
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
	
void Student::setInfo(string n, string m)
{
	name = n;
	matric = m;
}
	
string Student::getName() 
{ 
	return name; 
}
	
string Student::getMatric() 
{ 
	return matric; 
}
	
string Student::returnNM (int a)
{
	return _studentlist[a].getName() + " " + _studentlist[a].getMatric();
}
	
string Student::returnN (int a)
{
	return _studentlist[a].getName();
}
	
string Student::returnM (int a)
{
	return _studentlist[a].getMatric();
}
	
bool Student::addSubject (Subject* s)
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