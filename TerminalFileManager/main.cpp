#include <filesystem>
#include <iostream>
#include "app.hpp"
#include "mystr.hpp"

int main()
{
	App app;

	Mystr str1 = "123";
	Mystr str2("");
	str2 = str1;

	std::cout << str2;

	//app.run();


}