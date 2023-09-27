#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode { // ��� ����ü
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct BinarySearchTree { // ����Ž��Ʈ�� ����ü
    TreeNode* root;
} BinarySearchTree;

TreeNode* createNode(int key) { // �� ��� ���� �Լ�
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BinarySearchTree* createBST() { // �� ����Ž��Ʈ�� ���� �Լ�
    BinarySearchTree* newBST = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    newBST->root = NULL;
    return newBST;
}

// ����Ž��Ʈ���� ��� �����ϴ� �Լ�
TreeNode* insert(TreeNode* root, int key, int* visitCount) {
    if (root == NULL) {
        (*visitCount)++;
        return createNode(key);
    }
    if (key < root->key) {
        (*visitCount)++;
        root->left = insert(root->left, key, visitCount);
    }
    else if (key > root->key) {
        (*visitCount)++;
        root->right = insert(root->right, key, visitCount);
    }
    return root;
}

// ����Ž��Ʈ���� Ű �����ϴ� �Լ�
void insertKey(BinarySearchTree* bst, int key) {
    int visitCount = 0;  // Initialize visitCount
    bst->root = insert(bst->root, key, &visitCount);
    printf("�湮�� ����� ��: %d\n", visitCount);
}

// ������ȸ��� ��� �Լ�
void inorderTree(TreeNode* root, int* visitCount) {
    if (root != NULL) {
        inorderTree(root->left, visitCount);
        printf("%d ", root->key);
        inorderTree(root->right, visitCount);
        (*visitCount)++;
    }
}

// ������ȸ���� ����Ž��Ʈ�� ����ϴ� �Լ�
int inorderPrint(BinarySearchTree* bst) {
    int visitCount = 0;
    inorderTree(bst->root, &visitCount);
    return visitCount;
}

// Ư�� Ű�� ã�� �Լ�
int search(TreeNode* root, int key, int* visitCount) {
    if (root == NULL) {
        return 0;
    }

    (*visitCount)++; // ��带 �湮�ϸ� �湮 Ƚ�� ����

    if (root->key == key) {
        return 1;
    }

    if (key < root->key) {
        return search(root->left, key, visitCount);
    }
    else {
        return search(root->right, key, visitCount);
    }
}

// ����Ž��Ʈ������ Ư�� Ű�� ã�� �Լ�
int searchKey(BinarySearchTree* bst, int key) {
    int visitCount = 0;
    int result = search(bst->root, key, &visitCount);
    if (result) {
        printf("�˻� ����: %d\n", key);
        printf("�湮�� ����� ��: %d\n", visitCount);
        inorderPrint(bst);
        printf("\n");
    }
    else {
        printf("�˻� ����: %d\n", key);
    }
    return result;
}

// ����Ʈ������ ���� ���� ���� ã�� �Լ�
TreeNode* findMin(TreeNode* node, int* visitCount) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
        (*visitCount)++;
    }
    return current;
}

// ��� ���� ���� �Լ�
TreeNode* deleteNode(TreeNode* root, int key, int* visitCount) {
    if (root == NULL)
        return root;

    (*visitCount)++;

    if (key < root->key)
        root->left = deleteNode(root->left, key, visitCount);
    else if (key > root->key)
        root->right = deleteNode(root->right, key, visitCount);
    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = findMin(root->right, visitCount);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key, visitCount);
    }

    return root;
}

// ����Ž��Ʈ������ Ư�� Ű�� �����ϴ� �Լ�
void deleteKey(BinarySearchTree* bst, int key) {
    int visitCount = 0;
    bst->root = deleteNode(bst->root, key, &visitCount);
    if (visitCount > 0) {
        printf("�湮�� ����� ��: %d\n", visitCount);
        inorderPrint(bst);
        printf("\n");
    }
    else {
        printf("���� ����: %d (��尡 �������� �ʽ��ϴ�)\n", key);
    }
}

int main() {
    BinarySearchTree* bst = createBST();

    insertKey(bst, 60);
    insertKey(bst, 41);
    insertKey(bst, 74);
    insertKey(bst, 16);
    insertKey(bst, 53);
    insertKey(bst, 25);
    insertKey(bst, 46);
    insertKey(bst, 55);
    insertKey(bst, 42);
    insertKey(bst, 65);
    insertKey(bst, 63);
    insertKey(bst, 70);
    insertKey(bst, 62);
    insertKey(bst, 64);

    // �޴� ��
    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
    printf(" s : �˻�                 ��\n");
    printf(" i : ��� �߰�            ��\n");
    printf(" d : ��� ����            ��\n");
    printf(" t : ���� ��ȸ            ��\n");
    printf(" I : ��� �߰�(�ݺ�)      ��\n");
    printf(" D : ��� ����(�ݺ�)      ��\n");
    printf(" c : ����                 ��\n");
    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n\n");

    char menu;
    int input;
    int visitCount;

    while (1) {
        printf("\n�޴� �Է�: ");
        scanf_s(" %c", &menu);

        switch (menu) {
        case 's':
            printf("�˻��� �� �Է�: ");
            scanf_s("%d", &input);
            searchKey(bst, input);
            break;
        case 'i':
            printf("������ �� �Է�: ");
            scanf_s("%d", &input);
            insertKey(bst, input);
            inorderPrint(bst);
            printf("\n");
            break;
        case 'd':
            printf("������ �� �Է�: ");
            scanf_s("%d", &input);
            deleteKey(bst, input);
            break;
        case 't':
            visitCount = inorderPrint(bst);
            printf("\n�湮�� ����� ��: %d\n", visitCount);
            break;
        case 'I':
            printf("������ �� �Է�: ");
            scanf_s("%d", &input);
            insertKey(bst, input);
            inorderPrint(bst);
            printf("\n");
            break;
        case 'D':
            printf("������ �� �Է�: ");
            scanf_s("%d", &input);
            deleteKey(bst, input);
            break;
        case 'c':
            return 0;
        default:
            printf("���� ���� �޴��Դϴ�. �ٽ� �Է��Ͻÿ�.\n");
        }
    }

    return 0;
}
