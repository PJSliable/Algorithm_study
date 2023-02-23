#include <bits/stdc++.h>
using namespace std;
const int mv = 100 * 10 + 1;
int N, p[11], nn, m[11][11], adj, ret = mv, mp = 0;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int check(int s){
    int idx = 0;
    for (idx = 0; idx < N; idx++)
    {
        if (s & (1 << idx))
            break;
    }
    queue<int> q;
    int now_ret = 0;
    int now_visited = 0;
    q.push(idx);
    now_visited |= (1 << idx);
    now_ret += p[idx];
    while (q.size())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < N; i++){
            if ((s & (1 << i)) && m[v][i] && (now_visited & (1 << i)) == 0){
                now_visited |= (1 << i);
                now_ret += p[i];
                q.push(i);
            }
        }
    }
    if (now_visited == s)
    {
        return now_ret;
    }
    else
    {
        return -1;
    }
}

int main()
{
    fastIO();
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> p[i];
        mp += p[i];
    }
    for (int i = 0; i < N; i++){
        cin >> nn;
        for (int j = 0; j < nn; j++){
            cin >> adj;
            m[i][adj-1] = 1;
        }
    }
    for (int i = 1; i < ((1 << N) /2); i++)
    {
        int sumA = check(i);
        if (sumA == -1)
            continue;
        int sumB = check((1 << N) - 1 - i);
        if (sumB == -1)
            continue;
        ret = min(ret, abs(sumA - sumB));
    }

    if (ret == mv)cout << -1;
    else cout << ret;
    return 0;
}