#include <iostream>
#include <fstream>
#include <optional>
#include <string>
/*
 * What to do if function failed,
 * but returs the default value
 * 
 * This is also C++17 feature
 * One mast activate the C++17 in compiler settings
 * 
 * std::optional
 * 
 * 
 * 
 * 
 * 
 */ 

std::string ReadFileAsString(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		// read file
		std::string results;
		// done
		stream.close();
		return results;
	}
	return std::string(); // empty string
}

std::optional<std::string> ReadFile(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		// read file
		std::string results;
		// done
		stream.close();
		return results;
	}
	return {}; // empty optional
}



int main(int argc, char **argv)
{
	std::string data = ReadFileAsString("data.txt");
	/*
	if ... -- we do want to know whether the read was successfull
	It can be done by passing a bool into the func to signal
	the sucess
	But this is also cumbersome as another var is required
	*/
	
	
	// Using optional it is just
 
	std::optional<std::string> data2 = ReadFile("data.txt"); //auto
	std::string value = data2.value_or("Not present"); // setting default -- if faild to read
	if (data2) // .has_value()
	{
		std::cout << "Read Succasfull" << std::endl;
	}
	else
	{
		std::cout << "File could not be open" << std::endl;
	}
	
	// similar to smart pointer
	std::string& string = *data2;// dereference the pointer
	
	/*
	 * Here I ger errors.
	 * It seems that the syntax for reading a file
	 * in Linux is different. 
	 * 
	 */ 
	
	/*
	 * Imagine that you want to read the data,
	 * but it is not mandatory. There is a default answer
	 * so to say.
	 */

	
	return 0;
}
