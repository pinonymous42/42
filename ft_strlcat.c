/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:32:44 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/10/18 15:37:09 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(src);
	if (dst == NULL)
		return (s_len);
	d_len = ft_strlen(dst);
	if (d_len >= dstsize)
		return (s_len + dstsize);
	while (*dst)
		dst++;
	while (src[i] && i < (dstsize - d_len - 1))
	{
		*dst = src[i];
		dst++;
		i++;
	}
	*dst = '\0';
	return (s_len + d_len);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char str1[7] = "123456";
//     char str2[] = "123456789";
//     printf("%zu\n",ft_strlcat(NULL,"a",0));
// 	printf("%s\n",str1);

// 	char str11[7] = "123456";
//     char str22[] = "123456789";
//     printf("%lu\n",strlcat(NULL,"a",0));
// 	printf("%s\n",str11);
//     return 0;
// }