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
/*
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
*/

// 3197
// 백조의 호수
/*
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Direction
{
  int y, x;
};

void input();
void check_ice();
bool check(Direction cur);

Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
std::vector<std::vector<char>> map;
std::queue<Direction> L_que, next_L_que, Ice_que, next_ice_que;
int R, C;
bool visited[1500][1500];

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int day = 1;

  input();
  check_ice();

  while (1)
  {
    while (!Ice_que.empty())
    {
      Direction cur = Ice_que.front();
      visited[cur.y][cur.x] = true;
      map[cur.y][cur.x] = '.';
      Ice_que.pop();

      for (int d = 0; d < 4; d++)
      {
        Direction next({cur.y + dir[d].y, cur.x + dir[d].x});

        if (next.y >= 0 && next.y < R && next.x >= 0 && next.x < C)
        {
          if (!visited[next.y][next.x] && map[next.y][next.x] == 'X')
          {
            next_ice_que.push(next);
            visited[next.y][next.x] = true;
          }
        }
      }
    }

    Ice_que.swap(next_ice_que);

    while (!L_que.empty())
    {
      Direction cur = L_que.front();
      map[cur.y][cur.x] = 'O';
      L_que.pop();

      for (int d = 0; d < 4; d++)
      {
        Direction next({cur.y + dir[d].y, cur.x + dir[d].x});

        if (next.y >= 0 && next.y < R && next.x >= 0 && next.x < C && map[next.y][next.x] != 'O')
        {
          if (map[next.y][next.x] == '.')
          {
            L_que.push(next);
            map[next.y][next.x] = 'O';
          }
          else if (map[next.y][next.x] == 'X')
          {
            next_L_que.push(next);
            map[next.y][next.x] = 'O';
          }

          else if (map[next.y][next.x] == 'L')
          {
            std::cout << day << '\n';
            return 0;
          }
        }
      }
    }
    L_que.swap(next_L_que);

    day++;
  }
}

void input()
{
  std::vector<char> map_x;
  std::string str;
  bool is_L = false;

  std::cin >> R >> C;

  for (int y = 0; y < R; y++)
  {
    std::cin >> str;
    for (int x = 0; x < C; x++)
    {
      map_x.push_back(str[x]);
      if (!is_L && str[x] == 'L')
      {
        is_L = true;
        L_que.push({y, x});
      }
    }
    map.push_back(map_x);
    map_x.clear();
    map_x.shrink_to_fit();
  }
}

void check_ice()
{
  for (int y = 0; y < R; y++)
  {
    for (int x = 0; x < C; x++)
    {
      if (map[y][x] == 'X')
      {
        if (check({y, x}))
          Ice_que.push({y, x});
      }
    }
  }
}

bool check(Direction cur)
{
  Direction next{cur};

  for (int d = 0; d < 4; d++)
  {
    Direction next({cur.y + dir[d].y, cur.x + dir[d].x});
    if (next.y < 0 || next.y >= R || next.x < 0 || next.x >= C)
      continue;
    if (map[next.y][next.x] == '.' || map[next.y][next.x] == 'L')
      return true;
  }

  return false;
}
*/

// 11401
// 이항 계수 3
/*
#include <iostream>
#define MOD 1000000007

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  long long result = 1, N, K;

  std::cin >> N >> K;

  for (long long num = K + 1; num <= N; num++)
    result = (result * num) % MOD;

  long long base = 1;
  for (long long num = 1; num <= N - K; num++)
    base = (base * num) % MOD;

  long long exponent = MOD - 2;

  while (exponent)
  {
    if (exponent & 1) // 홀수일때 (exponent % 2 == 1)
      result = (result * base) % MOD;

    base = (base * base) % MOD;
    exponent = (exponent >> 1); // exponent /= 2
  }

  std::cout << result << '\n';

  return 0;
}
*/

/*
// 4344
// 평균은 넘겠지
#include <cmath>
#include <iostream>
#include <vector>

int main()
{
  std::vector<double> vec;
  int C;
  double N, num;
  std::cin >> C;

  for (int idx = 0; idx < C; idx++)
  {
    int count = 0;
    double sum = 0, avg = 0;
    std::cin >> N;

    for (int idx2 = 0; idx2 < N; idx2++)
    {
      std::cin >> num;
      vec.push_back(num);
      sum += num;
    }
    avg = sum / N;

    for (int idx2 = 0; idx2 < N; idx2++)
    {
      if (vec[idx2] > avg)
        count++;
    }

    std::cout << std::fixed;
    std::cout.precision(3);

    std::cout << std::round((count) / N * 1000) / 10 << "%\n";
    vec.clear();
    vec.shrink_to_fit();
  }
  return 0;
}
*/

// 행렬 제곱
// 10830

#include <iostream>
#include <vector>

int main()
{
  std::vector<std::vector<int>> vec;
  std::vector<int> vec_x;
  int N, num;
  long long B;

  std::cin >> N >> B;
  std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));

  for (int y = 0; y < N; y++)
  {
    for (int x = 0; x < N; x++)
    {
      std::cin >> num;
      vec_x.push_back(num);
      if (y == x)
        result[y][x] = 1;
    }
    vec.push_back(vec_x);

    vec_x.clear();
    vec_x.shrink_to_fit();
  }

  if (B != 1)
  {
    while (B > 0)
    {
      if (B & 1)
      {
        std::vector<std::vector<int>> temp(N, std::vector<int>(N, 0));

        for (int k = 0; k < N; k++)
        {
          for (int y = 0; y < N; y++)
          {
            int cal = result[y][k];

            for (int x = 0; x < N; x++)
              temp[y][x] += (cal * vec[k][x]) % 1000;
          }
        }
        result = temp;
      }

      std::vector<std::vector<int>> temp(N, std::vector<int>(N, 0));
      for (int k = 0; k < N; k++)
      {
        for (int y = 0; y < N; y++)
        {
          int cal = vec[y][k];
          for (int x = 0; x < N; x++)
            temp[y][x] += (cal * vec[k][x]) % 1000;
        }
      }

      vec = temp;

      B = B >> 1;
    }
  }
  else
    result = vec;

  for (int y = 0; y < N; y++)
  {
    for (int x = 0; x < N; x++)
    {
      std::cout << result[y][x] % 1000 << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
