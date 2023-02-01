#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B, C;
ll go(ll A, ll B)
{
  if (B == 1)return A % C;
  //ll ret을 B/2의 경우로 정의하여 계산한 이후, ret끼리의 연산으로 ret을 재정의해야 연산을 절반으로 줄일 수 있음
  //만약 ll ret = (go(A, B / 2) * go(A, B / 2)) % C; 으로 한번에 ret을 정의한다면 go(A, B / 2)는 2번 계산되기에 시간 초과 발생
  ll ret = go(A, B / 2);
  ret = (ret * ret) % C;
  if (B % 2) ret = (ret * A) % C;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> A >> B >> C;
  cout << go(A, B) << '\n';
  return 0;
}