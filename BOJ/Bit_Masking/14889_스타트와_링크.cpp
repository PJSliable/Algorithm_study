#include <bits/stdc++.h>
using namespace std;
int N, a[20][20], ret = 100 * 20 +1;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void combi(int start, int num, int cnt){
    if (start >= N)
        return;
    if (cnt == N / 2)
    {
        vector<int> b;
        vector<int> c;
        for (int i = 0; i < N; i++)
        {
            if (num & (1 << i))
                b.push_back(i);
            else c.push_back(i);
        }
        int sumB = 0;
        int sumC = 0;
        while (b.size())
        {
            int poped = b.back();
            b.pop_back();
            for (int now:b){
                sumB += a[poped][now] + a[now][poped];
            }
        }
        while (c.size())
        {
            int poped = c.back();
            c.pop_back();
            for (int now:c){
                sumC += a[poped][now] + a[now][poped];
            }
        }
        ret = min(ret, abs(sumB - sumC));
        return;
    }
    combi(start+1, num | (1 << start), cnt+1);
    combi(start+1, num, cnt);
    return;
}
int main(){
    fastIO();
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    combi(0, 0, 0);
    cout << ret;
    return 0;
}