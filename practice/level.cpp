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
void levelorder(node* root){
	if(root == nullptr){
		return;
	}
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* current = q.front();
		cout<<current -> value<<" ";
		q.pop();
		if(! (current->left == nullptr)){
			q.push(current->left);
		}
		if(! (current->right == nullptr)){
			q.push(current->right);
		}
	}
}
int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	levelorder(root);
	cout << endl;
	return 0;
}
