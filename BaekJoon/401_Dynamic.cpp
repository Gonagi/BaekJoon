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

/*
// 11057번 문제

#include <iostream>
#include <vector>

int main()
{
    int N;
    long long sum = 0;
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
        for(int index = 0; index < 10; index++){
            for(int j = 0 + index; j < 10; j++)
                sum += DP[j].at(i-1);
            DP[index].push_back(sum % 10007);
            sum = 0;
        }
        
        // DP[0].push_back((DP[0].at(i - 1) + DP[1].at(i - 1) + DP[2].at(i - 1) + DP[3].at(i - 1) + DP[4].at(i - 1) + DP[5].at(i - 1) + DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        // DP[1].push_back((DP[1].at(i - 1) + DP[2].at(i - 1) + DP[3].at(i - 1) + DP[4].at(i - 1) + DP[5].at(i - 1) + DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        // DP[2].push_back((DP[2].at(i - 1) + DP[3].at(i - 1) + DP[4].at(i - 1) + DP[5].at(i - 1) + DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        // DP[3].push_back((DP[3].at(i - 1) + DP[4].at(i - 1) + DP[5].at(i - 1) + DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        // DP[4].push_back((DP[4].at(i - 1) + DP[5].at(i - 1) + DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        // DP[5].push_back((DP[5].at(i - 1) + DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        // DP[6].push_back((DP[6].at(i - 1) + DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        // DP[7].push_back((DP[7].at(i - 1) + DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        // DP[8].push_back((DP[8].at(i - 1) + DP[9].at(i - 1)) % 10007 );
        // DP[9].push_back((DP[9].at(i - 1)) % 10007 );
        
    }

    std::cout << (DP[0].at(N - 1) + DP[1].at(N - 1) + DP[2].at(N - 1) + DP[3].at(N - 1) + DP[4].at(N - 1) + DP[5].at(N - 1) + DP[6].at(N - 1) + DP[7].at(N - 1) + DP[8].at(N - 1) + DP[9].at(N - 1)) % 10007 << "\n";

    return 0;
}
*/

/*
// 9465번 문제

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int T, num;
    long long n;
    std::vector<int> input[2], dp[2];
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        std::cin >> n;

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
            {
                std::cin >> num;
                input[j].push_back(num);
            }
        }

        dp[0].push_back(input[0].at(0));
        dp[1].push_back(input[1].at(0));

        if (n > 1)
        {
            dp[0].push_back(input[0].at(1) + input[1].at(0));
            dp[1].push_back(input[0].at(0) + input[1].at(1));

            for (int i = 2; i < n; i++)
            {
                dp[0].push_back(input[0].at(i) + std::max(dp[1].at(i - 1), dp[1].at(i - 2)));
                dp[1].push_back(input[1].at(i) + std::max(dp[0].at(i - 1), dp[0].at(i - 2)));
            }
        }

        std::cout << std::max(dp[0].at(n - 1), dp[1].at(n - 1)) << "\n";

        for (int i = 0; i < 2; i++)
        {
            input[i].clear();
            input[i].shrink_to_fit();
            dp[i].clear();
            dp[i].shrink_to_fit();
        }
    }
    return 0;
}
*/

// 2156번 문제

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, num;
    std::vector<int> cup, dp;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cin >> num;
        cup.push_back(num);
    }

    dp.push_back(cup.at(0));
    
    if(n > 1){
        dp.push_back(dp.at(0) + cup.at(1));

        if(n > 2){
            dp.push_back(std::max({cup.at(1) + cup.at(2), cup.at(0) + cup.at(2), cup.at(0) + cup.at(1)}));

            for(int i = 3; i < n; i++){
                dp.push_back(std::max({dp.at(i-3) + cup.at(i-1) + cup.at(i),
                                        dp.at(i-2) + cup.at(i),
                                        dp.at(i-1)}));
            }
        }
    }

    std::cout << dp.at(n-1);

    return 0;
}