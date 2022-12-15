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

// Thirza's:
// t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
// {
//     t_list *tmp;
//     int copy;

//     tmp = lst;
//     while(lst->next)
//     {
//         if(((*cmp)(lst->data, lst->next->data)) == 0)
//         {
//             copy = lst->data;
//             lst->data = lst->next->data;
//             lst->next->data = copy;
//             lst = tmp;
//         }
//         else
//             lst = lst->next;
//     }
//     lst = tmp;
//     return(tmp);
// }

// returns anything BUT 0 if a and b are in right order
// returns 0 if a and b are NOT in right order
int	cmp(int a, int b)
{
	return (a <= b);
}

int is_sorted(t_list *lst)
{
    while(lst->next != NULL)
    {
        if (lst->data > lst->next->data)
            return(0);
        lst = lst->next;
    }
    return (1);
}

// Mine:
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *current = NULL;
    int tmp;

    while(!(is_sorted(lst)))
    {
        current = lst;
        while(current->next != NULL)
        {
            // printf("current->data = %i\n", current->data);
            // printf("current->next->data = %i\n", current->next->data);
            // printf("cmp(current->data, current->next->data) = %i\n", cmp(current->data, current->next->data));
            if(cmp(current->data, current->next->data) == 0)
            {
                tmp = current->data;
                current->data = current->next->data;
                current->next->data = tmp;
            }
            current = current->next;
        }
    }
    return(current);
}

// Arthur's:
// t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
// {
// 	t_list	*tmp;
// 	int		tmp_data;

// 	while (is_sorted(lst, cmp))
// 	{
// 		tmp = lst;
// 		while (tmp->next != NULL)
// 		{
// 			if (!cmp(tmp->data, tmp->next->data))
// 			{
// 				tmp_data = tmp->data;
// 				tmp->data = tmp->next->data;
// 				tmp->next->data = tmp_data;
// 			}
// 			tmp = tmp->next;
// 		}
// 	}
// 	return (lst);
// }

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