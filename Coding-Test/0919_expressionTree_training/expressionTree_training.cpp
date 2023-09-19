#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    float data;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode n1 = { 4.00, NULL, NULL };
TreeNode n2 = { 5.00, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 3.00, NULL, NULL };
TreeNode n5 = { '+', &n4, &n3 };
TreeNode n6 = { 2.00, NULL, NULL };
TreeNode n7 = { '+', &n6, &n5 };
TreeNode n8 = { 6.00, NULL, NULL };
TreeNode n9 = { 7.00, NULL, NULL };
TreeNode n10 = { '/', &n8, &n9 };
TreeNode n11 = { '-', &n7, &n10 };
TreeNode n12 = { 9.00, NULL, NULL };
TreeNode n13 = { '+', &n11, &n12 };


// ���� ��� �Լ�
float evaluate(TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;

    float leftValue = evaluate(root->left);
    float rightValue = evaluate(root->right);

    switch ((int)root->data) {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;

    }
}

// �� ����� ���� ����ϴ� �Լ�
int countNodes(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int main(void) {

    float result = evaluate(&n13);

    // ��� ���
    printf("4.00 * 5.00 = %.2f\n", n1.data * n2.data);
    printf("3.00 + 20.00 = %.2f\n", n4.data + n3.data);
    printf("2.00 + 23.00 = %.2f\n", n6.data + n5.data);
    printf("6.00 / 7.00 = %.2f\n", n8.data / n9.data);
    printf("25.00 - 0.86 = %.2f\n", n3.data - n4.data);
    printf("%.2f - 9.00 = %.2f\n", result - n12.data, result);
    printf("������ ���� %.2f�Դϴ�.\n\n", result);

    // �� ����� ���� ���
    int nodeCount = countNodes(&n13);
    printf("�� ����� ���� %d�� �Դϴ�.\n", nodeCount);

    return 0;
}