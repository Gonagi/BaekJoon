/*
// 9613번 문제

#include <iostream>
#include <vector>
#include <algorithm>

long long GCD(long long num1, long long num2);

int main() {
	int t, n;
	long long num, result = 0;
	std::vector<long long> vec;

	std::cin >> t;

	for (int i = 0; i < t; i++) {
		std::cin >> n;
		for (int j = 0; j < n; j++) {
			std::cin >> num;
			vec.push_back(num);
		}

		for (int a = 0; a < n - 1; a++)
			for (int b = a+1; b < n; b++)
				result += GCD(vec.at(a), vec.at(b));

		std::cout << result << "\n";
		result = 0;
		for (int j = 0; j < n; j++)
			vec.pop_back();
	}
	return 0;
}

long long GCD(long long num1, long long num2) {
	if (num2 == 0) return num1;
	return GCD(num2, num1 % num2);
}
*/

/*
// 17087번 문제

#include <iostream>
#include <vector>
#include <cstdlib>

long long GCD(long long num1, long long num2);

int main() {
	long long N, S, num, result;
	std::vector<long long> A_distance;

	std::cin >> N >> S;

	for (int i = 0; i < N; i++) {
		std::cin >> num;
		A_distance.push_back(std::abs(S-num));
	}
	
	result = A_distance.at(0);
	for (int i = 1; i < A_distance.size(); i++) 
		result = GCD(result, A_distance.at(i));
	
	std::cout << result;

	return 0;
}

long long GCD(long long num1, long long num2) {
	if (num2 == 0)return num1;
	return GCD(num2, num1 % num2);
}
*/


// 1373번 문제

/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string binary;
	cin >> binary;

	int len = binary.length();
	int i = 0;
	if (len % 3 == 1) {
		cout << binary[0];
		i = 1;
	}
	else if (len % 3 == 2) {
		cout << ((binary[0] - '0') * 2) + (binary[1] - '0');
		i = 2;
	}

	for (; i < len; i += 3)	
		cout << ((binary[i] - '0') * 4) + ((binary[i + 1] - '0') * 2) + (binary[i + 2] - '0');

	cout << '\n';

	return 0;
}


#include <iostream>
#include <stack>

int main() { 
	int num, input, cal = 1, result = 0;
	std::stack<int> stack;
	std::cin >> input;
	if (input == 0)
		std::cout << 0;
	else {
		while (input) {
			num = input % 1000;
			while (num) {
				result += (num % 10) * cal;
				num /= 10;
				cal *= 2;
			}
			stack.push(result);
			input /= 1000;

			result = 0;
			cal = 1;
		}
		while (!stack.empty()) {
			std::cout << stack.top();
			stack.pop();
		}
	}
	return 0;
}
*/

/*
// 1212번 문제
#include <iostream>
#include <string>
#include <stack>

int main() {
	std::string str;
	int num;
	std::stack<std::string> stack;
	std::cin >> str;

	for (int i = static_cast<int>(str.length()) - 1; i >= 1; i--) {
		std::string result;
		num = str.at(i) - '0';

		if (num - 4 >= 0) {
			result = "1";
			num -= 4;
		}
		else
			result = "0";
		if (num - 2 >= 0) {
			result += "1";
			num -= 2;
		}
		else
			result += "0";
		if (num - 1 >= 0) {
			result += "1";
			num -= 1;
		}
		else
			result += "0";
		stack.push(result);

	}

	
	int result2 = 0;
	num = str.at(0) - '0';
	if (num == 0)
		stack.push("0");
	else {
		if (num - 4 >= 0) {
			result2 += 100;
			num -= 4;
		}
		if (num - 2 >= 0) {
			result2 += 10;
			num -= 2;
		}
		if (num - 1 >= 0) {
			result2 += 1;
			num -= 1;
		}
		
		stack.push(std::to_string(result2));
	}

	while (!stack.empty()) {
		std::cout << stack.top();
		stack.pop();
	}
	return 0;
}


#include <iostream>
#include <string>

int main() {
	std::string octal;
	std::cin >> octal;

	if (octal == "0")
		std::cout << 0;

	std::string result;
	for (int i = 0; i < octal.length(); i++) {
		result += std::to_string((octal.at(i) - '0') / 4);		// 0
		result += std::to_string(((octal.at(i) - '0') % 4) / 2);	// 1
		result += std::to_string(((octal.at(i) - '0') % 4) % 2);	// 1
	}

	bool flag = false;

	for (int i = 0; i < result.length(); i++) {
		if (!flag) {
			if (result[i] == '1') {
				flag = true;
				std::cout << result[i];
			}
		}
		else
			std::cout << result[i];	
	}

	std::cout << "\n";
	return 0;
}
*/

// 2089번 문제

#include <iostream>
#include <string>

int main() {
	long long N, result = 0, num = 1;
	std::string str;

	std::cin >> N;

	while (1) {
		result += num;

		if (N <= result)
			break;
		num *= 4;
	}

	for (int i = num; i >= 1; i /= 2) {
		if (N == num) {
			std::cout << 1;
			result = num;
		}
		else {
			if (N <= (result - num)) {
				std::cout << 1;
				result -= num;
			}
			else {
				std::cout << 0;
			}
		}
	}
	return 0;
}