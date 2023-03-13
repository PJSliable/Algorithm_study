#include <bits/stdc++.h>
using namespace std;
int a[10], v[51], lo[4];
vector<int> adj[51];

void add(int here, int there){
    adj[here].push_back(there);
}
void setMap(){
    for (int i = 0; i < 20; i++)add(i, i + 1); add(20, 50);
    for (int i = 21; i < 26; i++)add(i, i + 1); 
    add(26, 20); add(27, 28); add(28, 24); add(29, 30); add(30, 31); add(31, 24); 
    add(5, 21); add(15, 29); add(10, 27);

    v[1] = 2; v[2] = 4;  v[3] = 6; v[4] = 8; v[5] = 10; 
	v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20; 
	v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30; 
	v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40; 
	v[21] = 13; v[22] = 16; v[23] = 19; v[24] = 25; 
	v[27] = 22; v[28] = 24; v[25] = 30; v[26] = 35; 
	v[29] = 28; v[30] = 27; v[31] = 26;
}

int move(int temp_lo, int cnt){
    if (temp_lo == 50)return 50;
    int next;
    if (adj[temp_lo].size() == 1)next = adj[temp_lo][0];
    else next = adj[temp_lo][1];
    if (next == 50)return next;
    for (int i = 0; i < cnt-1; i++){
        next = adj[next][0];
        if (next == 50)
            break;
    }
    return next;
}

bool checklo(int move_lo){
    if (move_lo == 50)return false;
    for (int i = 0; i < 4; i++){
        if (lo[i] == move_lo)
            return true;
    }
    return false;
}

int go(int here){
    if (here == 10)
        return 0;
    int score = 0;
    for (int i = 0; i < 4; i++){
        int temp_lo = lo[i];
        int move_lo = move(temp_lo, a[here]);
        if (checklo(move_lo))
            continue;
        lo[i] = move_lo;
        score = max(score, go(here + 1) + v[move_lo]);
        lo[i] = temp_lo;
    }
    return score;
}

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    for (int i = 0; i < 10; i++){
        cin >> a[i];
    }
    setMap();
    cout << go(0) << '\n';
    return 0;
}