#include <bits/stdc++.h>
using namespace std;

string s;
int H, W, x, y;
vector<pair<int, int>> c;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> H >> W;
  int ret[H][W];
  for (int i = 0; i < H; i++){
    cin >> s;
    for (int j = 0; j < W; j++){
      if (s[j] == 'c'){
        c.push_back({i,j});
        ret[i][j] = 0;
      }else ret[i][j] = -1;
    }
  }
  int cnt = 1;
  for (int i = 0; i < W; i++){
    for (auto now: c){
      tie(x,y) = now;
      y += cnt;
      if (y < W && ret[x][y] == -1){
        ret[x][y] = cnt;
      }
    }
    cnt++;
  }
  for(int i = 0; i < H; i++){
    for (int j: ret[i]) cout << j << ' ';
    cout << '\n';
  }
}