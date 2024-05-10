#include "systemc.h"
SC_MODULE(monitor)
{
	sc_in<bool> d;
	sc_in<bool> q;
	sc_in<bool> qbar;
	sc_in<bool> clk;

	void mon()
	{
		cout << "Inputs: " << d << clk << " Output: "
			 << " Q=" << q << " Qb=" << qbar << endl;
	}

	SC_CTOR(monitor)
	{
		SC_METHOD(mon);
		sensitive << clk.pos();
	}
};
