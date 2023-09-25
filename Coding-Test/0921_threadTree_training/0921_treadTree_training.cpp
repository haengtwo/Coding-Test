#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
    bool is_thread;
} TreeNode;

TreeNode* find_successor(TreeNode* t)
{
    TreeNode* pright = t->right;

    if (pright == NULL || t->is_thread == true)
        return pright;

    while (pright->left != NULL)
        pright = pright->left;

    return pright;
}

void thread_inorder(TreeNode* t)
{
    TreeNode* r;
    r = t;
    while (r->left != NULL) r = r->left;
    do
    {
        printf("%d ", r->data);
        r = find_successor(r);
    } while (r != NULL);
}

int main()
{
    TreeNode n1 = { 1, NULL, NULL, false };
    TreeNode n2 = { 2, NULL, NULL, false };
    TreeNode n3 = { 3, NULL, NULL, true };
    TreeNode n4 = { 4, NULL, NULL, true };
    TreeNode n5 = { 5, NULL, NULL, true };
    TreeNode n6 = { 6, NULL, NULL, true };
    TreeNode n7 = { 7, NULL, NULL, false };
    TreeNode n8 = { 8, NULL, NULL, false };
    TreeNode n9 = { 9, NULL, NULL, false };
    TreeNode n10 = { 10, NULL, NULL, false };
    TreeNode n11 = { 11, NULL, NULL, false };

    n1.left = &n2;
    n1.right = &n7;
    n2.left = &n3;
    n2.right = &n6;
    n3.left = &n4;
    n3.right = &n5;
    n7.left = &n8;
    n7.right = &n9;
    n9.left = &n10;
    n9.right = &n11;
    

    // 중위 순회
    thread_inorder(&n1);

    return 0;
}