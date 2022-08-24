/*
// 10828번 문제
#include <iostream>
#include <stdlib.h>

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
*/

/*
// 9093번 문제
#include <iostream>
#include <sstream>

int main() {
	int T;
	std::string str, word;

	std::cin >> T;
	std::cin.ignore();

	for (int i = 0; i < T; i++) {
		getline(std::cin, str);
		std::istringstream ss(str);

		while (getline(ss, word, ' ')) {
			for (int i = word.length()-1; i >= 0; i--)
				std::cout << word.at(i);
			std::cout << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
*/

/*
// 9012번 문제

#include <iostream>
#include <stack>

bool Check() {
	std::string str;
	std::stack<std::string> st;

	std::cin >> str;
	for (int i = 0; i < static_cast<int>(str.length()); i++) {
		if (str.at(i) == '(')
			st.push("(");
		else {
			if (!st.empty())
				st.pop();
			else
				return false;
		}
	}
	return st.empty();
}

int main() {
	int T;
	std::cin >> T;

	for(int i = 0; i < T; i++){

		if (Check())
			std::cout << "YES" << "\n";
		else
			std::cout << "NO" << "\n";
	}
	return 0;
}

*/

/*
// 1874번 문제

#include <iostream>
#include <stack>
#include <vector>

int main() {
	int n, num = 1, input;
	std::vector<char> result;
	std::stack<int> list;

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> input;

		while (num <= input) {
			list.push(num++);
			result.push_back('+');
		}
		if (list.top() == input) {
			list.pop();
			result.push_back('-');
		}
		else {
			std::cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < static_cast<int>(result.size()); i++)
		std::cout << result.at(i) << "\n";

	return 0;
}
*/

/*
// 1406번 문제

#include <iostream>
#include <stack>
int main() {
	int N, M, size;
	char c;
	std::string str;
	std::stack<char> list1, list2;

	std::cin >> str >> M;
	N = static_cast<int>(str.length());

	for (int i = 0; i < N; i++)
		list1.push(str.at(i));

	for (int i = 1; i <= M; i++) {
		std::cin >> c;
		if (c == 'L') {
			if (list1.empty())
				continue;
			list2.push(list1.top());
			list1.pop();
		}
		else if (c == 'D') {
			if (list2.empty())
				continue;
			list1.push(list2.top());
			list2.pop();
		}
		else if (c == 'B') {
			if (list1.empty())
				continue;
			list1.pop();
		}
		else if (c == 'P') {
			std::cin >> c;
			list1.push(c);
		}
	}

	size = static_cast<int>(list1.size());

	for (int i = 0; i < size; i++) {
		list2.push(list1.top());
		list1.pop();
	}

	size = static_cast<int>(list2.size());

	for (int i = 0; i < size; i++) {
		std::cout << list2.top();
		list2.pop();
	}

	return 0;
}
*/

// 10845번 문제

#include <iostream>

struct Node {
	int data;
	Node* next;
};

struct queue {
	Node* Front;
	Node* Back;
};

class Queue {
private:
	queue* queue;
	int Size;

public:
	Queue();

	Node* creative_node(int _data);
	void push(int data);
	void pop();
	void size();
	void empty();
	void front();
	void back();
};

Node* Queue::creative_node(int _data) {
	Node* new_node = new Node;
	new_node->data = _data;
	new_node->next = nullptr;
	return new_node;
}

Queue::Queue() {
	queue = new struct queue;
	queue->Front = nullptr;
	queue->Back = nullptr;
	Queue::Size = 0;
}


void Queue::push(int data){
	Node* new_node = creative_node(data);
	Size++;

	if (Queue::Size == 0) {
		queue->Front = new_node;
		queue->Back = new_node;
	}
	else {
		queue->Back->next = new_node;
		queue->Back = new_node;
	}
}

void Queue::pop(){
	Node* old_node = queue->Front;
	Node* new_node = queue->Back;
	int check = Size;

	if (Queue::Size == 0) 
		std::cout << -1 << "\n";
	else{
		std::cout << old_node->data << "\n";
		
		if (check >= 3) {
			while (check >= 3) {
				new_node->next = new_node->next->next;
				check--;
			}
			queue->Front = new_node;
		}
		else {
			queue->Front = new_node;
		}
		
		delete[] old_node;
		old_node = nullptr;
		Size--;
	}
}

void Queue::size(){
	std::cout << Queue::Size << "\n";
}

void Queue::empty(){
	if (Queue::Size == 0)
		std::cout << 1 << "\n";
	else
		std::cout << 0 << "\n";
}

void Queue::front(){
	if (Queue::Size == 0)
		std::cout << -1 << "\n";
	else 
		std::cout << queue->Front->data << "\n";
}
void Queue::back() {
	if (Queue::Size == 0)
		std::cout << -1 << "\n";
	else
		std::cout << queue->Back->data << "\n";
}

int main() {
	int N, num;
	Queue queue;
	std::string str;
	
	std::cin >> N;
	
	for (int i = 0; i < N; i++) {
		std::cin >> str;

		if (str == "push") {
			std::cin >> num;
			queue.push(num);
		}
		else if (str == "pop")
			queue.pop();
		else if (str == "size")
			queue.size();
		else if (str == "empty")
			queue.empty();
		else if (str == "front")
			queue.front();
		else if (str == "back")
			queue.back();
	}

	return 0;
}