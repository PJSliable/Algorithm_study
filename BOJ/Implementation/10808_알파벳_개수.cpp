#include <bits/stdc++.h>
using namespace std;
int a[26];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string b;
    cin >> b;
    for (char c: b)
        a[c - 'a']++;

    for (int i: a){
        cout << i << " ";
    }
    return 0;
}