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

// 스택을 이용한 전위 순회
void preorder_stack(TreeNode* root)
{
    if (root == NULL) return;

    push(root); // 루트 노드를 스택에 추가

    while (top >= 0) {
        TreeNode* node = pop(); //스택에서 노드를 뺌
        printf("%d ", node->data); // 꺼낸 노드 데이터를 출력

        if (node->right != NULL)
            push(node->right);

        if (node->left != NULL)
            push(node->left);
    }
}

// 스택을 이용한 중위 순회
void inorder_stack(TreeNode* root)
{
    TreeNode* current = root; // 현재 노드를 가리키는 포인터를 루트로 초기화

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            push(current); // 현재 노드를 스택에 추가
            current = current->left;
        }

        current = pop();
        printf("%d ", current->data);

        current = current->right;
    }
}

// 스택을 이용한 후위 순회
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

        root = pop(); // 스택에서 노트를 뺌

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
    // 노드를 초기화
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

    // 루트 노드 설정
    TreeNode* root = &n1;

    printf("<Traversal with Stack>\n");

    printf("1. 전위 순회\n");
    preorder_stack(root);
    printf("\n\n");

    top = -1; // 스택 초기화

    printf("2. 중위 순회\n");
    inorder_stack(root);
    printf("\n\n");

    top = -1; // 스택 초기화

    printf("3. 후위 순회\n");
    postorder_stack(root);
    printf("\n\n");

    return 0;
}