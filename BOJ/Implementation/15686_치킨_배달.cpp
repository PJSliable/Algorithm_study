#include <bits/stdc++.h>
using namespace std;

int M, N, m[51][51];
int mx = 100 * 13 * 50 * 50;
vector<pair<int, int>> h;
vector<pair<int, int>> ch;

void combi(int start, vector<pair<int,int >> b){
    if (b.size() == M){
        int ret = 0;
        for (auto nh : h)
        {
            int nowmx = 100 * 13 * 50 * 50;
            for(auto nc: b){
                int now_value = abs(nh.first - nc.first) + abs(nh.second - nc.second);
                nowmx = min(nowmx, now_value);
            }
            ret += nowmx;
        }
        mx = min(mx, ret);
        return;
    }
    for (int i = start + 1; i < ch.size(); i++){
        b.push_back(ch[i]);
        combi(i, b);
        b.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> m[i][j];
            if (m[i][j]== 2)
                ch.push_back({i, j});
            else if (m[i][j] == 1)
                h.push_back({i, j});
        }
    }
    vector<pair<int, int>> b;
    combi(-1, b);
    cout << mx << '\n';
}