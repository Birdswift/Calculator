#include <stack>
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include "Header.h"

std::string polska(std::string beg_exp)
{	
		std::string ch;
		std::string numbers;
		std::stack <char> oper;
		for (size_t i = 0; i < beg_exp.size(); i++) {
			if (isdigit(beg_exp[i]) || beg_exp[i] == '.') {
				ch += beg_exp[i];

			}
			if ((!isdigit(beg_exp[i]) && beg_exp[i] != '.' && !ch.empty()) ||
				(isdigit(beg_exp[i]) && !ch.empty() &&
					i == beg_exp.size() - 1)) {
				numbers += ch;
				numbers += ' ';
				ch.clear();
			}
			if (beg_exp[i] == 's' && beg_exp[i + 1] == 'i' && beg_exp[i + 2] == 'n' && beg_exp.size() - i >= 4) {
				oper.push('s');
				i += 3;
			}
			else
				if (beg_exp[i] == 'c' && beg_exp[i + 1] == 'o' && beg_exp[i + 2] == 's' && beg_exp.size() - i >= 4) {
					oper.push('c');
					i += 3;
				}
				else
					if (beg_exp[i] == 't' && beg_exp[i + 1] == 'a' && beg_exp[i + 2] == 'n' && beg_exp.size() - i >= 4) {
						oper.push('t');
						i += 3;
					}
					else
						if (beg_exp[i] == 'c' && beg_exp[i + 1] == 'o' && beg_exp[i + 2] == 't' && beg_exp.size() - i >= 4) {
							oper.push('o');
							i += 3;
						}
			if (beg_exp[i] == '(') {
				oper.push(beg_exp[i]);
			}
			else {
				if (!isdigit(beg_exp[i]) && beg_exp[i] != '(' && beg_exp[i] != '.') {
					if (beg_exp[i] == ')') {
						while (oper.top() != '(' && !oper.empty()) {
							numbers += oper.top();
							numbers += ' ';
							oper.pop();
						}
						if (!oper.empty())
						{
							oper.pop();
						}
					}
					else {
					Link1:
						if (oper.empty() ||
							priorityofelem(beg_exp[i]) > priorityofelem(oper.top())) {
							oper.push(beg_exp[i]);
						}
						else {
							while (priorityofelem(beg_exp[i]) <= priorityofelem(oper.top())) {
								numbers += oper.top();
								numbers += ' ';
								oper.pop();
								if (oper.empty()) {
									break;
								}
							}
							goto Link1;
						}
					}
				}
			}
		}
		while (!oper.empty()) {
			numbers += oper.top();
			numbers += ' ';
			oper.pop();
		}
	
		
		return numbers;
	}
