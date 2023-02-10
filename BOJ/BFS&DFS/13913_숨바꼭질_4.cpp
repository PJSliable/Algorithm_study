#include <bits/stdc++.h>
using namespace std;
const int mv = 200001;
int N, K, m[mv], ret;
map<int, int> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    queue<int> q;
    q.push(N);
    m[N] = 1;
    while (q.size()){
        int v = q.front();
        q.pop();
        if (v == K){
            break;
        }
        for (int i : {v *2, v + 1, v -1})
        {
            if (i >= 0 && i < mv && !m[i]){
                mp[i] = v;
                m[i] = m[v] + 1;
                q.push(i);
            }
        }
    }
    cout << m[K]-1 << '\n';
    vector<int> ans;
    for (int i = K; i != N; i = mp[i]){
        ans.push_back(i);
    }
    ans.push_back(N);
    reverse(ans.begin(), ans.end());
    for(int i:ans)
        cout << i << ' ';
    cout << '\n';
    return 0;
}