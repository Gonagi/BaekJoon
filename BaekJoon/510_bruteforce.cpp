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

/*
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
*/

/*
// 11651번 문제

#include <iostream>
#include <vector>

int M, N;
std::vector<int> vec(8,0);
void print(int check);

int main(){
    std::cin >> N >> M;

    print(0);
    return 0;
}

void print(int check){
    if(check == M){
        for(int index = 1; index <= M; index++)
            std::cout << vec.at(index)<< " ";
        std::cout << "\n";

        return;
    }

    for(int num = 1; num <= N; num++){
        vec.at(check+1) = num;
        print(check+1);
    }
}
*/

/*
// 11652번 문제

#include <iostream>
#include <vector>

int N, M;
std::vector<int> vec(9,0);

void print(int check, int cur_num);

int main(){
    std::cin >> N >> M;

    print(0, 1);
    return 0;
}

void print(int check, int cur_num){
    if(check == M){
        for(int index = 1; index <= M; index++)
            std::cout << vec.at(index) << " ";
        std::cout <<"\n";

        return;
    }

    for(int num = cur_num; num <= N; num++){
        vec.at(check+1) = num;
        print(check+1, num);
    }
}
*/

/*
// 15654번 문제

#include <algorithm>
#include <iostream>
#include <vector>

int N, M, num;
std::vector<int> input, vec(8, 0);
std::vector<bool> visited(8, false);

void DFS(int count);

int main()
{
    std::cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        std::cin >> num;
        input.push_back(num);
    }

    std::sort(input.begin(), input.end());
    DFS(0);

    return 0;
}

void DFS(int count)
{
    if (count == M)
    {
        for (int index = 0; index < M; index++)
            std::cout << vec.at(index) << " ";
        std::cout << "\n";
    }

    for (int num = 0; num < N; num++)
    {
        if (!visited.at(num))
        {
            vec.at(count) = input.at(num);
            visited.at(num) = true;
            DFS(count + 1);
            visited.at(num) = false;
        }
    }
}
*/

// 15655번 문제

#include <algorithm>
#include <iostream>
#include <vector>

int N, M;
std::vector<int> input, vec(8);
std::vector<bool> visited(8, false);

void DFS(int count, int cur_num);

int main() {
  int num;
  std::cin >> N >> M;

  for (int i = 0; i < N; i++) {
    std::cin >> num;
    input.push_back(num);
  }

  std::sort(input.begin(), input.end());
  DFS(0, 0);

  return 0;
}

void DFS(int count, int cur_num) {
  if (count == M) {
    for (int index = 0; index < M; index++)
      std::cout << vec.at(index) << " ";
    std::cout << "\n";
  }

  for (int num = cur_num; num < N; num++) {
    if (!visited.at(num)) {
      vec.at(count) = input.at(num);
      visited.at(num) = true;
      DFS(count + 1, num+1);
      //visited.at(num) = false;
    }
  }
}