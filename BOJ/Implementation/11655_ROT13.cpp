#include <bits/stdc++.h>
using namespace std;

string str;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getline(cin, str);
  int l = str.size();
  for (int i = 0; i < l;i++){
    if ('a' <= str[i] && str[i] <= 'z'){
      str[i] = str[i] + 13;
      if (!('a' <= str[i] && str[i] <= 'z')) str[i] -= 26;
    } else if ('A'<=str[i] && str[i] <='Z'){
      str[i] = str[i] + 13;
      if (!('A' <= str[i] && str[i] <= 'Z')) str[i] -= 26;
    }
    cout << str[i];
  }
  return 0;
}