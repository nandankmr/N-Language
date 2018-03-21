#pragma once
#include <iostream>
#include <string>
using namespace std;

class str
{
	struct link
	{
		char c;
		link *next, *pre;
	}*start,*p,*q,*r;

	void append(char ll)
	{
		if (start == NULL)
		{
			start = new link;
			start->c = ll;
			start->next = NULL;
			r = start;
		}
		else
		{
			p = new link;
			p->c = ll;
			r->next = p;
			p->next = NULL;
			r = r->next;
		}
	}
	
public:
	str()
	{
		start = NULL;
	}

	void clear()
	{
		start = NULL;
	}
	
	void console(string end = "\n")
	{
		link *q;
		q = start;
		for (; q != NULL; q = q->next)
			cout << q->c;
		cout << end;
	}

	char index(int i)
	{
		int j;
		link *q;
		q = start;
		for (j = 0; q != NULL; q = q->next, j++)
		{
			if (j == i)				
				return (q->c);
		}
		return -1;

	}	

	void operator =(string a)
	{
		clear();
		for (int i = 0; a[i] != '\0'; i++)
			append(a[i]);
	}

	int length()
	{
		int i = 0;
		link *l;
		for (l = start; l != NULL; l = l->next, i++);
		return i;
	}

	str input()
	{
		str p;
		string ss;
		getline(cin, ss);
		clear();
		for (int i = 0; ss[i] != '\0';p.append(ss[i]), i++)
			append(ss[i]);
		return p;
	}

	str input(string ss)
	{
		str p;			
		clear();
		for (int i = 0; ss[i] != '\0';p.append(ss[i]), i++)
			append(ss[i]);
		return p;
	}

	int find(str ss)
	{
		link *l,*m;
		int i, j=0, k;
		for (l = start, k = 0; l != NULL; l = l->next, k++)
		{
			for (m = l, i = 0, j = 0; i < ss.length(); i++,m=m->next)
			{
				if (m == NULL)
					return -1;
				if (m->c != ss.index(i))
				{
					j++;
					break;
				}
			}
			if (j == 0)
				return k;
		}
		return -1;
	}

	int find(string s1)
	{
		str ss;
		ss.input(s1);
		link *l, *m;
		int i, j = 0, k;
		for (l = start, k = 0; l != NULL; l = l->next, k++)
		{
			for (m = l, i = 0, j = 0; i < ss.length(); i++, m = m->next)
			{
				if (m == NULL)
					return -1;
				if (m->c != ss.index(i))
				{
					j++;
					break;
				}
			}
			if (j == 0)
				return k;
		}
		return -1;
	}

	str lower()
	{
		str s;
		link *l;
		for (l = start; l != NULL; l = l->next)
		{
			if (l->c >= 'A'&&l->c <= 'Z')
				s.append(l->c + 32);
			else
				s.append(l->c);
		}
		return s;
	}

	str upper()
	{
		str s;
		link *l;
		for (l = start; l != NULL; l = l->next)
		{
			if (l->c >= 'a'&&l->c <= 'z')
				s.append(l->c - 32);
			else
				s.append(l->c);
		}
		return s;
	}

	str strip()
	{
		str s;
		link *l;
		for (l = start; l->next != NULL; l = l->next)
		{
			if (l->c == ' ' || l->c == '\t')
			{
				if (l->next->c != ' '&&l->next->c != '\t')
					s.append(l->c);
			}
			else
				s.append(l->c);			
		}
		s.append(l->c);
		return s;
	}

	str reversed()
	{
		
	}

};