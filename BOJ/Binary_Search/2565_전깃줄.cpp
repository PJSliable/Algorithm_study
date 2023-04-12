#include <bits/stdc++.h>
using namespace std;
int N, f, s, lis[100], len;
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
        cin >> f >> s;
        v.push_back({f, s});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++){
        auto it = lower_bound(lis, lis + len, v[i].second);
        if (*it == 0)
            len++;
        *it = v[i].second;
    }
    cout << N - len << '\n';
    return 0;
}