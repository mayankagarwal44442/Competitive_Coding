#define MOD 1000000007

//Complexity: O(nlogn)

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> pq;
    for(int ele:B) pq.push(ele);
    
    int sum = 0;
    while(A--)
    {
        int ele = pq.top();
        pq.pop();
        pq.push(ele/2);
        sum = (sum%MOD + ele%MOD)%MOD;
    }
    return sum;
}
