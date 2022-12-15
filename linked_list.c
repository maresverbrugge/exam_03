#include "list_sort.h"
#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

// iterating over a list:
void print_list(t_list *list)
    {
        t_list *current = list;

        printf("list:\n");
        while (current != NULL)
        {
            printf("%d\n", current->data);
            current = current->next;
        }
        printf("\n");
    }

// add element to end of list:
void push_to_end(t_list *list, int data)
{
    // set pointer for current element
    t_list *current = list;
    // move to end of list
    while (current->next != NULL)
        current = current->next;
    // add new element/node
    current->next = malloc(sizeof(t_list));
    // set data of new element/node
    current->next->data = data;
    current->next->next = NULL;
}

// add element to beginning of list:
void push_to_begin(t_list **list, int n)
{
    // create new item
    t_list *new_elem = malloc(sizeof(t_list));
    // set data of element/node
    new_elem->data = n;
    // link new element to point to the head of the list
    new_elem->next = *list;
    // set head of list to be new element
    *list = new_elem;
}

// remove first element of the list:
void pop_from_begin(t_list **list)
{
    // take next item that heads point to and save it
    t_list *next_elem = NULL;
    next_elem = (*list)->next;
    // free head item of list
    free(*list);
    // set head of list to be next element
    *list = next_elem;
}

// remove last element of the list:
void pop_from_end(t_list *list)
{
    // if there's only 1 element in the list, remove it:
    if (list->next == NULL)
    {
        free(list);
        return ;
    }
    // go to the second-to-last element:
    t_list *current = list;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    // current points to second-to-last element, so remove current->next = last element
    free(current->next);
    current->next = NULL;
    return ;
}

// remove specific element of the list:
void remove_by_index(t_list **list, int index)
{
    int i = 0;
    t_list *current = *list;
    t_list *temp_elem = NULL;

    if (index == 0)
        pop_from_begin(list);
    // set current to element right before indexed element we want to remove
    while (i < index - 1)
    {
        if (current->next == NULL)
            return ;
        current = current->next;
        i++;
    }
    // save element we want to remove in temp pointer
    temp_elem = current->next;
    // set previous node's next pointer to point to the node after the node we wish to delete
    current->next = temp_elem->next;
    // free temp element
    free(temp_elem);
    return ;
}

void remove_by_value(t_list **list, int value)
{
    t_list *current = *list;
    t_list *temp_elem = NULL;

    // set current to element right before indexed element we want to remove
    while (current->next != NULL)
    {
        if (current->next->data == value)
            break ;
        current = current->next;
    }
    // save element we want to remove in temp pointer
    temp_elem = current->next;
    // set previous node's next pointer to point to the node after the node we wish to delete
    current->next = temp_elem->next;
    // free temp element
    free(temp_elem);
}

int main(void)
{
    // create first element of list:
    t_list *list = malloc(sizeof(t_list));
    if (list == NULL)
        return (-1);
    list->data = 1;
    list->next = NULL;

    print_list(list);
    push_to_end(list, 2);
    print_list(list);
    push_to_begin(&list, 5);
    push_to_begin(&list, 6);
    push_to_begin(&list, 9);
    push_to_begin(&list, 14);
    push_to_begin(&list, 81);
    push_to_begin(&list, 7);
    print_list(list);
    pop_from_begin(&list);
    print_list(list);
    pop_from_end(list);
    print_list(list);
    remove_by_index(&list, 2);
    print_list(list);
    remove_by_value(&list, 14);
    print_list(list);
    return (0);
}