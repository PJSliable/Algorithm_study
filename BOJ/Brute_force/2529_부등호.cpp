//메모리: 3692KB, 시간: 4ms
#include <bits/stdc++.h>
using namespace std;
int K, visited[10];
int a[] = {9,8,7,6,5,4,3,2,1,0};
int b[] = {0,1,2,3,4,5,6,7,8,9};
char oper_str[9];
vector<string> ret;
bool oper(char c, char a, char b)
{
    if (c == '>')return a > b;
    else return a < b;
}
void dfs(int cnt, string num){
    if (cnt == K+1){
        ret.push_back(num);
        return;
    }
    for (int i = 0; i < 10; i++){
        if (visited[i] != 0)continue;
        if (cnt != 0 && !oper(oper_str[cnt - 1], num[cnt - 1], i + '0'))continue;
        visited[i] = 1;
        dfs(cnt + 1, num + to_string(i));
        visited[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K;
    for (int i = 0; i < K;i++){
        cin >> oper_str[i];
    }
    dfs(0, "");
    sort(&ret[0], &ret[0] + ret.size());
    cout << ret[ret.size()-1] << '\n' << ret[0] << '\n';
    return 0;
}


/**
 * 메모리: 2024KB, 시간: 0ms
#include <bits/stdc++.h>
using namespace std;
int K, visited[10];
int a[] = {9,8,7,6,5,4,3,2,1,0};
int b[] = {0,1,2,3,4,5,6,7,8,9};
char c;
vector<int> num;
vector<char> oper_str;
string bigans, smallans;
bool oper(char c, int a, int b)
{
    if (c == '>')return a > b;
    else return a < b;
}
void bigdfs(int cnt, int visited[10], vector<int> v){
    if (bigans != ""){
        return;
    }
    if (cnt == K+1){
        for (int i: v){
            bigans += to_string(i);
        }
        return;
    }
    for (int i = 9; i >= 0; i--){
        if (visited[i] == 0){
            if (cnt != 0 && !oper(oper_str[cnt-1], v[cnt-1], i))continue;
            visited[i] = 1;
            v.push_back(i);
            bigdfs(cnt + 1, visited, v);
            v.pop_back();
            visited[i] = 0;
        }
    }
}

void smalldfs(int cnt, int visited[10], vector<int> v){
    if (smallans != ""){
        return;
    }
    if (cnt == K+1){
        for (int i: v){
            smallans += to_string(i);
        }
        return;
    }
    for (int i = 0; i < 10; i++){
        if (visited[i] == 0){
            if (cnt != 0 && !oper(oper_str[cnt-1], v[cnt-1], i))continue;
            visited[i] = 1;
            v.push_back(i);
            smalldfs(cnt + 1, visited, v);
            v.pop_back();
            visited[i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K;
    for (int i = 0; i < K;i++){
        cin >> c;
        oper_str.push_back(c);
    }
    vector<int> b;
    vector<int> s;
    bigdfs(0, visited,b);
    smalldfs(0, visited,s);
    cout << bigans << '\n' << smallans << '\n';
    return 0;
}
*/