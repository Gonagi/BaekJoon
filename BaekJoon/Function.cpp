/*
// 15596번 문제

#include <iostream>
#include <vector>

long long sum(std::vector<int>& a) {
	long long result = 0;

	for (std::vector<int>::iterator iter = a.begin(); iter < a.end(); iter++)
		result += *iter;

	return result;
}
*/

/*
// 4673번 문제

#include <iostream>

int d(int number) {
	int sum = number;

	while (number != 0) {
		sum = sum + (number % 10);
		number = number / 10;
	}
	return sum;
}

int main() {
	bool check[10001]{ false };

	for (int i = 1; i <= 10000; i++) {
		int n = d(i);
		if (n < 10001)
			check[n] = true;
	}

	for(int i = 1; i <= 10000; i++)
		if(!check[i])
			std::cout << i << "\n";

	return 0;
}
*/

// 1065번 문제

#include <iostream>

bool Check(int);

int main() {
	bool check[10001]{ false };
	int N, count = 0;

	std::cin >> N;

	for (int i = 1; i <= N; i++)
		if (Check(i))
			count++;

	std::cout << count;

	return 0;
}

bool Check(int N) {
	int num1, num2, num3;
	
	if (N <= 99)
		return true;

	else{
		num3 = N % 10;
		num2 = (N / 10) % 10;
		num1 = N / 100;
		
		//if (num1 == num2 && num1 == num3)
			//return false;

		if ((num3 + num1) == (num2*2))
			return true;
	}

	return false;
}