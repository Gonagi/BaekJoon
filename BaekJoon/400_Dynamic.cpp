/*
// 1463�� ����

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
// 11726�� ����

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
// 11727�� ����

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

/*
// 11052�� ����

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
*/

/*
// 10052번 문제
#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	int N, num;
	std::vector<int> vec, dp(1001);
	std::cin >> N;

	for(int i = 1; i <= N; i++){
		std::cin >> num;
		vec.push_back(num);
	}

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= i; j++)
			dp.at(i) = std::max(dp.at(i), dp.at(j-1) + vec.at(i-j));

	std::cout << dp.at(N);
	return 0;
}
*/

/*
// 16194번 문제

#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	long long N, num, max = 0;
	std::vector<long long> dp, card;

	std::cin >> N;
	dp.push_back(0);

	for(int i = 1; i <= N; i++){
		std::cin >> num;
		card.push_back(num);
		max += 10001;
		dp.push_back(num);
	}

	for(int i = 1; i <= N; i++)
		for(int j = i; j >= 1; j--)
		dp.at(i) = std::min(dp.at(i), (dp.at(i-j) + card.at(j-1)));

	std::cout << dp.at(N)<<"\n";

	return 0;
}
*/

/*
// 15990번 문제

#include <iostream>
#include <vector>

int main(){
	long long T, n, result;
	std::vector<long long> D[3];

	D[0].push_back(1);
	D[0].push_back(0);
	D[0].push_back(1);

	D[1].push_back(0);
	D[1].push_back(1);
	D[1].push_back(1);

	D[2].push_back(0);
	D[2].push_back(0);
	D[2].push_back(1);

	std::cin >> T;

	for(int i = 0; i < T; i++){
		std::cin >> n;

		for(int j = D->size(); j < n; j++){
			D[0].push_back((D[1].at(j-1) + D[2].at(j-1))%1000000009);
			D[1].push_back((D[0].at(j-2) + D[2].at(j-2))%1000000009);
			D[2].push_back((D[0].at(j-3) + D[1].at(j-3))%1000000009);
		}
		std::cout << (D[0].at(n-1) + D[1].at(n-1) + D[2].at(n-1))%1000000009 <<"\n";
	}
	return 0;
}
*/

/*
// 10844번 문제

#include <iostream>
#include <vector>

int main(){
	int N;
	long long result = 0;
	std::vector<long long> DP[10];

	DP[0].push_back(0);
	for(int i = 1; i <= 9; i++)
		DP[i].push_back(1);

	std::cin >> N;

	for(int i = 1; i < N; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0)
				DP[j].push_back(DP[j+1].at(i-1) % 1000000000);
			else if(j == 9)
				DP[j].push_back(DP[j-1].at(i-1) % 1000000000);
			else
				DP[j].push_back(DP[j-1].at(i-1)% 1000000000 + DP[j+1].at(i-1) % 1000000000);
		}
		int n = i;
	}

	for(int i = 0; i < 10; i++)
		result += DP[i].at(N-1);

	std::cout << result% 1000000000;

	return 0;
}
*/

/*
// 2193번 문제

#include <iostream>
#include <vector>

int main(){
	int N;
	std::vector<long long> DP[2];

	DP[0].push_back(0);
	DP[1].push_back(1);
	DP[0].push_back(1);
	DP[1].push_back(0);

	std::cin >> N;

	for(int i = 2; i < N; i++){
		DP[0].push_back(DP[0].at(i-1) + DP[0].at(i-2));
		DP[1].push_back(DP[1].at(i-1) + DP[1].at(i-2));
	}

	std::cout << DP[0].at(N-1) + DP[1].at(N-1)<<"\n";
	return 0;
}
*/

/*
// 11053번 문제

#include <iostream>
#include <vector>
#include <iostream>

int main(){
	int N, num;
	std::vector<int> vec;
	std::cin >> N;
	std::vector<int> DP(N, 1);

	for(int i = 0; i < N; i++){
		std::cin >> num;
		vec.push_back(num);
	}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < i; j++)
			if(vec.at(i) > vec.at(j))
				DP.at(i) = std::max(DP.at(j)+1, DP.at(i));

	int result = 0;

	for(int i = 0; i < N; i++)
		result = std::max(result, DP.at(i));

	std::cout << result;

	return 0;
}
*/

/*
// 14002번 문제

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int N, num, max_num = 0;
	std::vector<int> A, result;
	std::cin >> N;
	std::vector<int> DP(N, 1);

	for(int i = 0; i < N; i++){
		std::cin >> num;
		A.push_back(num);
	}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < i; j++){
			if(A.at(i) > A.at(j))
				DP.at(i) = std::max(DP.at(j) + 1, DP.at(i));
		}

	for(int i = 0; i < N; i++)
		max_num = std::max(max_num, DP.at(i));

	std::cout << max_num << "\n";

	for(int i = N-1; i >= 0; i--){
		if(DP.at(i) == max_num){
			result.push_back(A.at(i));
			max_num--;
		}
	}

	std::sort(result.begin(), result.end());

	for(int i = 0; i< result.size(); i++)
		std::cout << result.at(i) <<" ";

	return 0;
}
*/

// 1912번 문제

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N, num, sum = 0;
	std::vector<int> result;

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> num;

		if (sum == 0)
		{
			sum = num;
			result.push_back(sum);
		}

		else
		{
			if (sum + num < num)
			{
				result.push_back(num);
				sum = num;
			}

			else
			{
				result.push_back(sum + num);
				sum += num;
			}
		}
	}

	std::sort(result.rbegin(), result.rend());
	std::cout << result.at(0);

	return 0;
}
