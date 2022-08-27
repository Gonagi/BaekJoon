/*
// 17413번 문제
#include <iostream>
#include <string>
#include <stack>

int main() {
	std::string str;
	std::stack<char> list;

	getline(std::cin, str);

	for (int index = 0; index < static_cast<int>(str.length()); index++) {
		if (str.at(index) == '<' && !list.empty()) {
			while (!list.empty()) {
				std::cout << list.top();
				list.pop();
			}
		}
		if (str.at(index) == '<' && list.empty()) {
			while (str.at(index) != '>') {
				std::cout << str.at(index);
				index++;
			}
			std::cout << '>';
			continue;
		}
		
		if (str.at(index) == ' ') {
			while (!list.empty()) {
				std::cout << list.top();
				list.pop();
			}
			std::cout << ' ';
			continue;
		}
			list.push(str.at(index));
		
	}

	while (!list.empty()) {
		std::cout << list.top();
		list.pop();
	}

	return 0;
}
*/

/*
// 10799번 문제

#include <iostream>
#include <stack>

int main() {
	std::string list;
	std::stack<char> stack;
	char cur;
	int check = 0, result = 0;

	std::cin >> list;

	for (int index = 0; index < static_cast<int>(list.length()); index++) 
		stack.push(list.at(index));

	while(!stack.empty()){
		cur = stack.top();
		stack.pop();

		if (cur == ')') {
			if (stack.top() == '(') {
				result += check;
				stack.pop();
			}
			else
				check++;
		}
		else if (cur == '(') {
			result++;
			check--; 
		}
	}

	std::cout << result;

	return 0;
}
*/
