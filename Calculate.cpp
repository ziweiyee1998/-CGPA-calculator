# include "Calculate.h"

# define FILE_DATA 83

Calculate::Calculate(int tc, int tt)
{
	tolcredit = 0;
	tolTPV = 0;
}

string Calculate::calGrad(float marks)
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

float Calculate::calcGradePt(float marks)
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

int Calculate::extractCredit(string c)
{
	string temp;
	temp = c.substr(7, 1);
	credit = atoi(temp.c_str());
		
	return credit;
}

void Calculate::calctolCre(int cre)
{
	tolcredit += cre;
}
	
void Calculate::calctolTPV(float tpv)
{
	tolTPV += tpv;
}
	
float Calculate::calcTPV(float gpt, int c)
{
	TPV = gpt * c;
		
	return TPV;
}

int Calculate::gettolcredit()
{
	return tolcredit;
}
	
float Calculate::gettolTPV()
{
	return tolTPV;
}