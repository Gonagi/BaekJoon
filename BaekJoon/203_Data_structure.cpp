// 1935�� ����

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
			str.at(i) == '+' || str.at(i) == '-') {										// ������
			operator_stack.push(str.at(i));
			count = 0;
		}
		else {	// �ǿ�����
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
		if ('A' <= str[i] && str[i] <= 'Z')	// �ǿ�����
			stack.push(vector[str[i] - 'A']);
		else {
			if (!stack.empty()) {	// ������
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
		if('A' <=infix.at(i) && infix.at(i) <= 'Z')	// �ǿ������϶�
			postfix.push_back(infix.at(i));
		else {	// �������϶�
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

/*
#include <iostream>
#include <stack>

int prec(char ch);

int main() {
	std::string infix;
	std::stack<char> stack;

	std::cin >> infix;

	for (int i = 0; i < infix.size(); i++) {
		if ('A' <= infix.at(i) && infix.at(i) <= 'Z')	// �ǿ������϶�
			std::cout << infix.at(i);
		else {	// �������϶�
			if (stack.empty() || infix.at(i) == '(')
				stack.push(infix.at(i));
			else if (infix.at(i) == ')') {
				while (stack.top() != '(') {
					std::cout << stack.top();
					stack.pop();
				}
				stack.pop();
			}
			else if (prec(stack.top()) > prec(infix.at(i)) || stack.top() == '(')
				stack.push(infix.at(i));
			else{
				while (!stack.empty() && prec(stack.top()) <= prec(infix.at(i))) {
					if (stack.top() == '(')
						break;
					std::cout << stack.top();
					stack.pop();
				}
				stack.push(infix.at(i));
			}
		}	
	}

	while (!stack.empty()) {
		if (stack.top() == '(' || stack.top() == ')')
			stack.pop();
		std::cout << stack.top();
		stack.pop();
	}
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
*/

/*
// 10808�� ����
#include <iostream>

int main() {
	int alphabet_num[26]{ 0 };
	std::string str;

	std::cin >> str;

	for (int i = 0; i < str.size(); i++)
		alphabet_num[str.at(i) - 'a']++;

	for(int i = 0; i < 26; i++)
		std::cout << alphabet_num[i] << " ";
	return 0;
}
*/

/*
// 10820�� ����
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {		// ���ڿ��� �Է¹��� ������ �ݺ�
		int a = 0, b = 0, c = 0, d = 0;
		for (int i = 0; i < s.size(); i++) {	// ���ڿ��� ���̸��� �ݺ�
			if (s[i] >= 'a' && s[i] <= 'z') a++;
			else if (s[i] >= 'A' && s[i] <= 'Z') b++;
			else if (s[i] >= '0' && s[i] <= '9') c++;
			else if (s[i] == ' ') d++;
		}
		cout << a << " " << b << " " << c << " " << d << '\n';
	}
	return 0;
}
*/

/*
// 2743�� ����
#include <iostream>

int main() {
	std::string str;
	std::cin >> str;

	std::cout << str.length();
	return 0;
}
*/

/*
// 11655�� ����
#include <iostream>
#include <string>
#include <vector>

int main() {
	char ch;
	std::string str;
	std::vector<char> ROT13_str;
	std::getline(std::cin, str);

	for (int i = 0; i < str.length(); i++) {
		ch = str.at(i);
		if (isupper(str.at(i))) {
			if ('A' <= ch - 13)
				ch -= 13;
			else
				ch += 13;
		}

		else if (islower(str.at(i))) {
			if ('a' <= ch - 13)
				ch -= 13;
			else
				ch += 13;
		}
		ROT13_str.push_back(ch);
	}

	for (int i = 0; i < ROT13_str.size(); i++)
		std::cout << ROT13_str.at(i);
	return 0;
}
*/

/*
// 10824�� ����

#include <iostream>

int main() {
	long long A, B, C, D, num1, num2, count1 = 0, count2 = 0, check1, check2;

	std::cin >> A >> B >> C >> D;
	check1 = B;
	check2 = D;

	while (check1) {
		check1 /= 10;
		count1++;
	}

	while (check2) {
		check2 /= 10;
		count2++;
	}

	for (int i = 0; i < count1; i++)
		A *= 10;

	for (int i = 0; i < count2; i++)
		C *= 10;

	num1 = A + B;
	num2 = C + D;

	std::cout << num1 + num2;

	return 0;
}
*/

/*
// 11656�� ����

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
	std::string str;
	std::vector<std::string> vec;
	
	std::cin >> str;

	for (int i = 0; i < 8; i++) 
		vec.push_back(str.substr(i, str.length()));

	std::sort(vec.begin(), vec.end());

	for (int i = 0; i < 8; i++)
		std::cout << vec.at(i) << "\n";

	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main(void){
	string s;
	cin >> s;
	vector<string> v;

	for (int i = 0; i < s.length(); i++)
		v.push_back(s.substr(i, s.length()));

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	return 0;
}
*/

/*
// 2920�� ����

#include <iostream>
#include <vector>

int main() {
	int n;
	std::vector<int> num;

	for (int i = 0; i < 8; i++) {
		std::cin >> n;
		num.push_back(n);
	}

	for (int i = 1; i < 8; i++) {
		if (num.at(i) != (num.at(i - 1) + 1) && num.at(i) != (num.at(i - 1) - 1)) {
			std::cout << "mixed";
			return 0;
		}
	}
	
	if (num.at(1) == num.at(0) + 1)
		std::cout << "ascending";
	else
		std::cout << "descending";
	return 0;
}
*/

/*
// 2475�� ����

#include <iostream>

int main() {
	int num, square = 0;

	for (int i = 0; i < 5; i++) {
		std::cin >> num;
		square += (num * num);
	}

	std::cout << square % 10;

	return 0;
}
*/