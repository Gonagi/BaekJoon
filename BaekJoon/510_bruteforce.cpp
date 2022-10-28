/*
// 15649번 문제

#include <iostream>
#include <vector>

std::vector<bool> visited(8, false);
std::vector<int> vec(8, 0);
int M, N;

void print(int count);

int main()
{
    std::cin >> N >> M;

    print(0);
    return 0;
}

void print(int count)
{
        if (count == M)
        {
            for(int i = 0; i < M; i++)
                std::cout << vec.at(i)<<" ";
            std::cout << "\n";
            return;
        }

    for (int i = 0; i < N; i++)
    {
        if (!visited.at(i))
        {
            vec.at(count) = i+1;
            visited.at(i) = true;
            print(count+1);
            visited.at(i) = false;
        }
    }
}
*/
// 15650번 문제

#include <iostream>
#include <vector>

int M, N;
std::vector<int> vec(8, 0);
std::vector<bool> visited(8, false);

void print(int count, int cur);

int main()
{
    std::cin >> N >> M;
    print(0, 0);
    return 0;
}

void print(int count, int cur)
{
    if (count == M)
    {
        for (int i = 0; i < M; i++)
            std::cout << vec.at(i) << " ";
        std::cout << "\n";
        return;
    }

    for (int index = cur; index < N; index++)
    {
        if (!visited.at(index))
        {
            visited.at(index) = true;
            vec.at(count) = index + 1;
            print(count + 1, index + 1);
            visited.at(index) = false;
        }
    }
}