#include "list_sort.h"
#include <stdlib.h>
#include <stdio.h>

void print_list(t_list *lst)
{
    printf("list:\n");
    while(lst != NULL)
    {
        printf("%i\n", lst->data);
        lst = lst->next;
    }
    printf("\n");
}

// returns anything BUT 0 if a and b are in right order
// returns 0 if a and b are NOT in right order
int	cmp(int a, int b)
{
	return (a <= b);
}

// Mine:
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *tmp_list = NULL;
    int temp_data;

    tmp_list = lst;
    while(lst->next)
    {
        if(cmp(lst->data, lst->next->data) == 0)
        {
            temp_data = lst->data;
            lst->data = lst->next->data;
            lst->next->data = temp_data;
            lst = tmp_list;
        }
        else
            lst = lst->next;
        // print_list(lst);
    }
    // lst = tmp_list;
    return(lst);
}

int main(void)
{
	t_list *lst;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = 4;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = 3;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = 6;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = 1;
	lst->next->next->next->next =  NULL;

    // lst = (t_list*)malloc(sizeof(t_list));
	// lst->data = 1;
	// lst->next = (t_list*)malloc(sizeof(t_list));
	// lst->next->data = 2;
	// lst->next->next = (t_list*)malloc(sizeof(t_list));
	// lst->next->next->data = 3;
	// lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	// lst->next->next->next->data = 4;
	// lst->next->next->next->next =  NULL;

    print_list(lst);
	sort_list(lst, cmp);
    print_list(lst);
	return (0);
}