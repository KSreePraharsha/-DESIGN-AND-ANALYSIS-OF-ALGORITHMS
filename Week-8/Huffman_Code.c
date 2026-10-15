
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char ch;
    int frequency;
    struct Node *left, *right;
};

struct Node *newNode(char ch, int frequency)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->ch = ch;
    temp->frequency = frequency;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void swap(struct Node **a, struct Node **b)
{
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct Node *heap[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n &&
        heap[left]->frequency < heap[smallest]->frequency)
        smallest = left;

    if (right < n &&
        heap[right]->frequency < heap[smallest]->frequency)
        smallest = right;

    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

struct Node *extractMin(struct Node *heap[], int *n)
{
    struct Node *temp = heap[0];

    heap[0] = heap[*n - 1];
    (*n)--;

    if (*n > 0)
        minHeapify(heap, *n, 0);

    return temp;
}

void insert(struct Node *heap[], int *n, struct Node *temp)
{
    int i = *n;
    heap[i] = temp;
    (*n)++;

    while (i > 0 &&
           heap[(i - 1) / 2]->frequency > heap[i]->frequency)
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printCodes(struct Node *root, int code[], int top)
{
    if (root->left != NULL)
    {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right != NULL)
    {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if (root->left == NULL && root->right == NULL)
    {
        printf("%c: ", root->ch);

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
    }
}

int main()
{
    int n, i;
    char ch[50];
    int frequency[50];
    int code[50];

    struct Node *heap[100];

    printf("Enter number of characters: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter character and frequency: ");
        scanf(" %c %d", &ch[i], &frequency[i]);

        heap[i] = newNode(ch[i], frequency[i]);
    }

    int size = n;

    for (i = size / 2 - 1; i >= 0; i--)
        minHeapify(heap, size, i);

    while (size > 1)
    {
        struct Node *left = extractMin(heap, &size);
        struct Node *right = extractMin(heap, &size);

        struct Node *temp = newNode(
            '$', left->frequency + right->frequency);

        temp->left = left;
        temp->right = right;

        insert(heap, &size, temp);
    }

    printf("\nHuffman Codes:\n");
    printCodes(heap[0], code, 0);

    return 0;
}
