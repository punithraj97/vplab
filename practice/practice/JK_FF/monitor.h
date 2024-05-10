#include<systemc.h>
SC_MODULE(monitor)
{
	sc_in<bool> j,k;
	sc_in<bool> q,qb;
	sc_in<bool> rst;
	sc_in<bool> clk;
	
	
	void display()
	{
		cout<<"clock="<<clk<<"reset="<<rst<<"j="<<j<<"k="<<k<<"q="<<q<<"qb="<<qb<<endl;
	}
	
	SC_CTOR(monitor)
	{
		SC_METHOD(display);
		sensitive<<clk.pos();
	}
	
};
	
