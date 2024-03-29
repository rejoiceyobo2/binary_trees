#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int height(TreeNode* root) {
    if (root == NULL)
        return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

int is_avl_helper(TreeNode* root) {
    if (root == NULL)
        return 1;
    int left_height = height(root->left);
    int right_height = height(root->right);
    if (abs(left_height - right_height) > 1)
        return 0;
    return is_avl_helper(root->left) && is_avl_helper(root->right);
}

int binary_tree_is_avl(const TreeNode *tree) {
    if (tree == NULL)
        return 0;
    return is_avl_helper(tree);
}

int main() {
    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = 1;
    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->val = 2;
    root->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->val = 3;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = NULL;
    root->right->right = NULL;
    printf("Is the tree a valid AVL tree? %s\n", binary_tree_is_avl(root) ? "Yes" : "No");
    free(root->left);
    free(root->right);
    free(root);
    return 0;
}

