#include <bits/stdc++.h>
using namespace std;

//Brute force: O(n_squared_logn) (add all pairs and push into map)
//Optimized - sort and then start from end and then for n iterations, pop first , push into answer, if x-1,y and x,y-1 not int map, push them
//O(nlogn) 


vector<int> solve(vector<int> &A, vector<int> &B)
{

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    priority_queue<pair<int,pair<int,int>>> pq;
    int end1 = A.size() - 1;
    int end2 = B.size() - 1;
    
    map<pair<int,int>,bool> mp;
    
    pq.push({A[end1] + B[end2], {end1, end2}});
    mp[{end1,end2}] = true;
    
    vector<int> sol;
    
    int count = 1;

    while(count <= A.size())
    {
        pair<int,pair<int,int>> tp = pq.top();
        pq.pop();
        sol.push_back(tp.first);
        
        pair<int,int>p1 = {tp.second.first-1, tp.second.second};
        
        if(!mp[p1])
        {
            pq.push({A[p1.first]+B[p1.second], p1});
            mp[p1] = true;
        }
        
        p1 = {tp.second.first, tp.second.second-1};
        
        if(!mp[p1])
        {
            pq.push({A[p1.first]+B[p1.second], p1});
            mp[p1] = true;            
        }
        count++;
    }
    return sol;
	
}


int main()
{
	int n;
	cin >> n;

	vector<int> A(n);
	vector<int> B(n);

	for(int i = 0; i < n; ++i) cin >> A[i];
	for(int j = 0; j < n; ++j) cin >> B[j];

	vector<int> sol = solve(A,B);
	
	for(int ele: sol) cout << ele << " "; cout << endl;

}