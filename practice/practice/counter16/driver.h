#include<systemc.h>
SC_MODULE(driver)
{
	
	sc_out<bool> en;
	sc_out<bool> rst;
	sc_in<bool> clk;
	
	
	void function()
	{
		rst.write(true);	
		wait(5,SC_NS);
		rst.write(false);
		wait(5,SC_NS);
		en.write(true);	
		wait(5,SC_NS);
		
	}
	
	SC_CTOR(driver)
	{
		SC_THREAD(function);
		sensitive<<clk.pos();
	}	
	
};
	
