#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <random>

using namespace std;
const double time_limit = 4.8 / 10.0;
// while (clock() < int(double(time_limit) * double(CLOCKS_PER_SEC)))
// {
// }

int main(int argc, char const *argv[])
{
  random_device rd;
  mt19937 eng(137);
  uniform_int_distribution<int> d500(0, 1000000000);

  long long M;
  double e;
  cin >> M >> e;
  long long N = 0;
  for (int i = 0; i < M; i++)
  {
    if (i * (i - 1) / 2 >= M)
    {
      N = i;
      break;
    }
  }
  cout << N << endl;
  long long N_L = (N - 1) * N / 2;
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < i; j++)
    {
      cout << 1;
    }
    for (int j = 0; j < N_L - i; j++)
    {
      cout << 0;
    }
    cout << endl;
  }
  for (int i = 0; i < 100; i++)
  {
    string S;
    cin >> S;
    long long ans = 0;
    for (int j = 0; j < S.size(); j++)
    {
      ans += (S.at(j) == '1');
    }
    cout << min(ans, M - 1) << endl;
    // cerr << i << endl;
  }
  return 0;
}
