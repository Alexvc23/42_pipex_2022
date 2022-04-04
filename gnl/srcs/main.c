/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:26:15 by jvalenci          #+#    #+#             */
/*   Updated: 2022/04/04 14:27:41 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"get_next_line.h"
# include <stdio.h>

int main(void)
{
    char *str;

    while (!get_next_line(0, &str))
    {
        printf("%s\n", str);
        free(str);
    }
    return (0);
}
