#include <bits/stdc++.h>
using namespace std;

// Benefits: minimal key movements.
//Count total number of elements less than it



void comparison_count_sort(vector<int> &arr)
{
	vector<int> count(arr.size(), 0);
	for(int i = 0; i < arr.size() - 1; ++i)
	{
		for(int j = i +1; j < arr.size() ; ++j)
		{
			if(arr[i] > arr[j]) count[i] += 1;
			else count[j] += 1;
		}
	}
	vector<int> aux(arr.size());
	for(int i = 0; i < arr.size(); ++i) aux[count[i]] = arr[i];
	arr = aux;
}





int main()
{
	vector<int> arr= {62, 31, 84, 96, 19, 47};
	comparison_count_sort(arr);
	for(int ele: arr) cout << ele << " "; cout << endl;
}