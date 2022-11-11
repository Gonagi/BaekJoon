/*
// 10972번 문제

#include <algorithm>
#include <iostream>
#include <vector>

int N;
bool result = false, result2 = false;
std::vector<int> input, check, vec;
std::vector<bool> visited;

void DFS(int count);

int main() {
  int num;
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> num;
    input.push_back(num);
    visited.push_back(false);
  }

  check = input;
  vec = check;
  std::sort(check.begin(), check.end());

  DFS(0);
  if (result)
    std::cout << -1 << "\n";

  return 0;
}

void DFS(int count) {
  if (count == N) {
    if (result) {
      for (int index = 0; index < N; index++)
        std::cout << vec.at(index) << " ";
      std::cout << "\n";
      result = false;
      result2 = true;
      return;

    } else {
      for (int index = 0; index < N; index++) {
        if (vec.at(index) != input.at(index))
          return;
      }
      result = true;
      return;
    }
  }

  for (int index = 0; index < N; index++) {
    if (!visited.at(index)) {
      visited.at(index) = true;
      vec.at(count) = check.at(index);
      DFS(count + 1);
      visited.at(index) = false;

      if (result2)
        return;
    }
  }
}
*/

/*
// 10972번 문제

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N, num;
  bool result = false;
  std::cin >> N;
  std::vector<int> input;

  for (int i = 0; i < N; i++) {
    std::cin >> num;
    input.push_back(num);
  }

  for (int index = N - 1; index > 0; index--) {

    if (input.at(index - 1) < input.at(index)) {
      int min = index;

      for (int check = index; check < N; check++)
        if (input.at(index - 1) < input.at(check) &&
            input.at(min) > input.at(check))
          min = check;

      std::swap(input[index - 1], input[min]);
      std::sort(input.begin() + index, input.end());

      result = true;
      break;
    }
  }

  if (result) {
    for (int index = 0; index < N; index++)
      std::cout << input.at(index) << " ";
    std::cout << "\n";
  }

  else
    std::cout << -1 << "\n";

  return 0;
}
*/

/*
// 10973번 문제

#include <algorithm>
#include <iostream>
#include <vector>

bool compare(int a, int b) { return a > b; }

int main() {
  int N, num;
  bool result = false;
  std::cin >> N;
  std::vector<int> input;

  for (int i = 0; i < N; i++) {
    std::cin >> num;
    input.push_back(num);
  }

  for (int index = N - 1; index > 0; index--) {

    if (input.at(index - 1) > input.at(index)) {
      int min = index;

      for (int check = index; check < N; check++)
        if (input.at(check) < input.at(index - 1) &&
            input.at(min) < input.at(check))
          min = check;

      std::swap(input.at(index - 1), input.at(min));
      std::sort(input.begin() + index, input.end(), compare);
      result = true;
      break;
    }
  }

  if (result) {
    for (int index = 0; index < N; index++)
      std::cout << input.at(index) << " ";
    std::cout << "\n";
  }

  else
    std::cout << -1 << "\n";

  return 0;
}
*/

/*
// 10974번 문제

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N;
  std::vector<int> vec;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    vec.push_back(i + 1);
  }

  long long count = 1;

  for (int i = 1; i <= N; i++)
    count *= static_cast<long long>(i);

  for (long long a = 1; a <= count; a++) {
    for (int i = 0; i < N; i++)
      std::cout << vec.at(i) << " ";
    std::cout << "\n";

    for (int index = N - 1; index > 0; index--) {
      if (vec.at(index - 1) < vec.at(index)) {
        int min = index;

        for (int check = index; check < N; check++)
          if (vec.at(index - 1) < vec.at(check) && vec.at(min) > vec.at(check))
            min = check;

        std::swap(vec[index - 1], vec[min]);
        std::sort(vec.begin() + index, vec.end());
        break;
      }
    }
  }
  return 0;
}
*/

/*
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> vec(N);

    for (int i = 1; i <= N; i++)
        vec.at(i - 1) = i;

    do {
        for (auto p : vec)
            std::cout << p << " ";
        std::cout << "\n";
    } while (std::next_permutation(vec.begin(), vec.end()));

    return 0;
}
*/

/*
// 10819번 문제

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    int N, num, result = 0;
    long long max = 0;
    bool is_ascending = true;
    std::cin >> N;
    std::vector<int> vec, vec2;

    for (int index = 0; index < N; index++) {
        std::cin >> num;
        vec.push_back(num);
    }

    std::sort(vec.begin(), vec.end());

    do {
        for (int index = 0; index < N - 1; index++)
            result += std::abs(vec.at(index + 1) - vec.at(index));

        max = std::max(max, static_cast<long long>(result));
        result = 0;
    } while (std::next_permutation(vec.begin(), vec.end()));

    std::cout << max << "\n";
    return 0;
}
*/

/*
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

void DFS(int count, std::vector<int> &vec, std::vector<int> &result);
void Cal(std::vector<int> &result);

int N, count = 0, max = 0;
std::vector<bool> visited(8, false);

int main() {
    int num;
    std::vector<int> vec, result(8);
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        vec.push_back(num);
    }

    std::sort(vec.begin(), vec.end());
    DFS(0, vec, result);
    std::cout << max << "\n";
}

void DFS(int count, std::vector<int> &vec, std::vector<int> &result) {
    if (count == N) {
        Cal(result);
        return;
    }

    for (int index = 0; index < N; index++) {
        if (!visited.at(index)) {
            visited.at(index) = true;
            result.at(count) = vec.at(index);
            DFS(count + 1, vec, result);
            visited.at(index) = false;
        }
    }
}

void Cal(std::vector<int> &result) {
    int cal = 0;
    for (int index = 0; index < N - 1; index++)
        cal += std::abs(result.at(index + 1) - result.at(index));

    max = std::max(max, cal);
}
*/

/*
// 외판원 순회2
// 10971번 문제

#include <iostream>
#include <vector>

void DFS(int count);
void Cal();

int N, min = 10000000;
std::vector<std::vector<int>> W;
std::vector<bool> visited(10, false);
std::vector<int> input(10, 0), result(10, 0), vec;

int main() {
    int num;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> num;
            input.at(j) = num;
        }
        W.push_back(input);
        vec.push_back(i);
    }

    DFS(0);
    std::cout << min << "\n";
    return 0;
}

void DFS(int count) {
    if (count == N) {
        Cal();
        return;
    }

    for (int index = 0; index < N; index++) {
        if (!visited.at(index)) {
            visited.at(index) = true;
            result.at(count) = vec.at(index);
            DFS(count + 1);
            visited.at(index) = false;
        }
    }
}

void Cal() {
    int cal = 0;

    for (int index = 0; index < N; index++) {
        if (index == N - 1) {
            if (W[result.at(N - 1)].at(result.at(0)) == 0)
                return; // 갈 수 없는 길인 경우 종료
            cal += W[result.at(N - 1)].at(result.at(0));
        } else {
            if (W[result.at(index)].at(result.at(index + 1)) == 0)
                return; // 갈 수 없는 길인 경우 종료
            cal += W[result.at(index)].at(result.at(index + 1));
        }
    }
    min = std::min(min, cal);
}
*/

// 로또
// 6603

#include <algorithm>
#include <iostream>
#include <vector>

void print(std::vector<int> &result);
void DFS(std::vector<int> &result, int count, int cur_index);
void clear();

int k;
std::vector<int> S;

int main() {
    int num;
    std::vector<int> result(6, 0);

    while (1) {
        std::cin >> k;
        if (k == 0)
            break;

        for (int i = 0; i < k; i++) {
            std::cin >> num;
            S.push_back(num);
        }

        DFS(result, 0, 0);
        std::cout << "\n";
        clear();
    }
    return 0;
}

void print(std::vector<int> &result) {
    std::sort(result.begin(), result.end());

    for (int index = 0; index < 6; index++)
        std::cout << result.at(index) << " ";
    std::cout << "\n";
    return;
}

void DFS(std::vector<int> &result, int count, int cur_index) {
    if (count == 6) {
        print(result);
        return;
    }

    for (int index = cur_index; index < k; index++) {
        result.at(count) = S.at(index);
        DFS(result, count + 1, index + 1);
    }
}

void clear() {
    S.clear();
    S.shrink_to_fit();
}