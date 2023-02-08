#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll N;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++){
    cin >> N;
    int n5 = 0;
    while (N >= 5)
    {
      n5 += N / 5;
      N /= 5;
    }
    cout << n5 << '\n';
  }
}