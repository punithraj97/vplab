#include <iostream>
using namespace std;


ostream & operator +(ostream &out, float c)
{
	out << c;
	cout<<endl;
	return out;
}

ostream & operator +(ostream &out, const char *c)
{
	out << (char*)c;
	cout<<endl;
	return out;
}


int main()
{


char name[50]="hello world";
cout+5.5f+name;
cout<<endl;
return 0;
}
