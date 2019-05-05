# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <iomanip>
# include <algorithm>
//# include <bits/stdc++.h>
using namespace std;

# ifndef CALCULATE_H
# define CALCULATE_H

# define FILE_DATA 83

class Calculate
{
	float cgpa, gpa, gradePt, TPV, tolTPV;
	string grade;
	int credit, tolcredit;
	
public:
	Calculate(int tc, int tt): tolcredit(0), tolTPV(0) {	}
	
	string calGrad(float marks);
		
	float calcGradePt(float marks);
	
	int extractCredit(string c);
	
	void calctolCre(int cre);
	
	void calctolTPV(float tpv);
	
	float calcTPV(float gpt, int c);

	int gettolcredit();
	
	float gettolTPV();
};

# endif