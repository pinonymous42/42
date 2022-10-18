/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:40:01 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/10/18 18:52:20 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new)
	{
		if (lst)
		{
			if (*lst == NULL)
				*lst = new;
			else
			{
				last = ft_lstlast(*lst);
				last->next = new;
			}
		}
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list *l = NULL;
// 	ft_lstadd_back(&l, ft_lstnew((void*)1));
// 	ft_lstadd_back(&l, ft_lstnew((void*)2));
// 	printf("%p\n", ft_lstlast(l)->next);
// 	return (0);
// }
