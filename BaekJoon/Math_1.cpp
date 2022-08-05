/*
// 1712번 문제

#include <iostream>

int main() {
	long long A, B, C, result;
	std::cin >> A >> B >> C;

	if (B >= C)
		std::cout << -1;
	else {
		result = A / (C - B);
		std::cout << result + 1;
	}

	return 0;
}
*/

// 2292번 문제

#include <iostream>

int main() {
	int N, sum = 1, i= 1;
	std::cin >> N;

	for(; sum < N; i++)
		sum += (i*6);

	if (N == 1)
		i = 1;
	std::cout << i;
	return 0;
}