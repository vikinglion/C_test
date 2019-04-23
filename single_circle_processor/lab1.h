#ifndef __LAB1_H__
#define __LAB1_H__
#define WIDTH 32
#define IN
#define OUT

/*****************************************************************************\ 
Function Description:
halfadder. 
notice that if u want to set a output value inside the function, you need to 
use * to access the memory.

Arguments:
IN      a       : BOOL   - the first bit u want to feed the gate
IN      b       : BOOL   - the second bit  
OUT     c       : BOOL * - carry bit
OUT     s       : BOOL * - sum bit

Return Value:
void
\*****************************************************************************/
void halfadder(IN BOOL a, IN BOOL b,
                OUT BOOL * c, OUT BOOL * s){
    *s = xor_gate(a, b);
    *c = and_gate(a, b);
}

/*****************************************************************************\ 
Function Description:
fulladder. 

Arguments:
IN      a           : BOOL   - the first bit 
IN      b           : BOOL   - the second bit  
IN      carry_in    : BOOL   - carry in bit
OUT     carry_out   : BOOL * - carry out bit
OUT     s           : BOOL * - sum bit

Return Value:
void
\*****************************************************************************/
void fulladder(IN BOOL a, IN BOOL b, IN BOOL carry_in,
                OUT BOOL * carry_out, OUT BOOL * s){
    //TODO
    /*
    TASK 1

    You need to employ a full-adder to perform addition and subtraction operations. 
    The full-adder can be implemented by the following formulas (see document). You
	may check your full-adder according to the truth table (see document).

    You are encouraged to implement the full-adder using basic logic gates. A 1-bit 
    half-adder is implemented at first, which contains two logic gates: a XOR gate 
    and an AND gate. And then, a 1-bit full-adder is built using two half-adders 
    and an OR gate.

    Hit: 
    1. when u call the function halfadder, you need to pass the address of the 
    value to the output parameter. use & to get the address of the value.
    2. if u want to set a output value, use * to access the memory and set it.

    */

	// write your code here.
	BOOL p1 = and_gate(a,b);
	BOOL p2 = and_gate(a,carry_in);
	BOOL p3 = and_gate(b,carry_in);
	*s = xor_gate(xor_gate(a,b),carry_in);
	*carry_out = or_gate(or_gate(p1,p2),p3);
}

/*****************************************************************************\ 
Function Description:
fulladder32. this function simulat a 32 bit fulladder. it will save the result
in parameter c.

Arguments:
IN      a           : int   - the first number
IN      b           : int   - the second number
OUT     c           : int * - the result of the number

Return Value:
void
\*****************************************************************************/
void fulladder32(IN int a, IN int b, OUT int * c){

	// don't revise this code segment.
    int i;
    BOOL A_bin[WIDTH], B_bin[WIDTH], S_bin[WIDTH];
	for (i = 0; i < WIDTH; i++){
		A_bin[i] = get_bit(a,i);  // representing A in binary.
		B_bin[i] = get_bit(b,i);  // representing B in binary.
	}
	BOOL C[WIDTH+1];   // Declaration of carry in and carry out;
	C[0] = 0;
	
	//TODO
    /*
    TASK 2

    A 32-bit full-adder is implemented by just connecting the carry-out of the 
    least significant bit of 1-bit full-adder to the carry-in of the next least 
    significant bit of another 1-bit full-adder.

    Hit: 
    You need to write a loop and calculate it from lowest bit to high bit, and
    save the carry_out result for the next eval.

    */
	
	
	// write your code here.
	for (i = 0; i < WIDTH; i++){
	fulladder(A_bin[i],B_bin[i],C[i],&C[i+1],&S_bin[i]);
	}
	
	
	// don't modify this code segment.
	for (i = 0; i < WIDTH; i++){
		change_bit(c, i, S_bin[i]);	
	}	
	
}

/*****************************************************************************\ 
Function Description:
neg. this function gets the inverse of input number.

Arguments:
IN      num           : int - the input number

Return Value:
the inverse of input number
\*****************************************************************************/
int neg(int num){
    int an = 0;
    int inverse_an = 0;
    inverse(num, &inverse_an);
    fulladder32(inverse_an, 1, &an);
    return an;
}

/*****************************************************************************\ 
Function Description:
add. this function performs addition.

Arguments:
IN      a           : int   - the first number
IN      b           : int   - the second number
OUT     c           : int * - the result of the number

Return Value:
void
\*****************************************************************************/
void add(IN int a, IN int b, OUT int * c){
    fulladder32(a, b, c);
}

/*****************************************************************************\ 
Function Description:
add. this function performs substraction.

Arguments:
IN      a           : int   - the first number
IN      b           : int   - the second number
OUT     c           : int * - the result of the number

Return Value:
void
\*****************************************************************************/
void sub(IN int a, IN int b, OUT int * c){
    fulladder32(a, neg(b), c);
}

/*****************************************************************************\ 
Function Description:
unsigned_mult. this function simulat a multiplier with unsigned numbers. it will
save the result in Product.

Arguments:
IN      Multiplicand      : int   - the Multiplicand
IN      Multiplier        : int   - the Multiplier
OUT     Product           : int * - the Product

Return Value:
void
\*****************************************************************************/
void unsigned_mult(int Multiplicand, int Multiplier, long long int * Product){
    int ProductLeft = 0;
    int i;
    for(i = 0; i < WIDTH; i++){
        BOOL LSB = get_bit(Multiplier, 0);
        if(LSB == TRUE){
            int an = 0;
            add(ProductLeft, Multiplicand, &an);
            ProductLeft = an;
        }
        shifter(&ProductLeft, &Multiplier, 1);
    }
    
    for(i = 0; i < WIDTH; i++){
        change_long_bit(Product, i, get_bit(Multiplier, i));
        change_long_bit(Product, i + WIDTH, get_bit(ProductLeft, i));
    }
}

/*****************************************************************************\ 
Function Description:
booth_mult. this function simulate a multiplier with signed numbers using Booth
algorithm. it will save the result in Product.

Arguments:
IN      Multiplicand      : int   - the Multiplicand
IN      Multiplier        : int   - the Multiplier
OUT     Product           : int * - the Product

Return Value:
void
\*****************************************************************************/
void booth_mult(int Multiplicand, int Multiplier, long long int * Product){
	//TODO
    /*
    TASK 3

    You are required to modify and fill in the body of the functions to implement
	a  multiplier using Booth algorithm.

    Hit: 
    You can refer to the implementation of unsigned_mult.
    */
    
    int ProductLeft = 0;
	int i;
	
	
	// write your code here.
	 for(i = 0; i < WIDTH; i++){
        BOOL LSB = get_bit(Multiplier, 0);
		BOOL check[2] = {LSB, 0};
        if(check[0] == 1 && check[1] == 0){
            int an = 0;
            fulladder32(ProductLeft, Multiplicand, &an);
            ProductLeft = an;
        }
		else if (check[0] == 0 && check[1] == 1){
			int an = 0;
			fulladder32(ProductLeft, neg(Multiplicand), &an);
			ProductLeft = an;
		}
		check[1] = LSB;
        shifter(&ProductLeft, &Multiplier, 1);
    }
	
	
	// don't modify this code segment.
    *Product = 0L; 
    for(i = 0; i < WIDTH; i++){		
        change_long_bit(Product, i, get_bit(Multiplier, i));
        change_long_bit(Product, i + WIDTH, get_bit(ProductLeft, i));
    }

   
}

/*****************************************************************************\ 
Function Description:
unsigned_div. this function simulat a divider with unsigned numbers. it will
save the results in Remainder and Quotient.

Arguments:
IN      Dividend            : int   - the Dividend
IN      Divisor             : int   - the Divisor
OUT     Remainder           : int * - the Remainder
OUT     Quotient            : int * - the Quotient

Return Value:
void
\*****************************************************************************/
void unsigned_div(IN int Dividend, IN int Divisor,
             OUT int * Remainder, OUT int * Quotient){
             	
    //TODO
    /*
    TASK 4

    You are required to modify and fill in the body of the functions to implement
	a  divider with unsign numbers.
    */
    

	// write your code here.
	int Remainder_left = 0;
	int i;
	shifter(&Remainder_left, &Dividend, 0);
	for (i = 0;i < WIDTH;i++){
		int an = 0;
		fulladder32(Remainder_left, neg(Divisor), &an);
		Remainder_left = an;
		if (Remainder_left >= 0){
			shifter(&Remainder_left, &Dividend, 0);
			change_bit(&Dividend, 0,1);
		}
		else if (Remainder_left < 0){
			Remainder_left = Remainder_left + Divisor;
			shifter(&Remainder_left, &Dividend, 0);
			change_bit(&Dividend, 0,0);
		}
	}
	Remainder_left = Remainder_left >> 1;
	for(i = 0; i < WIDTH; i++){		
        change_bit(Quotient, i, get_bit(Dividend, i));
        change_bit(Remainder, i , get_bit(Remainder_left, i));
    }
}

/*****************************************************************************\ 
Function Description:
unsigned_div. this function simulate a divider with signed numbers. it will
save the results in Remainder and Quotient.

Arguments:
IN      Dividend            : int   - the Dividend
IN      Divisor             : int   - the Divisor
OUT     Remainder           : int * - the Remainder
OUT     Quotient            : int * - the Quotient

Return Value:
void
\*****************************************************************************/
void signed_div(IN int Dividend, IN int Divisor,OUT int * Remainder, OUT int * Quotient){
    BOOL DividendBS = get_bit(Dividend, WIDTH - 1);
    if(DividendBS == TRUE)
        Dividend = neg(Dividend);

    BOOL DivisorBS = get_bit(Divisor, WIDTH - 1);
    if(DivisorBS == TRUE)
        Divisor = neg(Divisor);

    unsigned_div(Dividend, Divisor, Remainder, Quotient);

    BOOL RemainderBS = DividendBS;
    BOOL QuotientBS = xor_gate(DividendBS, DivisorBS);

    if(RemainderBS == TRUE)
        *Remainder = neg(*Remainder);
    if(QuotientBS == TRUE)
        *Quotient = neg(*Quotient);
}

#endif
