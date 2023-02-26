#include <bits/stdc++.h>
using namespace std;
int N, x, y, ret, s= -1000000001, e= -1000000001;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        if (e <= v[i].first){
            ret += e - s;
            s = v[i].first;
            e = v[i].second;
        }
        else if (s <= v[i].first && v[i].first < e){
            e = max(v[i].second, e);
        }
    }
    ret += e - s;
    cout << ret << '\n';
    return 0;
}