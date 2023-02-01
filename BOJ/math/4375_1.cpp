#include <bits/stdc++.h>
using namespace std;
int a;
int main()
{
  while(scanf("%d", &a) != EOF){
    int now = 1;
    int lo = 0;
    while (now % a != 0)
    {
      lo++;
      now = ((now * 10) + 1) % a;
    }
    printf("%d\n", lo + 1);
  }
}