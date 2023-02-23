#include <bits/stdc++.h>
using namespace std;
int N, ret = 20 * 20 + 1, a[20];
string s;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int idx){
    if (idx == N){
        int total = 0;
        for (int j = 0; j < N; j++)
        {
            int now_cnt = 0;
            for (int i = 0; i < N; i++){
                if (a[i] & (1<<j))
                    now_cnt++;
            }
            total += min(now_cnt, N - now_cnt);
        }
        ret = min(ret, total);
        return;
    }
    dfs(idx + 1);
    a[idx] = (1 << N) - 1 - a[idx];
    dfs(idx + 1);
}

int main()
{
    fastIO();
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> s;
        int v = 0;
        for (int j = 0; j < s.size() - 1; j++)
        {
            if (s[j] == 'T')v |= 1;
            v *= 2;
        }
        if (s[s.size()-1] == 'T')v |= 1;
        a[i] = v;
    }
    dfs(0);
    cout << ret << '\n';
    return 0;
}