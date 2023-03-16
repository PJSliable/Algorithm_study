#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll X, Y, ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> X >> Y;
    long long s = 0, e = 1000000000, z = 100 * Y / X, mid;
    while (s <= e){
        mid = (s + e) / 2;
        if (100 * (Y + mid) / (X + mid) > z){
            ret = mid;
            e = mid - 1;
        }else
            s = mid + 1;
    }
    cout << (ret ? ret : -1) << "\n";
    return 0;
}