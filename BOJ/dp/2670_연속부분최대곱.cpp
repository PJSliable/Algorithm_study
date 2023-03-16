#include <bits/stdc++.h>
using namespace std;
int N;
double a[10001], b, ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    b = ret = a[0];
    for (int i = 1; i < N; i++){
        b = max(a[i], b * a[i]);
        ret = max(b, ret);
    }
    cout << fixed, cout.precision(3);
    cout << (double)round(ret * 1000)/1000 << '\n';
    return 0;
}