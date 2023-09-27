#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode { // 노드 구조체
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct BinarySearchTree { // 이진탐색트리 구조체
    TreeNode* root;
} BinarySearchTree;

TreeNode* createNode(int key) { // 새 노드 생성 함수
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BinarySearchTree* createBST() { // 새 이진탐색트리 생성 함수
    BinarySearchTree* newBST = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    newBST->root = NULL;
    return newBST;
}

// 이진탐색트리에 노드 삽입하는 함수
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

// 이진탐색트리에 키 삽입하는 함수
void insertKey(BinarySearchTree* bst, int key) {
    int visitCount = 0;  // Initialize visitCount
    bst->root = insert(bst->root, key, &visitCount);
    printf("방문한 노드의 수: %d\n", visitCount);
}

// 중위순회노드 출력 함수
void inorderTree(TreeNode* root, int* visitCount) {
    if (root != NULL) {
        inorderTree(root->left, visitCount);
        printf("%d ", root->key);
        inorderTree(root->right, visitCount);
        (*visitCount)++;
    }
}

// 중위순회노드로 이진탐색트리 출력하는 함수
int inorderPrint(BinarySearchTree* bst) {
    int visitCount = 0;
    inorderTree(bst->root, &visitCount);
    return visitCount;
}

// 특정 키를 찾는 함수
int search(TreeNode* root, int key, int* visitCount) {
    if (root == NULL) {
        return 0;
    }

    (*visitCount)++; // 노드를 방문하면 방문 횟수 증가

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

// 이진탐색트리에서 특정 키를 찾는 함수
int searchKey(BinarySearchTree* bst, int key) {
    int visitCount = 0;
    int result = search(bst->root, key, &visitCount);
    if (result) {
        printf("검색 성공: %d\n", key);
        printf("방문한 노드의 수: %d\n", visitCount);
        inorderPrint(bst);
        printf("\n");
    }
    else {
        printf("검색 실패: %d\n", key);
    }
    return result;
}

// 서브트리에서 가장 작은 값을 찾는 함수
TreeNode* findMin(TreeNode* node, int* visitCount) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
        (*visitCount)++;
    }
    return current;
}

// 노드 삭제 관련 함수
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

// 이진탐색트리에서 특정 키를 삭제하는 함수
void deleteKey(BinarySearchTree* bst, int key) {
    int visitCount = 0;
    bst->root = deleteNode(bst->root, key, &visitCount);
    if (visitCount > 0) {
        printf("방문한 노드의 수: %d\n", visitCount);
        inorderPrint(bst);
        printf("\n");
    }
    else {
        printf("삭제 실패: %d (노드가 존재하지 않습니다)\n", key);
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

    // 메뉴 바
    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    printf(" s : 검색                 ㅣ\n");
    printf(" i : 노드 추가            ㅣ\n");
    printf(" d : 노드 삭제            ㅣ\n");
    printf(" t : 중위 순회            ㅣ\n");
    printf(" I : 노드 추가(반복)      ㅣ\n");
    printf(" D : 노드 삭제(반복)      ㅣ\n");
    printf(" c : 종료                 ㅣ\n");
    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");

    char menu;
    int input;
    int visitCount;

    while (1) {
        printf("\n메뉴 입력: ");
        scanf_s(" %c", &menu);

        switch (menu) {
        case 's':
            printf("검색할 값 입력: ");
            scanf_s("%d", &input);
            searchKey(bst, input);
            break;
        case 'i':
            printf("삽입할 값 입력: ");
            scanf_s("%d", &input);
            insertKey(bst, input);
            inorderPrint(bst);
            printf("\n");
            break;
        case 'd':
            printf("삭제할 값 입력: ");
            scanf_s("%d", &input);
            deleteKey(bst, input);
            break;
        case 't':
            visitCount = inorderPrint(bst);
            printf("\n방문한 노드의 수: %d\n", visitCount);
            break;
        case 'I':
            printf("삽입할 값 입력: ");
            scanf_s("%d", &input);
            insertKey(bst, input);
            inorderPrint(bst);
            printf("\n");
            break;
        case 'D':
            printf("삭제할 값 입력: ");
            scanf_s("%d", &input);
            deleteKey(bst, input);
            break;
        case 'c':
            return 0;
        default:
            printf("옳지 않은 메뉴입니다. 다시 입력하시오.\n");
        }
    }

    return 0;
}
