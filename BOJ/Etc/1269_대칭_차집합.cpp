#include <bits/stdc++.h>
using namespace std;
int A, B, temp;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> A >> B;
    set<int> s;
    for (int i = 0; i < A; i++)
    {
        cin >> temp;
        s.insert(temp);
    }
    for (int i = 0; i < B; i++){
        cin >> temp;
        s.insert(temp);
    }
    cout << 2 * s.size() - A - B << '\n';
    return 0;
}