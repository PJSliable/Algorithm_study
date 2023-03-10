#include <bits/stdc++.h>
using namespace std;
int N, ret, sum;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> N;

    int b[N + 1];
    fill(b, b + (N + 1), 1);
    for (int i = 2; i <= N/2; i++)
    {
        if (b[i] == 1){
            for (int j = 2*i; j < N + 1; j += i)b[j] = 0;
        }
    }
    vector<int> p;
    for (int i = 2; i < N + 1; i++){
        if (b[i] == 1)
            p.push_back(i);
    }
    int s = 0;
    int e = 0;
    while (s <= e){
        if (sum <= N)
        {
            if (sum == N)
                ret++;
            if (e >= p.size())
                break;
            sum += p[e++];
        }else {
            sum -= p[s++];
        }
    }
    cout << ret << '\n';
    return 0;
}