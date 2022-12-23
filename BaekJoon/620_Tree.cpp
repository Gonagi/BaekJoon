#include <iostream>

int N;
std::pair<char, char> arr[26];

void preorder(char ch);
void inorder(char ch);
void postorder(char ch);

int main() {
    char node, left, right;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> node >> left >> right;
        arr[(node - 'A')].first = left;
        arr[(node - 'A')].second = right;
    }

    preorder('A');
    std::cout << "\n";
    inorder('A');
    std::cout << "\n";
    postorder('A');

    return 0;
}

void preorder(char ch) {
    if (ch != '.') {
        std::cout << ch;
        preorder(arr[ch - 'A'].first);
        preorder(arr[ch - 'A'].second);
    }
}

void inorder(char ch) {
    if (ch != '.') {
        inorder(arr[ch - 'A'].first);
        std::cout << ch;
        inorder(arr[ch - 'A'].second);
    }
}

void postorder(char ch) {
    if (ch != '.') {
        postorder(arr[(ch - 'A')].first);
        postorder(arr[(ch - 'A')].second);
        std::cout << ch;
    }
}
