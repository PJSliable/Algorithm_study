#include <bits/stdc++.h>
using namespace std;

int N, cnt;
string s;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> s;
    stack<char> st;
    for (char a: s){
      if (st.size() && st.top() == a)st.pop();
      else st.push(a);
    }
    if (st.size()==0)cnt++;
  }
  cout << cnt << '\n';
}