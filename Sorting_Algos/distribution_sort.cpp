#include <bits/stdc++.h>
using namespace std;

//very useful if elements are in a range
//O(n)


void distribution_sort(vector<int> &arr, int l, int r)
{
	vector<int> dist(r-l+1);
	vector<int> aux(arr.size());
	for(int j = 0; j < (r-l+1); ++j) dist[j] = 0;
	for(int i = 0; i < arr.size(); ++i) dist[arr[i] - l] ++;   // individual frequency
	for(int j = 1; j < (r-l+1); ++j) dist[j] += dist[j-1];

	for(int i = arr.size() - 1; i >=0; --i)
	{
		aux[--dist[arr[i]-l]] = arr[i];
	}
	arr = aux;


}




int main()
{
	vector<int> arr= {13, 11, 12, 13, 12, 12};
	distribution_sort(arr, 11, 13);
	for(int ele: arr) cout << ele << " "; cout << endl;
}