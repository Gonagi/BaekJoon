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

// 11726번 문제

#include <iostream>
#include <vector>

int main() {
	int n;
	std::vector<int> vec;

	std::cin >> n;

	vec.push_back(1);
	vec.push_back(2);

	for (int i = 2; i <= n; i++)
		vec.push_back(vec.at(i - 1) + vec.at(i - 2) % 10007);
	
	std::cout << vec.at(n - 1);
	return 0;
}