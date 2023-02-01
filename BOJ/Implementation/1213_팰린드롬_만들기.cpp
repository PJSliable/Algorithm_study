#include <bits/stdc++.h>
using namespace std;
string s, ret;
vector<int> a(26, 0);
vector<char> v;
int cnt;
char mid;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s;
  for (char i: s)a[i - 'A']++;

  for (int i = 25; i >= 0; i--)
  {
    if (a[i] % 2){
      cnt++;
      a[i]--;
      mid = i + 'A';
    }
    if (cnt >= 2){
      
      break;
    }
    for (int j=0; j< a[i] / 2 ; j++){
      ret = char(i + 'A') + ret + char(i + 'A');
    }
  }

  if (cnt >= 2){cout << "I'm Sorry Hansoo" << '\n';}
  else{
    if (mid){
    ret.insert(ret.begin() + ret.size() / 2, mid);
    }
    cout << ret << '\n';
  }
  return 0;
}