#include <bits/stdc++.h>
using namespace std;

//complexity : o(n)

vector<int> sol(vector<int> &A, int B)
{
    unordered_map<int,int> ht;
    vector<int> sol;
    for(int i = 0; i < A.size(); ++i)
    {
        if(ht.find(A[i]) == ht.end()) ht.insert({B-A[i], i});
    
        else
        {
            sol.push_back(ht[A[i]]+1);
            sol.push_back(i+1);
            return sol;
        }
    }
    return sol;

}


int main()
{
		vector<int> v = {2, 7, 11, 15};
		vector<int> s = sol(v,9);
		cout << s[0] <<  " " << s[1] << endl;
}