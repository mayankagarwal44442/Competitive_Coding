
vector<int> Solution::dNums(vector<int> &A, int B) {

    unordered_map<int,int> ht;
    for(int i = 0; i < B-1; ++i)
    {
        ht[A[i]]+=1;
    }
    
    vector<int> sol;
    for(int i = B-1; i < A.size(); ++i)
    {
        ht[A[i]] += 1;
        sol.push_back(ht.size());
        ht[A[i-B+1]] -= 1;
        if(ht[A[i-B+1]] == 0) ht.erase(A[i-B+1]);
     }
    return sol;
    
}
