#include<systemc.h>
SC_MODULE(driver)
{
	
	sc_out<bool> j,k;
	sc_out<bool> rst;
	sc_in<bool> clk;
	
	
	void function()
	{
		rst.write(true);	
		wait(5,SC_NS);
		rst.write(false);
		wait(5,SC_NS);
		j.write(false);
		k.write(false);	
		wait(5,SC_NS);
		
		j.write(false);
		k.write(true);	
		wait(5,SC_NS);
		
		j.write(true);
		k.write(false);	
		wait(5,SC_NS);
		
		j.write(true);
		k.write(true);	
		wait(5,SC_NS);
	}
	
	SC_CTOR(driver)
	{
		SC_THREAD(function);
		sensitive<<clk.pos();
	}	
	
};
	
