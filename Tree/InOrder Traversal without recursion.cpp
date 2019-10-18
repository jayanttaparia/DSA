/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 TreeNode* insert(TreeNode* cur, stack<TreeNode*>&stk){
     while(cur!=NULL){
        stk.push(cur);
        cur = cur->left;
    }
    return cur;
 }
 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> stk;
    TreeNode *cur = A;
    cur = insert(cur, stk);
    
    while(cur == NULL && !stk.empty()){
        cur = stk.top();
        stk.pop();
        ans.push_back(cur->val);
        cur=cur->right;
        if(cur != NULL)
            cur = insert(cur, stk);
    }
    
    return ans;
}
