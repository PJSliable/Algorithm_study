#include <bits/stdc++.h>
#define max_n 60000000004;
using namespace std;
typedef long long ll;
ll N, M, a[10004], mid, ret, temp, s, e = max_n;

bool check(ll mid){
    temp = M;
    for(ll i = 0; i < M; i++)temp += mid / a[i];
    return temp >= N; 
}

int main(){
    cin >> N >> M;
    for (ll i = 0; i < M; i++){
        cin >> a[i];
    }
    if (N <= M){  
        cout << N;
        return 0;
    }

    while(s <= e){
        mid = (s + e) / 2;
        if(check(mid)){
            ret = mid;
            e = mid - 1;
        }else
            s = mid + 1;
    }
    temp = M;
    for(ll i = 0; i < M; i++)temp += (ret-1) / a[i];

    for (ll i = 0; i < M; i++){
        if(ret % a[i] == 0)temp++; 
        if(temp == N){
            cout << i + 1 << '\n';
            return 0; 
        }
    }
    return 0;
}