/*
// 2739번 문제

#include <iostream>

void Multiplication_table(int N);

int main() {
	int N;

	try {
		std::cin >> N;
		if (N < 1 || N > 9)
			throw std::out_of_range("범위 벗어남");

		Multiplication_table(N);
	}
	catch (std::out_of_range& e) {
		std::cout << "오류 발생 : " << e.what();
	}
	return 0;
}

void Multiplication_table(int N) {
	for (int i = 1; i <= 9; i++)
		std::cout << N << " * " << i << " = " << N * i << std::endl;
}
*/

/*
// 10950번 문제

#include <iostream>

int main() {
	int T, A, B, result[100];
	std::cin >> T;

	try{
		for (int i = 0; i < T; i++) {
			std::cin >> A >> B;
			if (A <= 0)
				throw(std::out_of_range("범위 벗어남"));
			if (B >= 10)
				throw(std::out_of_range("범위 벗어남"));
			result[i] = A + B;
		}

		for (int i = 0; i < T; i++)
			std::cout << result[i] << std::endl;
	}
	catch (std::out_of_range& e) {
		std::cout << "오류 발생 : " << e.what();
	}
	return 0;
}
*/

/*
// 8393번 문제
#include <iostream>

int main() {
	int n, sum = 0;

	try {
		std::cin >> n;
		if (n < 1 || n > 10000)
			throw std::out_of_range("n이 범위를 벗어남");
		for (int i = 1; i <= n; i++)
			sum += i;
		std::cout << 6;
	}
	catch (std::out_of_range& e) {
		std::cerr << "오류 발생 : " << e.what();
	}
	return 0;
}
*/

// 25304번 문제
#include <iostream>

int main() {
	int X, N, a, b, sum = 0;

	std::cin >> X;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> a >> b;
		sum += (a * b);
	}

	if (sum == X)
		std::cout << "Yes";
	else
		std::cout << "No";

	return 0;
}
/*
// 15552번 문제

#include <iostream>

int main() {
	int T, A, B;

	std::ios_base::sync_with_stdio(false);	// C, C++ 동기화 해제
	std::cin.tie(NULL);	// 입력과 출력을 분리

	try {
		std::cin >> T;
		if (T > 1000000)
			throw(std::out_of_range("범위 벗어남"));

		for (int i = 0; i < T; i++) {
			std::cin >> A >> B;
			if (A < 1 || A > 1000) throw(std::out_of_range("범위 벗어남"));
			if (B < 1 || B > 1000) throw(std::out_of_range("범위 벗어남"));
			std::cout << A + B << "\n";
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "오류 발생 : " << e.what();
	}
	return 0;
}
*/

/*
// 2741번 문제

#include <iostream>

int main() {
	int N;
	std::ios_base::sync_with_stdio(false);	// C, C++ 동기화 해제
	std::cin.tie(NULL);	// 입력과 출력을 분리

	try {
		std::cin >> N;
		if (N < 1 || N > 1000000)
			throw std::out_of_range("범위 벗어남");
		for (int i = 1; i <= N; i++)
			std::cout << i << "\n";
	}
	catch (std::out_of_range& e) {
		std::cout << "오류 발생 : " << e.what();
	}

	return 0;
}
*/

/*
// 2742번 문제
#include <iostream>

int main() {
	int N;
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	try {
		std::cin >> N;
		if (N < 1 || N > 1000000)
			throw std::out_of_range("범위 벗어남");
		for (int i = N; i >= 1; i--)
			std::cout << i << "\n";
	}
	catch (std::out_of_range& e) {
		std::cout << "오류 발생 : " << e.what();
	}

	return 0;
}
*/

/*
// 11021번 문제 
#include <iostream>

int main() {
	int T, A, B;

	std::ios_base::sync_with_stdio(false);	// C, C++ 동기화 해제
	std::cin.tie(NULL);	// 입력과 출력을 분리

	try {
		std::cin >> T;
		if (T > 1000000)
			throw(std::out_of_range("범위 벗어남"));

		for (int i = 0; i < T; i++) {
			std::cin >> A >> B;
			if (A < 1 || A > 1000) throw(std::out_of_range("범위 벗어남"));
			if (B < 1 || B > 1000) throw(std::out_of_range("범위 벗어남"));
			std::cout << "Case #" << i + 1 << ": " << A + B << "\n";
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "오류 발생 : " << e.what();
	}
	return 0;
}
*/

// 11022번 문제
/*
#include <iostream>

int main() {
	int T, A, B;

	std::ios_base::sync_with_stdio(false);	// C, C++ 동기화 해제
	std::cin.tie(NULL);	// 입력과 출력을 분리

	try {
		std::cin >> T;
		if (T > 1000000)
			throw(std::out_of_range("범위 벗어남"));

		for (int i = 0; i < T; i++) {
			std::cin >> A >> B;
			if (A < 1 || A > 1000) throw(std::out_of_range("범위 벗어남"));
			if (B < 1 || B > 1000) throw(std::out_of_range("범위 벗어남"));
			std::cout << "Case #" << i + 1 << ": " << A << " + " << B << " = " << A + B << "\n";
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "오류 발생 : " << e.what();
	}
	return 0;
}
*/

/*
// 2438번 문제
#include <iostream>

int main() {
	int N;

	try {
		std::cin >> N;
		if (N < 1 || N > 100)
			throw std::out_of_range("범위 벗어남");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++)
				std::cout << "*";
			std::cout << std::endl;
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "오류 발생 : " << e.what();
	}
	return 0;
}
*/

/*
// 2439번 문제
#include <iostream>

int main() {
	int N;

	try {
		std::cin >> N;
		if (N < 1 || N > 100)
			throw std::out_of_range("범위 벗어남");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (j < N - i - 1)
					std::cout << " ";
				else
					std::cout << "*";
			}
			std::cout << std::endl;
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "오류 발생 : " << e.what();
	}
	return 0;
}
*/

/*
// 10871번 문제

#include <iostream>

int main() {
	int N, X, A[10000];

	try {
		std::cin >> N >> X;
		if (N < 1)
			throw std::out_of_range("N이 입력범위를 벗어남");
		if(X > 10000)
			throw std::out_of_range("X가 입력범위를 벗어남");

		for (int i = 0; i < N; i++)
			std::cin >> A[i];

		for (int i = 0; i < N; i++)
			if (A[i] < X)
				std::cout << A[i] << " ";
	}
	catch (std::out_of_range& e) {
		std::cerr << "오류 발생 : " << e.what();
	}
	return 0;
}
*/

/*
// 10952번 문제

#include <iostream>

int main() {
	int A, B;

	try {
		while (1) {
			std::cin >> A >> B;
			if (A == 0 && B == 0)
				break;
			if (A <= 0)
				throw std::out_of_range("A가 범위 벗어남");
			if (B >= 10)
				throw std::out_of_range("B가 범위 벗어남");

			std::cout << A + B << "\n";
		}
	}
	catch (std::out_of_range& e) {
		std::cerr << "오류 발생 : " << e.what();
	}
	
	return 0;
}
*/

/*
// 10951번 문제

#include <iostream>

int main() {
	int A, B;

	try {
		while (!(std::cin>>A>>B).eof()) {
			if (A <= 0)
				throw std::out_of_range("A가 범위 벗어남");
			if (B >= 10)
				throw std::out_of_range("B가 범위 벗어남");

			std::cout << A + B << "\n";
		}
	}
	catch (std::out_of_range& e) {
		std::cerr << "오류 발생 : " << e.what();
	}
	return 0;
}
*/

/*
// 1110번 문제

#include<iostream>

int Calculation(int);

int main() {
	int num;

	try {
		std::cin >> num;
		if (num < 0 || num > 99)
			throw std::out_of_range("num이 범위를 벗어남");

		std::cout << Calculation(num);
	}
	catch (std::out_of_range& e) {
		std::cerr << "오류 발생 : " << e.what();
	}
	return 0;
}

int Calculation(int num) {
	int new_num = num, count = 0;

	while (1) {
		if (new_num < 10)
			new_num = new_num * 10 + new_num;
		else {
			if ((new_num / 10) + (new_num % 10) < 10)
				new_num = (new_num % 10) * 10 + (new_num / 10) + (new_num % 10);
			else
				new_num = (new_num % 10) * 10 + ((new_num / 10) + (new_num % 10)) % 10;
		}
		count++;

		if (new_num == num)
			break;
	}
	return count;
}
*/