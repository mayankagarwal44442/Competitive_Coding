
//complexity: O(n_squared)

int Solution::colorful(int A) {
    
    vector<int> l;
    while(A)
    {
        l.push_back(A%10);
        A/=10;
    }
    
    bool res = true;
    
    unordered_set<int> ht;
    for(int i = 0; i < l.size(); ++i)
    {
        int prod = 1;
        for(int j = i; j < l.size(); ++j)
        {
            prod = prod * l[j];
            if(ht.find(prod) != ht.end())
            {
                res = false;
                break;
            }
            else ht.insert(prod);
        }
    }
    
    if(!res) return 0;
    else return 1;
    
    
}