/*
// 1712번 문제

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
// 2292번 문제

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
// 1193번 문제

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
// 2869번 문제

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

// 10250번 문제

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