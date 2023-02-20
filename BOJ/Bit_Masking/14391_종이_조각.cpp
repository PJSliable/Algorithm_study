#include <bits/stdc++.h>
using namespace std;
int N, M, a[4][4], ret;
char c;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main()
{
    fastIO();
    cin >> N >> M;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < M; j++){
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    for (int li = 0; li < (1 << (N * M)); li++){
        int now_sum = 0;
        for (int i = 0; i < N; i++){
            int now_value = 0;
            for (int j = 0; j < M; j++)
            {
                int k = i * M + j;
                if ((li & (1 << k)) == 0)now_value = now_value * 10 + a[i][j];
                else{
                    now_sum += now_value;
                    now_value = 0;
                }
            }
            now_sum += now_value;
        }
        for (int i = 0; i < M; i++){
            int now_value = 0;
            for (int j = 0; j < N; j++)
            {
                int k = j * M + i;
                if ((li & (1 << k)) != 0)now_value = now_value * 10 + a[j][i];
                else{
                    now_sum += now_value;
                    now_value = 0;
                }
            }
            now_sum += now_value;
        }
        ret = max(ret, now_sum);
    }
    cout << ret;
    return 0;
}