class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        this->preorder = preorder;
        this->inorder = inorder;
        return buildTree(0, preorder.size() - 1, 0, inorder.size() - 1);
        
    }

    TreeNode* buildTree(int pb, int pe, int ib, int ie) {
        if (pb > pe || ib > ie) {
            return NULL;
        }
        TreeNode* rootNode = new TreeNode(preorder[pb]);
        int len = 0;
        for (int i = ib; i <= ie; i++, len++) {
            if (inorder[i] == preorder[pb]) {
                break;
            }
        }
        rootNode->left = buildTree(pb+1, pb+len, ib, ib+len-1);
        rootNode->right = buildTree(pb+len+1, pe, ib+len+1, ie);
        return rootNode;
    }
private:
    vector<int> preorder;
    vector<int> inorder;
};