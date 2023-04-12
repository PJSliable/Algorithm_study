#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, H, mp[123456][3], ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(ll mid){
    ll init_atk = H;
    ll hp = mid;
    for (int i = 0; i < N; i++)
    {
        if (mp[i][0] == 1){
            ll m_atk = mp[i][1];
            ll m_hp = mp[i][2];

            int cnt = m_hp / init_atk - 1 + (m_hp % init_atk ? 1 : 0);
            if (hp <= m_atk * cnt)
                return false;
            hp -= m_atk * cnt;
        }
        else
        {
            init_atk += mp[i][1];
            hp = min(mid, hp + mp[i][2]);
        }
    }
    return true;
}

int main(){
    fastIO();
    cin >> N >> H;
    for (int i = 0; i < N; i++){
        cin >> mp[i][0] >> mp[i][1] >> mp[i][2];
    }
    ll s = 1, e = 1e18 + 4, mid;
    while(s <= e){
        mid = (s + e) / 2;
        if (check(mid)){
            ret = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }
    cout << ret << '\n';
    return 0;
}