/*
 * Generated by Digiblock. Don't modify this file!
 * Any changes will be lost if this file is regenerated.
 */
module Driver
(
    input in,
    input sel,
    output out
);
    assign out = (sel == 1'b1)? in : 1'bz;
endmodule
module DriverInv
(
    input in,
    input sel,
    output out
);
    assign out = (sel == 1'b0)? in : 1'bz;
endmodule

module \logic gate  (
  input [7:0] A1,
  input [7:0] B1,
  input A2,
  input B2,
  input A3,
  input B3,
  input C2,
  input A4,
  input B4,
  input A5,
  input A6,
  input B6,
  input A7,
  input B7,
  input A8,
  input B8,
  output [7:0] Y1,
  output Y2,
  output Y3,
  output Y4,
  output Y5,
  output Y6,
  output Y7,
  output Y8
);
  assign Y1 = (A1 & B1);
  assign Y2 = ~ (A2 & B2 & C2);
  assign Y3 = (A3 | B3);
  assign Y6 = (A6 ^ B6);
  assign Y5 = ~ A5;
  Driver Driver_i0 (
    .in( B7 ),
    .sel( A7 ),
    .out( Y7 )
  );
  assign Y4 = ~ (A4 | B4);
  DriverInv DriverInv_i1 (
    .in( B8 ),
    .sel( A8 ),
    .out( Y8 )
  );
endmodule
