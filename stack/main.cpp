#include <stack>
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include "Header.h"

int main()
{
	std::cout << "Hello,it is calculator!\nI can count these functions\n1)+\n2)-\n3)*\n4)/\n5)()\n6)sin()\n7)cos()\n8)tan()\n9)cot()\n10)e\n11)parameter x" << std::endl;
	std::string beg_exp;
	std::string numbers;
	//getline(std::cin, beg_exp);
	beg_exp = "cot(45)*sin(50)-tan(30)+cos(10)*e+x";
	beg_exp = correction(beg_exp);
	numbers = polska(beg_exp);
	result(numbers);
}
