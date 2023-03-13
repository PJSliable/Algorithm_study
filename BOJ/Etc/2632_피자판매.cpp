#include <bits/stdc++.h>
using namespace std;
int T, n, m, a[2000], b[2000], sumA[2000], sumB[2000], ret;
map<int, int> mpA, mpB;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    fastIO();
    cin >> T;
    cin >> m >> n;
    for (int i = 0; i < m; i++)cin >> a[i];
    for (int i = m; i < 2*m; i++)a[i] = a[i - m];
    sumA[0] = 0;
    for (int i = 1; i < 2 * m; i++)sumA[i] = sumA[i-1] + a[i-1];
    for (int i = 0; i < n; i++)cin >> b[i];
    for (int i = n; i < 2*n; i++)b[i] = b[i - n];
    sumB[0] = 0;
    for (int i = 1; i < 2 * n; i++)sumB[i] = sumB[i-1] + b[i-1];
    for (int i = 0; i < m; i++)for (int interval = 1; interval < m; interval++)mpA[sumA[interval + i] - sumA[i]]++;
    for (int i = 0; i < n; i++)for (int interval = 1; interval < n; interval++)mpB[sumB[interval + i] - sumB[i]]++;
    mpA[sumA[m] - sumA[0]]++;
    mpB[sumB[n] - sumB[0]]++;
    mpA[0] = 1;
    mpB[0] = 1;
    for (int i = 0; i <= T; i++)ret += mpA[i] * mpB[T - i];
    cout << ret << '\n';
    return 0;
}