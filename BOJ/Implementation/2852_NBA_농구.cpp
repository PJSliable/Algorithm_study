#include <bits/stdc++.h>
using namespace std;
int N, team, s1, s2, t1, t2;
string t, before;
string p(int t){
  string m = "00" + to_string(t / 60);
  string s = "00" + to_string(t % 60);
  return m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2);
}
int ttos(string t){
  return 60 * stoi(t.substr(0,2)) + stoi(t.substr(3,2));
}
void update(string s){
  if (s1 > s2) t1 += ttos(s) - ttos(before);
  if (s2 > s1) t2 += ttos(s) - ttos(before);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> team;
    cin >> t;
    update(t);
    if (team == 1)
      s1++;
    else
      s2++;
    before = t;
  }
  update("48:00");
  cout << p(t1) << '\n';
  cout << p(t2) << '\n';
  return 0;
}