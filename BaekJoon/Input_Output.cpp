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