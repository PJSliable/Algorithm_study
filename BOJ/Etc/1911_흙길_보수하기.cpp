#include <bits/stdc++.h>
using namespace std;
int N, L, s, e, ret;
vector<pair<int, int>> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> N >> L;
    for (int i = 0; i < N; i++){
        cin >> s >> e;
        v.push_back({s, e});
    }
    int start = 0;
    sort(v.begin(), v.end());
    for (auto now : v){
        if (start <= now.first)start = now.first;
        int cnt = 0;
        while (start + cnt * L < now.second){
            cnt++;
        }
        ret += cnt;
        start = start + cnt * L;
    }
    cout << ret;
    return 0;
}