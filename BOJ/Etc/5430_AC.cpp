#include <bits/stdc++.h>
using namespace std;
int T, n;
string s, order;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main()
{
    fastIO();
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> s;
        cin >> n;
        cin >> order;
        deque<int> v;
        int x = 0;
        for (char c:order)
        {
            if(c == '[')
                continue;
            if (c == ',' || c == ']')
            {
                if (x <= 0)
                    break;
                v.push_back(x);
                x = 0;
                continue;
            }
            x = 10 * x + (c - '0');
        }
        string ret = "[";

        int cnt = 0;
        int flag = -1;
        int counting_array[3] = {0, 0, 0};
        for (char c : s)
        {   
            if (c == 'D'){
                counting_array[flag + 1] += 1;
                cnt++;
                if (cnt > v.size()){
                    ret = "error";
                    break;
                }
            } else{
                flag *= -1;
            }
        }
        
        if (ret != "error")
        {
            for (int c = 0; c < counting_array[2]; c++)
                v.pop_back();
            if (flag == 1){
                reverse(v.begin(), v.end());
                for (int c = 0; c < counting_array[0]; c++){
                    v.pop_back();
                }
            } else{
                for (int c = 0; c < counting_array[0]; c++){
                    v.pop_front();
                }
            }
            for (int k = 0; k < v.size(); k++)
            {
                ret += to_string(v[k]);
                if (k == v.size() - 1)
                    continue;
                ret += ",";
            }
            ret += "]";
        }
        cout << ret << '\n';
    }
    return 0;
}