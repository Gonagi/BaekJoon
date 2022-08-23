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