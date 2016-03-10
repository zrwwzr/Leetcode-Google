class AVLTree{
private:
	struct AVLTreeNode {
		int val, height;
		AVLTreeNode *left;
		AVLTreeNode *right;
		AVLTreeNode(int x) : val(x), left(NULL), right(NULL), height(1) {}
	};

	AVLTreeNode *root;

	int height(AVLTreeNode *root){
		return root ? root->height : 0;
	}
	int getBalance(AVLTreeNode *root){
		return root ? height(root->left) - height(root->right) : 0;
	}
	AVLTreeNode* rotateRight(AVLTreeNode *root){
		AVLTreeNode* left = root->left, *right = root;
		root->left = left->right;
		left->right = root;
		root = left;
		root->height = max(height(root->left), height(root->right)) + 1;
		right->height = max(height(right->left), height(root->right)) + 1;
		return root;
	}
	AVLTreeNode* rotateLeft(AVLTreeNode *root){
		AVLTreeNode* left = root, *right = root->right;
		root->right = right->left;
		right->left = root;
		root = right;
		root->height = max(height(root->left), height(root->right)) + 1;
		left->height = max(height(left->left), height(left->right)) + 1;
		return root;
	}
	AVLTreeNode *findMinNode(AVLTreeNode *root){
		AVLTreeNode *pre = NULL;
		while(root){
			pre = root;
			root = root->left;
		}
		return pre;
	}
	AVLTreeNode* insert(AVLTreeNode *root, int val){
		//STEP 1: Standard BST node insertion
		if(!root) return new AVLTreeNode(val);
		if(val < root->val) root->left = insert(root->left, val);
		else root->right = insert(root->right, val);
		//STEP 2: Update root height
		root->height = max(height(root->left), height(root->right)) + 1;
		//STEP 3: Get balance factor
		int balance = getBalance(root);
		//STEP 4: If unbalanced, re-balance it for the following 4 cases
		//Case 1: Left Left
		if(balance > 1 && val < root->left->val)
			return rotateRight(root);
		//Case 2: Left Right
		else if(balance > 1 && val > root->left->val){
			root->left = rotateLeft(root->left);
			return rotateRight(root);
		}
		//Case 3: Right Right
		else if(balance < -1 && val > root->right->val)
			return rotateLeft(root);
		//Case 4L Right Left
		else if(balance < -1 && val < root->right->val){
			root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
		return root;
	}
	AVLTreeNode* remove(AVLTreeNode *root, int val){
		if(!root) return root;
		if(val < root->val) root->left = remove(root->left, val);
		else if(val > root->val) root->right = remove(root->right, val);
		else{
			if(!root->left || !root->right){
				AVLTreeNode *temp = root->left ? root->left : root->right;
				root = temp;
			}else{
				AVLTreeNode *temp = findMinNode(root->right);
				root->val = temp->val;
				root->right = remove(root->right, temp->val);
			}
		}
		if(!root) return root;
		//update root height
		root->height = max(height(root->left), height(root->right)) + 1;
		//get the balance factor
		int balance = getBalance(root);
		if(balance > 1 && getBalance(root->left) >= 0)
			return rotateRight(root);
		else if(balance > 1 && getBalance(root->left) < 0){
			root->left = rotateLeft(root->left);
			return rotateRight(root);
		}else if(balance < -1 && getBalance(root->right) <= 0)
			return rotateLeft(root);
		else if(balance < -1 && getBalance(root->right) > 0){
			root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
		return root;
	}
	void inorder(AVLTreeNode *root){
		if(!root) return;
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
public: 
	AVLTree(){
		root = NULL;
	}
	void insert(int val){
		root = insert(root, val);
	}
	void remove(int val){
		root = remove(root, val);
	}
	void inorder(){
		inorder(root);
		cout<<endl;
	}
};

int main(){
	AVLTree avltree;
	int arr[] = {9, 5, 10, 0, 6, 11, -1, 1, 2};
	for(int i = 0; i < sizeof(arr) / sizeof(int); ++i){
		avltree.insert(arr[i]);
	}
	avltree.inorder();
	avltree.remove(0);
	avltree.inorder();
	return 0;
}
