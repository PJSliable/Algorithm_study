#include <bits/stdc++.h>
using namespace std;

int a[9];
vector<int> v;
int sum;

void print(vector<int> v)
{
  for(int i: v)
    cout << i << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for (int i = 0; i < 9; i++){
    cin >> a[i];
    sum += a[i];
  }

  int total = sum - 100;

  for (int i = 0; i < 9;i++){
    for (int j = i + 1; j < 9;j++){
      if (a[i] + a[j] == total){
        for (int k = 0; k < 9;k++){
          if(k==i||k==j)
            continue;
          v.push_back(a[k]);
        }
        sort(v.begin(), v.end());
        print(v);
        return 0;
      }
    }
  }
}