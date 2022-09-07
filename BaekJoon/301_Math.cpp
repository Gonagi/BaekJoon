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

// 17087번 문제

#include <iostream>
#include <vector>
#include <cstdlib>

int GCD(int num1, int num2);

int main() {
	long long N, S, num;
	std::vector<long long> A_distance;

	std::cin >> N >> S;

	for (int i = 0; i < N; i++) {
		std::cin >> num;
		A_distance.push_back(std::abs(S-num));
	}


	return 0;
}

int GCD(int num1, int num2) {
	if (num1 == 0)return num2;
	return GCD(num2, num1%num2)
}