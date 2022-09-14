/*
// 1463번 문제

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, count = 0, result;
	std::vector<int> vec(1000001, 0);

	vec.at(2) = 1;
	vec.at(3) = 1;
	vec.at(4) = 2;

	std::cin >> N;

	for (int i = 5; i <= N; i++) {
		if (i % 2 == 0 && i % 3 == 0)
			vec.at(i) = std::min(vec.at(i / 2), vec.at(i / 3)) + 1;
		else if (i % 2 == 0)
			vec.at(i) = std::min(vec.at(i / 2), vec.at(i - 1)) + 1;
		else if (i % 3 == 0)
			vec.at(i) = std::min(vec.at(i / 3), vec.at(i - 1)) + 1;
		else
			vec.at(i) = vec.at(i - 1) + 1;
	}

	std::cout << vec.at(N);
	return 0;
}
*/

/*
// 11726번 문제

#include <iostream>
#include <vector>

int main() {
	int n;
	std::vector<int> vec;

	std::cin >> n;

	vec.push_back(1);
	vec.push_back(2);

	for (int i = 2; i < n; i++)
		vec.push_back((vec.at(i - 1) + vec.at(i - 2)) % 10007);
	
	std::cout << vec.at(n - 1);
	return 0;
}
*/

/*
// 11727번 문제

#include <iostream>
#include <vector>

int main() {
	int n;
	std::vector<int> vec;

	std::cin >> n;
	vec.push_back(1);
	vec.push_back(3);

	for (int i = 2; i <= n; i++)
		vec.push_back(((2 * vec.at(i - 2)) + vec.at(i - 1)) % 10007);

	std::cout << vec.at(n - 1);
	return 0;
}
*/

/*
// 9095번 문제

#include <iostream>
#include <vector>

int main() {
	int T, n;
	std::vector<int> vec;
	std::cin >> T;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);

	for (int i = 3; i < 10; i++)
		vec.push_back(vec.at(i - 3) + vec.at(i - 2) + vec.at(i - 1));

	for (int i = 0; i < T; i++) {
		std::cin >> n;
		std::cout << vec.at(n-1)<<"\n";
	}

	return 0;
}
*/

// 11052번 문제

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, num, result = 0;
	std::vector<int> input, vec;
	std::cin >> N;

	for (int i = 0; i < N;; i++) {
		std::cin >> num;
		input.push_back(num);
	}

	vec.push_back(input.at(0));

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < i; j++) {
			result = std::max(vec.at(j - 1) * 2, vec.at(j));
		}

	}

	return 0;
}