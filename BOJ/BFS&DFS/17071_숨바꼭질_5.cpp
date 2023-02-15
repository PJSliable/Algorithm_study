#include <bits/stdc++.h>
using namespace std;
const int mv = 500001;
int N, K, m[2][mv], ret = -1, turn, v;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    fastIO();
    cin >> N >> K;
    if (N == K){
        cout << 0 << '\n';
        return 0;
    }
    queue<pair<int, int>> q;
    q.push({0, N});
    m[0][N] = 1;
    while (q.size())
    {
        tie(turn, v) = q.front();
        q.pop();
        int now = m[turn][v] - 1;
        if (K + (now+1)*now/2 >= mv)
            break;
        if (m[now%2][K + (now+1)*now/2]){
            ret = now;
            break;
        }
        for (int i : {v * 2, v + 1, v - 1})
        {
            if (i >= 0 && i < mv && m[(turn+1) % 2][i] == 0){
                m[(turn+1) % 2][i] = m[turn][v] + 1;
                q.push({(turn+1) % 2, i});
            }
        }
    }
    cout << ret << '\n';
    return 0;
}