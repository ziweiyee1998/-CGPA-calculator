# include "Subject.h"

# define FILE_DATA 83

Subject::Subject()
{
}

Subject::Subject(string si, string g, float tpv, float mk)
{
	sub_info = si;
	grade = g;
	_tpv = tpv;
	mark = mk;
}

void Subject::setInfo(string si, string g, float tpv, float mk)
{
	sub_info = si;
	grade = g;
	_tpv = tpv;
	mark = mk;
}

float Subject::getSubMark()
{
	return mark; 
}
	
string Subject::getSubInfo()
{ 
	return sub_info; 
}
	
string Subject::getGrade() 
{ 
	return grade; 
}
	
float Subject::getTPV() 
{ 
	return _tpv; 
}
	
string Subject::getSubName(string kod)
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