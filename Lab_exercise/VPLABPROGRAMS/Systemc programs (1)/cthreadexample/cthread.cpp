// Learn with Examples, 2020, MIT license
#include <systemc>
using namespace sc_core;

SC_MODULE(MODULE) {
  sc_in<bool> clk; // need event_finder method, cannot use basic sc_port
  int in;
  SC_CTOR(MODULE) {
    SC_CTHREAD(cthread1, clk); // sensitive to clk pos edge
    // no static sensitivity, thus, cannot use dont_initialize()
    SC_CTHREAD(cthread2, clk.pos()); // sensitive to clk pos edge
    SC_CTHREAD(cthread3, clk.neg()); // sensitive to clk neg edge
  }
  void cthread1() {
    while (true) {
    in=!in;
      wait(); // wait for clk pos edge; wait() right after while loop to avoid initialization
      std::cout << sc_time_stamp() << ", cthread1, value = " << clk->read() << std::endl;
    }
  }
  void cthread2() {
    while (true) {
       in=!in;
      wait(); // wait for clk pos edge
      std::cout << sc_time_stamp() << ", cthread2, value = " << clk->read() << std::endl;
    }
  }
  void cthread3() {
    while (true) {
       in=!in;
      wait(); // wait for clk neg edge
      std::cout << sc_time_stamp() << ", cthread3, value = " << clk->read() << std::endl;
    }
  }
};

int sc_main(int, char*[]) {
  sc_clock clk("clk", 10, SC_NS, 0.2, 10, SC_NS, false); // 10s period, 2s true, 8s false, start at 10s, start at false.
  MODULE module("module"); // instantiate module
  module.clk(clk); // bind port
  sc_start(31, SC_NS); // run simulation for 31 s
  sc_trace_file *Tf;
Tf = sc_create_vcd_trace_file("traces");
sc_trace(Tf, clk,"clk"); 
sc_trace(Tf, module.in,"in");
sc_start(30,SC_NS);
sc_close_vcd_trace_file(Tf);
  return 0;
}
