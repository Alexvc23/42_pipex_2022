/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_prev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:59:54 by jvalenci          #+#    #+#             */
/*   Updated: 2022/02/11 15:04:07 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void    ft_check_prev(t_list **alst)
{
    t_list *temp;

    temp = *alst;
    while (temp->next)
    {
        temp->next->previous = temp;
        temp = temp->next;
    }
}

