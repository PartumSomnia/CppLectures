#include <stdio.h>
#include <iostream>
/*
 * Functions are not part of the class
 * The latter are the methods
 * 
 * Every time a function is called -- a call instructions are 
 * generated. Mamory is allocated. Then the result pushed back.
 * This slows down the program.
 * Note, that compiler may inline your function, that it 
 * will simply copy pasted.
 * The main goal of the function is to prevent code duplication
 * 
 * Funciton commonly split between decalration (in header)
 * and definitions (in .cpp file)
 * 
 * */

int Multiply(int a, int b)
{
	return a * b;
}

void MultiplyAndLog(int a, int b)
{
	int restult = Multiply(a, b);
	std::cout << restult << std::endl;
}

int main(int argc, char **argv)
{
	
	MultiplyAndLog(3, 2);
	MultiplyAndLog(8, 2);

	printf("hello world\n");
	return 0;
}
