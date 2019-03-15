# include <iostream>
# include <string>
# include <fstream>

using namespace std;

# idndef project_H
# define project_H

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
