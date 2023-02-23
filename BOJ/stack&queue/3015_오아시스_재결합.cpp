#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, A, ret;
stack<pair<ll, ll>> stk;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A;
        int cnt = 1;
        while (stk.size() && stk.top().first <= A)
        {
            ret+= stk.top().second;
            if (stk.top().first == A)
                cnt = stk.top().second + 1;
            else cnt = 1;
            stk.pop();
        }
        if(stk.size())
            ret++;
        stk.push({A, cnt});
    }
    cout << ret << '\n';
    return 0;
}