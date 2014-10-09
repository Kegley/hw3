
#include "binaryTree.h"

using namespace std;

int main(){
	binaryTree  bt = binaryTree();

	bt.preorder();
	cout << endl;
	bt.inorder();
	cout << endl;
	bt.postorder();

	return 0;
}