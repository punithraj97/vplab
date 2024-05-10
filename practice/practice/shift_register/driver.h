#include<systemc.h>
SC_MODULE(driver)
{
	
	sc_out<bool> in;
	
	sc_in<bool> clk;
	
	
	void function()
	{
		in.write(true);	
		wait(5,SC_NS);
		
		in.write(false);	
		wait(5,SC_NS);
		
		in.write(false);	
		wait(5,SC_NS);
		
		in.write(false);	
		wait(5,SC_NS);
		
		in.write(true);	
		wait(5,SC_NS);
		
		in.write(true);	
		wait(5,SC_NS);
		
		in.write(false);	
		wait(5,SC_NS);
		
		
		in.write(true);	
		wait(5,SC_NS);
		
		in.write(false);	
		wait(5,SC_NS);
		
		in.write(true);	
		wait(5,SC_NS);
	}
	
	SC_CTOR(driver)
	{
		SC_THREAD(function);
		sensitive<<clk.pos();
	}	
	
};
	
