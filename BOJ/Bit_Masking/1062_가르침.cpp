#include <bits/stdc++.h>
using namespace std;
int N, K, ret, total_num;
string s;
vector<int> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int cnt, int idx, int num){
    if (cnt > K)
        return;
    if (idx == 26)
    {
        int now_count = 0;
        for (int word:v)
        {
            if ((num | word) == num)
                now_count++;
        }
        ret = max(ret, now_count);
        return;
    }
    dfs(cnt + 1, idx + 1, num | (1 << idx));
    if (idx != 'a'-'a' && idx != 'n'-'a' && idx != 't'-'a' && idx != 'i'-'a' && idx != 'c'-'a'){
        dfs(cnt, idx + 1, num);
    }
    return;
}

int main(){
    fastIO();
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        cin >> s;
        int nv = 0;
        for (char c:s)
        {
            nv |= 1 << (c - 'a');
        }
        v.push_back(nv);
    }
    dfs(0, 0, 0);
    cout << ret;
    return 0;
}