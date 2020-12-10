#include <stdio.h>
#include <stdlib.h>

struct List{
    struct Node *first;
    struct Node *last;
};

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *constructNode(struct Node *next, struct Node *prev, int data){
    struct Node *node = malloc(sizeof(struct Node));
    node->next = next;
    node->prev = prev;
    node->data = data;

    return node;
}

struct List *constructList(struct Node *first, struct Node *last){
    struct List *list = malloc(sizeof(struct List));
    list->first = first;
    list->last = last;

    return list;
}


struct List* constructListN(size_t elements, int value) {
    struct List *List = malloc(sizeof(struct List));
    List->first = NULL;
    List->last = NULL;

    if (elements > 0) {
        struct Node *node = List->first = constructNode(NULL, NULL, value);

        for (int i = 1; i < elements; i++) {
            struct Node *temp = node;
            node = node->next = constructNode(NULL, temp, --value);
        }
    }
    return List;
}

void printList(struct List* l)
{
    struct Node *node = l->first;
    while(node != NULL){
        printf("%d\n", node->data);
        node = node->next;
    }
    printf("\n");
}

void pop_front(struct List* l)
{
    struct Node *node = l->first;
    if(l->first == l->last)
    {
        free(node);
        l->first = NULL;
        l->last = NULL;
        return;
    }
    struct Node *newFirst = node->next;
    free(node);
    l->first = newFirst;
    if(l->first == l->last)
    {
        l->first = newFirst;
        l->last = newFirst;
    }
}

int main()
{
    struct List *List = constructListN(4, 100);
    printList(List);
    pop_front(List);
    printList(List);
    return 0;
}
