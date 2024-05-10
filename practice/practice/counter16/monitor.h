#include<systemc.h>
SC_MODULE(monitor)
{
	sc_in<sc_uint<4>> output;
	sc_in<bool> en;
	sc_in<bool> rst;
	sc_in<bool> clk;
	
	
	void display()
	{
		cout<<"clock="<<clk<<"reset="<<rst<<"enable="<<en<<"output="<<output<<endl;
	}
	
	SC_CTOR(monitor)
	{
		SC_METHOD(display);
		sensitive<<clk.pos();
	}
	
};
	
