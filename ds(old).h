#pragma once
#include <string>
#include <iostream>
using namespace std;

class str
{
private:
	string s;
	int  i, j, k, l, a, b, c;

	class link
	{		
	public:
		char a;
		link *next;
	}*start,*p,*q,*sk;
public:
	str()
	{
		start = NULL;
	}

	void append(char ll)
	{
		if (start == NULL)
		{
			start = new link;			
			start->a = ll;
			start->next = NULL;
			sk = start;
		}
		else
		{		
			p = new link;
			p->a = ll;
			sk->next = p;
			p->next = NULL;		
			sk = sk->next;			
		}
	}

	void console()
	{
		for (q = start; q!= NULL; q = q->next)
			cout << q->a;
	}
	 
	void operator=(char ss[])
	{
		s = ss;
	}

	void operator=(string ss)
	{
		s = ss;
	}

	int size ()
	{
		int i;
		for (i = 0; s[i] != '\0'; i++);
		return i;
	}

	str input()
	{
		str p;
		getline(cin,s);
		p.s = s;
		return p;
	}

	str input(string ss)
	{
		str p;
		s = ss;
		p.s = s;
		return p;
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

	str reversed()
	{
		char* p, *q;
		str r;
		p = new char[sizeof s];
		q = new char[sizeof s];

		for (i = 0; s[i] != '\0'; i++)
			*(p + i) = s[i];
		i--;

		for (j = 0; i >= 0; i--, j++)
			*(q + j) = *(p + i);
		*(q + j) = '\0';
		r = q;
		return r;
	}

	int startswith(str ss)
	{
		for (j = 0, i = 0; ss.index(i)!='\0'; i++)
		{
			if (s[i] != ss.index(i))
				j++;
		}
		if (j == 0)
			return 1;
		else
			return 0;
	}

	int endswith(str ss)
	{
		str p, q;
		p = s;
		p = reversed();
		q = ss.reversed();
		return p.startswith(q);
	}
	
	str replace(str x, str y)
	{
		int i, j, k, l, m;
		str z;
		char a[sizeof(s)], b[2 * sizeof(s)];

		for (i = 0; s[i] != '\0'; i++)
			a[i] = s[i];
		a[i] = '\0';
	
		for (i = 0, m=0; a[i] != '\0'; i++)
		{
			b[m] = a[i];

			for(j=i,k=0,l=0;x.index(k)!='\0';k++,j++)
				if (a[j] != x.index(k))
				{
					l++;
					break;
				}
			if (l == 0)
			{
				for (k = 0; y.index(k) != '\0'; k++, m++)
					b[m] = y.index(k);

				i = i + x.size() - 1;
			}
			else
				m++;
		}
		b[m] = '\0';
		z = b;
		return z;		
	}



};

template <class T>

class list
{
	class linkedlist
	{
	public:
			
		T a;				
		linkedlist *next;
	
	}*start,*p,*q,*r;		
	
public:
	list()			//constructor
	{		
		start = NULL;		
	}
	
	void append(T ll)
	{
		if (start == NULL)
		{
			start = new linkedlist;
			start->a = ll;
			start->next = NULL;
			r = start;
		}
		else
		{
			
			p = new linkedlist;
			p->a = ll;
			r->next = p;
			r = r->next;
			p->next = NULL;
		}
	}

	void console()
	{
		cout << "[";
		for (q = start; q != NULL; q = q->next)
		{
			cout << q->a;
			if (q->next != NULL)
				cout << ", ";
		}
		cout << "]"<<endl;
	}

	void clear()
	{
		start = NULL;		
	}

	list copy()
	{
		linkedlist *t;
		list l;
		for (t = start; t != NULL; t = t->next)
			l.append(t->a);
		return l;
	}
	
	int length()
	{
		int i;
		linkedlist *l;
		for (i = 0, l = start; l != NULL; l = l->next, i++);
		return i;
	}

	int data(int a)
	{
		int i;
		linkedlist *l;
		for (i = 0, l = start; l != NULL; l = l->next, i++)
			if (i == a)
				return l->a;
		return -1;
	}

	void extend(list y)
	{
		int i;
		for (i = 0; i < y.length(); i++)
			append(y.data(i));
	}
	
	int index(int a)
	{
		int i;
		linkedlist *l;
		for (i = 0, l = start; l != NULL; l = l->next, i++)
			if (l->a == a)
				return i;
		return -1;
	}

	void insert(int a,int b)			//index,value
	{
		int i;
		linkedlist *l,*m,*n;
		m = new linkedlist;
		m->a = b;
		if (a == 0)
		{
			m->next = start;
			start = m;
		}
		else
			for(i=0,l=start;l!=NULL;l=l->next,i++)
				if (i+1 == a)
				{
					n = l->next;
					l->next = m;
					m->next = n;
				}
	}

	int pop()
	{
		int x = length() - 1;
		int i,j;
		linkedlist *l;
		if (start == NULL)
			return -1;
		if (x == 0)
		{
			i = start->a;
			start = start->next;
			return i;
		}
		for(i=0, j=0, l=start ; l->next!=NULL ; l=l->next, i++)
			if (i+1 == x)
			{
				j = l->next->a;
				l->next = l->next->next;
				return j;

			}
		return -1;
	}

	int pop(int x)

	{		
		int i, j;
		linkedlist *l;

		if (start == NULL)
			return -1;
		if (x == 0)
		{
			i = start->a;
			start = start->next;
			return i;
		}
		for (i = 0, j = 0, l = start; l->next != NULL; l = l->next, i++)
			if (i + 1 == x)
			{
				j = l->next->a;
				l->next = l->next->next;
				return j;

			}
		return -1;
	}

	int count(int x)
	{
		int i;
		linkedlist *l;
		for(i=0,l=start;l!=NULL;l=l->next)
			if (l->a == x)
			{
				i++;
			}
		return i;
	}

	int remove(int x)
	{
		int i, j;
		linkedlist *l;			
		if (start!=NULL && x == start->a)
		{
			i = start->a;
			start = start->next;
			return i;
		}
		for (i = 0, j = 0, l = start; l->next != NULL; l = l->next, i++)
			if (l->next->a == x)
			{
				j = l->next->a;
				l->next = l->next->next;
				return j;
			}
		return -1;
	}

	list reversed()
	{
		list l;
		int i;
		for (i = 0; i < length(); i++)
			l.insert(0,data(i));
		return l;
	}

	void reverse()
	{
		int i;
		list l = reversed();
		clear();
		for (i = 0; i < l.length(); i++)
			append(l.data(i));
	}
	
	void sort()
	{
		int temp;
		linkedlist *l, *m;
		for (m = start; m!=NULL && m->next != NULL; m = m->next)
			for (l = start; l->next != NULL; l = l->next)
				if (l->a > l->next->a)
				{
					temp = l->a;
					l->a = l->next->a;
					l->next->a = temp;
				}
		
	}

	list sorted()
	{
		list l;
		l = copy();
		l.sort();
		return l;
	}


};
