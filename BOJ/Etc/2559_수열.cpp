#include <bits/stdc++.h>
using namespace std;
int N, K, temp;
vector<int> v, psum;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> K;
  for (int i = 0; i < N; i++){
    cin >> temp;
    v.push_back(temp);
  }

  psum.push_back(0);
  for (int i = 0; i < v.size(); i++)
  {
  psum.push_back(psum[i] + v[i]);
  }

  int mv = -100 * K - 1;
  for (int i = 0; i < psum.size() - K; i++)
  {
  int now = psum[i + K] - psum[i];

  if (now > mv)
    mv = now;
  }
  cout << mv << '\n';
}