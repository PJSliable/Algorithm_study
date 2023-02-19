#include <bits/stdc++.h>
using namespace std;
const int max_value = 500 * 15 + 1;
int N, m[4], p, f, s, v, c, a[15][5], ret = max_value;
vector<vector<int>> ans;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void check(int s){
    vector<int> v;
    int temp[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < N; i++)
    {
        if(s & (1 << i)){
            for (int j = 0; j < 5; j++)
                temp[j] += a[i][j];
            v.push_back(i + 1);
        }
    }
    for (int i = 0; i < 4; i++){
        if (m[i] > temp[i])
            return;
    }
    if(ret > temp[4]){
        ans.clear();
        ans.push_back(v);
        ret = temp[4];
    }else if(ret == temp[4])
        ans.push_back(v);
    return;
}

int main()
{
    fastIO();
    cin >> N;
    for (int i = 0; i < 4; i++)
        cin >> m[i];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 5; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < (1 << N); i++)check(i);
    if (ret == max_value){
        cout << -1;
        return 0;
    }
    cout << ret << '\n';
    sort(ans.begin(), ans.end());
    for (int a : ans[0])cout << a << ' ';
    return 0;
}