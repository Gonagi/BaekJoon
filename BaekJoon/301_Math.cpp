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

#include <iostream>
#include <stack>

int main() {
	long long input; 
	int num, cal = 1, result = 0;
	std::stack<int> stack;
	std::cin >> input;

	while (input) {
		num = input % 1000;
		while (num) {
			result += (num % 10)* cal;
			num /= 10;
			cal *= 2;
		}
		stack.push(result);
		input /= 1000;
		
		result = 0;
		cal = 1;
	}
	return 0;
}