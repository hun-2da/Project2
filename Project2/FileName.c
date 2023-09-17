#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

/**��� ����ü*/
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

/**������ ������_�迭 ����*/
#define SIZE 100

int top = -1;
int top2 = -1;
TreeNode* stack[SIZE];
TreeNode* stack2[SIZE];
/**���ÿ� ��� ����*/
void push(TreeNode* p) {
	if (top < SIZE - 1) {
		stack[++top] = p;
	}
}
/**���ÿ��� ��带 ��*/
TreeNode* pop() {
	TreeNode* p = NULL;
	if (top >= 0) {
		p = stack[top--];
	}
	return p;
}
/**����2_ ������ȸ�� ���_ ���� ���*/
void push2(TreeNode* p) {
	if (top2 < SIZE - 1) {
		stack2[++top2] = p;
	}
}
/**���ÿ��� ��带 ��*/
TreeNode* pop2() {
	TreeNode* p = NULL;
	if (top2 >= 0) {
		p = stack2[top2--];
	}
	return p;
}
/**����*/
void inorder_iter(TreeNode* root) {
	while (1) {
		for (; root; root = root->left) {		//�ִ��� ���ʱ��� �̵�
			push(root);							//���� ��带 ���� ���� (��,��,�� ���̱� ������ ���ʳ�带 ���� ���� �� ������ Ȯ���� ����)
		}
		root = pop();							//���ʳ�带 �ҷ��� ����ϰ� ������ ���� �̵�
		if (!root) break;						//���̻� ���� ��尡 ���ٸ� ����
		printf("[%d]", root->data);
		root = root->right;
	}
}
/**����*/
void preorder_iter(TreeNode* root) {
	while (1) {
		for (; root; root = root->left) {		//�ִ��� ���ʳ�� ��ġ���� �̵�
			if (root->right) {
				push(root);						//������ �ڽ� ��尡 �ִ� ��쿡 ���ÿ� ����
			}
			printf("[%d]", root->data);
		}
		if (!root) {
			root = pop();						// root�� NULL�̸� ���ÿ� ����� ��带 ���� �� ���������� �̵�
			if (!root) break;					// ���̻� pop�� ��尡 ���ٸ� ����(������)
			root = root->right;
		}
	}
}
/**������*/
void postorder_iter(TreeNode* root) {
	while (1) {

		if (!root) {
			root = pop2();				//���ʿ� ���� �ִ±� Ȯ��(2��° stack���� pop)
			if (!root) { break; }		//2��° ������ null�̸� break;
			else root = root->left;		//null�� �ƴϸ� root�� �����̷� �̵�
		}
		if (root->left) {				//���� �������� �̵��� �� �ִٸ� 2��° stack�� push
			push2(root);
		}
		push(root);						//ù��° ���ÿ� push
		root = root->right;
	}
	while (1) {
		root = pop(root);				//1��° stack���� �ϳ��� �ҷ���
		if (!root)break;
		printf("[%d]", root->data);

	}

}

TreeNode n15 = { 11, NULL, NULL };
TreeNode n14 = { 10, NULL, NULL };
TreeNode n9 = { 5, NULL, NULL };
TreeNode n8 = { 4, NULL, NULL };
TreeNode n7 = { 9, &n14, &n15 };
TreeNode n6 = { 8, NULL, NULL };
TreeNode n5 = { 6, NULL, NULL };
TreeNode n4 = { 3, &n8, &n9 };
TreeNode n3 = { 7, &n6, &n7 };
TreeNode n2 = { 2, &n4, &n5 };
TreeNode n1 = { 1, &n2, &n3 };
/**���� Ʈ�������*/
TreeNode* root = &n1;

int main(void) {
	printf("���� ��ȸ");
	inorder_iter(root);
	printf("\n");
	printf("���� ��ȸ");
	preorder_iter(root);
	printf("\n");
	printf("���� ��ȸ");
	postorder_iter(root);
	printf("\n");

	return 0;
}
