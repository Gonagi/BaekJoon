/*
// 1978번 문제

#include <iostream>

bool IsPrime(int num) {
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0) return false;
	if (num == 1)
		return false;
	return true;
}

int main() {
	int N, num, result = 0;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> num;

		if (IsPrime(num))
			result++;
	}
	std::cout << result;

	return 0;
}
*/

/*
// 2581먼 문제
#include <iostream>
#include <algorithm>

bool Is_prime(int num) {
	for (int i = 2; i * i <= num; i++) 
		if (num % i == 0)
			return false;
	if (num == 1)
		return false;
	return true;
}

int main() {
	int N, M, sum = 0, min;

	std::cin >> M >> N;
	min = N;

	for (int i = M; i <= N; i++) {
		if (Is_prime(i)) {
			sum += i;
			min = std::min(min, i);
		}
	}
	if (sum == 0) 
		std::cout << -1;
	
	else
		std::cout << sum << "\n" << min;
	return 0;
}
*/

/*
// 11653번 문제

#include <iostream>

void Is_prime(int num) {
	for (int i = 2; i*i <= num; i++) {
		 while(num % i == 0) {
			std::cout << i << "\n";
			num /= i;
		}
	}

	if (num > 1)
		std::cout << num << "\n";
}

int main() {
	int N;

	std::cin >> N;
	
	Is_prime(N);
	return 0;
}
*/


/*
// 1929번 문제

#include <iostream>
bool Is_prime(int num) {
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0)
			return false;
	if (num == 1)
		return false;
	return true;
}

int main() {
	int M, N;

	std::cin >> M >> N;

	for (int i = M; i <= N; i++) {
		if (Is_prime(i))
			std::cout << i << "\n";
	}
	return 0;
}
*/

/*
// 4948번 문제

#include<iostream>

bool Is_prime(int num) {
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0)
			return false;
	if (num == 1)
		return false;
	return true;
}

int main() {
	int n, result = 0;

	while (1) {
		result = 0;

		std::cin >> n;

		if (n == 0)
			break;

		for (int i = n + 1; i <= 2 * n; i++)
			if (Is_prime(i))
				result++;

		std::cout << result << "\n";
	}

	return 0;
}
*/

#include <iostream>

bool Is_prime(int num) {
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0)
			return false;
	if (num == 1)
		return false;
	return true;
}

int main() {
	int T, num;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> num;
		for (int j = num / 2; j >= 1; j--) 
			if (Is_prime(j) && Is_prime(num - j)) {
				std::cout << j << " " << num - j << "\n";
				break;
			}
	}
	return 0;
}