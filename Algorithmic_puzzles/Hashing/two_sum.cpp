#include <bits/stdc++.h>
using namespace std;

vector<int> sol(vector<int> &A, int B)
{
	unordered_map<int,int> ht;
	for(int i = 0; i < A.size(); ++i)
	{
		if(ht.find[A[i]] == ht.end()) ht.insert({B-A[i], i});
	
		else
		{
			vector<int> sol;
			sol.push_back(ht[A[i]]+1)
			sol.push_back(i+1);
			return sol;
		}
	}
}


int main()
{
		vector<int> v = {2, 7, 11, 15};
		cout << sol(v,9) << endl;
}