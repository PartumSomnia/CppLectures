#include <stdio.h>
#include <iostream> // A MASSIVE file with 50000 lines
/*
 * Compiling -- take text files and convert into object files
 * It does:
 * 1) preprocess code
 * 2) toking/parsing english -> abstract syntax tree
 * 3) Generate actual machine code and instraction for storage.
 * Each .cpp file -> each object file created to 
 * Files have no meaning. 
 * Compiler converts them as a translation unit that 
 * will result in an object. 
 * Note: if you include them into each other, then
 * the object may not be generated. 
 * 
 * During the preprocessing compiler goes throug
 * preprocessing #inclide, #if, #define #ifdef
 * #include -- read and past into the file 
 * (see the example in the main() function
 * 
 * Compiler result can be seen as an assemply code
 * but I do not know how to view it here. Otherwise 
 * it generates binaries that are unreadable. 
 * Complier can optimize the code for either readability -- 
 * if you are in Debug or for speed if you are in Release.
 * 
 */

#define INTEGER int // Will replace INTEGER with int in preprocessing


#if 1 // will include the follwoing text into compiled object IF 
INTEGER main(INTEGER argc, char **argv)
{
	printf("hello world\n");
	return 0;
#include <EndBrace.h> // prepocessing, will add } here
#endif