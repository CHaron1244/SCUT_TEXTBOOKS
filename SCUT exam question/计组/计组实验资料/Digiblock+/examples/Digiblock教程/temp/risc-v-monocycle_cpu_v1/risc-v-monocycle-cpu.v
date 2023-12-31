/*
 * Generated by Digital. Don't modify this file!
 * Any changes will be lost if this file is regenerated.
 */

module DIG_Counter_Nbit
#(
    parameter Bits = 2
)
(
    output [(Bits-1):0] out,
    output ovf,
    input C,
    input en,
    input clr
);
    reg [(Bits-1):0] count;

    always @ (posedge C) begin
        if (clr)
          count <= 'h0;
        else if (en)
          count <= count + 1'b1;
    end

    assign out = count;
    assign ovf = en? &count : 1'b0;

    initial begin
        count = 'h0;
    end
endmodule


module Mux_2x1_NBits #(
    parameter Bits = 2
)
(
    input [0:0] sel,
    input [(Bits - 1):0] in_0,
    input [(Bits - 1):0] in_1,
    output reg [(Bits - 1):0] out
);
    always @ (*) begin
        case (sel)
            1'h0: out = in_0;
            1'h1: out = in_1;
            default:
                out = 'h0;
        endcase
    end
endmodule

module ShiftLeftL #(
parameter Bits = 4,
parameter shiftBits=2
)
(
    input [(Bits-1):0] in,
    input [(shiftBits-1):0] shift,
    output [(Bits - 1):0] out
);

assign out = (in << shift);

endmodule

module Mux_4x1_NBits #(
    parameter Bits = 2
)
(
    input [1:0] sel,
    input [(Bits - 1):0] in_0,
    input [(Bits - 1):0] in_1,
    input [(Bits - 1):0] in_2,
    input [(Bits - 1):0] in_3,
    output reg [(Bits - 1):0] out
);
    always @ (*) begin
        case (sel)
            2'h0: out = in_0;
            2'h1: out = in_1;
            2'h2: out = in_2;
            2'h3: out = in_3;
            default:
                out = 'h0;
        endcase
    end
endmodule


module DIG_Register_BUS #(
    parameter Bits = 1
)
(
    input C,
    input en,
    input [(Bits - 1):0]D,
    output [(Bits - 1):0]Q
);

    reg [(Bits - 1):0] state = 'h0;

    assign Q = state;

    always @ (posedge C) begin
        if (en)
            state <= D;
   end
endmodule
module DIG_Add
#(
    parameter Bits = 1
)
(
    input [(Bits-1):0] a,
    input [(Bits-1):0] b,
    input c_i,
    output [(Bits - 1):0] s,
    output c_o
);
   wire [Bits:0] temp;

   assign temp = a + b + c_i;
   assign s = temp [(Bits-1):0];
   assign c_o = temp[Bits];
endmodule



module \monocycle-pc  (
  input [31:0] instr,
  input [1:0] pcw,
  input bxx,
  input clock,
  input pcen,
  input [31:0] rs1,
  input result,
  output [31:0] pc
);
  wire [31:0] s0;
  wire [31:0] pc_temp;
  wire s1;
  wire [12:0] s2;
  wire s3;
  wire [20:0] s4;
  wire [10:0] s5;
  wire [31:0] s6;
  wire [18:0] s7;
  wire [31:0] s8;
  wire [31:0] s9;
  wire [31:0] s10;
  wire s11;
  wire [19:0] s12;
  wire [31:0] s13;
  wire [31:0] s14;
  wire [31:0] s15;
  wire [31:0] s16;
  wire s17;
  assign s17 = (bxx & result);
  assign s1 = instr[31];
  assign s3 = instr[31];
  assign s11 = instr[31];
  assign s2[0] = 1'b0;
  assign s2[4:1] = instr[11:8];
  assign s2[10:5] = instr[30:25];
  assign s2[11] = instr[7];
  assign s2[12] = s1;
  assign s4[0] = 1'b0;
  assign s4[10:1] = instr[30:21];
  assign s4[11] = instr[20];
  assign s4[19:12] = instr[19:12];
  assign s4[20] = s3;
  Mux_2x1_NBits #(
    .Bits(11)
  )
  Mux_2x1_NBits_i0 (
    .sel( s3 ),
    .in_0( 11'b0 ),
    .in_1( 11'b11111111111 ),
    .out( s5 )
  );
  Mux_2x1_NBits #(
    .Bits(19)
  )
  Mux_2x1_NBits_i1 (
    .sel( s1 ),
    .in_0( 19'b0 ),
    .in_1( 19'b1111111111111111111 ),
    .out( s7 )
  );
  Mux_2x1_NBits #(
    .Bits(20)
  )
  Mux_2x1_NBits_i2 (
    .sel( s11 ),
    .in_0( 20'b0 ),
    .in_1( 20'b11111111111111111111 ),
    .out( s12 )
  );
  assign s6[20:0] = s4;
  assign s6[31:21] = s5;
  assign s8[12:0] = s2;
  assign s8[31:13] = s7;
  assign s13[11:0] = instr[31:20];
  assign s13[31:12] = s12;
  // ja
  ShiftLeftL #(
    .Bits(32),
    .shiftBits(1)
  )
  ShiftLeftL_i3 (
    .in( s6 ),
    .shift( 1'b1 ),
    .out( s9 )
  );
  // bxx
  ShiftLeftL #(
    .Bits(32),
    .shiftBits(1)
  )
  ShiftLeftL_i4 (
    .in( s8 ),
    .shift( 1'b1 ),
    .out( s10 )
  );
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i5 (
    .sel( s17 ),
    .in_0( 32'b100 ),
    .in_1( s10 ),
    .out( s14 )
  );
  Mux_4x1_NBits #(
    .Bits(32)
  )
  Mux_4x1_NBits_i6 (
    .sel( pcw ),
    .in_0( 32'b100 ),
    .in_1( s9 ),
    .in_2( s14 ),
    .in_3( s13 ),
    .out( s15 )
  );
  // pc
  DIG_Register_BUS #(
    .Bits(32)
  )
  DIG_Register_BUS_i7 (
    .D( s0 ),
    .C( clock ),
    .en( pcen ),
    .Q( pc_temp )
  );
  Mux_4x1_NBits #(
    .Bits(32)
  )
  Mux_4x1_NBits_i8 (
    .sel( pcw ),
    .in_0( pc_temp ),
    .in_1( pc_temp ),
    .in_2( pc_temp ),
    .in_3( rs1 ),
    .out( s16 )
  );
  DIG_Add #(
    .Bits(32)
  )
  DIG_Add_i9 (
    .a( s16 ),
    .b( s15 ),
    .c_i( 1'b0 ),
    .s( s0 )
  );
  assign pc = pc_temp;
endmodule
module DIG_RegisterFile
(
input [31:0] Din,
input we,
input [4:0] Rw,
input C,
input [4:0] Ra,
input [4:0] Rb,
output [31:0] Da,
output [31:0] Db
);

reg [31:0] memory[0:31];

assign Da = memory[Ra];
assign Db = memory[Rb];
initial
begin
memory[0]=0;
memory[1]=0;
memory[2]=0;
memory[3]=0;
memory[4]=0;
memory[5]=0;
memory[6]=0;
memory[7]=0;
memory[8]=0;
memory[9]=0;
memory[10]=0;
memory[11]=0;
memory[12]=0;
memory[13]=0;
memory[14]=0;
memory[15]=0;
memory[16]=0;
memory[17]=0;
memory[18]=0;
memory[19]=0;
memory[20]=0;
memory[21]=0;
memory[22]=0;
memory[23]=0;
memory[24]=0;
memory[25]=0;
memory[26]=0;
memory[27]=0;
memory[28]=0;
memory[29]=0;
memory[30]=0;
memory[31]=0;
end

always @ (posedge C) begin
if (we)
memory[Rw] <= Din;
end
endmodule

module DIG_RAMDualPort
#(
    parameter Bits = 8,
    parameter AddrBits = 4
)
(
  input [(AddrBits-1):0] A,
  input [(Bits-1):0] Din,
  input str,
  input C,
  input ld,
  output [(Bits-1):0] D
);
  reg [(Bits-1):0] memory[0:((1 << AddrBits) - 1)];

  assign D = ld? memory[A] : 'hz;

  always @ (posedge C) begin
    if (str)
      memory[A] <= Din;
  end
endmodule

module DIG_ROM_512X32 (
    input [8:0] A,
    input sel,
    output reg [31:0] D
);
    reg [31:0] my_rom [0:44];

    always @ (*) begin
        if (~sel)
            D = 32'hz;
        else if (A > 9'h2c)
            D = 32'h0;
        else
            D = my_rom[A];
    end

    initial begin
        my_rom[0] = 32'h0;
        my_rom[1] = 32'hfffff0b7;
        my_rom[2] = 32'h400093;
        my_rom[3] = 32'h40016f;
        my_rom[4] = 32'h158513;
        my_rom[5] = 32'hfeb50fe3;
        my_rom[6] = 32'hfff20193;
        my_rom[7] = 32'h318233;
        my_rom[8] = 32'h308023;
        my_rom[9] = 32'h309023;
        my_rom[10] = 32'h30a023;
        my_rom[11] = 32'h40a223;
        my_rom[12] = 32'h402383;
        my_rom[13] = 32'h800403;
        my_rom[14] = 32'h801403;
        my_rom[15] = 32'h804403;
        my_rom[16] = 32'h805403;
        my_rom[17] = 32'h802403;
        my_rom[18] = 32'hff3a413;
        my_rom[19] = 32'hffe3b413;
        my_rom[20] = 32'hfff44413;
        my_rom[21] = 32'h247493;
        my_rom[22] = 32'h249513;
        my_rom[23] = 32'h1f4d593;
        my_rom[24] = 32'h25d593;
        my_rom[25] = 32'h40125613;
        my_rom[26] = 32'h40460633;
        my_rom[27] = 32'hc616b3;
        my_rom[28] = 32'hc42733;
        my_rom[29] = 32'hc43733;
        my_rom[30] = 32'h864733;
        my_rom[31] = 32'he6d7b3;
        my_rom[32] = 32'h40f75733;
        my_rom[33] = 32'hd77733;
        my_rom[34] = 32'hc76833;
        my_rom[35] = 32'h200713;
        my_rom[36] = 32'h11d873;
        my_rom[37] = 32'h11d873;
        my_rom[38] = 32'h810f3;
        my_rom[39] = 32'h710f3;
        my_rom[40] = 32'ha973;
        my_rom[41] = 32'h25973;
        my_rom[42] = 32'h1039f3;
        my_rom[43] = 32'h10f9f3;
        my_rom[44] = 32'he7;
    end
endmodule


module CompSigned #(
    parameter Bits = 1
)
(
    input [(Bits -1):0] a,
    input [(Bits -1):0] b,
    output \> ,
    output \= ,
    output \<
);
    assign \> = $signed(a) > $signed(b);
    assign \= = $signed(a) == $signed(b);
    assign \< = $signed(a) < $signed(b);
endmodule


module CompUnsigned #(
    parameter Bits = 1
)
(
    input [(Bits -1):0] a,
    input [(Bits -1):0] b,
    output \> ,
    output \= ,
    output \<
);
    assign \> = a > b;
    assign \= = a == b;
    assign \< = a < b;
endmodule

module PriorityEncoder3 (
    input in0,
    input in1,
    input in2,
    input in3,
    input in4,
    input in5,
    input in6,
    input in7,
    output reg [2:0] num,
    output any
);
    always @ (*) begin
        if (in7 == 1'b1)
            num = 3'h7;
        else if (in6 == 1'b1)
            num = 3'h6;
        else if (in5 == 1'b1)
            num = 3'h5;
        else if (in4 == 1'b1)
            num = 3'h4;
        else if (in3 == 1'b1)
            num = 3'h3;
        else if (in2 == 1'b1)
            num = 3'h2;
        else if (in1 == 1'b1)
            num = 3'h1;
        else 
            num = 3'h0;
    end

    assign any = in0 | in1 | in2 | in3 | in4 | in5 | in6 | in7;
endmodule

module PriorityEncoder2 (
    input in0,
    input in1,
    input in2,
    input in3,
    output reg [1:0] num,
    output any
);
    always @ (*) begin
        if (in3 == 1'b1)
            num = 2'h3;
        else if (in2 == 1'b1)
            num = 2'h2;
        else if (in1 == 1'b1)
            num = 2'h1;
        else 
            num = 2'h0;
    end

    assign any = in0 | in1 | in2 | in3;
endmodule

module PriorityEncoder4 (
    input in0,
    input in1,
    input in2,
    input in3,
    input in4,
    input in5,
    input in6,
    input in7,
    input in8,
    input in9,
    input in10,
    input in11,
    input in12,
    input in13,
    input in14,
    input in15,
    output reg [3:0] num,
    output any
);
    always @ (*) begin
        if (in15 == 1'b1)
            num = 4'hf;
        else if (in14 == 1'b1)
            num = 4'he;
        else if (in13 == 1'b1)
            num = 4'hd;
        else if (in12 == 1'b1)
            num = 4'hc;
        else if (in11 == 1'b1)
            num = 4'hb;
        else if (in10 == 1'b1)
            num = 4'ha;
        else if (in9 == 1'b1)
            num = 4'h9;
        else if (in8 == 1'b1)
            num = 4'h8;
        else if (in7 == 1'b1)
            num = 4'h7;
        else if (in6 == 1'b1)
            num = 4'h6;
        else if (in5 == 1'b1)
            num = 4'h5;
        else if (in4 == 1'b1)
            num = 4'h4;
        else if (in3 == 1'b1)
            num = 4'h3;
        else if (in2 == 1'b1)
            num = 4'h2;
        else if (in1 == 1'b1)
            num = 4'h1;
        else 
            num = 4'h0;
    end

    assign any = in0 | in1 | in2 | in3 | in4 | in5 | in6 | in7 | in8 | in9 | in10 | in11 | in12 | in13 | in14 | in15;
endmodule

module PriorityEncoder1 (
    input in0,
    input in1,
    output reg [0:0] num,
    output any
);
    always @ (*) begin
        if (in1 == 1'b1)
            num = 1'h1;
        else 
            num = 1'h0;
    end

    assign any = in0 | in1;
endmodule


module \monocycle-controller  (
  input [31:0] ins,
  output [1:0] pcw, // pc?????????pc+4,jal bxx pc+????jalr pc+rs?
                    // 0->pc+4
                    // 1->jarl
                    // 2->jal
                    // 3->bxx
  output bxx,
  output [3:0] a_op,
  output [2:0] a_x,
  output [2:0] a_y,
  output siC, // aluy?SEimm ???12?????????????????
              // 0????12??1????,sw,sh,sb???
  output rwe,
  output [1:0] rws, // ??????????ram?alu
  output mw, // memory write
  output [2:0] mRF, // memory Read format
  output [1:0] mWF, // memory write format
  output mR, // memory read
  output csrR,
  output csrW
);
  wire [2:0] fun3;
  wire [6:0] fun7;
  wire ecallBreak;
  wire [7:0] op;
  wire lui;
  wire auipc;
  wire jal;
  wire jalr;
  wire \op==63 ;
  wire \op==03 ;
  wire \op==23 ;
  wire \op==13 ;
  wire \op==33 ;
  wire \op==0F ;
  wire \op==73 ;
  wire s0;
  wire beq;
  wire s1;
  wire bne;
  wire s2;
  wire blt;
  wire s3;
  wire bge;
  wire s4;
  wire bltu;
  wire s5;
  wire bgeu;
  wire s6;
  wire sb;
  wire s7;
  wire sh;
  wire s8;
  wire sw;
  wire s9;
  wire lb;
  wire s10;
  wire lh;
  wire s11;
  wire lw;
  wire s12;
  wire lbu;
  wire s13;
  wire lhu;
  wire s14;
  wire addi;
  wire s15;
  wire slti;
  wire s16;
  wire sltiu;
  wire s17;
  wire xori;
  wire s18;
  wire ori;
  wire s19;
  wire andi;
  wire s20;
  wire slli;
  wire s21;
  wire s22;
  wire srli;
  wire s23;
  wire s24;
  wire srai;
  wire s25;
  wire s26;
  wire add;
  wire s27;
  wire s28;
  wire sub;
  wire s29;
  wire sll;
  wire s30;
  wire slt;
  wire s31;
  wire sltu;
  wire s32;
  wire \xor ;
  wire s33;
  wire s34;
  wire srl;
  wire s35;
  wire s36;
  wire sra;
  wire s37;
  wire \or ;
  wire s38;
  wire \and ;
  wire s39;
  wire fence;
  wire s40;
  wire fencei;
  wire s41;
  wire s42;
  wire ecall;
  wire s43;
  wire s44;
  wire ebreak;
  wire s45;
  wire csrrw;
  wire s46;
  wire csrrs;
  wire s47;
  wire csrrc;
  wire s48;
  wire csrrwi;
  wire s49;
  wire csrrsi;
  wire s50;
  wire csrrci;
  wire s51;
  wire s52;
  wire s53;
  wire s54;
  wire s55;
  wire s56;
  wire s57;
  wire s58;
  wire s59;
  wire s60;
  wire s61;
  wire s62;
  wire s63;
  wire s64;
  wire s65;
  wire s66;
  wire s67;
  wire s68;
  wire s69;
  wire s70;
  wire s71;
  wire csrW_temp;
  wire s72;
  wire s73;
  wire s74;
  assign op[6:0] = ins[6:0];
  assign op[7] = 1'b0;
  assign fun3 = ins[14:12];
  assign fun7 = ins[31:25];
  assign ecallBreak = ins[20];
  CompSigned #(
    .Bits(8)
  )
  CompSigned_i0 (
    .a( op ),
    .b( 8'b110111 ),
    .\= ( lui )
  );
  CompSigned #(
    .Bits(8)
  )
  CompSigned_i1 (
    .a( op ),
    .b( 8'b10111 ),
    .\= ( auipc )
  );
  CompSigned #(
    .Bits(8)
  )
  CompSigned_i2 (
    .a( op ),
    .b( 8'b1101111 ),
    .\= ( jal )
  );
  CompSigned #(
    .Bits(8)
  )
  CompSigned_i3 (
    .a( op ),
    .b( 8'b1100111 ),
    .\= ( jalr )
  );
  CompSigned #(
    .Bits(8)
  )
  CompSigned_i4 (
    .a( op ),
    .b( 8'b1100011 ),
    .\= ( \op==63  )
  );
  CompSigned #(
    .Bits(8)
  )
  CompSigned_i5 (
    .a( op ),
    .b( 8'b11 ),
    .\= ( \op==03  )
  );
  CompSigned #(
    .Bits(8)
  )
  CompSigned_i6 (
    .a( op ),
    .b( 8'b100011 ),
    .\= ( \op==23  )
  );
  CompSigned #(
    .Bits(8)
  )
  CompSigned_i7 (
    .a( op ),
    .b( 8'b10011 ),
    .\= ( \op==13  )
  );
  CompUnsigned #(
    .Bits(8)
  )
  CompUnsigned_i8 (
    .a( op ),
    .b( 8'b110011 ),
    .\= ( \op==33  )
  );
  CompSigned #(
    .Bits(8)
  )
  CompSigned_i9 (
    .a( op ),
    .b( 8'b1111 ),
    .\= ( \op==0F  )
  );
  CompSigned #(
    .Bits(8)
  )
  CompSigned_i10 (
    .a( op ),
    .b( 8'b1110011 ),
    .\= ( \op==73  )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i11 (
    .a( fun3 ),
    .b( 3'b0 ),
    .\= ( s0 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i12 (
    .a( fun3 ),
    .b( 3'b1 ),
    .\= ( s1 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i13 (
    .a( fun3 ),
    .b( 3'b100 ),
    .\= ( s2 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i14 (
    .a( fun3 ),
    .b( 3'b101 ),
    .\= ( s3 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i15 (
    .a( fun3 ),
    .b( 3'b110 ),
    .\= ( s4 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i16 (
    .a( fun3 ),
    .b( 3'b111 ),
    .\= ( s5 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i17 (
    .a( fun3 ),
    .b( 3'b0 ),
    .\= ( s6 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i18 (
    .a( fun3 ),
    .b( 3'b1 ),
    .\= ( s7 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i19 (
    .a( fun3 ),
    .b( 3'b10 ),
    .\= ( s8 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i20 (
    .a( fun3 ),
    .b( 3'b0 ),
    .\= ( s9 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i21 (
    .a( fun3 ),
    .b( 3'b1 ),
    .\= ( s10 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i22 (
    .a( fun3 ),
    .b( 3'b10 ),
    .\= ( s11 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i23 (
    .a( fun3 ),
    .b( 3'b100 ),
    .\= ( s12 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i24 (
    .a( fun3 ),
    .b( 3'b101 ),
    .\= ( s13 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i25 (
    .a( fun3 ),
    .b( 3'b0 ),
    .\= ( s14 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i26 (
    .a( fun3 ),
    .b( 3'b10 ),
    .\= ( s15 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i27 (
    .a( fun3 ),
    .b( 3'b11 ),
    .\= ( s16 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i28 (
    .a( fun3 ),
    .b( 3'b100 ),
    .\= ( s17 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i29 (
    .a( fun3 ),
    .b( 3'b110 ),
    .\= ( s18 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i30 (
    .a( fun3 ),
    .b( 3'b111 ),
    .\= ( s19 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i31 (
    .a( fun3 ),
    .b( 3'b1 ),
    .\= ( s20 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i32 (
    .a( fun3 ),
    .b( 3'b101 ),
    .\= ( s21 )
  );
  CompUnsigned #(
    .Bits(7)
  )
  CompUnsigned_i33 (
    .a( fun7 ),
    .b( 7'b0 ),
    .\= ( s22 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i34 (
    .a( fun3 ),
    .b( 3'b101 ),
    .\= ( s23 )
  );
  CompUnsigned #(
    .Bits(7)
  )
  CompUnsigned_i35 (
    .a( fun7 ),
    .b( 7'b100000 ),
    .\= ( s24 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i36 (
    .a( fun3 ),
    .b( 3'b0 ),
    .\= ( s25 )
  );
  CompUnsigned #(
    .Bits(7)
  )
  CompUnsigned_i37 (
    .a( fun7 ),
    .b( 7'b0 ),
    .\= ( s26 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i38 (
    .a( fun3 ),
    .b( 3'b0 ),
    .\= ( s27 )
  );
  CompUnsigned #(
    .Bits(7)
  )
  CompUnsigned_i39 (
    .a( fun7 ),
    .b( 7'b100000 ),
    .\= ( s28 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i40 (
    .a( fun3 ),
    .b( 3'b1 ),
    .\= ( s29 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i41 (
    .a( fun3 ),
    .b( 3'b10 ),
    .\= ( s30 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i42 (
    .a( fun3 ),
    .b( 3'b11 ),
    .\= ( s31 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i43 (
    .a( fun3 ),
    .b( 3'b100 ),
    .\= ( s32 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i44 (
    .a( fun3 ),
    .b( 3'b101 ),
    .\= ( s33 )
  );
  CompUnsigned #(
    .Bits(7)
  )
  CompUnsigned_i45 (
    .a( fun7 ),
    .b( 7'b0 ),
    .\= ( s34 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i46 (
    .a( fun3 ),
    .b( 3'b101 ),
    .\= ( s35 )
  );
  CompUnsigned #(
    .Bits(7)
  )
  CompUnsigned_i47 (
    .a( fun7 ),
    .b( 7'b100000 ),
    .\= ( s36 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i48 (
    .a( fun3 ),
    .b( 3'b110 ),
    .\= ( s37 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i49 (
    .a( fun3 ),
    .b( 3'b111 ),
    .\= ( s38 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i50 (
    .a( fun3 ),
    .b( 3'b0 ),
    .\= ( s39 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i51 (
    .a( fun3 ),
    .b( 3'b1 ),
    .\= ( s40 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i52 (
    .a( fun3 ),
    .b( 3'b0 ),
    .\= ( s41 )
  );
  CompUnsigned #(
    .Bits(1)
  )
  CompUnsigned_i53 (
    .a( ecallBreak ),
    .b( 1'b0 ),
    .\= ( s42 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i54 (
    .a( fun3 ),
    .b( 3'b0 ),
    .\= ( s43 )
  );
  CompUnsigned #(
    .Bits(1)
  )
  CompUnsigned_i55 (
    .a( ecallBreak ),
    .b( 1'b1 ),
    .\= ( s44 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i56 (
    .a( fun3 ),
    .b( 3'b1 ),
    .\= ( s45 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i57 (
    .a( fun3 ),
    .b( 3'b10 ),
    .\= ( s46 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i58 (
    .a( fun3 ),
    .b( 3'b11 ),
    .\= ( s47 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i59 (
    .a( fun3 ),
    .b( 3'b101 ),
    .\= ( s48 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i60 (
    .a( fun3 ),
    .b( 3'b110 ),
    .\= ( s49 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i61 (
    .a( fun3 ),
    .b( 3'b111 ),
    .\= ( s50 )
  );
  assign beq = (s0 & \op==63 );
  assign bne = (s1 & \op==63 );
  assign blt = (s2 & \op==63 );
  assign bge = (s3 & \op==63 );
  assign bltu = (s4 & \op==63 );
  assign bgeu = (s5 & \op==63 );
  assign sb = (s6 & \op==23 );
  assign sh = (s7 & \op==23 );
  assign sw = (s8 & \op==23 );
  assign lb = (s9 & \op==03 );
  assign lh = (s10 & \op==03 );
  assign lw = (s11 & \op==03 );
  assign lbu = (s12 & \op==03 );
  assign lhu = (s13 & \op==03 );
  assign addi = (s14 & \op==13 );
  assign slti = (s15 & \op==13 );
  assign sltiu = (s16 & \op==13 );
  assign xori = (s17 & \op==13 );
  assign ori = (s18 & \op==13 );
  assign andi = (s19 & \op==13 );
  assign slli = (s20 & \op==13 );
  assign srli = (s21 & s22 & \op==13 );
  assign srai = (s23 & s24 & \op==13 );
  assign add = (s25 & s26 & \op==33 );
  assign sub = (s27 & s28 & \op==33 );
  assign sll = (s29 & \op==33 );
  assign slt = (s30 & \op==33 );
  assign sltu = (s31 & \op==33 );
  assign \xor  = (s32 & \op==33 );
  assign srl = (s33 & s34 & \op==33 );
  assign sra = (s35 & s36 & \op==33 );
  assign \or  = (s37 & \op==33 );
  assign \and  = (s38 & \op==33 );
  assign fence = (s39 & \op==0F );
  assign fencei = (s40 & \op==0F );
  assign ecall = (s41 & s42 & \op==73 );
  assign ebreak = (s43 & s44 & \op==73 );
  assign csrrw = (s45 & \op==73 );
  assign csrrs = (s46 & \op==73 );
  assign csrrc = (s47 & \op==73 );
  assign csrrwi = (s48 & \op==73 );
  assign csrrsi = (s49 & \op==73 );
  assign csrrci = (s50 & \op==73 );
  assign s65 = (lui | auipc);
  assign s70 = (auipc | jalr | jal);
  assign s69 = (jal | jalr);
  assign rwe = (srai | csrrci | csrrsi | csrrwi | csrrc | csrrs | csrrw | \and  | \or  | sra | srl | \xor  | sltu | slt | sll | sub | add | srli | slli | andi | ori | xori | sltiu | slti | addi | lhu | lbu | lw | lh | lb | jalr | jal | auipc | lui);
  assign s51 = (lb | lbu | lw | lh | lhu);
  assign s52 = (csrrw | csrrs | csrrc | csrrwi | csrrsi | csrrci);
  assign s53 = (addi | auipc | add | jal | jalr | lw | lh | lhu | lb | lbu | sw | sh | sb);
  assign s54 = (slli | sll);
  assign s55 = (srli | srl);
  assign s56 = (srai | sra);
  assign s57 = (andi | \and  | csrrc | csrrci);
  assign s58 = (ori | \or  | csrrs | csrrsi);
  assign s59 = (xori | \xor );
  assign s60 = (slti | slt | blt);
  assign s61 = (sltiu | bltu | sltu);
  assign s63 = (addi | slti | sltiu | andi | ori | xori | lb | lw | lh | lhu | sw | sh | sb | lbu);
  assign s64 = (slli | srli | srai);
  assign s66 = (add | sub | slt | sltu | \and  | \or  | \xor  | beq | bne | blt | bltu | bge | bgeu);
  assign s67 = (sll | srl | sra);
  assign s68 = (csrrw | csrrs | csrrc | csrrsi | csrrci);
  assign s71 = (csrrsi | csrrwi);
  assign csrW_temp = (csrrw | csrrwi | csrrs | csrrsi | csrrc | csrrci);
  assign s72 = (addi | slti | sltiu | andi | ori | xori | lw | lh | lhu | lb | lbu);
  assign s73 = (sw | sh | sb);
  assign s62 = (csrrw | csrrwi);
  // memRF
  PriorityEncoder3 PriorityEncoder3_i62 (
    .in0( lw ),
    .in1( lh ),
    .in2( lhu ),
    .in3( lb ),
    .in4( lbu ),
    .in5( 1'b0 ),
    .in6( 1'b0 ),
    .in7( 1'b0 ),
    .num( mRF )
  );
  // memWFormat
  PriorityEncoder2 PriorityEncoder2_i63 (
    .in0( sw ),
    .in1( sh ),
    .in2( sb ),
    .in3( 1'b0 ),
    .num( mWF )
  );
  assign mw = (sw | sh | sb);
  assign s74 = (beq | bne | blt | bltu | bge | bgeu);
  assign mR = (lw | lh | lhu | lb | lbu);
  assign bxx = (beq | bne | blt | bltu | bge | bgeu);
  // rwsPri
  PriorityEncoder2 PriorityEncoder2_i64 (
    .in0( 1'b1 ),
    .in1( s51 ),
    .in2( s52 ),
    .in3( 1'b0 ),
    .num( rws )
  );
  // aluopPri
  PriorityEncoder4 PriorityEncoder4_i65 (
    .in0( s53 ),
    .in1( sub ),
    .in2( s54 ),
    .in3( s55 ),
    .in4( s56 ),
    .in5( s57 ),
    .in6( s58 ),
    .in7( s59 ),
    .in8( bge ),
    .in9( s60 ),
    .in10( beq ),
    .in11( bgeu ),
    .in12( s61 ),
    .in13( bne ),
    .in14( lui ),
    .in15( s62 ),
    .num( a_op )
  );
  // aluyPri
  PriorityEncoder3 PriorityEncoder3_i66 (
    .in0( s63 ),
    .in1( s64 ),
    .in2( s65 ),
    .in3( s66 ),
    .in4( s67 ),
    .in5( s68 ),
    .in6( s69 ),
    .in7( csrrwi ),
    .num( a_y )
  );
  // aluxPri
  PriorityEncoder3 PriorityEncoder3_i67 (
    .in0( 1'b1 ),
    .in1( s70 ),
    .in2( s71 ),
    .in3( csrrc ),
    .in4( csrrci ),
    .in5( lui ),
    .in6( 1'b0 ),
    .in7( 1'b0 ),
    .num( a_x )
  );
  PriorityEncoder1 PriorityEncoder1_i68 (
    .in0( s72 ),
    .in1( s73 ),
    .num( siC )
  );
  // pcwPri
  PriorityEncoder2 PriorityEncoder2_i69 (
    .in0( 1'b1 ),
    .in1( jal ),
    .in2( s74 ),
    .in3( jalr ),
    .num( pcw )
  );
  assign csrR = csrW_temp;
  assign csrW = csrW_temp;
endmodule

module Mux_8x1_NBits #(
    parameter Bits = 2
)
(
    input [2:0] sel,
    input [(Bits - 1):0] in_0,
    input [(Bits - 1):0] in_1,
    input [(Bits - 1):0] in_2,
    input [(Bits - 1):0] in_3,
    input [(Bits - 1):0] in_4,
    input [(Bits - 1):0] in_5,
    input [(Bits - 1):0] in_6,
    input [(Bits - 1):0] in_7,
    output reg [(Bits - 1):0] out
);
    always @ (*) begin
        case (sel)
            3'h0: out = in_0;
            3'h1: out = in_1;
            3'h2: out = in_2;
            3'h3: out = in_3;
            3'h4: out = in_4;
            3'h5: out = in_5;
            3'h6: out = in_6;
            3'h7: out = in_7;
            default:
                out = 'h0;
        endcase
    end
endmodule


module \monocycle-aluI  (
  input [2:0] axI, // aluX input
  input [2:0] ayI, // aluy input
  input siC,
  input [31:0] opc,
  input [31:0] ins, // instruction
  input [31:0] rs1,
  input [31:0] rs2,
  input [31:0] csrIn,
  output [31:0] x,
  output [31:0] y
);
  wire [31:0] s0;
  wire [31:0] s1;
  wire [31:0] s2;
  wire [31:0] s3;
  wire [31:0] s4;
  wire [31:0] s5;
  wire [31:0] s6;
  wire [31:0] s7;
  wire [31:0] s8;
  wire [11:0] s9;
  wire s10;
  wire [19:0] s11;
  wire s12;
  wire [19:0] s13;
  assign s0[4:0] = ins[19:15];
  assign s0[31:5] = 27'b0;
  assign s9[11:5] = ins[31:25];
  assign s9[4:0] = ins[11:7];
  assign s4[4:0] = ins[24:20];
  assign s4[31:5] = 27'b0;
  assign s5[31:12] = ins[31:12];
  assign s5[11:0] = 12'b0;
  assign s6[4:0] = rs2[4:0];
  assign s6[31:5] = 27'b0;
  assign s1 = ~ rs1;
  assign s10 = ins[31];
  assign s12 = ins[31];
  assign s2 = ~ s0;
  Mux_2x1_NBits #(
    .Bits(20)
  )
  Mux_2x1_NBits_i0 (
    .sel( s10 ),
    .in_0( 20'b0 ),
    .in_1( 20'b11111111111111111111 ),
    .out( s11 )
  );
  Mux_2x1_NBits #(
    .Bits(20)
  )
  Mux_2x1_NBits_i1 (
    .sel( s12 ),
    .in_0( 20'b0 ),
    .in_1( 20'b11111111111111111111 ),
    .out( s13 )
  );
  Mux_8x1_NBits #(
    .Bits(32)
  )
  Mux_8x1_NBits_i2 (
    .sel( axI ),
    .in_0( rs1 ),
    .in_1( opc ),
    .in_2( s0 ),
    .in_3( s1 ),
    .in_4( s2 ),
    .in_5( 32'b0 ),
    .in_6( 32'b0 ),
    .in_7( 32'b0 ),
    .out( x )
  );
  assign s7[11:0] = ins[31:20];
  assign s7[31:12] = s11;
  assign s8[11:0] = s9;
  assign s8[31:12] = s13;
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i3 (
    .sel( siC ),
    .in_0( s7 ),
    .in_1( s8 ),
    .out( s3 )
  );
  Mux_8x1_NBits #(
    .Bits(32)
  )
  Mux_8x1_NBits_i4 (
    .sel( ayI ),
    .in_0( s3 ),
    .in_1( s4 ),
    .in_2( s5 ),
    .in_3( rs2 ),
    .in_4( s6 ),
    .in_5( csrIn ),
    .in_6( 32'b100 ),
    .in_7( 32'b0 ),
    .out( y )
  );
endmodule

module DIG_Sub #(
    parameter Bits = 2
)
(
    input [(Bits-1):0] a,
    input [(Bits-1):0] b,
    input c_i,
    output [(Bits-1):0] s,
    output c_o
);
    wire [Bits:0] temp;

    assign temp = a - b - c_i;
    assign s = temp[(Bits-1):0];
    assign c_o = temp[Bits];
endmodule

module SignedShiftLeftL #(
parameter Bits = 4,
parameter shiftBits=2
)
(
    input [(Bits-1):0] in,
    input [(shiftBits-1):0] shift,
    output [(Bits - 1):0] out
);

reg[Bits-1:0] regOut;
reg[0:0] buma;
initial
begin
buma=1;
regOut=0;
end
always @ (*) begin
    if(shift[shiftBits-1])
        begin
        regOut=(in >>(~shift+buma));
        end
    else
        begin
        regOut = (in << shift);
        end
    end
assign out = regOut;

endmodule
module SignedShiftRightL #(
parameter Bits = 4,
parameter shiftBits=2
)
(
input [(Bits-1):0] in,
input [(shiftBits-1):0] shift,
output [(Bits - 1):0] out
);

    reg[Bits-1:0] regOut;
reg[0:0] buma;
initial
begin
buma=1;
regOut=0;
end
always @ (*) begin
    if(shift[shiftBits-1])
        begin
        regOut=(in <<(~shift+buma));
        end
    else
        begin
        regOut = (in >> shift);
        end
    end
assign out = regOut;

endmodule
module SignedShiftRightA #(
parameter Bits = 4,
parameter shiftBits=2
)
(
    input [(Bits-1):0] in,
    input [(shiftBits-1):0] shift,
    output [(Bits - 1):0] out
);

reg[Bits-1:0] regOut;
reg[0:0] buma;
initial
    begin
    buma=1;
    regOut=0;
    end
always @ (*) begin
    if(shift[shiftBits-1])
        begin
        regOut=(in <<(~shift+buma));
        end
    else
        begin
        regOut = ($signed(in)>>>shift);
        end
    end
assign out = regOut;

endmodule


module Mux_16x1_NBits #(
    parameter Bits = 2
)
(
    input [3:0] sel,
    input [(Bits - 1):0] in_0,
    input [(Bits - 1):0] in_1,
    input [(Bits - 1):0] in_2,
    input [(Bits - 1):0] in_3,
    input [(Bits - 1):0] in_4,
    input [(Bits - 1):0] in_5,
    input [(Bits - 1):0] in_6,
    input [(Bits - 1):0] in_7,
    input [(Bits - 1):0] in_8,
    input [(Bits - 1):0] in_9,
    input [(Bits - 1):0] in_10,
    input [(Bits - 1):0] in_11,
    input [(Bits - 1):0] in_12,
    input [(Bits - 1):0] in_13,
    input [(Bits - 1):0] in_14,
    input [(Bits - 1):0] in_15,
    output reg [(Bits - 1):0] out
);
    always @ (*) begin
        case (sel)
            4'h0: out = in_0;
            4'h1: out = in_1;
            4'h2: out = in_2;
            4'h3: out = in_3;
            4'h4: out = in_4;
            4'h5: out = in_5;
            4'h6: out = in_6;
            4'h7: out = in_7;
            4'h8: out = in_8;
            4'h9: out = in_9;
            4'ha: out = in_10;
            4'hb: out = in_11;
            4'hc: out = in_12;
            4'hd: out = in_13;
            4'he: out = in_14;
            4'hf: out = in_15;
            default:
                out = 'h0;
        endcase
    end
endmodule


module \monocycle-alu  (
  input [3:0] alu_op,
  input [31:0] x,
  input [31:0] y,
  output [31:0] rst
);
  wire [31:0] r1;
  wire [31:0] r2;
  wire [4:0] s0;
  wire [31:0] r3;
  wire [31:0] r4;
  wire [31:0] r5;
  wire [31:0] r6;
  wire [31:0] r7;
  wire [31:0] r8;
  wire s1;
  wire s2;
  wire s3;
  wire s4;
  wire s5;
  wire s6;
  wire [31:0] r9;
  wire [31:0] r10;
  wire [31:0] r11;
  wire [31:0] r12;
  wire [31:0] r13;
  wire [31:0] r14;
  // +
  DIG_Add #(
    .Bits(32)
  )
  DIG_Add_i0 (
    .a( x ),
    .b( y ),
    .c_i( 1'b0 ),
    .s( r1 )
  );
  // -
  DIG_Sub #(
    .Bits(32)
  )
  DIG_Sub_i1 (
    .a( x ),
    .b( y ),
    .c_i( 1'b0 ),
    .s( r2 )
  );
  assign r6 = (x & y);
  assign r7 = (x | y);
  assign r8 = (x ^ y);
  // s>=<
  CompSigned #(
    .Bits(32)
  )
  CompSigned_i2 (
    .a( x ),
    .b( y ),
    .\> ( s1 ),
    .\= ( s2 ),
    .\< ( s3 )
  );
  // >=<
  CompUnsigned #(
    .Bits(32)
  )
  CompUnsigned_i3 (
    .a( x ),
    .b( y ),
    .\> ( s4 ),
    .\= ( s5 ),
    .\< ( s6 )
  );
  assign s0 = y[4:0];
  // sll
  SignedShiftLeftL #(
    .Bits(32),
    .shiftBits(5)
  )
  SignedShiftLeftL_i4 (
    .in( x ),
    .shift( s0 ),
    .out( r3 )
  );
  // srl
  SignedShiftRightL #(
    .Bits(32),
    .shiftBits(5)
  )
  SignedShiftRightL_i5 (
    .in( x ),
    .shift( s0 ),
    .out( r4 )
  );
  // sra
  SignedShiftRightA #(
    .Bits(32),
    .shiftBits(5)
  )
  SignedShiftRightA_i6 (
    .in( x ),
    .shift( s0 ),
    .out( r5 )
  );
  assign r9[0] = (s1 | s2);
  assign r9[31:1] = 31'b0;
  assign r12[0] = (s4 | s5);
  assign r12[31:1] = 31'b0;
  assign r14[0] = ~ s5;
  assign r14[31:1] = 31'b0;
  assign r10[0] = s3;
  assign r10[31:1] = 31'b0;
  assign r11[0] = s2;
  assign r11[31:1] = 31'b0;
  assign r13[0] = s6;
  assign r13[31:1] = 31'b0;
  Mux_16x1_NBits #(
    .Bits(32)
  )
  Mux_16x1_NBits_i7 (
    .sel( alu_op ),
    .in_0( r1 ),
    .in_1( r2 ),
    .in_2( r3 ),
    .in_3( r4 ),
    .in_4( r5 ),
    .in_5( r6 ),
    .in_6( r7 ),
    .in_7( r8 ),
    .in_8( r9 ),
    .in_9( r10 ),
    .in_10( r11 ),
    .in_11( r12 ),
    .in_12( r13 ),
    .in_13( r14 ),
    .in_14( y ),
    .in_15( x ),
    .out( rst )
  );
endmodule

module \risc-v-monocycle-cpu  (
  input en,
  input clock,
  output [8:0] pcOut,
  output [7:0] ramDataOut,
  output [7:0] ramDataIn,
  output [7:0] csrRDataOut,
  output csrW,
  output csrR,
  output ramW,
  output ramR,
  output rwe,
  output [7:0] clkCount,
  output [7:0] csrRDataIn
);
  wire [31:0] s0;
  wire [1:0] s1;
  wire s2;
  wire [3:0] s3;
  wire [2:0] s4;
  wire [2:0] s5;
  wire s6;
  wire rwe_temp;
  wire [1:0] s7;
  wire ramW_temp;
  wire [2:0] s8;
  wire [1:0] s9;
  wire ramR_temp;
  wire csrR_temp;
  wire csrW_temp;
  wire [31:0] s10;
  wire [31:0] s11;
  wire [31:0] s12;
  wire [31:0] s13;
  wire [31:0] s14;
  wire [31:0] s15;
  wire [31:0] s16;
  wire s17;
  wire [31:0] s18;
  wire [4:0] s19;
  wire s20;
  wire [4:0] s21;
  wire [4:0] s22;
  wire [8:0] pcOut_temp;
  wire [7:0] s23;
  wire [31:0] s24;
  wire s25;
  wire [31:0] s26;
  wire [7:0] s27;
  wire s28;
  wire [31:0] s29;
  wire [31:0] s30;
  wire [31:0] s31;
  wire s32;
  wire [23:0] s33;
  wire [7:0] s34;
  wire [31:0] s35;
  wire s36;
  wire [15:0] s37;
  wire [15:0] s38;
  wire [31:0] s39;
  wire [31:0] s40;
  wire [31:0] s41;
  wire [31:0] s42;
  assign s20 = ~ clock;
  assign s28 = ~ clock;
  assign s25 = ~ clock;
  DIG_Counter_Nbit #(
    .Bits(8)
  )
  DIG_Counter_Nbit_i0 (
    .en( en ),
    .C( clock ),
    .clr( 1'b0 ),
    .out( clkCount )
  );
  \monocycle-pc  \monocycle-pc_i1 (
    .instr( s0 ),
    .pcw( s1 ),
    .bxx( s2 ),
    .clock( clock ),
    .pcen( en ),
    .rs1( s11 ),
    .result( s17 ),
    .pc( s10 )
  );
  // regsFile
  DIG_RegisterFile DIG_RegisterFile_i2 (
    .Din( s18 ),
    .we( rwe_temp ),
    .Rw( s19 ),
    .C( s20 ),
    .Ra( s21 ),
    .Rb( s22 ),
    .Da( s11 ),
    .Db( s12 )
  );
  // cpuRam
  DIG_RAMDualPort #(
    .Bits(32),
    .AddrBits(8)
  )
  DIG_RAMDualPort_i3 (
    .A( s23 ),
    .Din( s24 ),
    .str( ramW_temp ),
    .C( s25 ),
    .ld( ramR_temp ),
    .D( s26 )
  );
  // csr
  DIG_RAMDualPort #(
    .Bits(32),
    .AddrBits(8)
  )
  DIG_RAMDualPort_i4 (
    .A( s27 ),
    .Din( s16 ),
    .str( csrW_temp ),
    .C( s28 ),
    .ld( csrR_temp ),
    .D( s13 )
  );
  assign s30[15:0] = s12[15:0];
  assign s30[31:16] = 16'b0;
  assign s31[7:0] = s12[7:0];
  assign s31[31:8] = 24'b0;
  assign s29 = s12[31:0];
  assign s38 = s26[15:0];
  assign s34 = s26[7:0];
  assign pcOut_temp = s10[10:2];
  assign csrRDataOut = s13[7:0];
  // cpuRom
  DIG_ROM_512X32 DIG_ROM_512X32_i5 (
    .A( pcOut_temp ),
    .sel( 1'b1 ),
    .D( s0 )
  );
  assign s40[31:16] = 16'b0;
  assign s40[15:0] = s38;
  assign s41[7:0] = s34;
  assign s41[31:8] = 24'b0;
  assign s36 = s38[15];
  assign s32 = s34[7];
  \monocycle-controller  \monocycle-controller_i6 (
    .ins( s0 ),
    .pcw( s1 ),
    .bxx( s2 ),
    .a_op( s3 ),
    .a_x( s4 ),
    .a_y( s5 ),
    .siC( s6 ),
    .rwe( rwe_temp ),
    .rws( s7 ),
    .mw( ramW_temp ),
    .mRF( s8 ),
    .mWF( s9 ),
    .mR( ramR_temp ),
    .csrR( csrR_temp ),
    .csrW( csrW_temp )
  );
  Mux_2x1_NBits #(
    .Bits(24)
  )
  Mux_2x1_NBits_i7 (
    .sel( s32 ),
    .in_0( 24'b0 ),
    .in_1( 24'b111111111111111111111111 ),
    .out( s33 )
  );
  Mux_2x1_NBits #(
    .Bits(16)
  )
  Mux_2x1_NBits_i8 (
    .sel( s36 ),
    .in_0( 16'b0 ),
    .in_1( 16'b1111111111111111 ),
    .out( s37 )
  );
  assign s19 = s0[11:7];
  assign s21 = s0[19:15];
  assign s22 = s0[24:20];
  assign s27 = s0[27:20];
  \monocycle-aluI  \monocycle-aluI_i9 (
    .axI( s4 ),
    .ayI( s5 ),
    .siC( s6 ),
    .opc( s10 ),
    .ins( s0 ),
    .rs1( s11 ),
    .rs2( s12 ),
    .csrIn( s13 ),
    .x( s14 ),
    .y( s15 )
  );
  Mux_4x1_NBits #(
    .Bits(32)
  )
  Mux_4x1_NBits_i10 (
    .sel( s9 ),
    .in_0( s29 ),
    .in_1( s30 ),
    .in_2( s31 ),
    .in_3( 32'b0 ),
    .out( s24 )
  );
  assign s35[7:0] = s34;
  assign s35[31:8] = s33;
  assign s39[15:0] = s38;
  assign s39[31:16] = s37;
  \monocycle-alu  \monocycle-alu_i11 (
    .alu_op( s3 ),
    .x( s14 ),
    .y( s15 ),
    .rst( s16 )
  );
  Mux_8x1_NBits #(
    .Bits(32)
  )
  Mux_8x1_NBits_i12 (
    .sel( s8 ),
    .in_0( s26 ),
    .in_1( s39 ),
    .in_2( s40 ),
    .in_3( s35 ),
    .in_4( s41 ),
    .in_5( 32'b0 ),
    .in_6( 32'b0 ),
    .in_7( 32'b0 ),
    .out( s42 )
  );
  assign ramDataIn = s24[7:0];
  Mux_4x1_NBits #(
    .Bits(32)
  )
  Mux_4x1_NBits_i13 (
    .sel( s7 ),
    .in_0( s16 ),
    .in_1( s42 ),
    .in_2( s13 ),
    .in_3( 32'b0 ),
    .out( s18 )
  );
  assign s17 = s16[0];
  assign s23 = s16[9:2];
  assign ramDataOut = s42[7:0];
  assign csrRDataIn = s16[7:0];
  assign pcOut = pcOut_temp;
  assign csrW = csrW_temp;
  assign csrR = csrR_temp;
  assign ramW = ramW_temp;
  assign ramR = ramR_temp;
  assign rwe = rwe_temp;
endmodule
