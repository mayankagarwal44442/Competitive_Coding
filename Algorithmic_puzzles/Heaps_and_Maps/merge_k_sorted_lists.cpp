/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//functors - classes with () overloaded

struct compare
{
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.empty()) return NULL;

    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
      
    for(ListNode* ele: A) if(ele) pq.push(ele);
      
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    
    while(!pq.empty())
    {
        tail -> next = pq.top();
        tail = tail -> next;
        pq.pop();
        if(tail->next)pq.push(tail->next);
    }
    return dummy -> next;
    
    
      
}
