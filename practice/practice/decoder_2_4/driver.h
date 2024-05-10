#include<systemc.h>
SC_MODULE(driver)
{
	sc_out<sc_uint<2>> input;
	
	sc_out<bool> en;
	
	void function()
	{
		en.write(false);
		input.write(10);
		wait(5,SC_NS);
		
		en.write(true);
		input.write(0);
		wait(5,SC_NS);
		
		input.write(1);
		wait(5,SC_NS);
		
		input.write(2);
		wait(5,SC_NS);
		
		input.write(3);
		wait(5,SC_NS);
		
		input.write(8);
		wait(5,SC_NS);
		
		
	}
	
	SC_CTOR(driver)
	{
		SC_THREAD(function);
		sensitive<<en<<input;
	}	
	
};
	
