#include <bits/stdc++.h>
using namespace std;

string str;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> str;
  int len = str.size();
  for (int i = 0; i < (int)(len / 2); i++)
  {
    if (str[i] != str[len - i - 1]){
      cout << 0 << '\n';
      return 0;
    }
  }
  cout << 1 << '\n';
  return 0;
}