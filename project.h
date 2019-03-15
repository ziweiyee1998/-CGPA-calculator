# include <iostream>
# include <string>
# include <fstream>

using namespace std;

# idndef Student_H
# define Student_H

class Student
{
  string name;
	string matric;
	
public:
	Student();
	void readDetail();
	void display();
}；

# endif
