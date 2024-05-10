#include<systemc.h>
#include "jkff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
	sc_signal<bool> j,k;
	sc_signal<bool> q,qb;
	sc_signal<bool> rst;
	sc_clock clk("TestClock",10,0.5,0,1);
	
	
	jkfff ff("jkfff");
	driver drive("driver");
	monitor mon("monitor");
	
	ff.rst(rst);ff.j(j);ff.k(k);ff.clk(clk);ff.q(q);ff.qb(qb);
	drive.rst(rst);drive.j(j);drive.k(k);drive.clk(clk);
	mon.rst(rst);mon.j(j);mon.k(k);mon.clk(clk);mon.q(q);mon.qb(qb);
	
	
	sc_trace_file *tf;
	tf=sc_create_vcd_trace_file("jkff");
	
	
	sc_trace(tf,rst,"rst");
	sc_trace(tf,j,"j");
	sc_trace(tf,k,"k");
	sc_trace(tf,clk,"clk");
	sc_trace(tf,q,"q");
	sc_trace(tf,qb,"qb");
	
	sc_start(100,SC_NS);
	
	sc_close_vcd_trace_file(tf);
	
	
	
	
	
	
	
	return 0;
}


