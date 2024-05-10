#include "systemc.h"
SC_MODULE(driver)
{	sc_out<bool> a1,a2;

	void inputs()
	{	
		a1.write(false);
		a2.write(false);
		wait(5,SC_NS);
	
		a1.write(false);
		a2.write(true);
		wait(5,SC_NS); 
		
		a1.write(true);
		a2.write(false);
		wait(5,SC_NS);
	
		a1.write(true);
		a2.write(true);
		wait(5,SC_NS); 
		}
	
		SC_CTOR(driver)
		{
			SC_THREAD(inputs);
			sensitive <<a1 <<a2;
		}
};
