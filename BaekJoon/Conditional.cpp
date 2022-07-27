/*
* 1330번 문제
#include <iostream>

int main() {
	int A, B;

	try {
		std::cin >> A >> B;
		if (A < -10000 || A > 10000)
			throw std::out_of_range("'A' 범위 벗어남");
		if (B < -10000 || B > 10000)
			throw std::out_of_range("'B' 범위 벗어남");
	}
	catch (std::out_of_range& e) {
		std::cout << "예외발생 : " << e.what();
	}

	if (A > B)
		std::cout << ">";
	else if (A == B)
		std::cout << "==";
	else
		std::cout << "<";

	return 0;
}
*/

/*
// 9498번 문제
#include <iostream>

int main() {
	int score;
	try {
		std::cin >> score;
		if (score < 0 || score > 100)
			throw std::out_of_range("점수 score가 범위를 벗어났다");

		if (90 <= score && score <= 100)
			std::cout << "A";
		else if (80 <= score && score <= 89)
			std::cout << "B";
		else if (70 <= score && score <= 79)
			std::cout << "C";
		else if (60 <= score && score <= 69)
			std::cout << "D";
		else
			std::cout << "F";
	}
	catch (std::out_of_range& e) {
		std::cout << "예외발생 : " << e.what();	
	}

	return 0;
}
*/

/*
// 2753번 문제
#include <iostream>

int main() {
	int year;

	try {
		std::cin >> year;
		if (year < 1 || year > 4000)
			throw std::out_of_range("'year' 범위 벗어남");

		if (year % 400 == 0)
			std::cout << 1;
		else if (year % 4 == 0 && year % 100 != 0)
			std::cout << 1;
		else
			std::cout << 0;
	}
	catch (std::out_of_range& e) {
		std::cout << "예외발생 : " << e.what();
	}

	return 0;
}
*/

/*
// 14681번 문제
#include <iostream>

int main() {
	int x, y;
	
	try {
		std::cin >> x;
		std::cin >> y;

		if (x < -1000 || x > 1000 || x == 0)
			throw std::out_of_range("'x' 범위 벗어남");
		if (y < -1000 || y > 1000 || y == 0)
			throw std::out_of_range("'y' 범위 벗어남");

		if (x > 0 && y > 0)
			std::cout << 1;
		else if (x < 0 && y > 0)
			std::cout << 2;
		else if (x < 0 && y < 0)
			std::cout << 3;
		else
			std::cout << 4;
	}
	catch (std::out_of_range& e) {
		std::cout << "예외발생 : " << e.what();
	}
	return 0;
}
*/

/*
// 2884번 문제
#include <iostream>

int main() {
	int H, M;

	try {
		std::cin >> H >> M;
		if (H < 0 || H > 23)
			throw std::out_of_range("'시' 범위 벗어남");
		if (M < 0 || M > 59)
			throw std::out_of_range("'분' 범위 벗어남");

		if (M < 45) {
			M += 15;
			if (H == 0)
				H = 23;
			else
				H -= 1;
		}
		else
			M -= 45;
		
		std::cout << H << " " << M;
	}
	catch (std::out_of_range& e) {
		std::cout << "예외발생 : " << e.what();
	}
	return 0;
}
*/

/*
// 2525번 문제
#include <iostream>

int main() {
	int A, B, C;

	try {
		std::cin >> A >> B;

		if (A < 0 || A > 23)
			throw std::out_of_range("'시' 범위 벗어남");
		if (B < 0 || B > 59)
			throw std::out_of_range("'분' 범위 벗어남");

		std::cin >> C;

		if (C < 0 || C > 1000)
			throw std::out_of_range("'요리하는데 필요한 시간' 범위 벗어남");

		B += C;
		A += B / 60;
		B = B % 60;

		if (A > 23)
			A -= 24;

		std::cout << A << " " << B;
	}
	catch(std::out_of_range& e) {
		std::cout << "예외 발생 : " << e.what() << std::endl;
	}
	return 0;
}
*/

#include <iostream>

int main() {
	int num1, num2, num3, money;

	try {
		std::cin >> num1 >> num2 >> num3;
		if (num1 < 1 || num2 < 1 || num3 < 1 ||
			6 < num1 || 6 < num2 || 6 < num3)
			throw std::out_of_range("주사위 범위 벗어남");

		if (num1 == num2 && num2 == num3)
			money = 10000 + (num1 * 1000);
		else if (num1 == num2 && num2 != num3)
			money = 1000 + num1 * 100;
		else if (num1 == num3 && num2 != num3)
			money = 1000 + num1 * 100;
		else if (num2 == num3 && num2 != num1)
			money = 1000 + num2 * 100;
		else {
			int big_num = num1;
			if (big_num < num2)
				big_num = num2;
			if (big_num < num3)
				big_num = num3;
			money = big_num * 100;
		}
		std::cout << money;
	}
	catch (std::out_of_range& e) {
		std::cout << "예외 발생 : " << e.what();
	}
	return 0;
}