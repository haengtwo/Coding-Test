#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

////����, ����, ���� ��ȸ
//
//typedef struct TreeNode {
//	int data;
//	struct TreeNode* left, * right;
//}TreeNode;
//
//TreeNode n1 = { 1, NULL, NULL };
//TreeNode n2 = { 4, &n1, NULL };
//TreeNode n3 = { 16, NULL, NULL };
//TreeNode n4 = { 25, NULL, NULL };
//TreeNode n5 = { 20, &n3, &n4 };
//TreeNode n6 = { 15, &n2, &n5 };
//TreeNode* root = &n6;
//
//void inorder(TreeNode* root) {
//	if (root != NULL) {
//		inorder(root->left);
//		printf("[%d] ", root->data);
//		inorder(root->right);
//	}
//}
//
//int main()
//{
//	printf("���� ��ȸ : ");
//	inorder(root);
//
//	return 0;
//}
//
//
//
//// �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�



//// push, pop ����
//
//typedef struct TreeNode {
//	int data;
//	struct TreeNode* left, * right;
//}TreeNode;
//
//TreeNode n1 = { 1, NULL, NULL };
//TreeNode n2 = { 4, &n1, NULL };
//TreeNode n3 = { 16, NULL, NULL };
//TreeNode n4 = { 25, NULL, NULL };
//TreeNode n5 = { 20, &n3, &n4 };
//TreeNode n6 = { 15, &n2, &n5 };
//TreeNode* root = &n6;
//
//#define SIZE 100
//int top = -1;
//TreeNode* stack[SIZE];
//
//void push(TreeNode* p) {
//	if (top < SIZE - 1)
//		stack[++top] = p;
//}
//
//TreeNode* pop()
//{
//	TreeNode* p = NULL;
//	if (top >= 0)
//		p = stack[top--];
//	return p;
//}
//
//void inorder_iter(TreeNode* root) {
//	while (1) {
//		for (; root; root = root->left)
//			push(root);
//		root = pop();
//		if (!root) break;
//		printf("[%d] ", root->data);
//		root = root->right;
//	}
//}
//
//int main()
//{
//	printf("���� ��ȸ = ");
//	inorder_iter(root);
//	printf("\n");
//
//	return 0;
//}



//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�


//// ���� ����
//
//
//typedef struct TreeNode {
//	int data;
//	struct TreeNode* left, * right;
//}TreeNode;
//
//TreeNode n1 = { 1, NULL, NULL };
//TreeNode n2 = { 4, NULL, NULL };
//TreeNode n3 = { '*', &n1, &n2};
//TreeNode n4 = { 16, NULL, NULL };
//TreeNode n5 = { 25, NULL, NULL };
//TreeNode n6 = { '+', &n4, &n5};
//TreeNode n7 = { '+', &n3, &n6};
//TreeNode* exp = &n7;
//
//// ���� ��� �Լ�
//int evaluate(TreeNode* root) {
//	if (root == NULL)
//		return 0;
//	if (root->left == NULL && root->right == NULL)
//		return root->data;
//	else {
//		int op1 = evaluate(root->left);
//		int op2 = evaluate(root->right);
//		printf("%d %c %d�� ����մϴ�\n", op1, root->data, op2);
//		switch (root->data) {
//		case '+':
//			return op1 + op2;
//		case '-':
//			return op1 - op2;
//		case '*':
//			return op1 * op2;
//		case '/':
//			return op1 / op2;
//		}
//	}
//
//	return 0;
//}
//
//int main()
//{
//	printf("������ ���� %d�Դϴ�.\n", evaluate(exp));
//	return 0;
//}



//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�



//// ���丮 �뷮 ���
//
//typedef struct TreeNode {
//	int data;
//	struct TreeNode* left, * right;
//}TreeNode;
//
//TreeNode n1 = { 1, NULL, NULL };
//TreeNode n2 = { 4, &n1, NULL };
//TreeNode n3 = { 16, NULL, NULL };
//TreeNode n4 = { 25, NULL, NULL };
//TreeNode n5 = { 20, &n3, &n4 };
//TreeNode n6 = { 15, &n2, &n5 };
//TreeNode* root = &n6;
//
//int calc_dir_size(TreeNode* root) {
//	int left_size, right_size;
//	if (root == NULL) return 0;
//
//	left_size = calc_dir_size(root->left);
//	right_size = calc_dir_size(root->right);
//
//	return (root->data + left_size + right_size);
//}
//
//int main(void) {
//	printf("���丮�� ũ�� = %d\n", calc_dir_size(root));
//
//	return 0;
//}



//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�



//// ��� ����, �ܸ� ��� ����, ����
//
//typedef struct TreeNode {
//	int data;
//	struct TreeNode* left, * right;
//}TreeNode;
//
//TreeNode n1 = { 1, NULL, NULL };
//TreeNode n2 = { 4, &n1, NULL };
//TreeNode n3 = { 16, NULL, NULL };
//TreeNode n4 = { 25, NULL, NULL };
//TreeNode n5 = { 20, &n3, &n4 };
//TreeNode n6 = { 15, &n2, &n5 };
//TreeNode* root = &n6;
//
//// ��� ���� �Լ�
//int get_node_count(TreeNode* root) {
//	int count = 0;
//	if (root != NULL)
//		count = 1 + get_node_count(root->left) + get_node_count(root->right);
//
//	return count;
//}
//
//// �ܸ� ��� ���� �Լ�
//int get_leafnode_count(TreeNode* root) {
//	int count = 0;
//	if (root != NULL) {
//		if (root->left == NULL && root->right == NULL)
//			return 1;
//		else
//			count = get_leafnode_count(root->left) + get_leafnode_count(root->right);
//	}
//
//	return count;
//}
//
//// ���� ���ϴ� �Լ�
//
//int max(int a, int b) {
//	return (a > b) ? a : b;
//}
//
//
//int get_height(TreeNode* root) {
//	int height = 0;
//	if (root != NULL)
//		height = 1 + max(get_height(root->left), get_height(root->right));
//
//	return height;
//}
//
//int main()
//{
//	printf("����� ������ %d���̴�.\n", get_node_count(root));
//	printf("�ܸ������ ������ %d���̴�.\n", get_leafnode_count(root));
//	printf("Ʈ���� ���̴� %d�̴�.\n", get_height(root));
//
//	return 0;
//}



//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�



//// ������ ���� Ʈ�� ��ȸ ���α׷�
//
//#define TRUE 1
//#define FALSE 0
//
//typedef struct TreeNode {
//	int data;
//	struct TreeNode* left, * right;
//	int is_thread; // �������̸� TRUE
//}TreeNode;
//
//TreeNode n1 = { 'A', NULL, NULL, 1 };
//TreeNode n2 = { 'B', NULL, NULL, 1 };
//TreeNode n3 = { 'C', &n1, &n2, 0 };
//TreeNode n4 = { 'D', NULL, NULL, 1 };
//TreeNode n5 = { 'E', NULL, NULL, 0 };
//TreeNode n6 = { 'F', &n4, &n5, 0 };
//TreeNode n7 = { 'G', &n3, &n6, 0 };
//TreeNode* exp = &n7;
//
//TreeNode* find_successor(TreeNode* p) {
//	// q�� p�� ������ ������
//	TreeNode* q = p->right;
//	// ���� ������ �����Ͱ� NULL�̰ų� �������̸� ������ ����Ʈ�� ��ȯ
//	if (q == NULL || p->is_thread == TRUE)
//		return q;
//
//	// ���� ������ �ڽ��̸� �ٽ� ���� ���� ���� �̵�
//	while (q->left != NULL) q = q->left;
//	return q;
//}
//
//void thread_inorder(TreeNode* t) {
//	TreeNode* q;
//
//	q = t;
//	while (q->left)q = q->left; // ���� ���� ���� ����
//	do {
//		printf("%c -> ", q->data); // ������ ���
//		q = find_successor(q);  // �ļ��� �Լ� ȣ��
//	} while (q);
//}
//
//int main()
//{
//	// ������ ����
//	n1.right = &n3;
//	n2.right = &n7;
//	n4.right = &n6;
//	// ���� ��ȸ
//	thread_inorder(exp);
//	printf("\n");
//
//	return 0;
//}



//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�

#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;

TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL, 1 };
TreeNode n3 = { 'C', &n1, &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 };
TreeNode n6 = { 'F', &n4, &n5, 0 };
TreeNode n7 = { 'G', &n3, &n6, 0 };
TreeNode* exp = &n7;

TreeNode* success(TreeNode* p) {
	TreeNode* q = p->right;

	if (q == NULL || p->is_thread == TRUE)
		return q;
	while (q->left != NULL)
		q = q->left;
	return q;
}

void inorder(TreeNode* t) {
	TreeNode* q;
	q = t;

	while (q->left)
		q = q->left;
	do {
		printf("%c ", q->data);
		q = success(q);
	} while (q);
}

int main() {

	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;
	inorder(exp);

	return 0;
}