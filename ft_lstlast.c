/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:25:06 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/10/18 18:58:11 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list * l =  NULL;
// 	ft_lstadd_back(&l, ft_lstnew((void*)1));
// 	printf("%s\n%p\n", (char *)(ft_lstlast(l)->content), ft_lstlast(l)->content);
// 	return (0);
// }