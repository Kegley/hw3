#include <stdio.h>
#include <iostream>
#include <stack>

class binaryTree{
public:
	struct Node{
		int data;
		Node * left = NULL;
		Node * right = NULL;
	};

	Node * root;
	Node * tail = root;



	binaryTree(){
		root = new Node;
		root->data = 0;
		root->left = new Node;
		root->left->data = 1;
		root->right = new Node;
		root->right->data = 2;
		root->left->left = new Node;
		root->left->right = new Node;
		root->left->left->data = 3;
		root->left->right->data = 4;
		root->right->left = new Node;
		root->right->left->data = 5;

	}

	void preorder(){
		if (root != NULL){
			std::stack<Node*> s;
			s.push(root);


			while (!s.empty()){
				Node * n = s.top();
				s.pop();
				std::cout << n->data;
				if (n->right != NULL) s.push(n->right);
				if (n->left != NULL) s.push(n->left);


			}
		}
	}


	void inorder(){
		if (root != NULL){
			std::stack<Node*> s;
			s.push(root);
			Node * n = s.top();
			bool goRight = false;
			while (!s.empty()){

				while (n->left != NULL && !goRight){
					if (s.empty()) { break; }
					n = n->left;
					s.push(n);
				}

				std::cout << n->data;
				s.pop();

				if (n->right != NULL){
					s.push(n->right);
					n = s.top();
					goRight = false;
				}
				else{
					if (!s.empty()){ n = s.top(); }
					goRight = true;
				}
			}
		}
	}


	void postorder(){
		if (root != NULL){
			std::stack<Node*> s;
			s.push(root);
			std::stack<Node*> sideStack;

			while (!s.empty()){
				Node * n = s.top();
				s.pop();

				if (n->left != NULL) s.push(n->left);
				if (n->right != NULL) s.push(n->right);

				sideStack.push(n);

			}
			while (!sideStack.empty()){
				std::cout << sideStack.top()->data;
				sideStack.pop();
			}
		}
	}
};