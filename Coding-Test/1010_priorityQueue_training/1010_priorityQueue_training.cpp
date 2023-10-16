#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ���� Ʈ�� ��� ���� �Լ�
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        // �� ��� ���� �� ���� ����
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    // ��� �̵� ������ ���
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
    // Ű ���� �������� ��带 ����
    if (key > root->key) {
        root->right = insert(root->right, key);
    }
    else if (key < root->key) {
        root->left = insert(root->left, key);
    }
    return root;
}

// �ִ밪 ��� ���� �� Ƚ���� ������Ű�� �Լ�
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


// ������ Ʈ�� ��� �Լ�
void print_level(TreeNode* root) {
    if (root == NULL) {
        printf("Ʈ���� �� �����Դϴ�.\n");
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

// �޴� ǥ��
char menu_choice() {
    char choice;
    printf("\n�޴� �Է�: ");
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

    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
    printf("l i     : ��� �߰�        ��\n");
    printf("l d     : ��� ����        ��\n");
    printf("l p     : ������ ���      ��\n");
    printf("l c     : ����             ��\n");
    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n\n\n");

    while (1) {
        choice = menu_choice();

        switch (choice) {
        case 'i':
            printf("�߰��� �� �Է�: ");
            scanf_s("%d", &value);
            move_count = 0;
            root = insert(root, value);
            printf("\n");
            while (root != NULL) {
                root = delete_max(root, &move_count);
            }
            printf("��尡 �̵��� Ƚ��: %d\n", move_count);
            break;
        case 'd':
            move_count = 0;
            root = delete_max(root, &move_count);
            printf("��尡 �̵��� Ƚ��: %d\n", move_count);
            break;
        case 'p':
            printf("Ʈ�� ������ ���: ");
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