#pragma once
#include <string>
#include <iostream>
using namespace std;

class str
{
private:
	string s;
	int  i, j, a, b, c;
public:	
	void operator=(string ss)
	{
		s = ss;
	}

	str input()
	{
		str p;
		getline(cin,s);
		p.s = s;
		return p;
	}

	string console(string end= "\n")
	{
		cout << s << end;
		return s;
	}

	char index(int d)
	{
		return s[d];
	}

	int find(str f)
	{
		for ( i = 0;s[i]!='\0'; i++)
		{
			for(j=i, b=0, a=0 ; f.index(b)!='\0' ; j++, b++)
				if (s[j] != f.index(b))
				{
					a++;
					break;					
				}

			if (a == 0)
			{
				return  i ;
			}
		}
		return -1;
	}

	str lower()
	{
		
			str p;
			
			char *a = new char[sizeof(s)];
			for (i = 0; s[i] != '\0'; i++)
			{
				if (s[i] >= 'A'&&s[i] <= 'Z')
					*(a + i) = s[i] + 32;
				else
					*(a + i) = s[i];
			}
			*(a + i) = '\0';
			p.s = a;
			return p;

	}		

	str upper()
	{

		str p;

		char *a = new char[sizeof(s)];
		for (i = 0; s[i] != '\0'; i++)
		{
			if (s[i] >= 'a'&&s[i] <= 'z')
				*(a + i) = s[i] - 32;
			else
				*(a + i) = s[i];
		}
		*(a + i) = '\0';
		p.s = a;
		return p;

	}
		
	str strip()
	{
		str p;
		char*a = new char[sizeof(s)];

		for (i = 0, j = 0; s[i] != '\0'; i++)
		{
			if (s[i] == ' ' || s[i] == '\t')
			{
				if (s[i+1] != ' '&&s[i+1] != '\t')
				{
					*(a + j) = s[i];
					j++;
				}
			}
			else
			{
				*(a + j) = s[i];
				j++;
			}
		}
		*(a + j) = '\0';
		p.s = a;
		
		return p;
	}
};




