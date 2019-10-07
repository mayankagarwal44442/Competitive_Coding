#include <bits/stdc++.h>
using namespace std;


int min_swaps(vector<int> &arr)
{
	unordered_map<int,int> ht;
	for(int i = 0; i < arr.size(); ++i) ht[arr[i]] = i;

	vector<bool> visited(arr.size(), false);

	vector<int> sorted_arr = arr;
	sort(sorted_arr.begin(), sorted_arr.end());

	int count = 0;

	for(int i = 0; i < arr.size(); ++i)
	{
		if(visited[i] || sorted_arr[i] == arr[i]) continue;
		else
		{
			int j = i;
			int cycle_size = 0;
			while(!visited[j])			//place the correct element at jth position and then j becomes the position from which correct element came
			{ 
				cycle_size ++;
				visited[j] = true;
				j = ht[sorted_arr[j]];
			}
			if(cycle_size > 0) 
			{
				count+= (cycle_size - 1);
			}
		}
	}
	return count;

}

int main()
{
	vector<int> arr = {2,4,5,1,3};
	cout << min_swaps(arr) << endl;
}