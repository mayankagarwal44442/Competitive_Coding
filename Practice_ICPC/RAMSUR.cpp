#include <bits/stdc++.h>
using namespace std;

#define MAX 1e5 + 1

int dp[(int)MAX];

string s;
int a,b;


int min_partitions()
{
	dp[0] = 0;  //number of partitions is 0 if number of elements is 0

	for(int i = 1; i < s.size(); ++i)
	{
		int min_val = INT_MAX;
		int value = 0;
		for(int j = i; j >0; --j)
		{
			value = (s[j] - '0')*pow(10,i-j) + value;
			if(value < a) continue;
			if(value > b) break;

			//partition at position left to j

			if(dp[j-1] != INT_MAX)					//if(dp[j-1]) is INT_MAX, then the partion left of j is not feasible
			min_val = min(min_val, dp[j-1] + 1);  
		}
		dp[i] = min_val;  
	}
	return (dp[s.size()-1] == INT_MAX)?-1: dp[s.size() - 1];


}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string temp;
		cin >>  temp >> a >> b;
		s = "?" + temp;                          //make string 1-indexed
		int res = min_partitions();
		if(res == -1) cout << -1 << endl;
		else 
		cout << res - 1<< endl;	//number of cuts = number of patitions - 1
	}
}