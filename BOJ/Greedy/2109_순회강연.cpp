#include <bits/stdc++.h>
using namespace std;
int n, p, d, dl[10000], sum;
vector<pair<int, int>> v;
bool cmp(pair<int, int> i, pair<int, int> j){
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
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> p >> d;
        v.push_back({p, d-1});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        auto now = v[i];
        int date = now.second;
        while (date >= 0 && dl[date] == 1)date--;
        if (date >= 0){
            dl[date] = 1;
            sum += now.first;
        }
    }
    cout << sum << '\n';
    return 0;
}