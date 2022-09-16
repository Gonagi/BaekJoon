/*
// 2739�� ����

#include <iostream>

void Multiplication_table(int N);

int main() {
	int N;

	try {
		std::cin >> N;
		if (N < 1 || N > 9)
			throw std::out_of_range("���� ���");

		Multiplication_table(N);
	}
	catch (std::out_of_range& e) {
		std::cout << "���� �߻� : " << e.what();
	}
	return 0;
}

void Multiplication_table(int N) {
	for (int i = 1; i <= 9; i++)
		std::cout << N << " * " << i << " = " << N * i << std::endl;
}
*/

/*
// 10950�� ����

#include <iostream>

int main() {
	int T, A, B, result[100];
	std::cin >> T;

	try{
		for (int i = 0; i < T; i++) {
			std::cin >> A >> B;
			if (A <= 0)
				throw(std::out_of_range("���� ���"));
			if (B >= 10)
				throw(std::out_of_range("���� ���"));
			result[i] = A + B;
		}

		for (int i = 0; i < T; i++)
			std::cout << result[i] << std::endl;
	}
	catch (std::out_of_range& e) {
		std::cout << "���� �߻� : " << e.what();
	}
	return 0;
}
*/

/*
// 8393�� ����
#include <iostream>

int main() {
	int n, sum = 0;

	try {
		std::cin >> n;
		if (n < 1 || n > 10000)
			throw std::out_of_range("n�� ������ ���");
		for (int i = 1; i <= n; i++)
			sum += i;
		std::cout << 6;
	}
	catch (std::out_of_range& e) {
		std::cerr << "���� �߻� : " << e.what();
	}
	return 0;
}
*/

/*
// 25304�� ����
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
*/
/*
// 15552�� ����

#include <iostream>

int main() {
	int T, A, B;

	std::ios_base::sync_with_stdio(false);	// C, C++ ����ȭ ����
	std::cin.tie(NULL);	// �Է°� ����� �и�

	try {
		std::cin >> T;
		if (T > 1000000)
			throw(std::out_of_range("���� ���"));

		for (int i = 0; i < T; i++) {
			std::cin >> A >> B;
			if (A < 1 || A > 1000) throw(std::out_of_range("���� ���"));
			if (B < 1 || B > 1000) throw(std::out_of_range("���� ���"));
			std::cout << A + B << "\n";
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "���� �߻� : " << e.what();
	}
	return 0;
}
*/

/*
// 2741�� ����

#include <iostream>

int main() {
	int N;
	std::ios_base::sync_with_stdio(false);	// C, C++ ����ȭ ����
	std::cin.tie(NULL);	// �Է°� ����� �и�

	try {
		std::cin >> N;
		if (N < 1 || N > 1000000)
			throw std::out_of_range("���� ���");
		for (int i = 1; i <= N; i++)
			std::cout << i << "\n";
	}
	catch (std::out_of_range& e) {
		std::cout << "���� �߻� : " << e.what();
	}

	return 0;
}
*/

/*
// 2742�� ����
#include <iostream>

int main() {
	int N;
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	try {
		std::cin >> N;
		if (N < 1 || N > 1000000)
			throw std::out_of_range("���� ���");
		for (int i = N; i >= 1; i--)
			std::cout << i << "\n";
	}
	catch (std::out_of_range& e) {
		std::cout << "���� �߻� : " << e.what();
	}

	return 0;
}
*/

/*
// 11021�� ���� 
#include <iostream>

int main() {
	int T, A, B;

	std::ios_base::sync_with_stdio(false);	// C, C++ ����ȭ ����
	std::cin.tie(NULL);	// �Է°� ����� �и�

	try {
		std::cin >> T;
		if (T > 1000000)
			throw(std::out_of_range("���� ���"));

		for (int i = 0; i < T; i++) {
			std::cin >> A >> B;
			if (A < 1 || A > 1000) throw(std::out_of_range("���� ���"));
			if (B < 1 || B > 1000) throw(std::out_of_range("���� ���"));
			std::cout << "Case #" << i + 1 << ": " << A + B << "\n";
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "���� �߻� : " << e.what();
	}
	return 0;
}
*/

// 11022�� ����
/*
#include <iostream>

int main() {
	int T, A, B;

	std::ios_base::sync_with_stdio(false);	// C, C++ ����ȭ ����
	std::cin.tie(NULL);	// �Է°� ����� �и�

	try {
		std::cin >> T;
		if (T > 1000000)
			throw(std::out_of_range("���� ���"));

		for (int i = 0; i < T; i++) {
			std::cin >> A >> B;
			if (A < 1 || A > 1000) throw(std::out_of_range("���� ���"));
			if (B < 1 || B > 1000) throw(std::out_of_range("���� ���"));
			std::cout << "Case #" << i + 1 << ": " << A << " + " << B << " = " << A + B << "\n";
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "���� �߻� : " << e.what();
	}
	return 0;
}
*/

/*
// 2438�� ����
#include <iostream>

int main() {
	int N;

	try {
		std::cin >> N;
		if (N < 1 || N > 100)
			throw std::out_of_range("���� ���");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++)
				std::cout << "*";
			std::cout << std::endl;
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "���� �߻� : " << e.what();
	}
	return 0;
}
*/

/*
// 2439�� ����
#include <iostream>

int main() {
	int N;

	try {
		std::cin >> N;
		if (N < 1 || N > 100)
			throw std::out_of_range("���� ���");
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
		std::cout << "���� �߻� : " << e.what();
	}
	return 0;
}
*/

/*
// 10871�� ����

#include <iostream>

int main() {
	int N, X, A[10000];

	try {
		std::cin >> N >> X;
		if (N < 1)
			throw std::out_of_range("N�� �Է¹����� ���");
		if(X > 10000)
			throw std::out_of_range("X�� �Է¹����� ���");

		for (int i = 0; i < N; i++)
			std::cin >> A[i];

		for (int i = 0; i < N; i++)
			if (A[i] < X)
				std::cout << A[i] << " ";
	}
	catch (std::out_of_range& e) {
		std::cerr << "���� �߻� : " << e.what();
	}
	return 0;
}
*/

/*
// 10952�� ����

#include <iostream>

int main() {
	int A, B;

	try {
		while (1) {
			std::cin >> A >> B;
			if (A == 0 && B == 0)
				break;
			if (A <= 0)
				throw std::out_of_range("A�� ���� ���");
			if (B >= 10)
				throw std::out_of_range("B�� ���� ���");

			std::cout << A + B << "\n";
		}
	}
	catch (std::out_of_range& e) {
		std::cerr << "���� �߻� : " << e.what();
	}
	
	return 0;
}
*/

/*
// 10951�� ����

#include <iostream>

int main() {
	int A, B;

	try {
		while (!(std::cin>>A>>B).eof()) {
			if (A <= 0)
				throw std::out_of_range("A�� ���� ���");
			if (B >= 10)
				throw std::out_of_range("B�� ���� ���");

			std::cout << A + B << "\n";
		}
	}
	catch (std::out_of_range& e) {
		std::cerr << "���� �߻� : " << e.what();
	}
	return 0;
}
*/

/*
// 1110�� ����

#include<iostream>

int Calculation(int);

int main() {
	int num;

	try {
		std::cin >> num;
		if (num < 0 || num > 99)
			throw std::out_of_range("num�� ������ ���");

		std::cout << Calculation(num);
	}
	catch (std::out_of_range& e) {
		std::cerr << "���� �߻� : " << e.what();
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