#include <bits/stdc++.h>
using namespace std;
int X, cnt;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> X;
    
    while(X){
        if(X & 1)cnt++;
        X /= 2;
    }
    cout << cnt << '\n';
    return 0;
}