#include<systemc.h>
SC_MODULE(decoder)
{
	sc_in<sc_uint<2>> input;
	sc_out<sc_uint<4>> output;
	sc_in<bool> en;
	
	
	void function()
	{
		if(en.read())
		{
			if(input.read() == 0)
				output.write(1);
			else if(input.read() == 1)
				output.write(2);
			else if(input.read() == 2)
				output.write(4);
			else if(input.read()== 3)
				output.write(8);
			else
				output.write(0);
				
		}
		else
			output.write(0);
	}
	
	
	SC_CTOR(decoder)
	{
		SC_METHOD(function);
		sensitive<<en<<input;
		
	}
	
	
};
