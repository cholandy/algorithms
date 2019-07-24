#include <stdio.h>

struct TreeNode {
    int data;
    struct TreeNode* parent;
};

void printLabels1(struct TreeNode* root) {
    printf("%d\n", root->data);
    printf("%s", root->parent);
}

int main()
{
    struct TreeNode tn1 = {10, NULL};
    printLabels1(&tn1);
    return 0;
}