// 12865
// 평범한 배낭
/*
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int max = 0;
std::vector<std::pair<int, int>> vec;

int main()
{
  int N, K, W, V; // 개수, 한계, 무게, 가치
  std::cin >> N >> K;

  for (int idx = 0; idx < N; idx++)
  {
    std::cin >> W >> V;
    vec.push_back({W, V});
  }

  std::vector<std::vector<int>> DP(N + 1, std::vector<int>(K + 1, 0));

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= K; j++)
    {
      if (j < vec[i - 1].first)
        DP[i][j] = DP[i - 1][j];
      else
      {
        DP[i][j] = std::max(DP[i - 1][j], vec[i - 1].second + DP[i - 1][j - vec[i - 1].first]);
      }
    }
  }

  std::cout << DP[N][K] << '\n';

  return 0;
}
*/

/* 시간초과
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int max = 0;
std::vector<std::pair<int, int>> vec;

int main() {
  int N, K, W, V;  // 개수, 한계, 무게, 가치
  std::cin >> N >> K;

  for (int idx = 0; idx < N; idx++) {
    std::cin >> W >> V;
    vec.push_back({W, V});
  }

  for (int i = 1; i < (1 << vec.size()); i++) {
    int weight_check = 0;
    int value_check = 0;

    for (int j = 0; j < vec.size(); j++) {
      if (i & (1 << j)) {

        if (K >= weight_check + vec[j].first) {
          weight_check += vec[j].first;
          value_check += vec[j].second;
        }
      }
    }

        for (int j = 0; j < vec.size(); j++)
        {
        if (i & (1 << j))
           {
           if (K >= weight_check + vec[j].first)
           {
               weight_check += vec[j].first;
               value_check += vec[j].second;
            }
        }
    }
    if (max < value_check)
      max = value_check;
  }

  std::cout << max << '\n';

  return 0;
}
*/

// 1655
// 가운데를 말해요

#include <algorithm>
#include <iostream>
#include <queue>

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, num;
  std::priority_queue<int> left;
  std::priority_queue<int, std::vector<int>, std::greater<int>> right;

  std::cin >> N;

  for (int idx = 0; idx < N; idx++)
  {
    std::cin >> num;
    if (left.size() == right.size())
      left.push(num);

    else
      right.push(num);

    if (!left.empty() && !right.empty())
    {
      int temp1 = left.top();
      int temp2 = right.top();
      if (temp1 > temp2)
      {
        left.pop();
        right.pop();
        left.push(temp2);
        right.push(temp1);
      }
    }
    std::cout << left.top() << '\n';
  }

  return 0;
}