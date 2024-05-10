#include "systemc.h"
SC_MODULE(monitor){

sc_in<bool> a1,a2;
sc_in<bool>d1,d2,d3,d4;

void mon()
{
cout << "Inputs: "<<a1 <<a2 << " Output: "<<d1 <<d2 <<d3 <<d4 <<endl; 
}

	SC_CTOR(monitor)
	{
		SC_METHOD(mon);
		sensitive <<a1 <<a2;
	}
};
