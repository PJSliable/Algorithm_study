#include <bits/stdc++.h>
using namespace std;
int T, N, n[20000], M, temp;
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> T;
    while(T--){
        cin >> N >> M;
        vector<int> v;
        for (int i = 0; i < N; i++)cin >> n[i];
        for (int i = 0; i < M; i++){
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        int ret = 0;
        for (int i = 0; i < N; i++){
            ret += lower_bound(v.begin(), v.end(), n[i]) - v.begin();
        }
        cout << ret << '\n';
    }
    return 0;
}