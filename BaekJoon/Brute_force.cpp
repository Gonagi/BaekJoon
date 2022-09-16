/*
// 2798�� ����

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int N, M, num, result = 0;
	std::vector<int> card;

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> num;
		card.push_back(num);
	}

	std::sort(card.rbegin(), card.rend());
	
	for (int i = 0; i < N; i++) {
		if (M >= card.at(i) + 2) {
			for (int j = i + 1; j < N; j++) {
				if (M - card.at(i) >= card.at(j) + 1)
					for (int k = j + 1; k < N; k++) {
						if (M - card.at(i) - card.at(j) >= card.at(k)) {
							if (result <= card.at(i) + card.at(j) + card.at(k) &&
								card.at(i) + card.at(j) + card.at(k) <= M)
								result = card.at(i) + card.at(j) + card.at(k);
						}
					}
			}
		}
	}

	std::cout << result;

	return 0;
}
*/

/*
// 2231�� ����
#include <iostream>
bool isConstructor(int, int);

int main() {
	int N, sum;

	std::cin >> N;

	for (int num = 1; num < N; num++) {
		if (isConstructor(num, N)) {
			std::cout << num;
			return 0;
		}
	}
	std::cout << 0;
	return 0;
}

bool isConstructor(int num, int N) {
	int sum = num;

	while (num) {
		sum += num % 10;
		num /= 10;
	}

	if (sum == N)
		return true;
	else
		return false;
}
*/

/*
// 7568�� ����
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
	int N, x, y, rank = 1;
	std::vector<std::pair<int, int>> students;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> x >> y;
		students.push_back(std::make_pair(x,y));
	}

	for (int i = 0; i < N; i++) {
		rank = 1;
		for (int j = 0; j < N; j++) {
			if (students.at(i).first < students.at(j).first &&
				students.at(i).second < students.at(j).second)
				rank++;
		}
		std::cout << rank << " ";
	}
	return 0;
}
*/

/*
// 1018�� ����

#include<iostream>
#include <algorithm>

#define Max 50

int main() {
	char chessboard[Max][Max]{ ' ' };
	int M, N, count1= 0, count2 = 0, result = 32;

	std::cin >> M >> N;

	for (int row = 0; row < M; row++)
		for (int col = 0; col < N; col++)
			std::cin >> chessboard[row][col];

	for(int row = 0; row < M-7; row++)
		for (int col = 0; col < N - 7; col++) {
			count1 = 0;
			count2 = 0;

			for (int i = row; i < row + 8; i++)
				for (int j = col; j < col + 8; j++) {
					if ((i + j) % 2 == 0 && chessboard[i][j] == 'B')
						count1++;
					else if ((i + j) % 2 == 1 && chessboard[i][j] == 'W')
						count1++;
					if ((i + j) % 2 == 0 && chessboard[i][j] == 'W')
						count2++;
					else if ((i + j) % 2 == 1 && chessboard[i][j] == 'B')
						count2++;
				}
			result = std::min(result, std::min(count1, count2));
		}
	std::cout << result;

	return 0;
}
*/
/*
// 1436�� ����
#include <iostream>

bool is_num(int);

int main() {
	int N, count = 0, num = 665;
	std::cin >> N;

	while (1) {
		num++;
		if(is_num(num))
			count++;

		if (count == N) {
			std::cout << num;
			return 0;
		}
	}

	return 0;
}

bool is_num(int num) {
	int check = 0;

	while (num) {
		if (num % 10 == 6) {
			check++;
			if (check == 3)
				return true;
		}
		else
			check = 0;
		num /= 10;
	}
	return false;
}
*/