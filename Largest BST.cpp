class Solution {
public:
    struct Info {
        int size;    
        int max;     
        int min;     
        int ans;     
        bool isBST;   
    };

    Info largestBSTUtil(Node* root) {
        if (root == nullptr) {
            return {0, INT_MIN, INT_MAX, 0, true};
        }
        
        Info left = largestBSTUtil(root->left);
        Info right = largestBSTUtil(root->right);
        
        Info current;
        current.size = 1 + left.size + right.size;
        
        if (left.isBST && right.isBST && left.max < root->data && root->data < right.min) {
            current.min = min(left.min, root->data);
            current.max = max(right.max, root->data);
            
            current.ans = current.size;
            current.isBST = true;
        } else {
            current.ans = max(left.ans, right.ans);
            current.isBST = false;
        }
        
        return current;
    }

    int largestBst(Node* root) {
        return largestBSTUtil(root).ans;
    }
};
