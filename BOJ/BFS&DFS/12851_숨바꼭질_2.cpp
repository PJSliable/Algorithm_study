#include <bits/stdc++.h>
using namespace std;
const int mv = 200001;
int N, K, m[mv], cnt[mv], ret = 200001;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main()
{
    fastIO();
    cin >> N >> K;
    queue<int> q;
    q.push(N);
    m[N] = 1;
    cnt[N] = 1;
    while (q.size())
    {
        int v = q.front();
        q.pop();
        for (int i : {v * 2, v + 1, v - 1})
        {
            if (i >= 0 && i < mv){
                if(!m[i]){
                    m[i] = m[v] + 1;
                    cnt[i] += cnt[v];
                    q.push(i);
                } else if(m[i] == m[v]+1){
                    cnt[i] += cnt[v];
                }
            }
        }
    }
    cout << m[K]-1 << '\n';
    cout << cnt[K] << '\n';
    return 0;
}