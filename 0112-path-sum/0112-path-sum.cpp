class Solution {
public:
    bool hasPathSum(TreeNode* r, int targetSum) {
        if (!r) return false;
        if (!r->left&&!r->right) {
            return targetSum-r->val==0;
        }
        targetSum-=r->val;
        return hasPathSum(r->left,targetSum) || hasPathSum(r->right,targetSum);        
    }
};