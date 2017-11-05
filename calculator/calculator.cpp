// calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <sstream>
double dts(std::string);//convert string to double
double dts(std::string s)
{
	std::stringstream ss(s);
	double d;
	ss >> d;
	return d;
}
int main()
{
	std::cout << "It is a calculator\nEnter q for quit\n";
	std::string s="";
	for (;;)
	{
		std::getline(std::cin,s);
		if (s == "q")break;
		std::smatch sm;
		std::regex e("(\\d+)\\+(\\d+)");
		std::regex_match(s,sm, e);
		std::cout << (dts(sm[1]) + dts(sm[2]))<<std::endl;
	}
}

