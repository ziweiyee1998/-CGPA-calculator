# include <iostream>
# include <string>

using namespace std;

#ifndef CALCULATE_H
#define CALCULATE_H

class Calculate
{
	protected:
	    int semester;
	    int amtSubject;
	    double marks;
	    double gpa;
	    double cgpa;
	public:
		double setMarks();
		void getMarks();
		
		string calGrad(double marks);
		double calGradPt(double marks);
		
};

#endif
