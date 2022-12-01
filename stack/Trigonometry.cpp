#include <stack>
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include "Header.h"
#include <cmath>                                      

double trigonometry(double ch, char exp) {
	double res1 = 0.0;
	if (exp == 's') {
		res1 = sin(ch);
	}
	if (exp == 'c') {
		res1 = cos(ch);
	}
	if (exp == 't') {
		res1 = tan(ch);
	}
	if (exp == 'o') {
		res1 = 1.0 / tan(ch);
	}
	return res1;
}