#include <bits/stdc++.h>
using namespace std;
int N, a[1001], dp[1001], ret;
vector<vector<int>> v;
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
        cin >> a[i];
        vector<int> v1 = {a[i]};
        v.push_back(v1);
    }
    fill(dp, dp + N, 1);
    for (int i = 1; i < N; i++){
        for (int j = 0; j < i; j++){
            if (a[j] < a[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                vector<int> temp = v[j];
                temp.push_back(a[i]);
                v[i] = temp;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        if(ret < dp[i]){
            ret = dp[i];
            ans = v[i];
        }
    }

    cout << ret << '\n';
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    return 0;
}