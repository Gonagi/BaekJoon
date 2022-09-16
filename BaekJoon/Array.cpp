/*
// 10818�� ����
#include <iostream>
#include <algorithm>

int main() {
	int N, input, min = 1000001, max = -1000001;

	try {
		std::cin >> N;
		if (N < 1 || N > 1000000)
			throw std::out_of_range("N�� ������ ���");

		for (int i = 0; i < N; i++) {
			std::cin >> input;
			min = std::min(min, input);
			max = std::max(max, input);
		}
		std::cout << min << " " << max;
	}
	catch (std::out_of_range& e) {
		std::cerr << "�����߻�" << e.what();
	}
	return 0;
}
*/

/*
// 2562�� ����

#include <iostream>
#include <algorithm>

int main() {
	int input, max = 0, index = 0;

	try {
		for (int i = 0; i < 9; i++) {
			std::cin >> input;

			if (input < 1 || input > 100)
				throw std::out_of_range("Input�� ������ ���");

			max = std::max(max, input);

			if (max == input) 
				index = i+1;
		}

		std::cout << max << "\n" << index;
	}
	catch (std::out_of_range& e) {
		std::cerr << "���� �߻� : " << e.what();
	}

	return 0;
}
*/

/*
// 2577�� ����
#include <iostream>
#include <string>

int main() {
	int num[10] = { 0, }, A, B, C, result, remainder;

	try {
		std::cin >> A >> B >> C;
		if (A < 100 || A > 1000)
			throw std::out_of_range("A�� ������ ���");
		if (B < 100 || B > 1000)
			throw std::out_of_range("B�� ������ ���");
		if (C < 100 || C > 1000)
			throw std::out_of_range("C�� ������ ���");

		result = A * B * C;
		std::string s_num = std::to_string(result);

		for(int i = 0; i < s_num.size(); i++){
			switch (s_num[i]) {
			case '0': num[0]++; break;
			case '1': num[1]++; break;
			case '2': num[2]++; break;
			case '3': num[3]++; break;
			case '4': num[4]++; break;
			case '5': num[5]++; break;
			case '6': num[6]++; break;
			case '7': num[7]++; break;
			case '8': num[8]++; break;
			case '9': num[9]++; break;
			}
		}

		for(int i = 0; i < 10; i++)
			std::cout << num[i] << "\n";
	}
	catch (std::out_of_range& e) {
		std::cerr << "���� �߻� : " << e.what();
	}
	return 0;
}



#include <iostream>
#include <string>
using namespace std;

int main() {
	int count[10] = {};
	int a, b, c;

	cin >> a >> b >> c;

	int res = a * b * c;
	string s = to_string(res);

	for (char ch : s) {
		count[ch - '0']++;
	}

	for (int v : count) {
		cout << v << "\n";
	}

	return 0;
}


#include <iostream>
using namespace std;

int main() {
	int count[10] = {};
	int a, b, c;

	cin >> a >> b >> c;

	int res = a * b * c;

	while (res != 0) {
		count[res % 10]++;
		res /= 10;
	}

	for (int v : count) {
		cout << v << "\n";
	}

	return 0;
}
*/

/*
// 3052�� ����
#include <iostream>

int main() {
	int input, count[42] = {0,}, result = 0;

	try {
		for (int i = 0; i < 10; i++) {
			std::cin >> input;
			count[input % 42]++;
		}

		for (int i : count) {
			if (i != 0)
				result++;
		}

		std::cout << result;
	}
	catch (std::out_of_range& e) {
		std::cerr << "���� �߻� : " << e.what();
	}
	return 0;
}
*/

/*
* // 1546�� ����
#include <iostream>
#include <algorithm>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cout.tie(0);

	int N, score[1000], count = 0;
	double average= 0;

	try {
		std::cin >> N;
		if (N < 0 || N > 100)
			throw std::out_of_range("������ ���� 'N'�� ������ ���");

		for (int i = 0; i < N; i++) {
			std::cin >> score[i];
			if (score[i] < 0 || score[i] > 100)
				throw std::out_of_range("������ �����ų� 100�� �ʰ���");
			if (score[i] == 0)
				count++;
		}

		if (count == N)
			throw std::out_of_range("��� ������ 0�̴�.");

		std::sort(score, score + N);

		for (int i = 0; i < N; i++) 
			average += (double)score[i] / score[N-1] * 100;

		std::cout << average / N;
	}
	catch (std::out_of_range& e) {
		std::cerr << "���� �߻� : " << e.what();
	}
	return 0;
}

#include <iostream>
#include <algorithm>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cout.tie(0);

	int N, count = 0;
	double  score[1000], average = 0;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> score[i];
		if (score[i] == 0)
			count++;
	}

	std::sort(score, score + N);

	for (int i = 0; i < N; i++)
		average += score[i] / score[N - 1] * 100;

	std::cout << average / N;
	return 0;
}
*/

/*
// 8958�� ����
#include <iostream>
#include <string>

int main() {
	int N, score = 0;
	std::string str;

	std::cin >> N;
	for (int n = 0; n < N; n++) {
		std::cin >> str;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'X')
				str[i] = '0';
			else {
				if (i >= 1 && str[i - 1] != '0')
					str[i] = ((str[i - 1]-'0') + 1)+'0';
				else
					str[i] = '1';
			}
			score += str[i]-'0';
		}
		std::cout << score << "\n";
		score = 0;
	}
	return 0;
}
*/

/*
// 4344�� ����

#include <iostream>

int main() {
	int C, N, score[1000], count = 0;
	double sum = 0, average, result;

	try {
		std::cin >> C;
		if (C < 1)
			throw std::out_of_range("�׽�Ʈ ���̽��� ���� 'C'�� ������ ���");
		
		for (int i = 0; i < C; i++) {
			std::cin >> N;
			if (N < 1 || N > 1000)
				throw std::out_of_range("�л� �� 'N'�� ������ ���");
			for (int j = 0; j < N; j++) {
				std::cin >> score[j];
				sum += score[j];
			}
			average = sum / N;

			for (int j = 0; j < N; j++) {
				if (score[j] > average)
					count++;
			}
			result = (double)count / N *100;

			std::cout << std::fixed;
			std::cout.precision(3);
			std::cout << result << "%" << "\n";

			sum = 0;
			count = 0;
		}
	}
	catch (std::out_of_range& e) {
		std::cerr << "���� �߻� : " << e.what();
	}
	return 0;
}
*/