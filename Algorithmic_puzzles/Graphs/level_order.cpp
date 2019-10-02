/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//q.size() gives number of nodes in that level . Take out all nodes in that level and push their children
//Complexity (O(n))

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    
    vector<vector<int>> sol;
    if(!A) return sol;
    queue<TreeNode*> q;
    q.push(A);
    
    while(!q.empty())
    {
        vector<int> cur_level;
        int cur_level_count = q.size();
        
        while(cur_level_count--)
        {
            TreeNode* temp = q.front();
            q.pop();
            cur_level.push_back(temp->val);
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        sol.push_back(cur_level);
    }
    return sol;
}
