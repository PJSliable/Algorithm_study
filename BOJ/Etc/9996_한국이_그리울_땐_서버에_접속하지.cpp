#include <bits/stdc++.h>
using namespace std;
int N;
string s, now;
vector<string> ans;
vector<string> split(string input, string delimiter)
{
  vector<string> ret;
  long long pos = 0;
  string token = "";
  while ((pos = input.find(delimiter)) != string::npos) { token = input.substr(0, pos); ret.push_back(token);
  input.erase(0, pos + delimiter.length());
  } 
  ret.push_back(input); 
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  cin >> s;
  vector<string> a = split(s,"*");
  int l1 = a[0].size();
  int l2 = a[1].size();
  for (int i = 0; i < N; i++)
  {
  cin >> now;
  if (now.size() >= s.size()-1 && now.substr(0, l1) == a[0] && now.substr(now.size() - l2, l2) == a[1])
    ans.push_back("DA");
  else
    ans.push_back("NE");
  }
  for (string i:ans)
  cout << i << '\n';
  return 0;
}