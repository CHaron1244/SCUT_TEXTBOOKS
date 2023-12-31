/*
 * Generated by Digiblock. Don't modify this file!
 * Any changes will be lost if this file is regenerated.
 */

module encoder (
  input D_0, // data bit 0.
  input D_1, // data bit 1.
  input D_2, // data bit 2.
  input D_3, // data bit 3.
  output A, // Output bit. One of the data bits is always output 
            // here. Which one is set by the inputs A_0 and A_1.
  output [1:0] Y
);
  assign A = (D_0 | D_1 | D_2 | D_3);
  assign Y[0] = ((D_1 & ~ D_2) | D_3);
  assign Y[1] = (D_2 | D_3);
endmodule
