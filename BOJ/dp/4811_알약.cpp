#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, dp[31][31];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll go(int whole, int half){
    if (whole == 0 && half == 0)
        return 1;
    if (dp[whole][half])
        return dp[whole][half];
    ll &ret = dp[whole][half];
    if (whole > 0)
        ret += go(whole - 1, half + 1);
    if (half > 0)
        ret += go(whole, half - 1);
    return ret;
}
int main(){
    fastIO();
    while(true){
        cin >> n;
        if (n == 0)
            break;
        cout << go(n, 0) << '\n';
    }
}