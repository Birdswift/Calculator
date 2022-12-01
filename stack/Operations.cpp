#include <iostream>
#include <string>
#include <stack>
#include <map>
#include "Header.h"
#include <cmath>                                      

double operation(char check, double now, double past) {
	double result = 0.0;
	if (check == '+') {
		result = now + past;
	}
	if (check == '-') {
		result = past - now;
	}
	if (check == '/') {
		result = past / now;
	}
	if (check == '*') {
		result = now * past;
	}
	return result;
}