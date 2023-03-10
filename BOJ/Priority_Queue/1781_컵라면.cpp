#include <bits/stdc++.h>
using namespace std;
int N, d, c, deadline, sum;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
bool cmp(pair<int, int> i, pair<int, int> j)
{
    if (i.first == j.first)
        return i.second > j.second;
    return i.first > j.first;
}
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> d >> c;
        v.push_back({d, c});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++){
        pq.push(v[i].second);
        if (pq.size() > v[i].first)
            pq.pop();
    }
    while(pq.size()){
        sum += pq.top();
        pq.pop();
    }
    cout << sum << '\n';
    return 0;
}