// 1935번 문제

/*
#include <iostream>
#include <stack>
#include <vector>
#include <string>

void pop_num(double& num1, double& num2, std::stack<double>& operand_stack);
double calculate(std::stack<int>& operator_stack, double& num1, double& num2);

int main() {
	char alphabet = 'A';
	int N, count = 0;
	double num, num1, num2, result;
	std::stack<int> operator_stack;
	std::stack<double> operand_stack;
	std::vector<double> input;
	std::string str;

	std::cin >> N >> str;

	for (int i = 0; i < static_cast<int>(str.size()); i++)
		input.push_back(str.at(i));

	for (int i = 0; i < N; i++) {
		std::cin >> num;


		for (int j = 0; j < static_cast<int>(input.size()); j++) {
			if (str.at(j) == alphabet)
				input[j] = num;
		}
		alphabet++;
	}

	for (int i = static_cast<int>(str.size()) - 1; i >= 0; i--) {
		if (str.at(i) == '*' || str.at(i) == '/' ||
			str.at(i) == '+' || str.at(i) == '-') {										// 연산자
			operator_stack.push(str.at(i));
			count = 0;
		}
		else {	// 피연신자
			operand_stack.push(static_cast<double>(input.at(i)));
			count++;
			if (count == 2) {
				pop_num(num1, num2, operand_stack);
				result = calculate(operator_stack, num1, num2);
				operand_stack.push(result);
				count = 0;
			}
		}

	}

	while (static_cast<int>(operand_stack.size()) != 1) {
		pop_num(num1, num2, operand_stack);
		result = calculate(operator_stack, num1, num2);
		operand_stack.push(result);
	}

	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);
	std::cout << result;

	return 0;
}

void pop_num(double& num1, double& num2, std::stack<double>& operand_stack) {
	num1 = operand_stack.top();
	operand_stack.pop();
	num2 = operand_stack.top();
	operand_stack.pop();
}

double calculate(std::stack<int>& operator_stack, double& num1, double& num2) {
	double result = 0;

	switch (operator_stack.top()) {
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
		break;
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	}
	operator_stack.pop();

	return result;
}
*/
/*
#include <iostream>
#include <stack>
#include <vector>

int main() {
	int N;
	std::string str;
	std::cin >> N >> str;

	std::vector<int> vector(N);
	std::stack<double> stack;

	for (int i = 0; i < N; i++)
		std::cin >> vector[i];

	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z')	// 피연산자
			stack.push(vector[str[i] - 'A']);
		else {
			if (!stack.empty()) {	// 연산자
				double tmp = stack.top();
				stack.pop();
				if (str[i] == '+')
					tmp = stack.top() + tmp;
				else if (str[i] == '-')
					tmp = stack.top() - tmp;
				else if (str[i] == '*')
					tmp = stack.top() * tmp;
				else if (str[i] == '/')
					tmp = stack.top() / tmp;
				stack.pop();
				stack.push(tmp);
			}
		}
	}

	return 0;
}
*/

/*
#include <iostream>
#include <stack>
#include <vector>

int prec(char ch);

int main() {
	std::string infix;
	std::vector<char> postfix;
	std::stack<char> stack;

	std::cin >> infix;
	
	for (int i = 0; i < infix.size(); i++) {
		if('A' <=infix.at(i) && infix.at(i) <= 'Z')	// 피연산자일때
			postfix.push_back(infix.at(i));
		else {	// 연산자일때
			if (stack.empty())
				stack.push(infix.at(i));
			else if (prec(stack.top()) > prec(infix.at(i)))
				stack.push(infix.at(i));
			else {
				while (!stack.empty() && prec(stack.top()) <= prec(infix.at(i))) {
					postfix.push_back(stack.top());
					stack.pop();
				}
				stack.push(infix.at(i));
			}
		}
	}

	while (!stack.empty()) {
		postfix.push_back(stack.top());
		stack.pop();
	}

	for (int i = 0; i < postfix.size(); i++)
		std::cout << postfix.at(i);

	return 0;
}

int prec(char ch) {
	switch (ch) {
	case '(' : case ')':
		return 0;
	case '*' : case '/':
		return 1;
	case '+' : case '-':
		return 2;
	}
}
*/

#include <iostream>
#include <stack>
#include <vector>

int prec(char ch);

int main() {
	std::string infix;
	std::vector<char> postfix;
	std::stack<char> stack;
	int is_bracket = 0;

	std::cin >> infix;

	for (int i = 0; i < infix.size(); i++) {
		if ('A' <= infix.at(i) && infix.at(i) <= 'Z')	// 피연산자일때
			postfix.push_back(infix.at(i));
		else {	// 연산자일때
			if(is_bracket != 0){
				if (infix.at(i) == '(')
					is_bracket++;
				if(stack.top() == '(')
					stack.push(infix.at(i));
				else {
					if (infix.at(i) == ')') {
						while (stack.top() != '(') {
							postfix.push_back(stack.top());
							stack.pop();
						}
						stack.pop();
						is_bracket--;
					}
					else if (prec(stack.top()) > prec(infix.at(i)))
						stack.push(infix.at(i));
					else {
						while (stack.top() != '(' && prec(stack.top()) <= prec(infix.at(i))) {
							postfix.push_back(stack.top());
							stack.pop();
						}
						stack.push(infix.at(i));
					}
				}
			}

			else {
				if (infix.at(i) == '(')
					is_bracket++;
				if (stack.empty())
					stack.push(infix.at(i));
				else if (prec(stack.top()) > prec(infix.at(i)))
					stack.push(infix.at(i));
				else {
					while (!stack.empty() && prec(stack.top()) <= prec(infix.at(i))) {
						postfix.push_back(stack.top());
						stack.pop();
					}
					stack.push(infix.at(i));
				}
			}
		}
	}

	while (!stack.empty()) {
		postfix.push_back(stack.top());
		stack.pop();
	}

	for (int i = 0; i < postfix.size(); i++)
		std::cout << postfix.at(i);

	return 0;
}

int prec(char ch) {
	switch (ch) {
	case '(': case ')':
		return 0;
	case '*': case '/':
		return 1;
	case '+': case '-':
		return 2;
	}
}
