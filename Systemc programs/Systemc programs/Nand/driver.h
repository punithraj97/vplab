#include "systemc.h"
SC_MODULE(driver)
{	sc_out<bool> a1,b1;
        sc_time             t3;

	void inputs()
	{	
		a1.write(false);
		b1.write(false);
	        wait(2,SC_NS);
	        t3 = sc_time_stamp();
	        cout <<"Value of t3 "<< t3.to_string() << endl;
	        
		a1.write(false);
		b1.write(true);
		 wait(2,SC_NS);
		  t3 = sc_time_stamp();
	        cout <<"Value of t3 "<< t3.to_string() << endl;
	        
		a1.write(true);
		b1.write(false);
		 wait(2,SC_NS);
		  t3 = sc_time_stamp();
	        cout <<"Value of t3 "<< t3.to_string() << endl;
	        
		 
		a1.write(true);
		b1.write(true);
		
		 wait(2,SC_NS);
		  t3 = sc_time_stamp();
	        cout <<"Value of t3 "<< t3.to_string() << endl;
		
		}
	
		SC_CTOR(driver)
		{
			SC_THREAD(inputs);
			sensitive <<a1 <<b1;
		}
};
