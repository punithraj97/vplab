#include<systemc.h>
SC_MODULE(monitor)
{
	sc_in<bool> in;
	sc_out<bool> out;
	sc_in<bool> clk;
	
	
	void display()
	{
		cout<<"clock="<<clk<<"in="<<in<<"out="<<out<<endl;
	}
	
	SC_CTOR(monitor)
	{
		SC_METHOD(display);
		sensitive<<clk.pos();
	}
	
};
	
