/*
// 11654번 문제

#include <iostream>
#include <string>

int main() {
	char c;
	std::cin >> c;

	std::cout << static_cast<int>(c);

	return 0;
}
*/

/*
// 11720번 문제

#include <iostream>

int main() {
	int N, sum = 0;
	std::string num;

	try {
		std::cin >> N;
		if (N < 1 || N > 100)
			throw std::out_of_range("숫자의 개수 'N' 오류");
		
		std::cin >> num;

		for (int i = 0; i < num.size(); i++) {
			if ('0' <= num[i] && num[i] <= '9')
				sum += (num[i] - '0');
		}

		std::cout << sum;
	}
	catch (std::out_of_range& e) {
		std::cerr << "오류 발생 : " << e.what();
	}
	return 0;
}
*/

/*
// 10809번 문제

#include <iostream>

int main() {
	std::string S;
	int index[27];
	memset(index, -1, sizeof(index));

	std::cin >> S;

	for (int i = 0; i < S.size(); i++) {
		if(index[static_cast<int>(S[i]) - 97] < 0)
			index[static_cast<int>(S[i]) - 97] = i;
	}

	for(int i = 0; i < 27; i++)
		std::cout << index[i] << " ";

	return 0;
}

#include <iostream>
#include <string>

int main() {
	std::string s;
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::cin >> s;

	for (int i = 0; i < alphabet.length(); i++)
		std::cout << (int)s.find(alphabet[i]) << " ";

	return 0;
}
*/

/*
// 2657번 문제

#include <iostream>

int main() {
	int T, R;
	std::string S;
	try {
		std::cin >> T;

		if (T < 1 || T > 1000)
			throw std::out_of_range("테스트 케이스의 개수 'T' 범위 오류");

		for (int k = 0; k < T; k++) {
			std::cin >> R;
			if (R < 1 || R > 8)
				throw std::out_of_range("반복횟수 'R' 범위 오류");

			std::cin >> S;
			for (int i = 0; i < S.size(); i++)
				for (int j = 0; j < R; j++)
					std::cout << S[i];
			std::cout << "\n";
		}
	}
	catch (std::out_of_range& e) {
		std::cerr << "범위 오류 : " << e.what();
	}

	return 0;
}
*/

// 1157번 문제

#include <iostream>
#include <string>
#include <array>

using namespace std;

int main() {
	std::string s;
	int max, index=0;
	std::array<int, 26> arr = { 0 };

	std::cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			arr[static_cast<int>(s[i] - 'A')]++;
		else if ('a' <= s[i] && s[i] <= 'z')
			arr[static_cast<int>(s[i] - 'a')]++;
	}

	max = arr[0];

	for (int i = 0; i < arr.size(); i++) {
		if (max < arr[i]) {
			max = arr[i];
			index = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (index == i)
			continue;
		else if (arr[index] == arr[i]) {
			std::cout << "?";
			return 0;
		}
	}

	std::cout << static_cast<char>('A' + index);

	return 0;
}
/*
#include <iostream>
using namespace std;

int main() {
	string s;
	int num[27] = {0};

	std::cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (65 <= s[i] && s[i] <= 90)
			num[static_cast<int>(s[i]) - 65]++;

		else if (97 <= s[i] && s[i] <= 122)
			num[static_cast<int>(s[i]) - 97]++;
	}

	int max = num[0];
	int index = 0;


	for (int i = 0; i < 26; i++) {
		
		if (max < num[i + 1]) {
			max = num[i + 1];
			index = i + 1;
		}
		else if (max == num[i + 1]) {
			std::cout << "?";
			return 0;
		}
	}

	std::cout << static_cast<char>(index + 65);
	return 0;

	
}
*/