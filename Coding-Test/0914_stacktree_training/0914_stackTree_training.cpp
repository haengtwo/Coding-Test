#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p)
{
    if (top < SIZE - 1)
        stack[++top] = p;
}

TreeNode* pop()
{
    TreeNode* p = NULL;
    if (top >= 0)
        p = stack[top--];
    return p;
}

// ������ �̿��� ���� ��ȸ
void preorder_stack(TreeNode* root)
{
    if (root == NULL) return;

    push(root); // ��Ʈ ��带 ���ÿ� �߰�

    while (top >= 0) {
        TreeNode* node = pop(); //���ÿ��� ��带 ��
        printf("%d ", node->data); // ���� ��� �����͸� ���

        if (node->right != NULL)
            push(node->right);

        if (node->left != NULL)
            push(node->left);
    }
}

// ������ �̿��� ���� ��ȸ
void inorder_stack(TreeNode* root)
{
    TreeNode* current = root; // ���� ��带 ����Ű�� �����͸� ��Ʈ�� �ʱ�ȭ

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            push(current); // ���� ��带 ���ÿ� �߰�
            current = current->left;
        }

        current = pop();
        printf("%d ", current->data);

        current = current->right;
    }
}

// ������ �̿��� ���� ��ȸ
void postorder_stack(TreeNode* root)
{
    if (root == NULL) return;

    do {
        while (root) {
            if (root->right)
                push(root->right);
            push(root);
            root = root->left;
        }

        root = pop(); // ���ÿ��� ��Ʈ�� ��

        if (root->right && stack[top] == root->right) {
            pop();
            push(root);
            root = root->right;
        }
        else {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (top >= 0);
}

int main(void)
{
    // ��带 �ʱ�ȭ
    TreeNode n10 = { 10, NULL, NULL };
    TreeNode n11 = { 11, NULL, NULL };
    TreeNode n9 = { 9, &n10, &n11 };
    TreeNode n8 = { 8, NULL, NULL };
    TreeNode n4 = { 4, NULL, NULL };
    TreeNode n5 = { 5, NULL, NULL };
    TreeNode n3 = { 3, &n4, &n5 };
    TreeNode n6 = { 6, NULL, NULL };
    TreeNode n7 = { 7, &n8, &n9 };
    TreeNode n2 = { 2, &n3, &n6 };
    TreeNode n1 = { 1, &n2, &n7 };

    // ��Ʈ ��� ����
    TreeNode* root = &n1;

    printf("<Traversal with Stack>\n");

    printf("1. ���� ��ȸ\n");
    preorder_stack(root);
    printf("\n\n");

    top = -1; // ���� �ʱ�ȭ

    printf("2. ���� ��ȸ\n");
    inorder_stack(root);
    printf("\n\n");

    top = -1; // ���� �ʱ�ȭ

    printf("3. ���� ��ȸ\n");
    postorder_stack(root);
    printf("\n\n");

    return 0;
}