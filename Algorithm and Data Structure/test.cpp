#include <bits/stdc++.h>

vector<int> slice(const vector<int>& v, int a, int b) {
    return vector<int>(v.begin()+a, v.begin()+b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
    const int N = preorder.size();
    if (preorder.empty()) return;
    const int root = preorder[0];
    const int L = find(inorder.begin(), inorder.end(), root) - 
}