#include <bits/stdc++.h>
using namespace std;
int N, lis[1000001], num, len;
const int INF = 1e9 + 4;
pair<int, int> ans[1000001];
stack<int> stk;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    fastIO();
    cin >> N;
    fill(lis, lis + 1000001, INF);
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
        if(*lowerPos == INF)
            len++;
        *lowerPos = num;
        ans[i].first = _pos;
        ans[i].second = num;
    }
    cout << len << '\n';
    for (int i = N - 1; i >= 0; i--){
        if(ans[i].first == len -1){
            stk.push(ans[i].second);
            len--;
        }
    }
    while(stk.size()){
        cout << stk.top() << ' ';
        stk.pop();
    }
    return 0;
}