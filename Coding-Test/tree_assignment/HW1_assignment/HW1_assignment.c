#include <stdio.h>
#include <stdlib.h>

// 트리노드 구조체
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

//새로운 노드 생성에 대한 코드
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//링크 전위 순회 함수
void preorder(struct TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

//링크 중위 순회 함수
void inorder(struct TreeNode* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

//링크 후위 순회 함수
void postorder(struct TreeNode* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

//배열 전위 순회 함수
void arrayPreorder(struct TreeNode* node, int index) {
    if (node != NULL) {
        printf("%d ", node->data);
        arrayPreorder(node->left, 2 * index + 1);
        arrayPreorder(node->right, 2 * index + 2);
    }

}

//배열 중위 순회 함수
void arrayInorder(struct TreeNode* node, int index) {
    if (node != NULL) {
        arrayInorder(node->left, 2 * index + 1);
        printf("%d ", node->data);
        arrayInorder(node->right, 2 * index + 2);
    }
}

//배열 후위 순회 함수
void arrayPostorder(struct TreeNode* node, int index) {
    if (node != NULL) {
        arrayPostorder(node->left, 2 * index + 1);
        arrayPostorder(node->right, 2 * index + 2);
        printf("%d ", node->data);
    }
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(3);
    root->left->left->left = createNode(4);
    root->left->left->right = createNode(5);
    root->left->right = createNode(6);
    root->right = createNode(7);
    root->right->left = createNode(8);
    root->right->right = createNode(9);
    root->right->right->left = createNode(10);
    root->right->right->right = createNode(11);

    printf("<Linked Tree>\n");
    printf("1. 전위순회\n");
    preorder(root);
    printf("\n\n");

    printf("2. 중위순회\n");
    inorder(root);
    printf("\n\n");

    printf("3. 후위순회\n");
    postorder(root);
    printf("\n\n\n");

    printf("<Array Tree>\n");
    printf("1. 전위순회\n");
    arrayPreorder(root, 0);
    printf("\n\n");

    printf("\n2. 중위순회\n");
    arrayInorder(root, 0);
    printf("\n\n");

    printf("\n3. 후위순회\n");
    arrayPostorder(root, 0);
    printf("\n\n");

    //메모리를 해제하는 코드
    free(root->right->right->right);
    free(root->right->right->left);
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left->right);
    free(root->left->left->right);
    free(root->left->left->left);
    free(root->left->left);
    free(root->left);
    free(root);

    return 0;
}