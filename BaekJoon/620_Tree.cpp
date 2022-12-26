/*
// 트리 순회
// 1991
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
*/

/*
// 트리의 높이와 너비
// 2250

#include <algorithm>
#include <iostream>
#define Max 100000 + 1

void inorder(int num);
void find_min();

int N, level, idx = 1, count[Max], low[Max], high[Max];
std::pair<int, int> arr[Max];

int main() {
    std::fill_n(low, Max, Max);
    int node, left, right;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> node >> left >> right;
        arr[node].first = left;
        arr[node].second = right;

        count[node]++;
        count[left]++;
        count[right]++;
    }

    int root;
    for (int i = 1; i <= N; i++) {
        if (count[i] == 1) {
            root = i;
            break;
        }
    }

    inorder(root);
    find_min();

    return 0;
}

void inorder(int num) {
    if (num != -1) {
        level++;
        inorder(arr[num].first);
        low[level] = std::min(low[level], idx);
        high[level] = std::max(high[level], idx++);
        inorder(arr[num].second);
        level--;
    }
}

void find_min() {
    int max_level = 1, max = 0;
    for (int cur_level = 1; cur_level <= N; cur_level++) {
        if (max < high[cur_level] - low[cur_level] + 1) {
            max = high[cur_level] - low[cur_level] + 1;
            max_level = cur_level;
        }
    }

    std::cout << max_level << " " << max << "\n";
    return;
}
*/

/*
// 11725
// 트리의 부모 찾기

#include <iostream>
#include <queue>
#include <vector>

#define Max 100000 + 1

int N, level[Max];
bool visited[Max];
std::vector<int> vec[Max];

void input();
void level_BFS();
void print();

int main() {
    input();
    level_BFS();
    print();
    return 0;
}

void input() {
    int dot1, dot2;

    std::cin >> N;

    for (int i = 1; i < N; i++) {
        std::cin >> dot1 >> dot2;
        vec[dot1].push_back(dot2);
        vec[dot2].push_back(dot1);
    }
}

void level_BFS() {
    std::queue<std::pair<int, int>> que;
    que.push({1, 1});
    level[1] = 1;
    visited[1] = true;

    while (!que.empty()) {
        int cur_node = que.front().first;
        int cur_level = que.front().second;
        level[cur_node] = cur_level;
        visited[cur_node] = true;
        que.pop();

        for (int idx = 0; idx < vec[cur_node].size(); idx++) {
            int next_node = vec[cur_node][idx];
            if (!visited[next_node])
                que.push({next_node, cur_level + 1});
        }
    }
}

void print() {
    for (int num = 2; num <= N; num++) {
        for (int idx = 0; idx < vec[num].size(); idx++) {
            if (level[vec[num][idx]] == level[num] - 1) {
                std::cout << vec[num][idx] << "\n";
                break;
            }
        }
    }
}
*/

#include <iostream>
#include <queue>
#include <vector>

#define Max 100000 + 1

int N, level[Max];
bool visited[Max];
std::vector<int> vec[Max];

void input();
void level_BFS();
void print();

int main() {
    input();
    level_BFS();
    print();
    return 0;
}

void input() {
    int dot1, dot2;

    std::cin >> N;

    for (int i = 1; i < N; i++) {
        std::cin >> dot1 >> dot2;
        vec[dot1].push_back(dot2);
        vec[dot2].push_back(dot1);
    }
}

void level_BFS() {
    std::queue<int> que;
    que.push(1);
    visited[1] = true;

    while (!que.empty()) {
        int cur_node = que.front();
        visited[cur_node] = true;
        que.pop();

        for (int idx = 0; idx < vec[cur_node].size(); idx++) {
            int next_node = vec[cur_node][idx];
            if (!visited[next_node]) {
                que.push(next_node);
                level[next_node] = cur_node;
            }
        }
    }
}

void print() {
    for (int num = 2; num <= N; num++)
        std::cout << level[num] << "\n";
}
