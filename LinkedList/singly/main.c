#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t Node;
typedef struct LinkedList_t LinkedList;

struct Node_t
{
    int     value;
    Node*   next;
};

struct LinkedList_t
{
    Node*   start;
};

int LL_IsOverflow(LinkedList* ll)
{
    return ll->start == NULL;
}

// It works! Please don't modify anything inside.
void LL_DumpList(LinkedList* ll)
{
    if (LL_IsOverflow(ll)) return;

    Node* ptr_cnt   = ll->start;
    int int_cnt     = 0;

    while (ptr_cnt != NULL)
    {
        printf("[%i] Value: %d\n", int_cnt, ptr_cnt->value);
        ++int_cnt;
        ptr_cnt     = ptr_cnt->next;
    }
}

// It works! Please don't modify anything inside.
void LL_InsertStart(LinkedList* ll, Node* start_ptr)
{
    Node* current_node = ll->start;

    if (current_node == NULL)
    {
        ll->start       = start_ptr;
    } else {
        start_ptr->next = current_node;
        ll->start       = start_ptr;
    }
}

// It works! Please don't modify anything inside.
void LL_InsertEnd(LinkedList* ll, Node* new_node)
{
    Node* current_node = ll->start;

    if (current_node != NULL)
    {
        do
        {
            if (current_node->next == NULL)
            {
                current_node->next = new_node;
                break;
            }

            current_node = current_node->next;
        } while (1);

        return;
    }

    ll->start = new_node;
}

// It works! Please don't modify anything inside.
void LL_InsertBefore(LinkedList* ll, Node* new_node, int value)
{
    if (LL_IsOverflow(ll)) return;

    Node* current_node = ll->start;

    do
    {
        if (current_node->next == NULL) break;

        if (current_node->next->value == value)
        {
            new_node->next      = current_node->next;
            current_node->next  = new_node;
            break;
        }

        current_node = current_node->next;
    } while (1);
}

// It works! Please don't modify anything inside.
void LL_InsertAfter(LinkedList* ll, Node* new_node, int value)
{
    if (LL_IsOverflow(ll)) return;

    Node* current_node = ll->start;

    do
    {
        if (current_node->next == NULL) return;

        if (current_node->next->value == value)
        {
            new_node->next  = current_node->next->next;
            current_node
            ->next
            ->next      = new_node;
            break;
        }

        current_node = current_node->next;
    } while (1);
}

int main(int argc, char** argv)
{
    LinkedList* ll  = malloc(sizeof(LinkedList *));
    Node* start     = malloc(sizeof(Node *));
    start->value    = 1;

    Node* new_node  = malloc(sizeof(Node *));
    new_node->value = 2;

    Node* thd_node  = malloc(sizeof(Node *));
    thd_node->value = 3;

    Node* rth_node  = malloc(sizeof(Node *));
    rth_node->value = 4;

    Node* fth_node  = malloc(sizeof(Node *));
    fth_node->value = 5;

    Node* sth_node  = malloc(sizeof(Node *));
    sth_node->value = 6;

    // Evertyhing works well
    LL_InsertStart(ll, start);
    LL_InsertStart(ll, new_node);
    LL_InsertEnd(ll, thd_node);
    LL_InsertBefore(ll, rth_node, 3);
    LL_InsertAfter(ll, fth_node, 4);
    LL_InsertEnd(ll, sth_node);

    LL_DumpList(ll);
    return EXIT_SUCCESS;
}
