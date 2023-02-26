#include <bits/stdc++.h>
using namespace std;
int N, s, e, ret = 1;
vector<pair<int, int>> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end());
    int s = v[0].first;
    int e = v[0].second;
    for (int i = 1; i < N; i++)
    {
        auto now = v[i];
        if (now.first >= s && now.second < e)
        {
            s = now.first;
            e = now.second;
        }
        else if (now.first >= e){
            ret++;
            s = now.first;
            e = now.second;
        }
    }
    cout << ret << '\n';
    return 0;
}