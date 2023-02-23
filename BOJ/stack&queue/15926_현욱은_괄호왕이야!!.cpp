#include <bits/stdc++.h>
using namespace std;
int n, m[200001], ret, cnt;
string s;
stack<int> stk;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')stk.push(i);
        else {
            if (stk.size()){
                m[stk.top()] = 1;
                stk.pop();
                m[i] = 1;
            }
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (m[i] == 1){
            cnt++;
            ret = max(cnt, ret);
        }else cnt = 0;
    }
    cout << ret << '\n';
    return 0;
}