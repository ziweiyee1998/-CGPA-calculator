#include "Calculate.h"

string Calculate::calGrad(double marks)
{
	string grade;
	
	if(marks >= 90 && marks <= 100 )
	{
	    grade = "A+";
	}
	else if(marks >= 80 )
	{
		grade = "A";
	}
	else if(marks >= 75 )
	{
		grade = "A-";
	}
	else if(marks >= 70 )
	{
		grade = "B+";
	}
	else if(marks >= 65 )
	{
		grade = "B";
	}
	else if(marks >= 60 )
	{
		grade = "B-";
	}
	else if(marks >= 55 )
	{
		grade = "C+";
	}
	else if(marks >= 45 )
	{
		grade = "C-";
	}
	else if(marks >= 40 )
	{
		grade = "D+";
	}
	else if(marks >= 35 )
	{
		grade = "D";
	}
	else if(marks >= 30 )
	{
		grade = "D-";
	}
	else
	{
		grade = "E";
	}
	
	return grade;
}

double Calculate::calGradPt(double marks)
{
	double gradePt;
	
	if(marks >= 90 && marks <= 100 )
	{
	    gradePt = 4.00;
	}
	else if(marks >= 80 )
	{
		gradePt = 4.00;
	}
	else if(marks >= 75 )
	{
		gradePt = 3.67;
	}
	else if(marks >= 70 )
	{
		gradePt = 3.33;
	}
	else if(marks >= 65 )
	{
		gradePt = 3.00;
	}
	else if(marks >= 60 )
	{
		gradePt = 2.67;
	}
	else if(marks >= 55 )
	{
		gradePt = 2.33;
	}
	else if(marks >= 45 )
	{
		gradePt = 1.67;
	}
	else if(marks >= 40 )
	{
		gradePt = 1.33;
	}
	else if(marks >= 35 )
	{
		gradePt = 1.00;
	}
	else if(marks >= 30 )
	{
		gradePt = 0.67;
	}
	else
	{
		gradePt = 0.00;
	}
	
	return gradePt;
}
