#include <stack>
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>

std::string correction(std::string exp) {
	int sch1 = 0;
	int sch2 = 0;
	bool flag = false;
	std::string x;
	std::string str;
	for (auto& i : exp) {
		if (i == '(') sch1++;
		if (i == ')') sch2++;
		if (i == ' ') {
			continue;
		}
		else {
			str += i;
		}
	}
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == 'e') {
			str.replace(i, 1, "2.71828");
			i += 7;
		}
	}
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == 'x') {
			flag = true;
			break;
		}
	}
	if (flag == true) {
		std::cout << "Please, input x " << std::endl;
		std::cin >> x;
		for (size_t i = 0; i < str.size(); i++) {
			if (str[i] == 'x') {
				str.replace(i, 1, x);
				i += x.size();
			}
		}
	}
	
	for (auto& i : str) {
		if (i == ',') {
			i = '.';
		}
	}
	if (sch1 != sch2) {
		std::cerr << "Incorrect expression! Check brackets!";
		exit(0);
	}
	if (str.find_first_not_of("xsincotane0123456789+/()*-.") != std::string::npos) {
		std::cerr << "Incorrect input!" << std::endl;
		exit(0);
	}
	for (size_t i = 1; i < str.size(); i++) {
		if ((str[i-1] == 'i' && str[i] == 'n' && str[i + 1] != '(') || (str[i - 1] == 'o' && str[i] == 's' && str[i + 1] 
			!= '(') || (str[i - 1] == 'o' && str[i] == 't' && str[i + 1] != '(') || 
			(str[i - 1] == 'a' && str[i] == 'n' && str[i + 1] != '(')) {
			std::cerr << "Use brackets with triginometrical functions!" << std::endl;
			exit(0);
	}
	}
	for (size_t i = 1; i < str.size(); i++) {
		if (str[i] == '-' && !isdigit(str[i - 1]) && str[i - 1] != ')') {
			str.insert(i, "0");
			i++;
		}
	}
	return str;
}
