/*
// 17413번 문제
#include <iostream>
#include <string>
#include <stack>

int main() {
	std::string str;
	std::stack<char> list;

	getline(std::cin, str);

	for (int index = 0; index < static_cast<int>(str.length()); index++) {
		if (str.at(index) == '<' && !list.empty()) {
			while (!list.empty()) {
				std::cout << list.top();
				list.pop();
			}
		}
		if (str.at(index) == '<' && list.empty()) {
			while (str.at(index) != '>') {
				std::cout << str.at(index);
				index++;
			}
			std::cout << '>';
			continue;
		}
		
		if (str.at(index) == ' ') {
			while (!list.empty()) {
				std::cout << list.top();
				list.pop();
			}
			std::cout << ' ';
			continue;
		}
			list.push(str.at(index));
		
	}

	while (!list.empty()) {
		std::cout << list.top();
		list.pop();
	}

	return 0;
}
*/

/*
// 10799번 문제

#include <iostream>
#include <stack>

int main() {
	std::string list;
	std::stack<char> stack;
	char cur;
	int check = 0, result = 0;

	std::cin >> list;

	for (int index = 0; index < static_cast<int>(list.length()); index++) 
		stack.push(list.at(index));

	while(!stack.empty()){
		cur = stack.top();
		stack.pop();

		if (cur == ')') {
			if (stack.top() == '(') {
				result += check;
				stack.pop();
			}
			else
				check++;
		}
		else if (cur == '(') {
			result++;
			check--; 
		}
	}

	std::cout << result;

	return 0;
}
*/

// 메모리 누수 공부
/*
#include <iostream>
#include <stdlib.h>
#include <memory>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif

struct Node {
	int data;
	Node* next;
};

struct Stack {
	Node* top;
};

class STACK {
private:
	struct Stack* stack;
	int check;
public:
	STACK() {
		stack = new Stack;
		stack->top = nullptr;
		check = 0;
	}
	~STACK() {
		std::cout << "소멸자 작동" << "\n";
		delete stack;
	}
	Node* create_node();
	void push(int data);
	void pop();
	void size();
	void empty();
	void top();
};

Node* STACK::create_node() {
	Node* new_node = new Node;
	new_node->data = 0;
	new_node->next = nullptr;
	return new_node;
}

void STACK::push(int _data) {
	Node* new_node = create_node();
	new_node->data = _data;
	if (stack->top == nullptr)
		stack->top = new_node;
	else {
		new_node->next = stack->top;
		stack->top = new_node;
	}
	check++;
}
void STACK::pop() {
	if (stack->top == nullptr)
		std::cout << -1 << "\n";
	else {
		std::cout << stack->top->data << "\n";
		struct Node* old_node = stack->top;
		stack->top = old_node->next;

		delete old_node;
		old_node = nullptr;
		check--;
	}
}
void STACK::size() {
	std::cout << check << "\n";
}
void STACK::empty() {
	if (stack->top == nullptr)
		std::cout << 1 << "\n";
	else
		std::cout << 0 << "\n";
}
void STACK::top() {
	if (stack->top == nullptr)
		std::cout << -1 << "\n";
	else
		std::cout << stack->top->data << "\n";
}
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// _CrtSetBreakAlloc(255);

	int N, num;
	std::string str;
	auto stack = std::make_unique<STACK>();

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> str;
		if (str == "pop")
			stack->pop();
		else if (str == "size")
			stack->size();
		else if (str == "empty")
			stack->empty();
		else if (str == "top")
			stack->top();
		else if (str == "push") {
			std::cin >> num;
			stack->push(num);
		}
	}
	int* a = new int(6);
	std::cout << "ddd";
	return 0;
}
*/

/*
#include <iostream>
//#include <crtdbg.h>
using namespace std;

//#ifdef _DEBUG
//	#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
//	#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
//#endif

int* aNew() {
	auto p = new int{ 9 };
	return p;
}

int* bNew() {
	auto p = new int{ 1 };
	return p;
}

void pDelete(int* p) {
	delete p;
}

int main() {
		// _CrtSetBreakAlloc(78);	메모리 누수 일어난곳으로 이동
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	auto ptr = aNew();
	auto ptr2 = bNew();
	pDelete(ptr);

		// _CrtDumpMemoryLeaks();
}
*/

// 17298번 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

int main() {
	int N, num;
	std::vector<int> input, result;
	std::stack<int> stack;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> num;
		input.push_back(num);
	}

	for (int i = static_cast<int>(input.size()) - 1; i >= 0; i--) {

		while (!stack.empty() && stack.top() <= input.at(i))
			stack.pop();
		if (stack.empty())
			result.push_back(-1);
		else
			result.push_back(stack.top());
		stack.push(input.at(i));
	}

	for (int i = N-1; i >= 0; i--)
		std::cout << result.at(i) << " ";

	return 0;
}
/*
int main() {
	int N, num, size;
	bool is_push = false;
	std::stack<int> input;
	std::vector<int> result, check;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> num;
		input.push(num);
	}

	while(!input.empty()) {
		if (check.empty()) {
			check.push_back(input.top());
			result.push_back(-1);
		}
		else {
			if (check.at(check.size() - 1) > input.top()) {
				result.push_back(check.at(check.size() - 1));
				check.push_back(input.top());
			}

			else {
				size = static_cast<int>(check.size());
				for (int i = size - 1; i >= 0; i--) {
					if (input.top() < check.at(i)) {
						result.push_back(check.at(i));
						check.push_back(input.top());
						is_push = true;
						break;
					}
					else {
						check.push_back(input.top());
						is_push = false;
					}
				}

				if (!is_push)
					result.push_back(-1);
			}
		}
		input.pop();
	}

	for (auto data = result.rbegin(); data != result.rend(); data++)
		std::cout << *data << " ";

	return 0;
}
*/