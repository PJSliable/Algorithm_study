#include <bits/stdc++.h>
using namespace std;
int N;
string s, now;
vector<string> ret;
bool cmp(string a, string b)
{
  if(a.size() == b.size())
    return a < b; // 아스키 코드 비교
  return a.size() < b.size(); // 사이즈 비교
}
void go(){
  int flag = 0;
  for (int j = 0; j < now.size(); j++)
  {
    if (now[j] != '0')
    {
      now = now.substr(j, now.size() - j);
      flag = 1;
      break;
    }
  }
  if (flag == 0)now = '0'; // 0으로만 구성된다면 0으로 변경
  ret.push_back(now);
}
int main()
{
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> s;
    now = "";
    for(char s1 : s){
      if (isdigit(s1))now += s1;
      else{
        if(now.size()){
          go();
        }
        now = "";
      }
    }
    if (now.size())go();
  }
  sort(ret.begin(), ret.end(), cmp);
  for (string i:ret)
    cout << i << '\n';
  return 0;
}