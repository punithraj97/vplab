#include<systemc.h>
SC_MODULE(shift_left)
{
	
	
	sc_in<bool> in;
	sc_out<bool> out;
	sc_in<bool> clk;
	bool a;
	bool b;
	bool c;
	bool d;
	
	/*temp[0]=0;
	temp[1]=0;
	temp[2]=0;
	temp[3]=0;*/
	void function()
	{
		out.write(a);
		a=b;
		b=c;
		c=d;
		d=in.read();
	}
	
	
	SC_CTOR(shift_left)
	{
		SC_METHOD(function);
		sensitive<<clk.pos();
		
	}
	
	
	
	
};
