#include <bits/stdc++.h>
using namespace std;
int T, K, num, direction, ret;
string s, temp;
vector<string> v;
void move(int num, int direction)
{
    int cnt = 1;
    int a[T], now = num - 1;
    a[now] = direction;
    while (cnt < T){
        if (now + cnt < T)a[now + cnt] = a[now + cnt - 1] * -1 * (v[now + cnt - 1][2] != v[now + cnt][6]);
        if (now - cnt >= 0)a[now - cnt] = a[now - cnt + 1] * -1 * (v[now - cnt][2] != v[now - cnt + 1][6]);
        cnt++;
    }
    for (int i = 0; i < T; i++)
    {
        if (a[i] == 1)rotate(v[i].begin(),v[i].begin() + v[i].size() - 1, v[i].end());
        else if(a[i] == -1)rotate(v[i].begin(),v[i].begin()+1, v[i].end());
    }
    return;
}

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    cin >> K;
    for (int i = 0; i < K; i++){
        cin >> num >> direction;
        move(num, direction);
    }
    for(string c:v){
        if (c[0]=='1')
            ret++;
    }
    cout << ret << '\n';
    return 0;
}