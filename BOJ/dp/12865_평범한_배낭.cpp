#include <bits/stdc++.h>
using namespace std;
int N, K, dp[100001], temp, W, V;
set<int> st;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> N >> K;
    st.insert(0);
    for (int i = 0; i < N; i++){
        cin >> W >> V;
        vector<pair<int, int>> temp;
        for (int k : st)
        {
            if (k + W <= K){
                if (dp[k+W] < dp[k] + V){
                    temp.push_back({k + W, dp[k] + V});
                }
            }
        }
        for (auto it : temp){
            dp[it.first] = it.second;
            st.insert(it.first);
        }
    }
    int ret = 0;
    for (int v = 1; v <= K; v++){
        ret = max(dp[v], ret);
    }
    cout << ret << '\n';
}