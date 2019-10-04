#include <bits/stdc++.h>
using namespace std;

//approach. Store sum and corresponding index as you go. If you see the sum again, take difference. check if max
//complexity - O(n)


vector<int> solve(vector<int> &A)
{
	unordered_map<int,int> ht;
	int sum = 0;
	int best_left = -1;
	int best_right = -1;
	int best_length = -1;

	ht[0] = 0;

	for(int i = 0; i < A.size(); ++i)
	{
		sum += A[i];
		if(ht.find(sum)!=ht.end())
		{
			if(i-ht[sum] > best_length)
			{
				best_length = i - ht[sum];
				best_left = ht[sum];
				best_right = i+1;
			}
		}
		else ht[sum] = i+1;
	}

	vector<int> sol;
	for(int i = best_left; i < best_right; ++i) sol.push_back(A[i]);
	return sol;
}

int main()
{
	vector<int> ans = {1,2,-2,4,-4};
	vector<int> sol = solve(ans);
	for(int ele: sol) cout << ele << " "; cout << endl;
}