#include <bits/stdc++.h>
using namespace std;
int N, M, a[100000], ret;
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(int temp){
    int cnt = 1;
    int sum = temp;
    for (int i = 0; i < N; i++){
        if (sum < a[i]){
            if(temp < a[i])
                return false;
            cnt++;
            sum = temp - a[i];
        }
        else{
            sum -= a[i];
        }
    }
    return cnt <= M;
}

int main(){
    fastIO();
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    int s = 1, e = 100000 * 10000, mid;
    while (s <= e){
        mid = (s + e) / 2;
        if (check(mid)){
            ret = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    cout << ret << '\n';
    return 0;
}