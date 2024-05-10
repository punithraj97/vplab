#include<systemc.h>
#include "decoder.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
	sc_signal<bool> en;
	sc_signal<sc_uint<2>> input;
	sc_signal<sc_uint<4>> output;
	
	driver drive("driver");
	monitor mon("monitor");
	decoder deco("decoder");
	
	drive.en(en);drive.input(input);
	mon.en(en);mon.input(input);mon.output(output);
	deco.en(en);deco.input(input);deco.output(output);
	
	
	sc_trace_file *tf;
	tf=sc_create_vcd_trace_file("traces");
	
	sc_trace(tf,en,"en");
	sc_trace(tf,input,"input");
	sc_trace(tf,output,"output");
	
	sc_start();
	
	sc_close_vcd_trace_file(tf);
	
	return 0;
}


