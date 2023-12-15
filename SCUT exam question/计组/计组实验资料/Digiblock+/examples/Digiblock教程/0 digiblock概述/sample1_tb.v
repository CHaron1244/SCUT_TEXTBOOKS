//  A testbench for sample1_tb
`timescale 1us/1ns

module sample1_tb;
    reg [1:0] A1;
    reg [1:0] A2;
    reg [1:0] A3;
    wire [1:0] Y1;

  sample1 sample1_tb0 (
    .A1(A1),
    .A2(A2),
    .A3(A3),
    .Y1(Y1)
  );

  parameter PERIOD = 10;


  initial begin
    $dumpfile("db_sample1_tb.vcd");
    $dumpvars(0, sample1_tb);
    /*
    * Please insert your code as fellow.
    */
	A1=1;
	A2=3;
	A3=0;


  end

  initial
    #100000 $finish;
  endmodule