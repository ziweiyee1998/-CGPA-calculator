# include <iostream>
# include <string>
# include <fstream>

using namespace std;

# ifndef Student_H
# define Student_H

class Student
{
	string name;
	string matric;
	
public:
	Student();
	void readDetail();
	friend void display(string name, string matric);
};

# endif
