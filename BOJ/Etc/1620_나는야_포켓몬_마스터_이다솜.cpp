#include <bits/stdc++.h>
using namespace std;
int M, N;
map<string, int> mp;
map<int, string> mp2;
string q;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;
  string l[N];
  for (int i = 1; i < N+1; i++)
  {
    cin >> q;
    mp.insert({q, i});
    mp2.insert({i, q});
  }

  for (int i = 0; i < M; i++)
  {
    cin >> q;
    int j = atoi(q.c_str());
    if (j){
      cout << mp2[j] << '\n';
    }
    else
      cout << mp[q] << '\n';
  }
  return 0;
}