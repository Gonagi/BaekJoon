/*
2557�� ����

#include <iostream>

int main() {
	std::cout << "Hello World!";
}
*/

/*
10718 ����
#include <iostream>

int main() {
	std::cout << "����ģ�� ��������" << std::endl << "����ģ�� ��������";
	
	return 0;
}
*/

/*
* 10171�� ����
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
* 10172�� ����
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
* 1000�� ����
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
*  1001�� ����
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
* 10998�� ����
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
* 10926�� ����
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
* 18108�� ����
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