#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread; //스리드이면 TRUE
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
	//q는 p의 오른쪽 포인터
	TreeNode* q = p->right;
	//만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
	if (q == NULL || p->is_thread == TRUE)
		return q;

	//만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
	while (q->left != NULL) q = q->left;
	return q;
}

void thread_inorder(TreeNode* t)
{
	TreeNode* q;

	q = t;
	printf("1. 중위 순회 결과\n");
	while (q->left) q = q->left; //가장 왼쪽 노드로 간다.
	do {
		printf("%d ", q->data);
		q = find_successor(q);
	} while (q);
}

TreeNode* parent(TreeNode* root, TreeNode* child) {
	if (root == NULL || root == child) {
		return NULL; // 루트가 NULL이거나 찾는 노드가 루트인 경우 부모가 없음
	}

	if ((root->left == child) || (root->right == child)) {
		return root; // 루트의 왼쪽 노드 또는 오른쪽 노드가 찾는 노드인 경우 루트가 부모
	}

	TreeNode* left_parent = parent(root->left, child);
	if (left_parent != NULL) {
		return left_parent; // 왼쪽 서브트리에서 찾았으면 반환
	}

	return parent(root->right, child); // 오른쪽 서브트리에서 찾았거나 못 찾았으면 반환
}

int main(void)
{
	//스레드 설정
	n1.right = &n3;
	n2.right = &n5;
	n4.right = &n11;
	n6.right = &n10;
	n7.right = &n9;
	//중위 순회
	thread_inorder(exp);
	printf("\n\n");

	// 특정 노드의 부모 노드 찾기
	TreeNode* child_node_1 = &n1;
	TreeNode* parent_node_1 = parent(exp, child_node_1);
	if (parent_node_1 != NULL) {
		printf("2. Node %d의 부모: %d\n", child_node_1->data, parent_node_1->data);
	}
	
	TreeNode* child_node_2 = &n2;
	TreeNode* parent_node_2 = parent(exp, child_node_2);
	if (parent_node_2 != NULL) {
		printf("3. Node %d의 부모: %d\n", child_node_2->data, parent_node_2->data);
	}

	TreeNode* child_node_4 = &n4;
	TreeNode* parent_node_4 = parent(exp, child_node_4);
	if (parent_node_4 != NULL) {
		printf("4. Node %d의 부모: %d\n", child_node_4->data, parent_node_4->data);
	}

	printf("\n");


	return 0;
}