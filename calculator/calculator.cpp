// calculator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <boost\regex.hpp>
std::string number = "((?:(?:(?<=\\()|^)-)?(?:\\d+\\.?\\d*|\\.\\d+)(?:[eE][\\+\\-]?\\d+)?)";
std::vector<std::string> operations = { "(\\^)","([\\*\\/])","([\\+\\-])" };
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
	boost::smatch sm;
	while (boost::regex_search(s, sm, boost::regex("[\\(\\[\\{]" + number + "[\\)\\]\\}]")))
		s.replace(sm.position(), sm.length(), sm[1]);
	return s;
}
int main()
{
	std::cout << "It is a calculator\nEnter q for quit\nEnter help, h or ? for information\n";
	std::string s="";
	std::string tempInput;
	int cell = 0;
	boost::smatch sm;
	for (;;)//main loop
	{
		cell++;
		std::cout << "inp[" << cell << "]:";
		std::getline(std::cin,s);
		tempInput = s;
		if (s == "q")break;
		if (s == "help" || s == "h" || s == "?")
		{
			std::cout << "You can print math expressions with numbers and operations +-*/, ^ or ** for power, brackets ()[]{}\nFor example (1+2+3)/(4+5+6)\n";
			continue;
		}
		while (boost::regex_search(s, sm, boost::regex("\\*\\*")))
		{
			s.replace(sm.position(), sm.length(), "^");
		}
		for each (std::string var0 in operations)
		{
			unbracket(s);
			while (boost::regex_search(s, sm, boost::regex(number + var0+ number )))
			{
				char sig;

				sig = sm[2].str()[0];
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
				case '^':n[0] = pow(n[0], n[1]);
					break;
				default:
					break;
				}
				s.replace(sm.position(), sm.length(), dts(n[0]));
				unbracket(s);
			}
		}
		std::cout <<"out["<<cell<<"]:"<< s<<"="<<tempInput<<std::endl;
	}
}