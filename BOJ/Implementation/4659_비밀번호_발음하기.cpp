#include <bits/stdc++.h>
using namespace std;
string s;
bool isVowel(char s1){
  return (s1 == 'a' || s1 == 'e' || s1 == 'i' || s1 == 'o' || s1 == 'u');
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while(cin >> s){
    if (s == "end")
      break;
    int m = 0;
    int j = 0;
    int id = 0;
    int m_i = 0;
    char be = '0';
    for (char s1 : s)
    {
      if (isVowel(s1))m++,m_i = 1,j = 0;
      else j++, m = 0;
      if ((m>=3||j>=3) || ((s1 == be) && (!(s1 == 'e' || s1 == 'o')))){
        id = 1;
        break;
      }
      be = s1;
    }
    cout << '<' << s << '>';
    if (id || m_i == 0){
      cout << " is not acceptable." << '\n';
    } else{
    cout << " is acceptable." << '\n';
    }
  }
}