#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (getline(cin, s)){
    if (s == ".")
      break;
    stack<char> stk;
    int flag = 0;
    for(char c:s){
      if (c == '(' || c == '[')
        stk.push(c);
      else if(c == ')' || c == ']'){
        if (stk.size() && ((stk.top() == '(' && c == ')') || (stk.top() == '[' && c == ']')))
          stk.pop();
        else{
          flag = 1;
          break;
        }
      }
    }

    if (stk.size() || flag)
      cout << "no" << '\n';
    else
      cout << "yes" << '\n';
  }
  return 0;
}