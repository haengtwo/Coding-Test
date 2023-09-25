#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread; //�������̸� TRUE
}TreeNode;

TreeNode n1 = { 4, NULL, NULL, 1 };
TreeNode n2 = { 5, NULL, NULL, 1 };
TreeNode n3 = { 3, &n1, &n2, 0 };
TreeNode n4 = { 6, NULL, NULL, 1 };
TreeNode n5 = { 2, &n3, &n4, 0 };
TreeNode n6 = { 8, NULL, NULL, 1 };
TreeNode n7 = { 10, NULL, NULL, 1 };
TreeNode n8 = { 11, NULL, NULL, 0 };
TreeNode n9 = { 9, &n7, &n8, 0 };
TreeNode n10 = { 7, &n6, &n9, 0 };
TreeNode n11 = { 1, &n5, &n10, 0 };
TreeNode* exp = &n11;

TreeNode* find_successor(TreeNode* p)
{
	//q�� p�� ������ ������
	TreeNode* q = p->right;
	//���� ������ �����Ͱ� NULL�̰ų� �������̸� ������ �����͸� ��ȯ
	if (q == NULL || p->is_thread == TRUE)
		return q;

	//���� ������ �ڽ��̸� �ٽ� ���� ���� ���� �̵�
	while (q->left != NULL) q = q->left;
	return q;
}

void thread_inorder(TreeNode* t)
{
	TreeNode* q;

	q = t;
	printf("1. ���� ��ȸ ���\n");
	while (q->left) q = q->left; //���� ���� ���� ����.
	do {
		printf("%d ", q->data);
		q = find_successor(q);
	} while (q);
}

TreeNode* parent(TreeNode* root, TreeNode* child) {
	if (root == NULL || root == child) {
		return NULL; // ��Ʈ�� NULL�̰ų� ã�� ��尡 ��Ʈ�� ��� �θ� ����
	}

	if ((root->left == child) || (root->right == child)) {
		return root; // ��Ʈ�� ���� ��� �Ǵ� ������ ��尡 ã�� ����� ��� ��Ʈ�� �θ�
	}

	TreeNode* left_parent = parent(root->left, child);
	if (left_parent != NULL) {
		return left_parent; // ���� ����Ʈ������ ã������ ��ȯ
	}

	return parent(root->right, child); // ������ ����Ʈ������ ã�Ұų� �� ã������ ��ȯ
}

int main(void)
{
	//������ ����
	n1.right = &n3;
	n2.right = &n5;
	n4.right = &n11;
	n6.right = &n10;
	n7.right = &n9;
	//���� ��ȸ
	thread_inorder(exp);
	printf("\n\n");

	// Ư�� ����� �θ� ��� ã��
	TreeNode* child_node_1 = &n1;
	TreeNode* parent_node_1 = parent(exp, child_node_1);
	if (parent_node_1 != NULL) {
		printf("2. Node %d�� �θ�: %d\n", child_node_1->data, parent_node_1->data);
	}
	
	TreeNode* child_node_2 = &n2;
	TreeNode* parent_node_2 = parent(exp, child_node_2);
	if (parent_node_2 != NULL) {
		printf("3. Node %d�� �θ�: %d\n", child_node_2->data, parent_node_2->data);
	}

	TreeNode* child_node_4 = &n4;
	TreeNode* parent_node_4 = parent(exp, child_node_4);
	if (parent_node_4 != NULL) {
		printf("4. Node %d�� �θ�: %d\n", child_node_4->data, parent_node_4->data);
	}

	printf("\n");


	return 0;
}