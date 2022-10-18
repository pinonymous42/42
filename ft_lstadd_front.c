/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:59:13 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/10/18 14:32:52 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			new->next = *lst;
			*lst = new;
		}
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list *l = NULL;
// 	// ft_lstadd_front(&l, ft_lstnew((void *)2));
// 	ft_lstadd_front(&l, ft_lstnew((void *)1));
// 	printf("%p\n", (l->next));
// 	return (0);
// }