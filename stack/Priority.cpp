#include <stack>
#include <iostream>
#include <string>
#include <stack>
#include <map>
int priorityofelem(char check) {
	int level = 0;
	std::map <char, int> priority;
	priority.insert({ '+',1 });
	priority.insert({ '-',1 });
	priority.insert({ '*',2 });
	priority.insert({ '/',2 });
	priority.insert({ 's',3 });
	priority.insert({ 'c',3 });
	priority.insert({ 't',3 });
	priority.insert({ 'o',3 });
	for (auto& i : priority) {
		if (check == i.first) {
			level = i.second;
		}
	}
	return level;
}