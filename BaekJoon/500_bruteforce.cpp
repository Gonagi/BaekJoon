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

// 3085번 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(){
    int N, max = 0;
    std::cin >> N;

    std::string Board[N];
    std::vector<std::vector<int>> Length(N, std::vector<int>(N, 1));

    for (int i = 0; i < N; i++)
        std::cin >> Board[i];

    for(int i = 0; i < N; i++)
        for(int j = 1; j < N; j++)
            if(Board[i].at(j-1) == Board[i].at(j))
                max = std::max(max, Length[i].at(j)++);

    for(int i = 0; i < N; i++)
        for(int j = 0; j <N; j++)
            Length[i].at(j) = 1;

    for (int j = 0; j < N; j++)
        for (int i = 1; i < N; i++)
            if (Board[i].at(j) == Board[i - 1].at(j))
                max = std::max(max, Length[i].at(j)++);

    for(int i = 0; i < N; i++)
        for(int j = 0; j <N; j++)
            Length[i].at(j) = 1;

    for(int i = 0; i < N; i++){
        for(int j = 1; j < N; j++){
            if(Board[i].at(j-1) != Board[i].at(j)){
                if(j+1 < N && Board[i].at(j-1) == Board[i].at(j+1))
            }
        }
    }
    return 0;
}
