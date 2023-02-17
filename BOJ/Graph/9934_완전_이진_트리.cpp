#include <bits/stdc++.h>
using namespace std;
int K, a[1024];
vector<int> ret[11];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void go(int cnt, int start, int end){
    if (start > end)
        return;
    if (start == end)
    {
        ret[cnt].push_back(a[start]);
        return;
    }
    ret[cnt].push_back(a[(start + end) / 2]);
    go(cnt + 1, start, (start + end) / 2 - 1);
    go(cnt + 1, (start + end) / 2 + 1,  end);
}

int main(){
    fastIO();
    cin >> K;
    int _end = (int)pow(2, K) - 1; 
    for(int i = 0; i < _end; i++){
        cin >> a[i]; 
    }
    go(0, 0, _end);
    for(int i = 0; i < K; i++){
        for (int now :ret[i])
            cout << now << " ";
        cout << '\n';
    }
    return 0;
}