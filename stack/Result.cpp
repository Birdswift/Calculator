#include <stack>
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include "Header.h"
#include <cmath>         
#include <iomanip>
#define PI 3.14159265

void result(std::string exp) {
	std::string str;
	std::string ch;
	std::stack <double> numb;
	double first = 0.0;
	double second = 0.0;
	double res = 0.0;
	for (size_t i = 0; i < exp.size(); i++) {
		if (isdigit(exp[i]) || exp[i] == '.') {
			ch += exp[i];
		}
		if ((!isdigit(exp[i]) && exp[i] != '.' && !ch.empty()) ||
			(isdigit(exp[i]) && !ch.empty() &&
				i == exp.size() - 1)) {
			numb.push(std::stod(ch));
			ch.clear();
		}
		if (exp[i] == 's' || exp[i] == 'c' || exp[i] == 't' || exp[i] == 'o') {
			res = trigonometry(numb.top(), exp[i]);
			numb.pop();
			numb.push(res);
		}
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
			first = numb.top();
			numb.pop();
			second = numb.top();
			numb.pop();
			res = operation(exp[i], first, second);
			numb.push(res);
		}
	}
	std::cout << numb.top() << std::endl;
}