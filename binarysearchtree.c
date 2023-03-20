#include <stdio.h>
#include <stdlib.h>

struct node {
  	int key;
  	struct node *left;
	struct node *right;
};
struct node *root;

void inorder( struct node *);
void preorder(struct node *);
void postorder(struct node *);
struct node *newnode(int);
struct node *insert(struct node *, int);
struct node *minvaluenode(struct node *);
void maxvaluenode(struct node *);
struct node *deletenode(struct node *, int);
int height(struct node*);
void levelorder(struct node*);
struct node *search(struct node *, int);
// Driver code
int main() 
{
    struct node *root = NULL;
    int ch;
	int res;
	int val;
    while (1) {
		printf("\nSELECT OPTION\n");
		printf("\n1.INSERT\n2.IN ORDER\n3.PRE ORDER\n4.POST ORDER\n5.LEVEL ORDEER\n6.DELETE NODE\n7.MIN VALUE\n8.MAX VALUE\n9.HEIGHT\n10.SEARCH\n11.EXIT\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1:
                printf("\nEnter data:\n");
                scanf("%d", &val);
                root = insert(root, val);
				break;
			case 2:
				printf("\nINORDER TRAVERSAL:-\n");
				inorder(root);
				break;
			case 3:
				printf("\nPRE ORDER TRAVERSAL:-\n");
				preorder(root);
				break;	
			case 4:
				printf("\nPOST ORDER TRAVERSAL:-\n");
				postorder(root);
				break;
			case 5:
				printf("\nLEVEL ORDER TRAVERSAL:-\n");
				levelorder(root);
				break;
			case 6:
				printf("\nEnter the node to delete:\n");
				scanf("%d", &val);
				root = deletenode(root, val);
				break;
			case 7:
				minvaluenode(root);
				break;
			case 8:
				maxvaluenode(root);
				break;
			case 9:
				res = height(root);
				printf("\nHeight of tree: %d\n", res);
				break;
			case 10:
				printf("\nEnter value to search\n");
				scanf("%d", &val);
				if ( search(root, val) == NULL) {
					printf("\nDoesn't Exist!\n");
				} else {
					printf("\nExist in tree!\n");
				}
				break;
			case 11:
				exit(1);
				break;
			default:
				printf("\nEnter valid option!\n");
			}
	}
    return 0;
}

// Create a node
struct node *newnode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Inorder Traversal
void inorder(struct node *root)
{
    if (root != NULL) {
    inorder(root->left);
    printf(" %d -> ", root->key);
    inorder(root->right);
  	}
}

// preorder Traversal
void preorder(struct node *root)
{
    if (root != NULL) {
	printf(" %d -> ", root->key);
    preorder(root->left);
    preorder(root->right);
   }
}

// postorder Traversal
void postorder(struct node *root)
{
    if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
	printf(" %d -> ", root->key);
    }
}

// Insert a node
struct node *insert(struct node *node, int key)
{
    // Return a new node if the tree is empty
    if (node == NULL) {
		return newnode(key);
	}
    if (key < node->key) {
        node->left = insert(node->left, key);
     } else {
    	node->right = insert(node->right, key);
  	}
    return node;
}

struct node *search(struct node *root, int key)
{
	if (root == NULL) {
		return NULL;
	}
	if (root->key == key) {
		return root;
	}
	if (key < root->key) {
		return search(root->left, key);
	}
	return search(root->right, key);
}
struct node *minvaluenode(struct node *node)  
{
    struct node *current = node;
    // Find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
	}
	printf("\nMin value node = %d\n", current->key);
    return current;
}

void maxvaluenode(struct node *node)
{
	struct node *current = node;
	//find the rightmost leaf
	while (current && current->right != NULL) {
		current = current->right;
	}
	printf("\nMax value node = %d\n", current->key);
}
// Deleting a node
struct node *deletenode(struct node *root, int key)  
{
    // Return if the tree is empty
    if (root == NULL) {
		return root;
	}
    // Find the node to be deleted
    if (key < root->key) {
    	root->left = deletenode(root->left, key);
	} else if (key > root->key) {
    	root->right = deletenode(root->right, key);
	} else {
    	// If the node is with only one child or no child
    	if (root->left == NULL) {
      		struct node *temp = root->right;
      		free(root);
    		return temp;
    	} else if (root->right == NULL) {
      		struct node *temp = root->left;
      		free(root);
      		return temp;
    	}
    	// If the node has two children
    	struct node *temp = minvaluenode(root->right);
    	// Place the inorder successor in position of the node to be deleted
    	root->key = temp->key;
    	// Delete the inorder successor
    	root->right = deletenode(root->right, temp->key);
    }
    return root;
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf(" %d-> ", root->key);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void levelorder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
