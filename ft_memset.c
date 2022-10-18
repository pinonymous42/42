/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:55:14 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/10/18 14:33:22 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)b;
	while (len--)
	{
		*a = (unsigned char)c;
		a++;
	}
	return (b);
}

// #include        <stdio.h>
// #include        <string.h>
// int main(void)
// {
// 	char str[] = "0123456789";
// 	memset(str+2, '*', 5);
// 	printf("%s\n\n",str);

// 	char str1[] = "0123456789";
// 	ft_memset(str1+2, '*', 5);
// 	printf("%s\n",str1);

// 	return 0;
// }