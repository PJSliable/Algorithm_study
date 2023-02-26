#include <bits/stdc++.h>
using namespace std;
int n, a[100001], x, ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> x;
    sort(a, a + n);
    int start = 0;
    int end = n - 1;
    while (start < end){
        if (a[start] + a[end] == x){
            ret++;
            start++;
            end--;
        }
        else if(a[start] + a[end] < x)
            start++;
        else if(a[start] + a[end] > x)
            end--;
    }
    cout << ret << '\n';
    return 0;
}