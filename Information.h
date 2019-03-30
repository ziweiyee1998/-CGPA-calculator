#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#ifndef INFORMATION_H
#define INFORMATION_H

class Information
{
	private:
		string subjectCode;
		string scredit;
		int credit;
		
	public:
		Information();
		void readInfo();
		string getSubjectCode();
		void setSubjectCode(string subjectCode);
		void extractCredit(string subjectCode);
		void stringToInt();
		void printInfo();
};

#endif
