#include "list_remove_if.h"
#include <stdlib.h>
#include <stdio.h>

void print_list(t_list *lst)
{
    printf("list:\n");
    while(lst != NULL)
    {
        printf("%i\n", *(int*)lst->data);
        lst = lst->next;
    }
    printf("\n");
}

int	cmp(void *data, void *data_ref)
{
	int *i = data;
	int *j = data_ref;

	if (*i == *j)
		return(0);
	return(1);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;
	t_list *temp;

	current = *begin_list;
	while(current->next != NULL)
	{
		if (cmp(current->next->data, data_ref) == 0)
            break ;
        current = current->next;
	}
	temp = current->next;
	current->next = temp->next;
	free(temp);
}

int main(void)
{
	t_list *lst;
	int i = 4;
	int j = 2;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = &i;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = &j;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = &i;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = &j;
	lst->next->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->next->data = &i;
	lst->next->next->next->next->next =  NULL;

    print_list(lst);
	ft_list_remove_if(&lst, &j, cmp);
    print_list(lst);
	// system("leaks --quiet a.out");
	return (0);
}