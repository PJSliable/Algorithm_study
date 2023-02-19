#include <bits/stdc++.h>
using namespace std;
int sum;
string A, B, ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> A >> B;
    while (A.size() || B.size() || sum != 0){
        if (A.size()){
            sum += A.back() - '0';
            A.pop_back();
        }
        if (B.size()){
            sum += B.back() - '0';
            B.pop_back();
        }
        ret += sum % 10 + '0';
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    cout << ret;
    return 0;
}