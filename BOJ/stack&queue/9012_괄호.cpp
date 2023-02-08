#include <bits/stdc++.h>
using namespace std;

int T;
string s;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++){
    stack<char> stk;
    cin >> s;
    int flag = 0;
    for (char c:s)
    {
      if (c == '(') stk.push(c);
      else{
        if (stk.size())stk.pop();
        else{
          flag = 1;
          break;
        }
      }
    }
    if (stk.size() || flag)
      cout << "NO" << '\n';
    else cout << "YES" << '\n';
  }
  return 0;
}