/*
// 10872�� ����

#include <iostream>

int fac(int num) {
	if (num == 0)
		return 1;
	else 
		return num * fac(num - 1);
}

int main() {
	int N, num;
	std::cin >> N;

	num = fac(N);
	std::cout << fac(N);

	return 0;
}
*/

/*
// 10870�� ����

#include <iostream>

int fib(int num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else
		return fib(num - 1) + fib(num - 2);
}
int main() {
	int n;

	std::cin >> n;
	std::cout << fib(n);

	return 0;
}
*/

// 17478�� ����

#include <iostream>

void print(int N, int num) {
	if (num == 0) {
		for (int i = 0; i < N - num; i++)
			std::cout << "____";
		std::cout << "\"����Լ��� ������\?\"" << "\n";

		for (int i = 0; i < N - num; i++)
			std::cout << "____";
		std::cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";

		for (int i = 0; i < N - num; i++) 
			std::cout << "____";
		std::cout << "��� �亯�Ͽ���." << "\n";
		return;
	}

	if(num == N)
		std::cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";
	
	for (int i = 0; i < N-num; i++)
		std::cout << "____";
	std::cout << "\"����Լ��� ������ \?\"" << "\n";

	for (int i = 0; i < N-num; i++)
		std::cout << "____";
	std::cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";

	for (int i = 0; i < N-num; i++)
		std::cout << "____";
	std::cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";

	for (int i = 0; i < N-num; i++)
		std::cout << "____";
	std::cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";
	

	print(N, num - 1);
	
	for (int i = 0; i < N - num; i++) 
		std::cout << "____";
	
	std::cout << "��� �亯�Ͽ���." << "\n";

}
int main() {
	int N;

	std::cin >> N;

	print(N, N);
	return 0;
}