#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* create(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node* insert(node* root) {
    int data;
    printf("Enter data for the node (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    root = create(data);

    printf("\nEnter left child of %d:\n", data);
    root->left = insert(root->left);

    printf("\nEnter right child of %d:\n", data);
    root->right = insert(root->right);

    return root;
}

void getChildren(node* parent) {
    if (parent == NULL) {
        printf("Parent node is NULL.\n");
        return;
    }

    int leftChild;
    if(parent->left!=NULL){
        leftChild=parent->left->data;
    }
    else{
        leftChild=-1;
    }
    int rightChild;
    if(parent->right!=NULL){
        rightChild=parent->right->data;
    }
    else{
        rightChild=-1;
    }

    printf("Parent Node: %d\n", parent->data);
    printf("Left Child: %d\n", leftChild);
    printf("Right Child: %d\n", rightChild);
}

void print(node* root, int space) {
    if (root == NULL) {
        return;
    }

    int indent = 5;  // Space indentation for tree structure
    space += indent;

    print(root->right, space);

    printf("\n");
    for (int i = indent; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    print(root->left, space);
}

int main() {
    node* root = NULL;
    root = insert(root);

    printf("\nTree Structure:\n");
    print(root, 0);

    printf("\nGetting children of root:\n");
    getChildren(root);

    printf("\nGetting children of root's left child:\n");
    getChildren(root->left->left);

    printf("\nGetting children of root's right child:\n");
    getChildren(root->right);

    return 0;
}
