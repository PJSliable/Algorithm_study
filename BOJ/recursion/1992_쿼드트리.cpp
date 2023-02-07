#include <bits/stdc++.h>
using namespace std;
int N;
string s;
char a[65][65];
string quad(int x, int y, int N)
{
  char b = a[x][y];
  string ret = "";
  for (int i = x; i < x + N; i++)
  {
    for (int j = y; j < y + N; j++){
      if (b != a[i][j]){
        ret += '(';
        ret += quad(x, y, N / 2);
        ret += quad(x, y+N/2, N / 2);
        ret += quad(x+N/2, y, N / 2);
        ret += quad(x+N/2, y+N/2, N / 2);
        ret += ')';
        return ret;
      }
    }
  }
  return string(1, a[x][y]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> s;
    for (int j = 0; j < N; j++){
      a[i][j] = s[j];
    }
  }
  cout << quad(0, 0, N) << '\n';
  return 0;
}