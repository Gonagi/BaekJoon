/*
// 1712�� ����

#include <iostream>

int main() {
	long long A, B, C, result;
	std::cin >> A >> B >> C;

	if (B >= C)
		std::cout << -1;
	else {
		result = A / (C - B);
		std::cout << result + 1;
	}

	return 0;
}
*/

/*
// 2292�� ����

#include <iostream>

int main() {
	int N, sum = 1, i= 1;
	std::cin >> N;

	for(; sum < N; i++)
		sum += (i*6);

	if (N == 1)
		i = 1;
	std::cout << i;
	return 0;
}
*/

/*
// 1193�� ����

#include <iostream>

int main() {
	int X, Numerator, Denominator, sum = 1, i = 1;

	std::cin >> X;

	while(sum < X){
		i++;
		sum += i;
	}

	if (i % 2 == 0) {
		Denominator = sum - X + 1;
		Numerator = i - Denominator + 1;
	}

	else {
		Numerator = sum - X + 1;
		Denominator = i - Numerator + 1;
	}

	std::cout << Numerator << "/" << Denominator;

	return 0;
}
*/

/*
// 2869�� ����

#include <iostream>

int main() {
	int A, B, V, day;

	std::cin >> A >> B >> V;

	day = (V - A) / (A - B) + 1;

	if (((V - A) % (A - B)) > 0)
		day++;

	std::cout << day;

	return 0;
}
*/

/*
// 10250�� ����

#include <iostream>

int main() {
	int T, H , W, N, result;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> H >> W >> N;

		if (N % H == 0)
			result = H * 100 + (N / H);
		else
			result = (N % H) * 100 + (N / H) + 1;

		std::cout << result << std::endl;
	}
	return 0;
}
*/

/*
// 2775�� ����

#include <iostream>
#define Max 100
int apart[Max][14] = { 0 };

int main() {
	int T, k, n;
	for (int i = 0; i < 14; i++)
		apart[0][i] = i + 1;

	std::cin >> T;

	for (int a = 0; a < T; a++) {
		std::cin >> k >> n;
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j < n; j++) {
				if (j == 0)
					apart[i][j] = 1;
				else
					apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
			}
		}
		std::cout << apart[k][n-1] << "\n";
			
	}
	return 0;
}

int getNum(int a, int b){
	if(b == 1)
		return 1;
	if(a == 0)
		return b;
	return getNum((a-1, b) + getNum(a, b-1));
}

int main(){
	int T, k, n;
	std::cin >> T;
	for(int i = 0; i < T; i++){
		cin >> k >> n;
		std::cout << getNum(k, n) <<"\n";
	}
}
*/

/*
// 2839�� ����

#include <iostream>

int main() {
	int N, result = 0;

	try {
		std::cin >> N;
		if (N < 3 || N > 100) {
			throw std::out_of_range("'N'�� ������ ������ϴ�.");
		}

		for (int a = 0; a < N / 3; a++) {
			if ((N - 3 * a) % 5 == 0) {
				if (result == 0)
					result = a + (N - 3 * a) / 5;
				else if (result > a + (N - 3 * a) / 5)
					result = a + (N - 3 * a) / 5;
			}
		}

		if (result == 0 && N % 3 == 0)
			result = N / 3;
		
		if(result == 0)
			result = -1;

		std::cout << result;

	}
	catch (std::out_of_range& exception) {
		std::cerr << "���� �߻� : " << exception.what();
	}

	return 0;
}

#include <iostream>
int main() {
	int kg, a, b;
	std::cin >> kg;

	a = kg / 5;
	while (1) {
		if (a < 0) {
			std::cout << -1;
			return 0;
		}
		if ((kg - (5 * a) % 3 == 0)) {
			b = (kg - (5 * 1)) / 3;
			break;
		}
		a--;
	}
	std::cout << a + b;
	return 0;
}
*/


/*
// 10757�� ����
#include <iostream>
#include <vector>
#include <string>

int main() {
	std::string s1, s2;
	std::vector<int> result{};
	int s1_index=0, s2_index=0, cal=0, upper = 0;

	std::cin >> s1 >> s2;
	s1_index = static_cast<int>(s1.size()) - 1;
	s2_index = static_cast<int>(s2.size()) - 1;

	while (s1_index != -1 || s2_index != -1) {
		cal = (s1[s1_index] - '0') + (s2[s2_index] - '0');

		if (upper == 1) {
			if (cal >= 10) {
				result.push_back(cal % 10 + 1);
				upper = 1;
			}
			else {
				result.push_back(cal + 1);
				upper = 0;
			}
		}

		else {
			if (cal >= 10) {
				result.push_back(cal % 10);
				upper = 1;
			}
			else {
				result.push_back(cal);
				upper = 0;
			}
		}

		s1_index--;
		s2_index--;

		if (upper == 1 && (s1_index == -1 || s2_index == -1))
			result.push_back(1);
	}

	for (int i = static_cast<int>(result.size()) - 1; i >= 0; i--)
		std::cout << result.at(i);
	return 0;
}
*/