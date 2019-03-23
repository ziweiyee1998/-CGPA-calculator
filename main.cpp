# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>

# include "Student.h"
# include "Information.h"

using namespace std;

int main()
{
	Student x;
	
	x.readDetail();
	
	Information y;
	
	y.readInfo();
	y.printInfo();
	
	return 0;
}

