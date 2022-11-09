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

void solve() {
}
