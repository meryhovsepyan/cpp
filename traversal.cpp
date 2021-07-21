#include <iostream>
#include <cstdio>
#include <queue> 
struct Node{
	int m_data;
	struct Node* m_left;
	struct Node* m_right;
	Node(int data)	{
		this->m_data = data;
		m_left = m_right = NULL;
	}
};
void Postorder(struct Node* node){
	if (node == NULL){
		return;
	}
	Postorder(node->m_left);
	Postorder(node->m_right);
	printf("%d",node->m_data);
}
void Inorder(struct Node* node)
{
	if (node == NULL){
		return;
	}
	Inorder(node->m_left);
	printf("%d",node->m_data);
	Inorder(node->m_right);
}
void Preorder(struct Node* node){
	if (node == NULL){
		return;
	}
	printf("%d",node->m_data);
	Preorder(node->m_left);
	Preorder(node->m_right);
}
void LevelOrder(struct Node *node){
	if (node == NULL){  
		return;
	}
	std::queue<Node*> q;
        q.push(node);
        while (!q.empty()){
		const Node *const tmp = q.front();
		q.pop();
       		printf("%d",tmp->m_data);
       		if (tmp->m_left)
            		q.push(tmp->m_left);
       		if (tmp->m_right)
            		q.push(tmp->m_right);
    	}
}
int main(){
	struct Node *root = new Node(1);
	root->m_left = new Node(2);
	root->m_right = new Node(3);
	root->m_left->m_left = new Node(4);
	root->m_left->m_right = new Node(5);
	std::cout << " Preorder traversal- ";
	Preorder(root);
	
	std::cout << " Inorder traversal- ";
	Inorder(root);

	std::cout << " Postorder traversal- ";
	Postorder(root);
	std::cout<<" Levelorder traversal- ";
	LevelOrder(root);

	return 0;
}

