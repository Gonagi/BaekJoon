// 2609번 문제
/*
#include <iostream>
#include <algorithm>

int main() {
	int num1, num2, GCD, LCM;

	std::cin >> num1 >> num2;
	
	for (int i = 1; i <= std::min(num1, num2); i++)
		if (num1 % i == 0 && num2 % i == 0)
			GCD = i;
	
	std::cout << GCD << "\n";

	LCM = GCD * (num1 / GCD) * (num2 / GCD);

	std::cout << LCM << "\n";

	return 0;
}


#include <iostream>
#include <algorithm>

int GCD(int num1, int num2) {
	if (num2 == 0)
		return num1;
	GCD(num2, num1 % num2);
}

int main() {
	int num1, num2;

	std::cin >> num1 >> num2;

	std::cout << GCD(num1, num2) << "\n";
	std::cout << num1 * num2 / GCD(num1, num2) << "\n";
	return 0;

}
*/

/*
// 1934번 문제

#include <iostream>
using namespace std;

int divide(int x, int y)
{
	if (x % y == 0)
		return y;
	else
		return divide(y, x % y);
}

int main()
{
	int T;
	int A, B;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;
		if (A >= B)
		{
			cout << A * B / divide(A, B) << "\n";
		}
		else
			cout << A * B / divide(B, A) << "\n";
	}
}
*/

// 6588번 문제

#include <iostream>

bool is_prime(int num);

int main() {
	int n = 1;
	bool is_exist = false;

	while (n) {
		std::cin >> n;
		
		for (int i = 3; i <= n; i += 2) {
			if (is_prime(i) && is_prime(n - i)) {
				std::cout << n << " = " << i << " + " << n - i << "\n";
				is_exist = true;
				break;
			}
		}
		if(!is_exist)
			std::cout << "Goldbach's conjecture is wrong." << "\n";
		
		is_exist = false;
	}
	return 0;
}

bool is_prime(int num) {
	for (int i = 2; (i * i) < num; i++) 
		if (num % i == 0)
			return false;
	return true;
}