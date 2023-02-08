#include <bits/stdc++.h>
using namespace std;

int N, C, a;
vector<int> v;
map<int, int> mp;
map<int, int> mpf;
bool cmp(int a, int b){
  if (mp[a] == mp[b])
    return mpf[a] < mpf[b]; // 순서는 오름차순으로 나열해야 함. < : 오름차순, > : 내림차순
  return mp[a] > mp[b]; // 빈도수는 내림차순으로 나열해야 함. 
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> C;
  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    mp[a]++;
    if (mpf.find(a) == mpf.end()){
      mpf[a] = cnt;
      cnt++;
    }
    v.push_back(a);
  }
  sort(v.begin(), v.end(), cmp);
  for (int i: v)
    cout << i << ' ';
  return 0;
}