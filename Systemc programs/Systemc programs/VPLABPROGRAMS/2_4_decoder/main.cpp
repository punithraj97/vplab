#include "systemc.h"
#include "decoder.h"
#include "driver.h"
#include "monitor.h"

int sc_main( int argc, char* argv[] ) {
sc_signal <bool> a1,a2,d1,d2,d3,d4;

decoder decode("decoder");
driver drive("driver");
monitor mon("monitor");

decode.a1(a1); decode.a2(a2); decode.d1(d1);decode.d2(d2);decode.d3(d3);decode.d4(d4);
drive.a1(a1); drive.a2(a2); 
mon.a1(a1);mon.a2(a2); mon.d1(d1);mon.d2(d2);mon.d3(d3);mon.d4(d4);

sc_trace_file *Tf;
Tf = sc_create_vcd_trace_file("traces");
sc_trace(Tf, a1, "a1"); 
sc_trace(Tf, a2, "a2"); 
sc_trace(Tf, d1, "d1");
sc_trace(Tf, d2, "d2");
sc_trace(Tf, d3, "d3");
sc_trace(Tf, d4, "d4");
sc_start(25,SC_NS);
sc_close_vcd_trace_file(Tf);
return 0; 
}
