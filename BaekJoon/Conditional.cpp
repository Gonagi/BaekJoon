/*
* 1330�� ����
#include <iostream>

int main() {
	int A, B;

	try {
		std::cin >> A >> B;
		if (A < -10000 || A > 10000)
			throw std::out_of_range("'A' ���� ���");
		if (B < -10000 || B > 10000)
			throw std::out_of_range("'B' ���� ���");
	}
	catch (std::out_of_range& e) {
		std::cout << "���ܹ߻� : " << e.what();
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
// 9498�� ����
#include <iostream>

int main() {
	int score;
	try {
		std::cin >> score;
		if (score < 0 || score > 100)
			throw std::out_of_range("���� score�� ������ �����");

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
		std::cout << "���ܹ߻� : " << e.what();	
	}

	return 0;
}
*/

/*
// 2753�� ����
#include <iostream>

int main() {
	int year;

	try {
		std::cin >> year;
		if (year < 1 || year > 4000)
			throw std::out_of_range("'year' ���� ���");

		if (year % 400 == 0)
			std::cout << 1;
		else if (year % 4 == 0 && year % 100 != 0)
			std::cout << 1;
		else
			std::cout << 0;
	}
	catch (std::out_of_range& e) {
		std::cout << "���ܹ߻� : " << e.what();
	}

	return 0;
}
*/

/*
// 14681�� ����
#include <iostream>

int main() {
	int x, y;
	
	try {
		std::cin >> x;
		std::cin >> y;

		if (x < -1000 || x > 1000 || x == 0)
			throw std::out_of_range("'x' ���� ���");
		if (y < -1000 || y > 1000 || y == 0)
			throw std::out_of_range("'y' ���� ���");

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
		std::cout << "���ܹ߻� : " << e.what();
	}
	return 0;
}
*/

/*
// 2884�� ����
#include <iostream>

int main() {
	int H, M;

	try {
		std::cin >> H >> M;
		if (H < 0 || H > 23)
			throw std::out_of_range("'��' ���� ���");
		if (M < 0 || M > 59)
			throw std::out_of_range("'��' ���� ���");

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
		std::cout << "���ܹ߻� : " << e.what();
	}
	return 0;
}
*/

/*
// 2525�� ����
#include <iostream>

int main() {
	int A, B, C;

	try {
		std::cin >> A >> B;

		if (A < 0 || A > 23)
			throw std::out_of_range("'��' ���� ���");
		if (B < 0 || B > 59)
			throw std::out_of_range("'��' ���� ���");

		std::cin >> C;

		if (C < 0 || C > 1000)
			throw std::out_of_range("'�丮�ϴµ� �ʿ��� �ð�' ���� ���");

		B += C;
		A += B / 60;
		B = B % 60;

		if (A > 23)
			A -= 24;

		std::cout << A << " " << B;
	}
	catch(std::out_of_range& e) {
		std::cout << "���� �߻� : " << e.what() << std::endl;
	}
	return 0;
}
*/

/*
// 2480�� ����
#include <iostream>

int main() {
	int num1, num2, num3, money;

	try {
		std::cin >> num1 >> num2 >> num3;
		if (num1 < 1 || num2 < 1 || num3 < 1 ||
			6 < num1 || 6 < num2 || 6 < num3)
			throw std::out_of_range("�ֻ��� ���� ���");

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
		std::cout << "���� �߻� : " << e.what();
	}
	return 0;
}
*/

/*
// 7576�� ����
#include <iostream>
#include <string.h>
#include <queue>
#include <utility>

#define MAX 100
int M, N;
int Box[MAX][MAX];

typedef struct Position {
	int x, y;
}Pos;

bool Movable(Pos cur, int dir);
Pos Move_to(Pos cur, int dir);
void End();

int main() {
	Pos cur;
	int second = 0;
	memset(Box, -1, sizeof(Box));
	std::queue<std::pair<int, int>> q, n;

	try {
		std::cin >> M >> N;
		if (M < 2 || M > 1000)
			throw std::out_of_range("'����ĭ ��(��)' ���� �Է� ����");
		if (N < 2 || N > 1000)
			throw std::out_of_range("'����ĭ ��(��)' ���� �Է� ����");

		for (int i = 0; i < N; i++)			// BOX �ʱ�ȭ
			for (int j = 0; j < M; j++)
				std::cin >> Box[i][j];

		for (int i = 0; i < N; i++)			// queue�� ���� �丶�� ���� �Է�
			for (int j = 0; j < M; j++)
				if (Box[i][j] == 1)
					q.push(std::make_pair(i, j));

		if (q.empty()) {	// ���� �丶�䰡 �ϳ��� ���� ��Ȳ
			std::cout << -1;
			return -1;
		}

		while (!q.empty()) {
			cur.x = q.front().first;
			cur.y = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				if (Movable(cur, dir)) {
					Pos next = Move_to(cur, dir);
					Box[next.x][next.y] = Box[cur.x][cur.y] + 1;
					q.push(std::make_pair(next.x, next.y));
				}
			}
		}
		End();
	}

	catch (std::out_of_range& e) {
		std::cout << "���� �߻� : " << e.what();
	}
	return 0;
}


bool Movable(Pos cur, int dir) {
	switch (dir) {
		case 0: cur.x--; break;	// ��
		case 1: cur.y++; break;	// ��
		case 2: cur.x++; break;	// ��
		case 3: cur.y--; break;	// ��
	}

	if (cur.x < 0 || cur.y < 0 || cur.x >= N || cur.y >= M)	// ���� ���
		return false;
	else if(Box[cur.x][cur.y] == 0)	// �������� �丶��
		return true;
	else // �丶�䰡 �;��ְų� �丶�䰡 ������
		return false;

}

Pos Move_to(Pos cur, int dir) {
	switch (dir) {
		case 0: cur.x--; break;	// ��
		case 1: cur.y++; break;	// ��
		case 2: cur.x++; break;	// ��
		case 3: cur.y--; break;	// ��
	}
	return cur;
}

void End() {
	int result = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (Box[i][j] == 0) {
				std::cout << "-1";
				return;
			}
			if (result < Box[i][j])
				result = Box[i][j];
		}

	std::cout << result - 1;
	return;
}
*/