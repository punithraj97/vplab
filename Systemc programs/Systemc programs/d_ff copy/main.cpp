#include "systemc.h"
#include "d_ff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
    sc_signal<bool> dff, q, qb;
    sc_clock clk("TestClock", 10, 0.5, 0, 1);

    d_ff d("D Filp Flop");
    driver drive("driver");
    monitor mon("monitor");

    d.q(q);
    d.qbar(qb);
    d.clk(clk);
    d.d(dff);

    drive.d(dff);
    drive.clk(clk);
    
    mon.q(q);
    mon.qbar(qb);
    mon.clk(clk);
    mon.d(dff);

    sc_trace_file *Tf;
    Tf = sc_create_vcd_trace_file("traces");
    sc_trace(Tf, dff, "d");
    sc_trace(Tf, q, "q");
    sc_trace(Tf, clk, "clk");
    sc_trace(Tf, qb, "qb");
    sc_start(8*10, SC_NS);
    sc_close_vcd_trace_file(Tf);
    return 0;
}
