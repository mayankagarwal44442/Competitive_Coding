#include <bits/stdc++.h>
using namespace std;

int str_or(string &a, string &b)
{
    int count = 0;
    for(int i = 0; i < a.size(); ++i)
    {
        if(a[i]=='1' || b[i] == '1') count++;
    }
    return count;
}


// Complete the acmTeam function below.
vector<int> acmTeam(vector<string> topic) {
    int best = -1; int count = 0;
    for(int i = 0; i < topic.size(); ++i)
    {
        for(int j = i + 1; j < topic.size(); ++j)
        {
            int or_val = str_or(topic[i], topic[j]);
            if(or_val > best)
            {
                best = or_val;
                count = 1;
            }
            else if(or_val == best) count++;
        }
    }
    vector<int> sol;
    sol.push_back(best);
    sol.push_back(count);
    return sol;


}

int main()
{
    vector<string> in = {"10101", "11100", "11010", "00101"};
    vector<int> sol = acmTeam(in);
    cout << sol[0] << " " << sol[1] << endl;
}