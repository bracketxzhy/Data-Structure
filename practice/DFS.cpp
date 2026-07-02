#include <iostream>
#include <queue>
using namespace std;
struct node{
	int value;
	node* left;
	node* right;
	
	node(int v){
		value = v;
		left = nullptr;
		right = nullptr;
	}
};
void preorder(node* root){
	if(root == nullptr){
		return;
	}
	cout<<root -> value<<" ";
	preorder(root -> left);
	preorder(root -> right);
}
void inorder(node* root){
	if(root == nullptr){
		return;
	}
	inorder(root -> left);
	cout<<root -> value<<" ";
	inorder(root -> right);
}
void postorder(node* root){
	if(root == nullptr){
		return;
	}
	postorder(root -> left);
	postorder(root -> right);
	cout<<root -> value<<" ";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	return 0;
}
