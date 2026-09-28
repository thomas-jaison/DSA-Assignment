#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char id[20];
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char id[])
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->id, id);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, char id[])
{
    if (root == NULL)
        return createNode(id);

    if (strcmp(id, root->id) < 0)
        root->left = insert(root->left, id);
    else
        root->right = insert(root->right, id);

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->id);
        inorder(root->right);
    }
}

int bstSearch(struct Node *root, char key[], int *comparisons)
{
    while (root != NULL)
    {
        (*comparisons)++;

        if (strcmp(key, root->id) == 0)
            return 1;

        if (strcmp(key, root->id) < 0)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

int linearSearch(char arr[][20], int n, char key[], int *comparisons)
{
    for (int i = 0; i < n; i++)
    {
        (*comparisons)++;

        if (strcmp(arr[i], key) == 0)
            return 1;
    }

    return 0;
}

int main()
{
    char ids[][20] =
    {
        "A102", "A25", "A7", "B100",
        "B12", "A120", "B3", "A45"
    };

    int n = 8;

    struct Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, ids[i]);
    }

    printf("Inorder Traversal:\n");
    inorder(root);

    printf("\n\n");

    char keys[][20] = {"A45", "B3", "A50"};

    for (int i = 0; i < 3; i++)
    {
        int bstComp = 0;
        int linearComp = 0;

        int bstResult =
            bstSearch(root, keys[i], &bstComp);

        int linearResult =
            linearSearch(ids, n, keys[i], &linearComp);

        printf("Search: %s\n", keys[i]);

        printf("BST Search: %s, Comparisons = %d\n",
               bstResult ? "Found" : "Not Found",
               bstComp);

        printf("Linear Search: %s, Comparisons = %d\n\n",
               linearResult ? "Found" : "Not Found",
               linearComp);
    }

    return 0;
}
