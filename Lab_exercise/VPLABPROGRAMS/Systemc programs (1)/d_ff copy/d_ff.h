#include "systemc.h"
SC_MODULE(d_ff)
{
	sc_in<bool> clk;
	sc_in<bool> d;
	sc_out<bool> q;
	sc_out<bool> qbar;

	sc_uint<1> dprev = 0;
	void compute_result()
	{
		q.write(dprev);
		qbar.write(!dprev);
		dprev = d.read();
	}
	SC_CTOR(d_ff)
	{
		SC_METHOD(compute_result);
		sensitive << clk.pos();
	}
};
