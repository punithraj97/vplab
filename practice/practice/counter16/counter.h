#include<systemc.h>
SC_MODULE(counter)
{
	
	sc_out<sc_uint<4>> output;
	sc_in<bool> en;
	sc_in<bool> rst;
	sc_uint<4> temp;
	sc_in<bool> clk;
	
	void function()
	{
	
	
		if(rst.read())
		{
		output.write(0);	
		}
		else
		{
		if(en.read())
		{
		        temp=(temp+1)%16;
			output.write(temp);
		}}
	}
	
	
	SC_CTOR(counter)
	{
		SC_METHOD(function);
		sensitive<<rst<<clk.pos();
		
	}
	
	
};
