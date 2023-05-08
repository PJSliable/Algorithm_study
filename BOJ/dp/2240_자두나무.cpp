#include <bits/stdc++.h>
using namespace std;
int T, W, a[1000], dp[1000][2][31], ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int go(int idx, int tree, int cnt){
    if (cnt < 0) return -1e9;
    if (idx == T)
        return cnt == 0 ? 0 : -1e9;
    int &ret = dp[idx][tree][cnt];
    if (~ret)
        return ret;
    return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == a[idx] - 1);
}

int main(){
    fastIO();
    memset(dp, -1, sizeof(dp));
    cin >> T >> W;
    for (int i = 0; i < T; i++){
        cin >> a[i];
    }
    cout << max(go(0, 0, W), go(0, 1, W - 1)) << '\n';
}