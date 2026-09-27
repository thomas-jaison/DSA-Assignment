#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data[20];
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char data[])
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, char data[])
{
    if (root == NULL)
        return createNode(data);

    if (strcmp(data, root->data) < 0)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

/* BST Search */
int bstSearch(struct Node *root, char key[], int *count)
{
    while (root != NULL)
    {
        (*count)++;

        if (strcmp(key, root->data) == 0)
            return 1;

        if (strcmp(key, root->data) < 0)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

/* Linear Search */
int linearSearch(char id[][20], int n, char key[], int *count)
{
    int i;

    for (i = 0; i < n; i++)
    {
        (*count)++;

        if (strcmp(id[i], key) == 0)
            return 1;
    }

    return 0;
}

int main()
{
    struct Node *root = NULL;

    char id[][20] = {
        "A102", "A25", "A7", "B100",
        "B12", "A120", "B3", "A45"
    };

    char key[20];

    int i;
    int bstCount = 0;
    int linearCount = 0;

    for (i = 0; i < 8; i++)
    {
        root = insert(root, id[i]);
    }

    printf("Enter ID to search: ");
    scanf("%s", key);

    if (bstSearch(root, key, &bstCount))
        printf("\nBST Search: Found");
    else
        printf("\nBST Search: Not Found");

    if (linearSearch(id, 8, key, &linearCount))
        printf("\nLinear Search: Found");
    else
        printf("\nLinear Search: Not Found");

    printf("\n\nBST Comparisons = %d", bstCount);
    printf("\nLinear Search Comparisons = %d", linearCount);

    return 0;
}