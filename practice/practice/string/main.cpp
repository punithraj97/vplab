#include<systemc.h>
#include<iostream>
#include<string.h>
using namespace std;
int sc_main(int argc, char *argv[])
{
	
	string s1;
	int i=0;
	s1="101001101001010";
	
	int len;
	len=strlen(s1);
	cout<<len<<endl;
	while(s1[i]!='\0')
	{
	
	if(s1[i]=='1' && s1[i+1]=='0' && s1[i+2]=='0')
		cout<<"1"<<endl;
	else
		cout<<"0"<<endl;
	i++;
	}	
	return 0;
}
