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

/*
// 1157번 문제

#include <iostream>
#include <string>
#include <array>

using namespace std;

int main() {
	std::string s;
	int max, index = 0;
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
*/

/*
// 1152번 문제

#include <iostream>
#include <string>

int main() {
	std::string s;
	int count = 1;
	std::getline(std::cin, s);

	if (s.empty()) {
		std::cout << "0";
		return 0;
	}

	for (int i = 0; i < s.size(); i++)
		if (s[i] == ' ')
			count++;
	if (s[0] == ' ')
		count--;
	if (s[s.size() - 1] == ' ')
		count--;

	std::cout << count;

	return 0;
}
*/

/*
// 2908번 문제

#include <iostream>

int Change(int);

int main() {
	int A, B, new_A, new_B;

	try {
		std::cin >> A >> B;
		if (A == B)
			throw std::logic_error("A와 B가 같은 수이다");
		new_A = Change(A);
		new_B = Change(B);

		if (new_A > new_B)
			std::cout << new_A;
		else
			std::cout << new_B;
	}
	catch (std::logic_error& e) {
		std::cerr << "오류 발생 : " << e.what();
	}

	return 0;
}

int Change(int n) {
	int new_num = ((n % 100) % 10) * 100 + ((n / 10) % 10) * 10 + n / 100;
	return new_num;
}


#include <iostream>
#include <string>

int main() {

	std::string A, B;
	std::cin >> A >> B;

	std::string bigger;

	for (int i = 2; i >= 0; i--) {
		if (A[i] > B[i]) {
			bigger = A;
			break;
		}
		else if (A[i] < B[i]) {
			bigger = B;
			break;
		}
	}

	std::cout << bigger[2] << bigger[1] << bigger[0];
	return 0;
}
*/

/*
// 5622번 문제

#include <iostream>

int arr[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
int main() {
	std::string str;
	int result = 0;

	try {
		std::cin >> str;
		if (str.size() < 2 || str.size() > 15)
			throw std::out_of_range("입력한 단어의 길이가 2이상 15 이하 이어야 합니다.");

		for (int i = 0; i < str.size(); i++) {
			result += arr[str[i] - 'A'];
		}
		std::cout << result;
	}

	catch (std::out_of_range& e) {
		std::cerr << "오류 발생 : " << e.what();
	}


	return 0;
}
*/

/*
// 2941번 문제

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> arr = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	int index;
	string str;
	cin >> str;

	for (int i = 0; i < arr.size(); i++) {
		while (1) {
			index = str.find(arr[i]);
			if (index == string::npos)
				break;
			str.replace(index, arr[i].length(), "#");
		}
	}

	cout << str.length();

	return 0;
}
*/

// 1316번 문제

#include <iostream>
#include <string>
#include <algorithm>

int main() {
	int N, result = 0;
	int arr[26]{ 0 };
	std::string str;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		bool Is_group = true;
		std::cin >> str;

		str.erase(unique(str.begin(), str.end()), str.end());

		sort(str.begin(), str.end());

		for (int j = 0; j < str.size()-1; j++) {
			if (str[j] == str[j + 1]) {
				Is_group = false;
				break;
			}
		}
		if (Is_group)
			result++;
	}

	std::cout << result;
	return 0;
}