#include<systemc.h>
SC_MODULE(monitor)
{
	sc_in<sc_uint<2>> input;
	sc_in<sc_uint<4>> output;
	sc_in<bool> en;
	
	
	void display()
	{
		cout<<"enable="<<en<<"input="<<input<<"output="<<output<<endl;
	}
	
	SC_CTOR(monitor)
	{
		SC_METHOD(display);
		sensitive<<input<<en;
	}
	
};
	
