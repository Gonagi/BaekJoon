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

/*
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
*/

/*
// 1107번 문제

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<bool> broken(10, false);

int possible(int num){
    if(num == 0)
        return broken[0] ? 0 : 1;
    
    int length = 0;
    while(num > 0)
    {
        if(broken[num % 10]) return 0;
        length++;
        num /= 10;
    }

    return length;
}

int main(){
    int N, M, num;

    std::cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        std::cin >> num;
        broken.at(num) = true;
    }

    int min = std::max(100 - N, N - 100);

    if (N != 100)
    {
        for (int num = 0; num < 1000000; num++)
        {
            if(possible(num))
                min = std::min(min, possible(num) + std::max(N-num, num-N));
        }
    }

    std::cout << min << "\n";

    return 0;
}
*/

/*
// 14500번 문제

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<long long>> box;

long long case1(int N, int M);
long long case2(int N, int M);
long long case3(int N, int M);
long long case4(int N, int M);
long long case5(int N, int M);

int main()
{
    int N, M;
    long long num;

    std::cin >> N >> M;
    std::vector<long long> vec;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> num;
            vec.push_back(num);
        }
        box.push_back(vec);
        vec.clear();
        vec.shrink_to_fit();
    }

    std::cout << std::max({case1(N, M), case2(N, M), case3(N, M), case4(N, M), case5(N, M)}) << "\n";

    return 0;
}

long long case1(int N, int M)
{
    long long max = 0, sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M - 3; j++)
        {
            sum = box[i].at(j) + box[i].at(j + 1) + box[i].at(j + 2) + box[i].at(j + 3);
            max = std::max(max, sum);
        }
    }

    for (int i = 0; i < N - 3; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sum = (box[i].at(j) + box[i + 1].at(j) + box[i + 2].at(j) + box[i + 3].at(j));
            max = std::max(max, sum);
        }
    }

    return max;
}

long long case2(int N, int M)
{
    long long max = 0, sum = 0;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < M - 1; j++)
        {
            sum = box[i].at(j) + box[i + 1].at(j) + box[i].at(j + 1) + box[i + 1].at(j + 1);
            max = std::max(max, sum);
        }
    }
    return max;
}

long long case3(int N, int M)
{
    long long max1 = 0, max2 = 0, sum = 0;
    for(int i = 0; i < N-1; i++)
        for(int j = 0; j < M-2; j++)
            max1 = std::max({max1, 
                            box[i].at(j) + box[i+1].at(j) + box[i+1].at(j+1) + box[i+1].at(j+2),
                            box[i].at(j+2)+ box[i+1].at(j) + box[i+1].at(j+1) + box[i+1].at(j+2),
                            box[i].at(j) + box[i].at(j+1) + box[i].at(j+2) + box[i+1].at(j+2),
                            box[i].at(j) + box[i].at(j+1) + box[i].at(j+2) + box[i+1].at(j)});
    
    for(int i = 0; i < N-2; i++)
        for(int j = 0; j < M-1; j++)
            max2 = std::max({max2,
                             box[i].at(j) + box[i+1].at(j) + box[i+2].at(j) + box[i+2].at(j+1),
                             box[i].at(j) + box[i].at(j+1) + box[i+1].at(j) + box[i+2].at(j),
                             box[i].at(j+1) + box[i+1].at(j+1) + box[i+2].at(j) + box[i+2].at(j+1),
                             box[i].at(j) + box[i].at(j+1) + box[i+1].at(j+1) + box[i+2].at(j+1)});

    return std::max(max1, max2);
}

long long case4(int N, int M)
{
    long long max1 = 0, max2 = 0, sum = 0;

    for (int i = 0; i < N - 2; i++)
        for (int j = 0; j < M - 1; j++)
            max1 = std::max({max1, 
                            box[i].at(j) + box[i + 1].at(j) + box[i + 1].at(j + 1) + box[i + 2].at(j + 1),
                            box[i].at(j + 1) + box[i + 1].at(j) + box[i + 1].at(j + 1) + box[i + 2].at(j)});

    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < M - 2; j++)
            max2 = std::max({max2,
                            box[i].at(j + 1) + box[i].at(j + 2) + box[i + 1].at(j) + box[i + 1].at(j + 1),
                            box[i].at(j) + box[i].at(j + 1) + box[i + 1].at(j + 1) + box[i + 1].at(j + 2)});

    return std::max(max1, max2);
}

long long case5(int N, int M)
{
    long long max1 = 0, max2 = 0, sum = 0;

    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < M - 2; j++)
            max1 = std::max({max1, 
                            box[i].at(j) + box[i].at(j + 1) + box[i].at(j + 2) + box[i + 1].at(j + 1),
                            box[i].at(j + 1) + box[i + 1].at(j) + box[i + 1].at(j + 1) + box[i + 1].at(j + 2)});

    for (int i = 0; i < N - 2; i++)
        for (int j = 0; j < M - 1; j++)
            max2 = std::max({max2,
                            box[i].at(j) + box[i + 1].at(j) + box[i + 1].at(j + 1) + box[i + 2].at(j),
                            box[i].at(j + 1) + box[i + 1].at(j) + box[i + 1].at(j + 1) + box[i + 2].at(j + 1)});

    return std::max(max1, max2);
}
*/


#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<long long>> box;

int main()
{
    int N, M;
    long long num;

    std::cin >> N >> M;
    std::vector<long long> vec;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> num;
            vec.push_back(num);
        }
        box.push_back(vec);
        vec.clear();
        vec.shrink_to_fit();
    }

    return 0;
}