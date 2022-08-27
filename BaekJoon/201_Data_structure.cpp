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