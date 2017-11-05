// calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
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
	for (;;)//main loop
	{
		std::getline(std::cin,s);
		if (s == "q")break;
		std::smatch sm;
		std::regex e("(\\d+)([\\+\\-\\*\\/])(\\d+)");
		std::regex_match(s,sm, e);
		char sign = sm[2].str()[0];
		std::string ns[] = { sm[1],sm[3] };
		std::vector<double> n;
		for each (std::string var in ns)
		{
			n.push_back(dts(var));
		}
		switch (sign)
		{
			case '+':n[0]+=n[1];
				break;
			case '-':n[0] -= n[1];
				break;
			case '*':n[0] *= n[1];
				break;
			case '/':n[0] /= n[1];
				break;
		default:
			break;
		}
		std::cout << n[0]<<std::endl;
	}
}

