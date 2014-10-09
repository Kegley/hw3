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
		//root->left->right = new Node;
		root->left->left->data = 3;
		//root->left->right->data = 4;
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
			int i = 0;
			while (!s.empty()){
				
				while (n->left != NULL){
					if (s.empty()) { break; }
					//std::cout << "GOING LEFT" << std::endl;
					n = n->left;
					s.push(n);
				}

				if (!s.empty()){ s.pop(); }
				
				std::cout << n->data;
				if (!s.empty()){
					n = s.top();
				}
				std::cout << n->data;

				if (!s.empty()){ s.pop(); }

				if (n->right != NULL){
					//std::cout << "GOING RIGHT" << std::endl;
					n = n->right;
					s.push(n);
				}

				i++;
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