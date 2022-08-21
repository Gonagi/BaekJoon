/*
// 2750, 2751번 문제

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, number;
	std::vector<int> result;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> number;
		result.push_back(number);
	}

	std::sort(result.begin(), result.end());

	for (int i = 0; i < N; i++)
		std::cout << result.at(i) << "\n";
	
	return 0;
}
*/

/*
// 10989번 문제

#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, num, arr[10001]{};
	std::cin >> N;

	for (int i = 0; i < N; i++){
		std::cin >> num;
		arr[num]++;
	}

	for (int i = 0; i <= 10000; i++)
		for (int j = 1; j <= arr[i]; j++)
			std::cout << i << "\n";

	return 0;
}
*/

/*
// 25305번 문제

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, k, score, sum = 0;
	std::vector<int> students;

	std::cin >> N >> k;

	for (int i = 0; i < N; i++) {
		std::cin >> score;
		students.push_back(score);
	}

	std::sort(students.rbegin(), students.rend());
	std::cout << students.at(k-1);

	return 0;
}
*/

/*
// 2018번 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
	int N, num, sum = 0, arr[8002]{0}, max =0;
	bool check = false, check2 = false;

	std::vector<int> vec;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> num;
		vec.push_back(num);
	}
	std::sort(vec.begin(), vec.end());

	for (auto i : vec) {
		sum += i;
		arr[i+4000]++;
	}

	std::cout << std::fixed;
	std::cout.precision(0);
	if (-1 < (static_cast<double>(sum)/N) && (static_cast<double>(sum)/N) < 0)
		std::cout << 0 << "\n";
	else
		std::cout << std::round(static_cast<double>(sum) / N) << "\n";

	if (N % 2 != 0)
		std::cout << vec.at(N / 2) << "\n";
	else
		std::cout << (vec.at(N / 2) + vec.at(N / 2 - 1)) / 2 << "\n";


	for (int i = 0; i < 8001; i++) 
		if (max < arr[i])
			max = arr[i];

	for (int i = 0; i < 8001; i++) {
		if (max == arr[i])
			check = true;
		if (check) {
			for (int j = i+1; j < 8001; j++) {
				if (max == arr[j]) {
					std::cout << j-4000 << "\n";
					check2 = true;
					break;
				}
			}
			if(!check2)
				std::cout << i-4000 << "\n";
			break;
		}
	}

	if  (vec.at(N - 1) - vec.at(0) > 0)
		std::cout << vec.at(N - 1) - vec.at(0);
	else
		std::cout << -1 * (vec.at(N - 1) - vec.at(0));

	return 0;
}
*/

/*
// 1427번 문제
#include <iostream>
#include <string>
#include <algorithm>

bool compare(char a, char b) {
	return a > b;
}
int main() {
	std::string num;
	std::cin >> num;

	std::sort(num.begin(), num.end(), compare);

	std::cout << num;
	return 0;
}
*/

/*
// 11650번 문제

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

int main() {
	int N, first_num, second_num;
	std::vector<std::pair<int, int>> vec;
	
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> first_num >> second_num;
		vec.push_back(std::make_pair(first_num, second_num));
	}

	std::sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) 
		std::cout << vec.at(i).first << " " << vec.at(i).second << "\n";
	
	return 0;
}
*/

/*
// 11651번 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int N, first_num, second_num;
	std::vector<std::pair<int, int>> vec;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> first_num >> second_num;
		vec.push_back(std::make_pair(first_num, second_num));
	}

	std::sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < N; i++)
		std::cout << vec.at(i).first << " " << vec.at(i).second << "\n";

	return 0;
}
*/

/*
// 1181번 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <string_view>

bool compare(std::string_view a, std::string_view b) {
	if (a.length() == b.length())
		return a < b;
	return
		a.length() < b.length();
}

int main() {
	int N;
	std::string str;
	std::vector<std::string> list;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> str;
		list.push_back(str);
	}

	std::sort(list.begin(), list.end(), compare);
	list.erase(std::unique(list.begin(), list.end()), list.end());


	for (int i = 0; i < list.size(); i++)
		std::cout << list.at(i) << "\n";

	return 0;
}
*/

/*
// 10814번 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

bool compare(std::tuple<int, int, std::string> a, std::tuple<int, int, std::string> b);

int main() {
	int N, age;
	std::string name;
	std::vector<std::tuple<int, int, std::string>> list;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> age >> name;
		list.push_back(std::make_tuple(i, age, name));
	}

	std::sort(list.begin(), list.end(), compare);

	for (int i = 0; i < N; i++)
		std::cout << std::get<1>(list[i]) << " " << std::get<2>(list[i]) << "\n";
	return 0;
}

bool compare(std::tuple<int, int, std::string> a, std::tuple<int, int, std::string> b) {
	if (std::get<1>(a) == std::get<1>(b)) {
		return  std::get<0>(a) < std::get<0>(b);
	}
	return std::get<1>(a) < std::get<1>(b);
}
*/

// 18870번 문제

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, num;
	std::vector<int> list;

	std::cin >> N; 
	std::vector<int> original_list(N);

	for (int i = 0; i < N; i++) 
		std::cin >> original_list[i];	

	list = original_list;
	std::sort(list.begin(), list.end());
	list.erase(std::unique(list.begin(), list.end()), list.end());

	for (int i = 0; i < N; i++) {
		auto index = std::lower_bound(list.begin(), list.end(), original_list.at(i));
		std::cout << index - list.begin() << " ";
	}

	return 0;
}