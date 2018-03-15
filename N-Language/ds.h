#pragma once
#include <string>
#include <iostream>
using namespace std;

class str
{
private:
	string s;
	int a, b, c;
public:
	str();

	void operator=(string ss)
	{
		s = ss;
	}
	/*string console()
	{
		cout << s;
		return s;
	}*/


};
