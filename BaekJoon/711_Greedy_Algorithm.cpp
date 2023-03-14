// 잃어버린 괄
// 1541

#include <iostream>
#include <sstream>
#include <string>
std::string str;

int main() {
    std::cin >> str;
    std::stringstream ss(str);
    bool check = false;
    int num, sum = 0;

    while (ss >> num) {
        if (num < 0) {
            sum += num;
            check = true;
        } else if (!check) {
            sum += num;
        } else
            sum -= num;
    }

    std::cout << sum << '\n';
    return 0;
}