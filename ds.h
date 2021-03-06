#pragma once
#include <string>
#include <iostream>
using namespace std;

class str
{
	struct link
	{
		char c;
		link *next;
	}*start, *p, *q, *r;

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

	void insert0(char ll)
	{
		link *p;
		p = new link;
		p->c = ll;
		p->next = start;
		start = p;
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
		if (start != NULL)
		{
			q = start;
			cout << "\"";
			for (; q != NULL; q = q->next)
				cout << q->c;
			cout << "\"";
			cout << end;
		}
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
		for (int i = 0; ss[i] != '\0'; p.append(ss[i]), i++)
			append(ss[i]);
		return p;
	}

	str input(string ss)
	{
		str p;
		clear();
		for (int i = 0; ss[i] != '\0'; p.append(ss[i]), i++)
			append(ss[i]);
		return p;
	}

	int find(str ss)
	{
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
		str x;
		link *l;
		for (l = start; l != NULL; l = l->next)
			x.insert0(l->c);
		return x;
	}

	int startswith(str ss)
	{
		if (find(ss) == 0)
			return 1;
		else
			return 0;
	}

	int startswith(string s)
	{
		str ss;
		ss.input(s);
		if (find(ss) == 0)
			return 1;
		else
			return 0;
	}

	int endswith(str ss)
	{
		if (reversed().startswith(ss.reversed()))
			return 1;
		else
			return 0;
	}

	int endswith(string s)
	{
		str ss;
		ss.input(s);
		if (reversed().startswith(ss.reversed()))
			return 1;
		else
			return 0;
	}

	str copy()
	{
		str l;
		for (int i = 0; i < length(); i++)
			l.append(index(i));
		return l;
	}

	str replace(str x, str y)
	{
		str p, q;
		int i, j, k, l, m;
		if (x.length() == 0)
			return copy();
		for (i = 0; i < length(); i++)
		{
			for (j = i, k = 0, l = 0; k < x.length(); k++, j++)
				if (index(j) != x.index(k) || j >= length())
				{
					l++;
					break;
				}
			if (l == 0)
			{
				for (k = 0; k < y.length(); k++)
					p.append(y.index(k));
				i = i + x.length() - 1;
			}
			else
				p.append(index(i));
		}
		return p;
	}

	str replace(string s1, string s2)
	{
		str x, y;
		x = s1;
		y = s2;
		str p, q;
		int i, j, k, l, m;
		if (x.length() == 0)
			return copy();
		for (i = 0; i < length(); i++)
		{
			for (j = i, k = 0, l = 0; k < x.length(); k++, j++)
				if (index(j) != x.index(k) || j >= length())
				{
					l++;
					break;
				}
			if (l == 0)
			{
				for (k = 0; k < y.length(); k++)
					p.append(y.index(k));
				i = i + x.length() - 1;
			}
			else
				p.append(index(i));
		}
		return p;
	}
	
};

//class list

class list
{
	class linkedlist
	{
	public:					
		char type;
		int a;
		str s;
		list *k;
		linkedlist *next;	
	}*start,*p,*q,*r;
	
public:
	list()			//constructor
	{		
		start = NULL;
	}
	
	void append(int ll)
	{
		if (start == NULL)
		{
			start = new linkedlist;
			start->a = ll;
			start->next = NULL;
			
			r = start;
			start->type = 'i';
		}
		else
		{			
			p = new linkedlist;
			p->a = ll;
			p->type = 'i';
			r->next = p;
			r = r->next;
			p->next = NULL;
		}
	}

	void append(str ll)
	{
		if (start == NULL)
		{
			start = new linkedlist;
			start->s = ll;
			start->next = NULL;
			r = start;
			start->type = 's';
		}
		else
		{
			p = new linkedlist;
			p->s = ll;
			p->type = 's';
			r->next = p;
			r = r->next;
			p->next = NULL;
		}
	}

	void append(string n)
	{
		str ll;
		ll = n;
		if (start == NULL)
		{
			start = new linkedlist;
			start->s = ll;
			start->type = 's';
			start->next = NULL;
			r = start;
		}
		else
		{
			p = new linkedlist;
			p->s = ll;
			p->type = 's';
			r->next = p;
			r = r->next;
			p->next = NULL;
		}
	}

	void append(list ll)
	{		
		if (start == NULL)
		{
			start = new linkedlist;
			start->k = new list;
			*(start->k) = ll;
			start->type = 'l';
			start->next = NULL;
			r = start;
		}
		else
		{
			p = new linkedlist;
			p->k = new list;
			*(p->k) = ll;
			p->type = 'l';
			r->next = p;
			r = r->next;
			p->next = NULL;
		}
	}
	
	void append(list* ll)
	{
		if (start == NULL)
		{
			start = new linkedlist;
			start->k = new list;
			*(start->k) = *ll;
			start->type = 'l';
			start->next = NULL;
			r = start;
		}
		else
		{
			p = new linkedlist;
			p->k = new list;
			*(p->k) = *ll;
			p->type = 'l';
			r->next = p;
			r = r->next;
			p->next = NULL;
		}
	}

	char type(int a)
	{
		int i;
		linkedlist *p;
		for (p = start, i = 0; p != NULL; p = p->next, i++)
			if (i == a)
				return p->type;
	}

	void console(string end="\n")
	{
		linkedlist *q;
		cout << "[";
		for (q = start; q != NULL; q = q->next)
		{
			if (q->type == 'i')
				cout << q->a;
			else if (q->type == 'l')
				q->k->console("");
			else
				q->s.console("");
			if (q->next != NULL)
				cout << ", ";
		}
		cout << "]"<<end;
	}

	void clear()
	{
		start = NULL;		
	}

	list copy()
	{
		list l,t;
		linkedlist *m;
		for (m = start; m != NULL; m = m->next)
		{
			if (m->type == 'i')
				l.append(m->a);
			else if (m->type == 's')
				l.append((m->s));
			else
			{
				t = m->k->copy();
				l.append(t);
			}
		}
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
				if(l->type=='i')
				return l->a;
		return -1;
	}
	
	
	void extend(list x)
	{
		int i;
		list k,y;
		y = x.copy();
		for (i = 0; i < y.length(); i++)
		{
			if (y.type(i) == 'i')
				append(y.index_int(i));
			else if (y.type(i) == 's')
				append(y.index_str(i));
			else
			{
				k = (y.index_list(i))->copy();
				append(k);
			}
		}
	}
	
	int index_int(int a)
	{
		int i;
		linkedlist *l;
		for (i = 0, l = start; l != NULL; l = l->next, i++)
			if (i == a)
				return l->a;
		return -1;
	}
	
	str index_str(int a)
	{
		int i;
		str m;
		linkedlist *l;
		for (i = 0, l = start; l != NULL; l = l->next, i++)
			if (i == a)
				return l->s;
		return m;
	}
	
	list* index_list(int a)
	{
		int i;
		list k;
		linkedlist *l;
		for (i = 0, l = start; l != NULL; l = l->next, i++)
			if (i == a)
				return (l->k);
		return &k;
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

