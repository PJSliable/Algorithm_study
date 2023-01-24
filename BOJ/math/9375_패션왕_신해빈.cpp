#include <bits/stdc++.h>
using namespace std;

int T, n;
string name, k;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++){
    cin >> n;
    map<string, int> mp;
    for (int j = 0; j < n;j++){
      cin >> name >> k;
      mp[k] += 1;
    }
    int ans = 1;
    for (auto it: mp)
      ans *= it.second + 1;
    cout << ans - 1 << '\n';
  }
  return 0;
}