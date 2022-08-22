// 10828¹ø ¹®Á¦
#include <iostream>
#include <stdlib.h>
#include <memory>

struct Node {
	int data;
	Node* next;
};

struct Stack {
	Node* top;
};


class STACK {
private:
	// struct Node* node;
	struct Stack* stack;
	int check;

public:
	STACK() {
		stack = create_stack();
		check = 0;
	}

	Node* create_node();
	Stack* create_stack();

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

Stack* STACK::create_stack() {
	Stack* new_stack = new Stack;
	new_stack->top = nullptr;
	
	return new_stack;
}

void STACK::push(int _data) {
	Node* new_node = create_node();
	new_node->data = _data;

	if (check == 0) 
		stack->top = new_node;
	else {
		new_node->next = stack->top;
		stack->top = new_node;
	}
	check++;

}

void STACK::pop() {
	if (check == 0)
		std::cout << -1 << "\n";
	else {
		std::cout << stack->top->data << "\n";

		struct Node* old_node = stack->top;
		stack->top = old_node->next;
		
		free(old_node);
		old_node->next = nullptr;

		check--;
	}	
}

void STACK::size() {
	std::cout << check << "\n";
}

void STACK::empty() {
	if (check == 0) 
		std::cout << 1 << "\n";
	else 
		std::cout << 0 << "\n";
}

void STACK::top() {
	if (check == 0)
		std::cout << -1 << "\n";
	else
		std::cout << stack->top->data << "\n";
}

int main() {
	int N, num;
	std::string str;
	STACK stack;
	
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> str;
		if (str == "pop")
			stack.pop();
		else if (str == "size")
			stack.size();
		else if (str == "empty")
			stack.empty();
		else if (str == "top")
			stack.top();
		else if (str == "push") {
			std::cin >> num;
			stack.push(num);
		}
	}

	return 0;
}