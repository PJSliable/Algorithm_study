#include <bits/stdc++.h>
using namespace std;
long long N, a[100001], cnt[100001], ret, s, e;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> N;
    for (int i = 0; i < N; i++)cin >> a[i];
    while (e < N){
        if(!cnt[a[e]]){
            cnt[a[e]]++;
            e++;
        }
        else
        {
            ret += e - s;
            cnt[a[s]]--;
            s++;
        }
    }
    ret += (e - s) * (e - s + 1) / 2;
    cout << ret << '\n';
    return 0;
}