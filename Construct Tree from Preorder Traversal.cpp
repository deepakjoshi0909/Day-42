Node* solve(int pre[], char preLN[], int& cur) {
    Node* temp = new Node(pre[cur]);
    if (preLN[cur] == 'N') {
        cur++;
        temp->left = solve(pre, preLN, cur);
        cur++;
        temp->right = solve(pre, preLN, cur);
    }
    return temp;
}

Node* constructTree(int n, int pre[], char preLN[]) {
    int cur = 0;
    return solve(pre, preLN, cur);
}
