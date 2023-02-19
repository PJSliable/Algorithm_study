#include <bits/stdc++.h>
using namespace std;
int m, idx, n;
char s[11];
int main()
{
    scanf(" %d", &m);
    for (int i = 0; i < m;i++){
        scanf(" %s %d", s, &idx);
        if (s[0] == 'a' && s[1] == 'd')n |= 1 << idx;
        else if (s[0] == 'r')n &= ~(1 << idx);
        else if (s[0] == 'c')printf("%d\n", (n & (1<< idx))== 0 ? 0:1);
        else if (s[0] == 't')n ^= (1 << idx);
        else if (s[0] == 'a')n = (1 << 21) - 1;
        else if (s[0] == 'e')n = 0;
    }
}