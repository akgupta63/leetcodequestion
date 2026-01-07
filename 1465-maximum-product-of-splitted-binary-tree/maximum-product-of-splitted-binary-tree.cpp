class Solution {
public:
    long long totalSum = 0;
    long long maxProd = 0;
    static constexpr int MOD = 1e9 + 7;

    int maxProduct(TreeNode* root) {
        totalSum = treeSum(root);
        subtreeSum(root);
        return maxProd % MOD;
    }

    long long treeSum(TreeNode* node) {
        if (!node) return 0;
        return node->val + treeSum(node->left) + treeSum(node->right);
    }

    long long subtreeSum(TreeNode* node) {
        if (!node) return 0;

        long long left = subtreeSum(node->left);
        long long right = subtreeSum(node->right);

        long long sum = node->val + left + right;

        maxProd = max(maxProd, sum * (totalSum - sum));

        return sum;
    }
};
