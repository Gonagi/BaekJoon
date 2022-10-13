/*
// 2309번 문제

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int num, sum = 0;
    std::vector<int> vec;

    for (int i = 0; i < 9; i++)
    {
        std::cin >> num;
        sum += num;
        vec.push_back(num);
    }

    std::sort(vec.begin(), vec.end());

    for(int i = 0; i < 8; i++){
        for(int j = i+1; j<9; j++){
            if((sum - vec.at(i) - vec.at(j)) == 100){
                for(int a = 0; a < 9; a++){
                    if(a == i || a == j)
                        continue;
                    std::cout << vec.at(a)<<"\n";
                }
                return 0;
            }
        }
    }

    return 0;
}
*/

/*
// 3085번 문제

#include <iostream>
#include <vector>
#include <algorithm>

int check_x(const std::vector<std::vector<char>>& vec, int N);
int check_y(const std::vector<std::vector<char>>& vec, int N);

int main(){
    int N, max = 0;
    char ch;
    std::vector<std::vector<char>> vec1;
    std::vector<char> vec2;

    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> ch;
            vec2.push_back(ch);
        }
        vec1.push_back(vec2);
        vec2.clear();
        vec2.shrink_to_fit();
    }

    max = std::max({max, check_x(vec1, N), check_y(vec1, N)});

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (vec1[i].at(j) != vec1[i].at(j + 1))
            {
                std::swap(vec1[i].at(j), vec1[i].at(j + 1));
                max = std::max({max, check_x(vec1, N), check_y(vec1, N)});
                std::swap(vec1[i].at(j), vec1[i].at(j + 1));
            }
        }
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vec1[i].at(j) != vec1[i+1].at(j))
            {
                std::swap(vec1[i].at(j), vec1[i+1].at(j));
                max = std::max({max, check_x(vec1, N), check_y(vec1, N)});
                std::swap(vec1[i].at(j), vec1[i+1].at(j));
            }
        }
    }

    std::cout << max << "\n";
    return 0;
}

int check_x(const std::vector<std::vector<char>> &vec, int N)
{
    int max = 1, check = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (vec[i].at(j) == vec[i].at(j + 1))
                max = std::max(max, ++check);
            else
                check = 1;
        }
        check = 1;
    }
    return max;
}

int check_y(const std::vector<std::vector<char>> &vec, int N)
{
    int max = 1, check = 1;

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N - 1; i++)
        {
            if (vec[i].at(j) == vec[i + 1].at(j))
                max = std::max(max, ++check);

            else
                check = 1;
        }
        check = 1;
    }

    return max;
}
*/

// 1476번 문제

#include <iostream>

int main()
{
    long long a, b, c, i = 1;
    std::cin >> a >> b >> c;

    while (1)
    {
        if (((i % 15 == a) || (i % 15 == a-15)) &&
            ((i % 28 == b) || (i % 28 == b-28)) &&
            ((i % 19 == c) || (i % 19 == c-19)))
            break;
        i++;
    }

    std::cout << i << "\n";
    return 0;
}