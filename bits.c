/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {/* x^y=(x&~y)|(~x&y)=~(~(x&~y)&~(~x&y)) */
  return ~(~(x&~y)&~(~x&y));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1<<31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {/*若x为maximum，则~x＋~x为0，满足 (~x)+(~x)=0的数还有x=-1，因此需要排除x=-1的情况*/ 
  return !((~x)+(~x)) & !!(x+1);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {/*将x与0xAAAAAAAA做&运算，将偶数位置零，若x满足条件，那么此时x应该等于 0xAAAAAAAA，
再与0xAAAAAAAA作差取非*/ 
  int a = 0xAA;
  int b = (a << 8) + a; //0xAA AA
  int c = (b << 8) + a; //0xAA AA AA
  int d = (c << 8) + a; //0xAA AA AA AA
  return !((x&d)+(~d+1));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {/*负数对原数取反加一*/ 
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {/*对于满足条件的x，x-0x30与0x39-x的符号位均为0，即(x-0x30)|(0x39-x)符号位为零，
按位取反后符号位为一，再与0x80000000做&运算，结果仍为0x80000000，做两次！运算即为1*/ 
	int Tmin=1<<31;
 return !!(~((x+(~0x30+1))|(0x39+(~x+1)))&Tmin);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {/*x为0时将y置零（0&y），x不为零时y保持原数（-1&y），
考虑到（！x-1）当x为零时等于零，当x不为零时等于-1，故 (!x-1)&y为表达式的一部分。对于z：
当x为零时保持原数，x不为零时将z置零，那么只需对x多做一次！运算，即 （！！x-1）&z ，两部分
表达式用|连接。*/ 
  return ((!x+(~1+1))&y) | ((!!x+(~1+1))&z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int flag;
    int x_sign, y_sign;
    x_sign = (x >> 31) & 0x1;
    y_sign = (y >> 31) & 0x1;
    flag = y + (~x) + 1;/*将x，y，y-x的符号分别提出来*/ 
    flag = (flag>>31) & 0x1;
    flag = (x_sign & (y_sign ^ flag)) | (!(y_sign | flag));/*防止x，y异号时运算过程中溢出*/ 
    return flag;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {/*对于0，与其他所有数相比其特殊之处为0取反加一符号位为0不变，
那么（~x+1）&0x80000000和 (x&0x80000000)均为0，当且仅当x=0。其他情况下，（~x+1）&0x80000000
和 (x&0x80000000)一个为0一个为 0x80000000，二者做|运算，那么x=0时运算值为0，x为其他数时运算值
为 0x80000000，下面再将两种结果分别对应到1和0。考虑到0和0x80000000的位只有符号位不同，那么由 
0>>31=-2，0x80000000>>31=-1，再分别加2，可以得到，x=0时运算值为0，x为其他数时运算值为1，此时
再对整个式子取反加2，就可得到x=0时运算值为1，x为其他数时运算值为0。上述过程表达式为 
~(((((~x+1)&0x80000000)|(x&0x80000000))>>31)+2)+2。*/
int Tmin=1<<31;
int result= ((~(~x + 1) & ~x) >> 31) & 1;
  return result;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	int bit16, bit8,bit4,bit2,bit1;
	int sum;
	int i= ((!x) << 31) >> 31;
	int i1 = ((!~x) << 31) >> 31;
	int op = x ^ ((x >> 31));
	bit16 =(!!(op >> 16)) << 4;
	op = op >> bit16;
	bit8 = (!!(op >> 8)) << 3;
	op = op >> bit8;
	bit4 = (!!(op >> 4)) << 2;
	op = op >> bit4;
	bit2 = (!!(op >> 2)) << 1;
	op = op >> bit2;
	bit1 = (!!(op >> 1));
	op = op >> bit1;
	sum =bit16+bit8+bit4+bit2+bit1+2;
	return(i1&1) | ((~i1) & ((i&1) | ((~i) & sum)));
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) 
{
    unsigned signal = uf&0x80000000;
	unsigned exp = uf&0x7f800000;
	unsigned frac = uf&0x007fffff;/*分别记录符号位，阶码和尾数。*/ 
	if(exp==0) 
    {
		frac=frac<<1;/*将frac乘2*/
    
   }
	else if(exp^0x7f800000) /*如果阶码部分不为全1*/
   {
		exp =exp+0x00800000;/*将exp乘2*/
		if((exp^0x7f800000)==0)/*如果乘2后，阶码为全1,将尾数位全置0返回无穷大*/
			frac = 0;
   }
	return signal|exp|frac;/*利用或运算将之前拆分的符号位，阶码和尾数结合起来*/ 
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned sign = (uf & 0x80000000);
  unsigned exp = (uf & 0x7f800000) >> 23;
  unsigned frac = (1 << 23) | ((uf << 9) >> 9);
  int E = exp - 127;
  int val;
  if (exp < 127) return 0;/*如果exp<127,那么保留到整数时，整数位为零，故直接返回0。*/ 
  if (exp >= 158) return 0x80000000;/*如果exp大于等于127+31,发生过大溢出，返回0x80000000*/
  if (E <= 23) {/*剩下的范围可以转换为对应的整数*/
    val = (frac >> (23 - E));
    if(!sign) return val;
    else if (sign) return -val;
  }
  val = (frac << (E - 23));
     if(!sign) return val;
    else if (sign) return (-val);
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    if(x>127) return 0x7f800000;
    else if(x<-127) return 0;
    else return (x+127)<<23;
}
