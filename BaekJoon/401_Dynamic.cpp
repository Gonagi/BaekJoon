/*
// 15998번 문제

#include <iostream>
#include <vector>

int main(){
    long long T, n;
    std::vector<long long> vec[3];

    vec[0].push_back(1);
    vec[0].push_back(1);
    vec[0].push_back(2);

    vec[1].push_back(0);
    vec[1].push_back(1);
    vec[1].push_back(1);

    vec[2].push_back(0);
    vec[2].push_back(0);
    vec[2].push_back(1);

    std::cin >> T;

    for(int i = 0; i < T; i++){
        std::cin >> n;

        if(n > vec->size()){
            for(int j = vec->size(); j < n; j++){
                vec[0].push_back((vec[0].at(j-1) + vec[1].at(j-1) + vec[2].at(j-1)) % 1000000009);
                vec[1].push_back((vec[0].at(j-2) + vec[1].at(j-2) + vec[2].at(j-2)) % 1000000009);
                vec[2].push_back((vec[0].at(j-3) + vec[1].at(j-3) + vec[2].at(j-3)) % 1000000009);
            }
        }
        std::cout << (vec[0].at(n-1) + vec[1].at(n-1) + vec[2].at(n-1)) % 1000000009<< "\n" ;
    }
    return 0;
}
*/

/*
// 1149번 문제

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N, num;
    std::vector<int> RGB[3], DP[3];

    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> num;
            RGB[j].push_back(num);
        }
    }

    DP[0].push_back(RGB[0].at(0));
    DP[1].push_back(RGB[1].at(0));
    DP[2].push_back(RGB[2].at(0));

    for(int i = 1; i < N; i++){
        DP[0].push_back((std::min(DP[1].at(i-1), DP[2].at(i-1))) + RGB[0].at(i));
        DP[1].push_back((std::min(DP[0].at(i-1), DP[2].at(i-1))) + RGB[1].at(i));
        DP[2].push_back((std::min(DP[0].at(i-1), DP[1].at(i-1))) + RGB[2].at(i));
    }

    std::cout << std::min({DP[0].at(N-1), DP[1].at(N-1), DP[2].at(N-1)});

    return 0;
}
*/

/*
// 1309번 문제
#include <iostream>
#include <vector>

int main()
{
    long long N;
    std::vector<int> DP[3];

    std::cin >> N;

    DP[0].push_back(1);
    DP[1].push_back(1);
    DP[2].push_back(1);

    for (int i = 1; i < N; i++)
    {
        DP[0].push_back((DP[0].at(i - 1) + DP[1].at(i - 1) + DP[2].at(i - 1)) % 9901);
        DP[1].push_back((DP[0].at(i - 1) + DP[2].at(i - 1)) % 9901);
        DP[2].push_back((DP[0].at(i - 1) + DP[1].at(i - 1)) % 9901);
    }

    std::cout << (DP[0].at(N - 1) + DP[1].at(N - 1) + DP[2].at(N - 1)) % 9901 << "\n";
    return 0;
}
*/

// 11057번 문제

#include <iostream>
#include <vector>

int main()
{
    int N;
    std::vector<long long> DP[10];

    DP[0].push_back(1);
    DP[1].push_back(1);
    DP[2].push_back(1);
    DP[3].push_back(1);
    DP[4].push_back(1);
    DP[5].push_back(1);
    DP[6].push_back(1);
    DP[7].push_back(1);
    DP[8].push_back(1);
    DP[9].push_back(1);

    std::cin >> N;

    for (int i = 1; i < N; i++)
    {
        DP[0].push_back((DP[0].at(i - 1) + DP[1].at(i - 1) + DP[2].at(i - 1) + DP[3].at(i - 1) + DP[4].at(i - 1) + DP[5].at(i - 1) + DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        DP[1].push_back((DP[1].at(i - 1) + DP[2].at(i - 1) + DP[3].at(i - 1) + DP[4].at(i - 1) + DP[5].at(i - 1) + DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        DP[2].push_back((DP[2].at(i - 1) + DP[3].at(i - 1) + DP[4].at(i - 1) + DP[5].at(i - 1) + DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        DP[3].push_back((DP[3].at(i - 1) + DP[4].at(i - 1) + DP[5].at(i - 1) + DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        DP[4].push_back((DP[4].at(i - 1) + DP[5].at(i - 1) + DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        DP[5].push_back((DP[5].at(i - 1) + DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        DP[6].push_back((DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        DP[7].push_back((DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        DP[8].push_back((DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        DP[9].push_back((DP[9].at(i - 1)) % 10007 );
    }

    std::cout << (DP[0].at(N - 1) + DP[1].at(N - 1) + DP[2].at(N - 1) + DP[3].at(N - 1) + DP[4].at(N - 1) + DP[5].at(N - 1) + DP[6].at(N - 1) + DP[7].at(N - 1) + DP[8].at(N - 1) + DP[9].at(N - 1)) % 10007 << "\n";

    return 0;
}