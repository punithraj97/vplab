#include<systemc.h>
#include "counter.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
	sc_signal<sc_uint<4>> output;
	sc_signal<bool> en;
	sc_signal<bool> rst;
	
	sc_clock clk("TestClock",20,0.5,0,1);
	
	driver drive("driver");
	monitor mon("monitor");
	counter deco("decoder");
	
	drive.en(en);drive.rst(rst);drive.clk(clk);
	mon.en(en);mon.output(output);mon.rst(rst);mon.clk(clk);
	deco.en(en);deco.output(output);deco.rst(rst);deco.clk(clk);
	
	
	sc_trace_file *tf;
	tf=sc_create_vcd_trace_file("traces");
	
	sc_trace(tf,clk,"clk");
	sc_trace(tf,rst,"rst");
	sc_trace(tf,en,"en");
	sc_trace(tf,output,"output");
	
	sc_start(1000,SC_NS);
	
	sc_close_vcd_trace_file(tf);
	
	return 0;
}


