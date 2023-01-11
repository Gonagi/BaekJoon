#include <algorithm>
#include <iostream>
#include <vector>

int N;
bool visited[2000001];
std::vector<int> vec;

int main() {
    int num;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        vec.push_back(num);
    }
    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < (1 << N); i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j))
                sum += vec[j];
        }
        visited[sum] = true;
    }

    for (int num = 1; num <= 2000000; num++) {
        if (!visited[num]) {
            std::cout << num << "\n";
            break;
        }
    }
    return 0;
}