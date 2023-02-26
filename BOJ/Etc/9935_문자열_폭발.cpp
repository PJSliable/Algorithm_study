#include <bits/stdc++.h>
using namespace std;
string s, b, ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> s >> b;
    for (int i = 0; i < s.size(); i++){
        ret += s[i];
        if (ret.size() >= b.size() && ret.substr(ret.size()-b.size(), b.size()) == b)
            ret.erase(ret.size() - b.size(), b.size());
    }
    if (ret.size() == 0)
        ret = "FRULA";
    cout << ret << '\n';
    return 0;
}