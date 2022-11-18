#include <iostream>
#include <string>

void add(int num);
void remove(int num);
int check(int num);
void toggle(int num);
void all();
void empty();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int M, num, S = 0;
    std::string str;
    std::cin >> M;

    for (int index = 0; index < M; index++) {
        std::cin >> str;

        if (str == "add") {
            std::cin >> num;
            S |= (1 << num);
        }

        else if (str == "remove") {
            std::cin >> num;
            S &= ~(1 << num);
        }

        else if (str == "check") {
            std::cin >> num;
            if (S & (1 << num))
                std::cout << 1 << "\n";
            else
                std::cout << 0 << "\n";
        }

        else if (str == "toggle") {
            std::cin >> num;
            S ^= (1 << num);
        }

        else if (str == "all")
            S = (1 << 21) - 1;

        else if (str == "empty")
            S = 0;
    }

    return 0;
}