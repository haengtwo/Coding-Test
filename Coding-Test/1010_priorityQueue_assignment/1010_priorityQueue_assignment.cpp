#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 이진 트리 노드 삽입 함수
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        // 새 노드 생성 후 값을 설정
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    // 노드 이동 과정을 출력
    TreeNode* temp = root;
    while (1) {
        if (key > temp->key) {
            printf("%d ", temp->key);
            temp = temp->right;
        }
        else if (key < temp->key) {
            printf("%d ", temp->key);
            temp = temp->left;
        }
        else {
            break;
        }

        if (temp == NULL) {
            break;
        }
    }
    // 키 값을 기준으로 노드를 삽입
    if (key > root->key) {
        root->right = insert(root->right, key);
    }
    else if (key < root->key) {
        root->left = insert(root->left, key);
    }
    return root;
}

// 최대값 노드 삭제 및 횟수를 증가시키는 함수
TreeNode* delete_max(TreeNode* root, int* count) {
    if (root == NULL) return NULL;
    TreeNode* temp;
    if (root->right != NULL) {
        root->right = delete_max(root->right, count);
    }
    else {
        temp = root;
        root = root->left;
        free(temp);
        (*count)++;
    }
    return root;
}


// 레벨별 트리 출력 함수
void print_level(TreeNode* root) {
    if (root == NULL) {
        printf("트리가 빈 상태입니다.\n");
        return;
    }

    TreeNode* queue[MAX_ELEMENT];
    int level_queue[MAX_ELEMENT];
    int level = -1;
    int front = -1, rear = -1;
    queue[++rear] = root;
    level_queue[++rear] = 0;

    while (front != rear) {
        TreeNode* current = queue[++front];
        int current_level = level_queue[front];

        if (current_level > level) {
            if (level >= 0) {
                printf("\n");
            }
            printf("[%d] ", current_level + 1);
            level = current_level;
        }

        printf("%d ", current->key);

        if (current->left != NULL) {
            queue[++rear] = current->left;
            level_queue[rear] = current_level + 1;
        }
        if (current->right != NULL) {
            queue[++rear] = current->right;
            level_queue[rear] = current_level + 1;
        }
    }
    printf("\n");
}

// 메뉴 표시
char menu_choice() {
    char choice;
    printf("\n메뉴 입력: ");
    scanf_s(" %c", &choice);
    return choice;
}

int main(void) {
    TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
    n1->key = 21;
    n1->left = NULL;
    n1->right = NULL;

    TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
    n2->key = 18;
    n2->left = NULL;
    n2->right = NULL;

    TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
    n3->key = 36;
    n3->left = n1;
    n3->right = n2;

    TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
    n4->key = 15;
    n4->left = NULL;
    n4->right = NULL;

    TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode));
    n5->key = 75;
    n5->left = n4;
    n5->right = NULL;

    TreeNode* n6 = (TreeNode*)malloc(sizeof(TreeNode));
    n6->key = 89;
    n6->left = n3;
    n6->right = n5;

    TreeNode* n7 = (TreeNode*)malloc(sizeof(TreeNode));
    n7->key = 63;
    n7->left = NULL;
    n7->right = NULL;

    TreeNode* n8 = (TreeNode*)malloc(sizeof(TreeNode));
    n8->key = 65;
    n8->left = NULL;
    n8->right = NULL;

    TreeNode* n9 = (TreeNode*)malloc(sizeof(TreeNode));
    n9->key = 70;
    n9->left = n7;
    n9->right = n8;

    TreeNode* n10 = (TreeNode*)malloc(sizeof(TreeNode));
    n10->key = 90;
    n10->left = n6;
    n10->right = n9;

    TreeNode* root = n10;

    int choice, value, move_count;

    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    printf("l i     : 노드 추가        ㅣ\n");
    printf("l d     : 노드 삭제        ㅣ\n");
    printf("l p     : 레벨별 출력      ㅣ\n");
    printf("l c     : 종료             ㅣ\n");
    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n\n");

    while (1) {
        choice = menu_choice();

        switch (choice) {
        case 'i':
            printf("추가할 값 입력: ");
            scanf_s("%d", &value);
            move_count = 0;
            root = insert(root, value);
            printf("\n");
            while (root != NULL) {
                root = delete_max(root, &move_count);
            }
            printf("노드가 이동된 횟수: %d\n", move_count);
            break;
        case 'd':
            move_count = 0;
            root = delete_max(root, &move_count);
            printf("노드가 이동된 횟수: %d\n", move_count);
            break;
        case 'p':
            printf("트리 레벨별 출력: ");
            print_level(root);
            printf("\n");
            break;
        case 'c':
            free(root);
            return 0;
        }
    }

    return 0;
}