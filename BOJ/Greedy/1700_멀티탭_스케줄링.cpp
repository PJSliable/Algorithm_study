#include <bits/stdc++.h>
using namespace std;
int N, K, ret, a[100], visited[101], cnt;
vector<int> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> N >> K;
    for (int i = 0; i < K; i++){
        cin >> a[i];
    }
    for (int i = 0; i < K; i++){
        if (visited[a[i]] == 0){
            if (v.size() == N){
                int last_idx = 0, value;
                for(int p: v){
                    int now_idx = 101;
                    for (int j = i + 1; j < K; j++)
                    {
                        if (p == a[j]){
                            now_idx = j;
                            break;
                        }
                    }
                    if (last_idx < now_idx){
                        last_idx = now_idx;
                        value = p;
                    }
                }
                visited[value] = 0;
                visited[a[i]] = 1;
                cnt++;
                v.erase(find(v.begin(), v.end(), value));
            }
            visited[a[i]] = 1;
            v.push_back(a[i]);
        }
    }
    cout << cnt << '\n';
    return 0;
}