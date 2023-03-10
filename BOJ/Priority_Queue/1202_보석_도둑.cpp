#include <bits/stdc++.h>
using namespace std;
int N, K, M, V, C;
long long sum;
priority_queue<int> pq;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> N >> K;
    vector<pair<int, int>> v(N);
    vector<int> bag(K);
    for (int i = 0; i < N; i++)cin >> v[i].first >> v[i].second;
    for (int i = 0; i < K; i++)cin >> bag[i];
    sort(bag.begin(), bag.end());
    sort(v.begin(), v.end());
    int j = 0;
    for (int i = 0; i < K; i++)
    {
        while (j < N && bag[i] >= v[j].first)pq.push(v[j++].second);
        if (pq.size()){
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << '\n';
    return 0;
}