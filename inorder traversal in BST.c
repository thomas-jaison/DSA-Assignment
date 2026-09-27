#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char key[20];
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char key[])
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->key, key);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, char key[])
{
    if (root == NULL)
        return createNode(key);

    if (strcmp(key, root->key) < 0)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->key);
        inorder(root->right);
    }
}

int main()
{
    char ids[][20] = {
        "A102", "A25", "A7", "B100",
        "B12", "A120", "B3", "A45"
    };

    struct Node *root = NULL;
    int i;

    for (i = 0; i < 8; i++)
        root = insert(root, ids[i]);

    printf("Inorder Traversal:\n");
    inorder(root);

    return 0;
}