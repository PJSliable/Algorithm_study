#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, a[300000], ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(ll cut){
    ll cnt = 0;
    for (int i = 0; i < M; i++){
        cnt += a[i] / cut;
        if (a[i] % cut)
            cnt++;
    }
    return cnt <= N;
}

int main(){
    fastIO();
    cin >> N >> M;
    ll s = 1, e = 0, mid;
    for (int i = 0; i < M; i++){
        cin >> a[i];
        e = max(e, a[i]);
    }
    while (s <= e){
        mid = (s + e) / 2;
        if (check(mid)){
            ret = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    cout << ret << '\n';
    return 0;
}