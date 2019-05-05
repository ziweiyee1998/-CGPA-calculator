# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <iomanip>
# include <algorithm>
//# include <bits/stdc++.h>
using namespace std;

# ifndef SUBJECT_H
# define SUBJECT_H

# define FILE_DATA 83

class Subject
{
	string sub_info, grade;
	float mark, _tpv;	
	
public:
	Subject();
	
	Subject(string si, string g, float tpv, float mk);
	
	void setInfo(string si, string g, float tpv, float mk)
	{
		sub_info = si;
		grade = g;
		_tpv = tpv;
		mark = mk;
	}
	
	float getSubMark() { return mark; }
	
	string getSubInfo() { return sub_info; }
	
	string getGrade() { return grade; }
	
	float getTPV() { return _tpv; }
	
	string getSubName(string kod)
	{
		transform(kod.begin(), kod.end(), kod.begin(), ::toupper);
		
		string sub[FILE_DATA];
		
		ifstream inp("code.txt");
		
		if (!inp.is_open())
		{
			cout<<"Error! File does not exist!"<<endl;
			exit (1);
		}
		
		for (int i = 0; i < FILE_DATA; i++)
		{
			getline(inp, sub[i], '\n');
		}
	
		for (int i = 0; i < FILE_DATA; i++)
		{
			if (sub[i].compare(0,8,kod) == 0)
			{
				return sub[i];
				break;
			}
			
			else
				continue;
				
		}
		
		inp.close();
	}
};

# endif