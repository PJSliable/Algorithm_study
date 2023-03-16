#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, a[100000];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool check(int cut){
    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < N; i++){
        if (sum + a[i] <= cut){
            sum += a[i];
        }
        else{
            if (a[i] > cut)
                return false;
            cnt++;
            sum = a[i];
        }
    }
    return cnt <= M;
}
int main(){
    fastIO();
    cin >> N >> M;
    ll s = 0, e = 1000000000, mid;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    ll ret = 1000000000;
    while (s <= e){
        mid = (s + e) / 2;
        if (check(mid)){
            ret = mid;
            e = mid - 1;
        }else
            s = mid + 1;
    }
    cout << ret << '\n';
    return 0;
}