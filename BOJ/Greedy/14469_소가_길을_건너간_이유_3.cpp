#include <bits/stdc++.h>
using namespace std;
int N, s, c, start;
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
    for (int i = 0; i < N; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++){
        if(start <= v[i].first)
            start = v[i].first + v[i].second;
        else if(start > v[i].first)
            start += v[i].second;
    }
    cout << start << '\n';
    return 0;
}