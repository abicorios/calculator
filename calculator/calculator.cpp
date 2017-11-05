// calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
std::string number = "(\\d+)";
std::string sign = "([\\+\\-\\*\\/])";
double dts(std::string);//convert string to double
double dts(std::string s)
{
	std::stringstream ss(s);
	double d;
	ss >> d;
	return d;
}
std::string dts(double);//double to string
std::string dts(double d)
{
	std::stringstream ss;
	ss << d;
	return ss.str();
}
std::string unbracket(std::string&);
std::string unbracket(std::string& s)
{
	std::smatch sm;
	if (std::regex_search(s, sm, std::regex("\\(" + number + "\\)")))
		s.replace(sm.position(), sm.length(), sm[1]);
	return s;
}
int main()
{
	std::cout << "It is a calculator\nEnter q for quit\nEnter help, h or ? for information\n";
	std::string s="";
	for (;;)//main loop
	{
		std::getline(std::cin,s);
		if (s == "q")break;
		if (s == "help" || s == "h" || s == "?")
		{
			std::cout << "You can print math expressions with numbers and operations +-*/()\nFor example (1+2+3)/(4+5+6)\n";
			continue;
		}
		std::smatch sm;
		
		std::regex e(number+sign+number);
		unbracket(s);
		while (std::regex_search(s, sm, e))
		{
			char sig = sm[2].str()[0];
			std::string ns[] = { sm[1],sm[3] };
			std::vector<double> n;
			for each (std::string var in ns)
			{
				n.push_back(dts(var));
			}
			switch (sig)
			{
			case '+':n[0] += n[1];
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
			s.replace(sm.position(), sm.length(), dts(n[0]));
			unbracket(s);
		}
		std::cout << s<<std::endl;
	}
}

