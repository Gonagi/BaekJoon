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

/*
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
	queue* Q;
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
	Q = new struct queue;
	Q->Front = nullptr;
	Q->Back = nullptr;
	Size = 0;
}


void Queue::push(int data){
	Node* new_node = creative_node(data);

	if (Q->Front == nullptr) {
		Q->Front = new_node;
		Q->Back = new_node;
	}
	else {
		new_node->next = Q->Back;
		Q->Back = new_node;
	}
	Size++;
}

void Queue::pop() {
	if (Q->Front == nullptr)
		std::cout << -1 << "\n";
	
	else {
		Node* old_node = Q->Front;
		int check = Size;

		std::cout << old_node->data << "\n";

		if (check == 1) {
			Q->Front = nullptr;
		}
		else if (check == 2) {
			Node* new_node = Q->Back;

			Q->Front = new_node;
			Q->Front->next = nullptr;
		}
		else {
			Node* new_node = Q->Back;

			while (check >= 3) {
				new_node = new_node->next;
				check--;
			}

			Q->Front = new_node;
			Q->Front->next = nullptr;

		}

		delete[] old_node;
		old_node = nullptr;
		Size--;
	}
}

void Queue::size(){
	std::cout << Size << "\n";
}

void Queue::empty(){
	if (Q->Front == nullptr)
		std::cout << 1 << "\n";
	else
		std::cout << 0 << "\n";
}

void Queue::front(){
	if (Q->Front == nullptr)
		std::cout << -1 << "\n";
	else 
		std::cout << Q->Front->data << "\n";
}

void Queue::back() {
	if (Q->Front == nullptr)
		std::cout << -1 << "\n";
	else
		std::cout << Q->Back->data << "\n";
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
*/

/*
// 1158번 문제

#include <iostream>
#include <queue>

int main() {
	int N, K;
	std::queue<int> circle;

	std::cin >> N >> K;

	for (int i = 1; i <= N; i++)
		circle.push(i);

	std::cout << "<";

	while (!circle.empty()) {
		for (int i = 0; i < K - 1; i++) {
			circle.push(circle.front());
			circle.pop();
		}
		if (circle.size() == 1)
			std::cout << circle.front();
		else
			std::cout << circle.front() << ", ";
		circle.pop();
	}
	std::cout << ">";

	return 0;
}
*/

// 10866번 문제

#include <iostream>

struct Node {
	int data;
	Node* next;
};

struct deque {
	Node* Front;
	Node* Back;
};

class Deque {
private:
	deque* D;
	int Size;

public:
	Node* creative_node(int _data);

	Deque();
	void push_front(int _data);
	void push_back(int _data);
	void pop_front();
	void pop_back();
	void size();
	void empty();
	void  front();
	void back();
};

Node* Deque::creative_node(int _data) {
	Node* new_node = new Node;
	new_node->data = _data;
	new_node->next = nullptr;
	
	return new_node;
}

Deque::Deque() {
	D = new struct deque;
	D->Front = nullptr;
	D->Back = nullptr;
	Size = 0;
}

void Deque::push_front(int _data) {
	Node* new_node = creative_node(_data);

	if (D->Front == nullptr) {
		D->Front = new_node;
		D->Back = new_node;
	}
	else {
		D->Front->next = new_node;
		D->Front = new_node;
	}
	Size++;
}

void Deque::push_back(int _data) {
	Node* new_node = creative_node(_data);

	if (D->Back == nullptr) {
		D->Front = new_node;
		D->Back = new_node;
	}
	else {
		new_node->next = D->Back;
		D->Back = new_node;
	}
		
	Size++;
}

void Deque::pop_front() {
	if (D->Front == nullptr)
		std::cout << -1 << "\n";
	else {
		Node* old_node = D->Front;
		std::cout << old_node->data << "\n";

		if (Size == 1) {
			D->Front = nullptr;
			D->Back = nullptr;
		}
		else if (Size == 2) 
			D->Front = D->Back;
		else {
			Node* cur_node = D->Back;
			for (int i = 1; i < Size-1; i++)
				cur_node = cur_node->next;
			D->Front = cur_node;
		}

		Size--;
		delete[] old_node;
	}
}

void Deque::pop_back() {
	if (D->Back == nullptr)
		std::cout << -1 << "\n";
	else {
		Node* old_node = D->Back;
		std::cout << old_node->data << "\n";

		if (Size == 1) {
			D->Front = nullptr;
			D->Back = nullptr;
		}
		else if (Size == 2)
			D->Back = D->Front;
		else
			D->Back = D->Back->next;
		
		Size--;
		delete[] old_node;
	}
}

void Deque::size() {
	std::cout << Size << "\n";
}

void Deque::empty() {
	if (D->Front == nullptr)
		std::cout << 1 << "\n";
	else
		std::cout << 0 << "\n";
}

void Deque::front() {
	if (D->Front == nullptr)
		std::cout << -1 << "\n";
	else
		std::cout << D->Front->data << "\n";
}

void Deque::back() {
	if (D->Back == nullptr)
		std::cout << -1 << "\n";
	else
		std::cout << D->Back->data << "\n";
}

int main() {
	Deque d;
	int N, num;
	std::string str;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> str;

		if (str == "push_front") {
			std::cin >> num;
			d.push_front(num);
		}
		else if (str == "push_back") {
			std::cin >> num;
			d.push_back(num);
		}
		else if (str == "pop_front")
			d.pop_front();

		else if (str == "pop_back")
			d.pop_back();

		else if (str == "size")
			d.size();

		else if (str == "empty")
			d.empty();

		else if (str == "front")
			d.front();

		else if (str == "back")
			d.back();
	}
	return 0;
}