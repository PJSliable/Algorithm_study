#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll S, C, a[1000000], ret, sum;
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(ll cut){
    ll cnt = 0;
    for (int i = 0; i < S; i++){
        cnt += a[i] / cut;
    }
    return cnt >= C;
}

int main(){
    fastIO();
    cin >> S >> C;
    ll s = 1, e = 0, mid;
    for (int i = 0; i < S; i++){
        cin >> a[i];
        e = max(e, a[i]);
        sum += a[i];
    }
    while (s <= e){
        mid = (s + e) / 2;
        if (check(mid)){
            ret = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    cout << sum - ret * C << '\n';
    return 0;
}