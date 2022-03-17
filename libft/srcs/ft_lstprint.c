/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:03:09 by jvalenci          #+#    #+#             */
/*   Updated: 2022/02/14 12:48:11 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void    ft_lstprint(t_list **header)
{
   t_list *ptr; 

   ptr = *header;
   if (!*header)
       return;
    while (ptr)
    {
        ft_putnbr_fd(*((int*)ptr->content), 1);
        ptr = ptr->next;
        if (ptr)
            ft_putchar_fd(' ', 1);
    }
    ft_putstr_fd("\n", 1);
}
/* int main(int args, char *argv[])
{
    int i = 1;
    t_list *test;
    int *num;
    
    num = malloc((args - 1) * sizeof(int));
    test = NULL;
    if (!num)
        return (0);
    while (i <= (args - 1))
    {
        num[i] = ft_atoi(argv[i]);
        i++;
    }
    i = 1;
    while (i <= (args - 1))
        ft_lstadd_back(&test, ft_lstnew(&num[i++]));
    ft_lstprint(test);
    return (0);
}
 */