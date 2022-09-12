/*
// 11005번 문제

#include <iostream>
#include <string>
#include <algorithm>

char arr[37]{ '0','1','2','3','4','5','6','7','8','9',
			'A','B','C','D','E','F','G','H','I','J','K','L','M',
			'N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
int main() {
	long long N;
	int B;
	std::string result;

	std::cin >> N >> B;

	if (N == 0) {
		std::cout << 0;
		return 0;
	}

	while (N) {
		result += arr[N % B];
		N /= B;
	}

	std::reverse(result.begin(), result.end());
	std::cout << result;
	return 0;
}
*/

/*
// 2745번 문제

#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string N;
	int B;
	long long result = 0, check = 1;

	std::cin >> N >> B;


	std::reverse(N.begin(), N.end());

	for (int i = 0; i < static_cast<int>(N.size()); i++) {
		if ('A' <= N.at(i) && N.at(i) <= 'Z')
			result += (static_cast<long long>(N.at(i) - 'A') + 10) * check;
		else
			result += (static_cast<long long>(N.at(i) - '0')) * check;
		check *= B;
	}

	std::cout << result;
	return 0;
}	
*/

// 11576번 문제

#include<iostream>
#include <stack>

int main() {
	int A, B, m, input;
	long long sum = 0, cal = 1;
	std::stack<int> result;

	std::cin >> A >> B;
	std::cin >> m;

	for (int i = 0; i < m - 1; i++)
		cal *= A;

	while (cal) {
		std::cin >> input;
		sum += input * cal;
		cal /= A;
	}

	while (sum) {
		result.push(sum % B);
		sum /= B;
	}

	while (!result.empty()) {
		std::cout << result.top() << ' ';
		result.pop();
	}
	return 0;
}