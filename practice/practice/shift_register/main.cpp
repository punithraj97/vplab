#include<systemc.h>
#include "shift.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
	sc_signal<bool> in;
	sc_signal<bool> out;
	sc_clock clk("TestClock",20,0.5,0,1);
	
	
	shift_left shift("shift_left");
	driver drive("driver");
	monitor mon("monitor");
	
	shift.in(in);shift.out(out);shift.clk(clk);
	drive.in(in);drive.clk(clk);
	mon.in(in);mon.out(out);mon.clk(clk);
	
	
	sc_trace_file *tf;
	tf=sc_create_vcd_trace_file("jkff");
	
	
	sc_trace(tf,in,"input");
	sc_trace(tf,out,"output");
	sc_trace(tf,clk,"clk");
	
	
	sc_start(100,SC_NS);
	
	sc_close_vcd_trace_file(tf);
	
	
	
	
	
	
	
	return 0;
}


