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

/*
	compare first char of data to first char of data_ref
	(just for testing)
*/
int	cmp(void *data, void *data_ref)
{
	if (*(char *)data == *(char *)data_ref)
		return (0);
	return (1);
}

int	cmp(void *dat_one, void *dat_two)
{
	int *i = dat_one;
	int *j = dat_two;

	if (*i == *j)
		return(0);
	return(1);
}

// void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
// {
// 	t_list	*current, *temp, *old;

// 	current = *begin_list;
// 	old = NULL;
// 	while (current)
// 	{
// 		if (!(cmp(data_ref, current->data)))
// 		{
// 			temp = current;
// 			if (!old)
// 				*begin_list = (*begin_list)->next;
// 			else
// 				old->next = current->next;
// 			current = current->next;
// 			free(temp);
// 		}
// 		else
// 		{
// 			old = current;
// 			current = current->next;
// 		}
// 	}
// }

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;
	t_list *temp;

	current = *begin_list;
	while(current && cmp((current)->data, data_ref) == 0)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*begin_list = current;
	while(current && current->next)
	{
		if (cmp(current->next->data, data_ref) == 0)
		{
			temp = current->next->next;
			free(current->next);
			current->next = temp;
		}
		current = current->next;
	}
}

int main(void)
{
	t_list *lst;
	int i = 4;
	int j = 2;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = &i;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = &i;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = &j;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = &i;
	lst->next->next->next->next =  NULL;

    print_list(lst);
	ft_list_remove_if(&lst, &j, cmp);
    print_list(lst);
	// system("leaks --quiet a.out");
	return (0);
}