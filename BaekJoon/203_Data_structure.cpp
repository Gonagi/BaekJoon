// 1935번 문제

#include <iostream>
#include <stack>
#include <vector>
#include <string>

void pop_num(double& num1, double& num2, std::stack<double>& operand_stack);
double calculate(std::stack<int>& operator_stack, double& num1, double& num2);

int main() {
	char alphabet = 'A';
	int N, count = 0;
	double num,num1, num2, result;
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
