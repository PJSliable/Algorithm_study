#include <bits/stdc++.h>
using namespace std;
int T, N, M, A, B, visited[1001];
vector<int> adj[1001];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void dfs(int here){
    visited[here] = 1;
    for (int there : adj[here])if (!visited[there])dfs(there);
}
int main()
{
    fastIO();
    cin >> T;
    for (int i = 0; i < T; i++){
        for (int c = 0; c < 1001; c++)
            adj[c].clear();
        memset(visited, 0, sizeof(visited));
        cin >> N;
        cin >> M;
        for (int j = 0; j < M; j++)
        {
            cin >> A >> B;
            adj[A].push_back(B);
            adj[B].push_back(A);
        }
        dfs(1);
        int flag = 0;
        for (int k = 1; k <= N; k++)
        {
            if (visited[k] == 0){
                flag = 1;
                break;
            }
        }
        if (!flag && M == N-1)cout << "tree" << '\n';
        else cout << "graph" << '\n';
    }
    return 0;
}