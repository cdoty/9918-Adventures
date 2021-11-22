/;
/; tniASM unofficial Z80 syntax definition file v1.0
\; by Albert Beevendorp
\;

%macro ADD B\ADD A,B\ %endmacro
%macro ADD C\ADD A,C\ %endmacro
%macro ADD D\ADD A,D\ %endmacro
%macro ADD E\ADD A,E\ %endmacro
%macro ADD H\ADD A,H\ %endmacro
%macro ADD L\ADD A,L\ %endmacro
%macro ADD [HL]\ADD A,[HL]\ %endmacro
%macro ADD [IX%n]\ADD A,[IX+#1]\ %endmacro
%macro ADD [IY%n]\ADD A,[IY+#1]\ %endmacro
%macro ADD A\ADD A,A\ %endmacro
%macro ADD %n\ADD A,#1\ %endmacro
%macro ADD IXH\ADD A,IXH\ %endmacro
%macro ADD IXL\ADD A,IXL\ %endmacro
%macro ADD IYH\ADD A,IYH\ %endmacro
%macro ADD IYL\ADD A,IYL\ %endmacro

%macro ADC B\ADC A,B\ %endmacro
%macro ADC C\ADC A,C\ %endmacro
%macro ADC D\ADC A,D\ %endmacro
%macro ADC E\ADC A,E\ %endmacro
%macro ADC H\ADC A,H\ %endmacro
%macro ADC L\ADC A,L\ %endmacro
%macro ADC [HL]\ADC A,[HL]\ %endmacro
%macro ADC [IX%n]\ADC A,[IX+#1]\ %endmacro
%macro ADC [IY%n]\ADC A,[IY+#1]\ %endmacro
%macro ADC A\ADC A,A\ %endmacro
%macro ADC %n\ADC A,#1\ %endmacro
%macro ADC IXH\ADC A,IXH\ %endmacro
%macro ADC IXL\ADC A,IXL\ %endmacro
%macro ADC IYH\ADC A,IYH\ %endmacro
%macro ADC IYL\ADC A,IYL\ %endmacro

%macro SUB A,B\SUB B\ %endmacro
%macro SUB A,C\SUB C\ %endmacro
%macro SUB A,D\SUB D\ %endmacro
%macro SUB A,E\SUB E\ %endmacro
%macro SUB A,H\SUB H\ %endmacro
%macro SUB A,L\SUB L\ %endmacro
%macro SUB A,[HL]\SUB [HL]\ %endmacro
%macro SUB A,[IX%n]\SUB [IX+#1]\ %endmacro
%macro SUB A,[IY%n]\SUB [IY+#1]\ %endmacro
%macro SUB A,A\SUB A\ %endmacro
%macro SUB A,%n\SUB #1\ %endmacro
%macro SUB A,IXH\SUB IXH\ %endmacro
%macro SUB A,IXL\SUB IXL\ %endmacro
%macro SUB A,IYH\SUB IYH\ %endmacro
%macro SUB A,IYL\SUB IYL\ %endmacro

%macro SBC B\SBC A,B\ %endmacro
%macro SBC C\SBC A,C\ %endmacro
%macro SBC D\SBC A,D\ %endmacro
%macro SBC E\SBC A,E\ %endmacro
%macro SBC H\SBC A,H\ %endmacro
%macro SBC L\SBC A,L\ %endmacro
%macro SBC [HL]\SBC A,[HL]\ %endmacro
%macro SBC [IX%n]\SBC A,[IX+#1]\ %endmacro
%macro SBC [IY%n]\SBC A,[IY+#1]\ %endmacro
%macro SBC A\SBC A,A\ %endmacro
%macro SBC %n\SBC A,#1\ %endmacro
%macro SBC IXH\SBC A,IXH\ %endmacro
%macro SBC IXL\SBC A,IXL\ %endmacro
%macro SBC IYH\SBC A,IYH\ %endmacro
%macro SBC IYL\SBC A,IYL\ %endmacro

%macro AND A,B\AND B\ %endmacro
%macro AND A,C\AND C\ %endmacro
%macro AND A,D\AND D\ %endmacro
%macro AND A,E\AND E\ %endmacro
%macro AND A,H\AND H\ %endmacro
%macro AND A,L\AND L\ %endmacro
%macro AND A,[HL]\AND [HL]\ %endmacro
%macro AND A,[IX%n]\AND [IX+#1]\ %endmacro
%macro AND A,[IY%n]\AND [IY+#1]\ %endmacro
%macro AND A,A\AND A\ %endmacro
%macro AND A,%n\AND #1\ %endmacro
%macro AND A,IXH\AND IXH\ %endmacro
%macro AND A,IXL\AND IXL\ %endmacro
%macro AND A,IYH\AND IYH\ %endmacro
%macro AND A,IYL\AND IYL\ %endmacro

%macro XOR A,B\XOR B\ %endmacro
%macro XOR A,C\XOR C\ %endmacro
%macro XOR A,D\XOR D\ %endmacro
%macro XOR A,E\XOR E\ %endmacro
%macro XOR A,H\XOR H\ %endmacro
%macro XOR A,L\XOR L\ %endmacro
%macro XOR A,[HL]\XOR [HL]\ %endmacro
%macro XOR A,[IX%n]\XOR [IX+#1]\ %endmacro
%macro XOR A,[IY%n]\XOR [IY+#1]\ %endmacro
%macro XOR A,A\XOR A\ %endmacro
%macro XOR A,%n\XOR #1\ %endmacro
%macro XOR A,IXH\XOR IXH\ %endmacro
%macro XOR A,IXL\XOR IXL\ %endmacro
%macro XOR A,IYH\XOR IYH\ %endmacro
%macro XOR A,IYL\XOR IYL\ %endmacro

%macro OR A,B\OR B\ %endmacro
%macro OR A,C\OR C\ %endmacro
%macro OR A,D\OR D\ %endmacro
%macro OR A,E\OR E\ %endmacro
%macro OR A,H\OR H\ %endmacro
%macro OR A,L\OR L\ %endmacro
%macro OR A,[HL]\OR [HL]\ %endmacro
%macro OR A,[IX%n]\OR [IX+#1]\ %endmacro
%macro OR A,[IY%n]\OR [IY+#1]\ %endmacro
%macro OR A,A\OR A\ %endmacro
%macro OR A,%n\OR #1\ %endmacro
%macro OR A,IXH\OR IXH\ %endmacro
%macro OR A,IXL\OR IXL\ %endmacro
%macro OR A,IYH\OR IYH\ %endmacro
%macro OR A,IYL\OR IYL\ %endmacro

%macro CP A,B\CP B\ %endmacro
%macro CP A,C\CP C\ %endmacro
%macro CP A,D\CP D\ %endmacro
%macro CP A,E\CP E\ %endmacro
%macro CP A,H\CP H\ %endmacro
%macro CP A,L\CP L\ %endmacro
%macro CP A,[HL]\CP [HL]\ %endmacro
%macro CP A,[IX%n]\CP [IX+#1]\ %endmacro
%macro CP A,[IY%n]\CP [IY+#1]\ %endmacro
%macro CP A,A\CP A\ %endmacro
%macro CP A,IXH\CP IXH\ %endmacro
%macro CP A,IXL\CP IXL\ %endmacro
%macro CP A,IYH\CP IYH\ %endmacro
%macro CP A,IYL\CP IYL\ %endmacro

%macro EX AF,AF\EX AF,AF'\ %endmacro
%macro EX HL,DE\EX DE,HL\ %endmacro

%if %def(tniasm#z80parens.inc)
%macro ADD (HL)\ADD A,(HL)\ %endmacro
%macro ADD (IX%n)\ADD A,(IX+#1)\ %endmacro
%macro ADD (IY%n)\ADD A,(IY+#1)\ %endmacro
%macro ADC (HL)\ADC A,(HL)\ %endmacro
%macro ADC (IX%n)\ADC A,(IX+#1)\ %endmacro
%macro ADC (IY%n)\ADC A,(IY+#1)\ %endmacro
%macro SUB A,(HL)\SUB (HL)\ %endmacro
%macro SUB A,(IX%n)\SUB (IX+#1)\ %endmacro
%macro SUB A,(IY%n)\SUB (IY+#1)\ %endmacro
%macro SBC (HL)\SBC A,(HL)\ %endmacro
%macro SBC (IX%n)\SBC A,(IX+#1)\ %endmacro
%macro SBC (IY%n)\SBC A,(IY+#1)\ %endmacro
%macro AND A,(HL)\AND (HL)\ %endmacro
%macro AND A,(IX%n)\AND (IX+#1)\ %endmacro
%macro AND A,(IY%n)\AND (IY+#1)\ %endmacro
%macro XOR A,(HL)\XOR (HL)\ %endmacro
%macro XOR A,(IX%n)\XOR (IX+#1)\ %endmacro
%macro XOR A,(IY%n)\XOR (IY+#1)\ %endmacro
%macro OR A,(HL)\OR (HL)\ %endmacro
%macro OR A,(IX%n)\OR (IX+#1)\ %endmacro
%macro OR A,(IY%n)\OR (IY+#1)\ %endmacro
%macro CP A,(HL)\CP (HL)\ %endmacro
%macro CP A,(IX%n)\CP (IX+#1)\ %endmacro
%macro CP A,(IY%n)\CP (IY+#1)\ %endmacro
%endif
