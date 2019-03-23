#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#ifndef INFORMATION_H
#define INFORMATION_H

class Information
{
	private:
		string courseCode;
		string scredit;
		int credit;
		
	public:
		Information();
		void readInfo();
		string getCourseCode();
		void setCourseCode(string courseCode);
		void extractCredit(string courseCode);
		void stringToInt();
		void printInfo();
};

#endif
