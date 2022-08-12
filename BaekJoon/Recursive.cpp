/*
// 10872번 문제

#include <iostream>

int fac(int num) {
	if (num == 0)
		return 1;
	else 
		return num * fac(num - 1);
}

int main() {
	int N, num;
	std::cin >> N;

	num = fac(N);
	std::cout << fac(N);

	return 0;
}
*/

/*
// 10870번 문제

#include <iostream>

int fib(int num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else
		return fib(num - 1) + fib(num - 2);
}
int main() {
	int n;

	std::cin >> n;
	std::cout << fib(n);

	return 0;
}
*/

/*
// 17478번 문제

#include <iostream>

void print(int N, int num) {
	if (num == 0) {
		for (int i = 0; i < N - num; i++)
			std::cout << "____";
		std::cout << "\"재귀함수가 뭔가요\?\"" << "\n";

		for (int i = 0; i < N - num; i++)
			std::cout << "____";
		std::cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << "\n";

		for (int i = 0; i < N - num; i++) 
			std::cout << "____";
		std::cout << "라고 답변하였지." << "\n";
		return;
	}

	if(num == N)
		std::cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << "\n";
	
	for (int i = 0; i < N-num; i++)
		std::cout << "____";
	std::cout << "\"재귀함수가 뭔가요\?\"" << "\n";

	for (int i = 0; i < N-num; i++)
		std::cout << "____";
	std::cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << "\n";

	for (int i = 0; i < N-num; i++)
		std::cout << "____";
	std::cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << "\n";

	for (int i = 0; i < N-num; i++)
		std::cout << "____";
	std::cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << "\n";
	

	print(N, num - 1);
	
	for (int i = 0; i < N - num; i++) 
		std::cout << "____";
	
	std::cout << "라고 답변하였지." << "\n";

}
int main() {
	int N;

	std::cin >> N;

	print(N, N);
	return 0;
}
*/

/*
// 2447번 문제

#include <iostream>

void star(int i, int j, int n) {
	if (i / n % 3 == 1 && j / n % 3 == 1)
		std::cout << " ";
	else if (n / 3 == 0)
		std::cout << "*";
	else
		star(i,j, n / 3);
}

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			star(i, j, N);
		std::cout << "\n";
	}	
}

// 9
	######### 9		3
	# ## ## # 8		
	######### 7
	###   ### 6		2
	# #   # # 5
	###   ### 4 
	######### 3		1
	# ## ## # 2
	######### 1

// 27
	########################### 27		9  27/3 = 9
	# ## ## ## ## ## ## ## ## # 26			3 - 2
	########################### 25			27 / 3 <=  <= 27 / 3 - 3
	###   ######   ######   ### 24		8
	# #   # ## #   # ## #   # # 23
	###   ######   ######   ### 22
	########################### 21		7
	# ## ## ## ## ## ## ## ## # 20
	########################### 19
	#########         ######### 18		6
	# ## ## #         # ## ## # 17
	#########         ######### 16
	###   ###         ###   ### 15		5
	# #   # #         # #   # # 14
	###   ###         ###   ### 13
	#########         ######### 12		4
	# ## ## #         # ## ## # 11
	#########         ######### 10
	########################### 9		3
	# ## ## ## ## ## ## ## ## # 8
	########################### 7
	###   ######   ######   ### 6		2
	# #   # ## #   # ## #   # # 5
	###   ######   ######   ### 4
	########################### 3		1
	# ## ## ## ## ## ## ## ## # 2
	########################### 1
*/

// 11729번 문제

#include <iostream>
#include <math.h>

void Hanoi(int, int, int, int);

int main() {
	int N;
	std::cin >> N;

	std::cout << static_cast<int>(pow(2, N) - 1) << "\n";
	Hanoi(1, 2, 3, N);

	return 0;
}

void Hanoi(int start, int via, int end, int N) {
	if (N == 1) {
		std::cout << start << " " << end << "\n";
		return;
	}
	else {
		Hanoi(start, end, via, N - 1);
		std::cout << start << " " << end << "\n";
		Hanoi(via, start, end, N - 1);
	}
}
