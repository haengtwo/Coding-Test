#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

////전위, 중위, 후위 순회
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
//	printf("중위 순회 : ");
//	inorder(root);
//
//	return 0;
//}
//
//
//
//// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ



//// push, pop 스택
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
//	printf("중위 순회 = ");
//	inorder_iter(root);
//	printf("\n");
//
//	return 0;
//}



//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ


//// 수식 연산
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
//// 수식 계산 함수
//int evaluate(TreeNode* root) {
//	if (root == NULL)
//		return 0;
//	if (root->left == NULL && root->right == NULL)
//		return root->data;
//	else {
//		int op1 = evaluate(root->left);
//		int op2 = evaluate(root->right);
//		printf("%d %c %d을 계산합니다\n", op1, root->data, op2);
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
//	printf("수식의 값은 %d입니다.\n", evaluate(exp));
//	return 0;
//}



//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ



//// 디렉토리 용량 계산
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
//	printf("디렉토리의 크기 = %d\n", calc_dir_size(root));
//
//	return 0;
//}



//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ



//// 노드 개수, 단말 노드 개수, 높이
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
//// 노드 개수 함수
//int get_node_count(TreeNode* root) {
//	int count = 0;
//	if (root != NULL)
//		count = 1 + get_node_count(root->left) + get_node_count(root->right);
//
//	return count;
//}
//
//// 단말 노드 개수 함수
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
//// 높이 구하는 함수
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
//	printf("노드의 개수는 %d개이다.\n", get_node_count(root));
//	printf("단말노드의 개수는 %d개이다.\n", get_leafnode_count(root));
//	printf("트리의 높이는 %d이다.\n", get_height(root));
//
//	return 0;
//}



//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ



//// 스레드 이진 트리 순회 프로그램
//
//#define TRUE 1
//#define FALSE 0
//
//typedef struct TreeNode {
//	int data;
//	struct TreeNode* left, * right;
//	int is_thread; // 스레드이면 TRUE
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
//	// q는 p의 오른쪽 포인터
//	TreeNode* q = p->right;
//	// 만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인트를 반환
//	if (q == NULL || p->is_thread == TRUE)
//		return q;
//
//	// 만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
//	while (q->left != NULL) q = q->left;
//	return q;
//}
//
//void thread_inorder(TreeNode* t) {
//	TreeNode* q;
//
//	q = t;
//	while (q->left)q = q->left; // 가장 왼쪽 노드로 간다
//	do {
//		printf("%c -> ", q->data); // 데이터 출력
//		q = find_successor(q);  // 후속자 함수 호출
//	} while (q);
//}
//
//int main()
//{
//	// 스레드 설정
//	n1.right = &n3;
//	n2.right = &n7;
//	n4.right = &n6;
//	// 중위 순회
//	thread_inorder(exp);
//	printf("\n");
//
//	return 0;
//}



//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

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