/*
2557번 문제

#include <iostream>

int main() {
	std::cout << "Hello World!";
}
*/

/*
10718 문제
#include <iostream>

int main() {
	std::cout << "강한친구 대한육군" << std::endl << "강한친구 대한육군";
	
	return 0;
}
*/

/*
* 10171번 문제
#include <iostream>

int main() {
	std::cout << "\\    /\\" << std::endl;
	std::cout << " )  ( \')" << std::endl;
	std::cout << "(  /  )" << std::endl;
	std::cout << " \\(__)|" << std::endl;

	return 0;
}
*/

/*
* 10172번 문제
#include <iostream>

int main() {
	std::cout << "|\\_/|" << std::endl;
	std::cout << "|q p|   /}" << std::endl;
	std::cout << "( 0 )\"\"\"\\" << std::endl;
	std::cout << "|\"^\"\`    |" << std::endl;
	std::cout << "||_/=\\\\__|" << std::endl;

	return 0;
}
*/

/*
* 1000번 문제
#include <iostream>

int main() {
	int A, B;

	std::cin >> A;
	std::cin >> B;

	std::cout << A + B;
	return 0;
}
*/

/*
*  1001번 문제
#include <iostream>

int main() {
	int A, B;

	std::cin >> A;
	std::cin >> B;

	std::cout << A - B;
	return 0;
}
*/

/*
* 10998번 문제
#include <iostream>

int main() {
	int A, B;

	std::cin >> A;
	std::cin >> B;

	std::cout << A * B;

	return 0;
}
*/

/*
* 10926번 문제
#include <iostream>

int main() {
	std::string s;
	std::cin >> s;

	s += "??!";
	std::cout << s;

	return 0;
}
*/

/*
* 18108번 문제
#include <iostream>

int main() {
	int year;

	std::cin >> year;
	year -= 543;

	std::cout << year;

	return 0;
}
*/

// 3003번 문제
#include <iostream>
#include <vector>

int main() {
	int num;
	std::vector<int> vec = { 1, 1, 2, 2, 2, 8 };

	for (int i = 0; i < 6; i++) {
		std::cin >> num;
		vec.push_back(((-1) * num) + vec.at(i));
	}

	for (int i = 6; i < 12; i++)
		std::cout << vec.at(i) << " ";


	return 0;
}

/*
// 10430번 문제
#include <iostream>

int main() {
	int A, B, C;

	try {
		std::cin >> A >> B >> C;

		if (A < 2 || B < 2 || C < 2
			|| A > 10000 || B > 10000 || C > 10000)
			throw "범위 이탈";

		std::cout << (A + B) % C << std::endl;
		std::cout << ((A % C) + (B % C)) % C << std::endl;
		std::cout << (A * B) % C << std::endl;
		std::cout << ((A % C) * (B % C)) % C << std::endl;
	}
	catch(const char* s) {
		std::cout << s << std::endl;
	}
	return 0;
}
*/
/*
* 2588번 문제
#include <iostream>

int main() {
	int num1, num2;
	
	std::cin >> num1;
	std::cin >> num2;

	std::cout << num1 * (num2 % 10) << std::endl;
	std::cout << num1 * ((num2 % 100)/ 10) << std::endl;
	std::cout << num1 * (num2 / 100) << std::endl;

	std::cout << num1 * num2 << std::endl;
	return 0;
}
*/