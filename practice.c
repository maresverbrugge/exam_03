#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void print_list(t_list *lst)
{
    printf("list\n");
    while(lst != NULL)
    {
        printf("%i\n", lst->data);
        lst = lst->next;
    }
    printf("\n");
}

int	cmp(int a, int b)
{
	return (a <= b);
}

int is_sorted(t_list *lst)
{
    while(lst)
    {
        if (lst->data > lst->next->data)
            return(0);
        lst = lst->next;
    }
    return (1);
}

// t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
// {
//     t_list *tmp;
//     int copy;

//     while(!(is_sorted(lst)))
//     {
//         tmp = lst;
//         while(tmp->next != NULL)
//         {
//             if(cmp(tmp->data, tmp->next->data) == 0)
//             {
//                 copy = tmp->data;
//                 tmp->data = tmp->next->data;
//                 tmp->next->data = copy;
//             }
//             else
//                 tmp = tmp->next;
//         }
//     }
//     return(tmp);
// }

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *tmp;
    int copy;

    tmp = lst;
    while(lst->next)
    {
        if(((*cmp)(lst->data, lst->next->data)) == 0)
        {
            copy = lst->data;
            lst->data = lst->next->data;
            lst->next->data = copy;
            lst = tmp;
        }
        else
            lst = lst->next;
    }
    lst = tmp;
    return(tmp);
}

int main(void)
{
	t_list *lst;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = 4;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = 3;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = 2;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = 1;
	lst->next->next->next->next =  NULL;

    print_list(lst);
	sort_list(lst, cmp);
    print_list(lst);
	return (0);
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
