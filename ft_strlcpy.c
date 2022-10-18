/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:32:47 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/10/18 14:33:51 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(src);
	if (dstsize == 0)
		return (s_len);
	while (src[i] && i < (dstsize - 1))
	{
		*dst = src[i];
		dst++;
		i++;
	}
	*dst = '\0';
	return (s_len);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char str1[25] = "123456";
//     char str2[] = "abcdefgh";
//     printf("%zu\n",ft_strlcpy(str1,str2,0));
// 	printf("%s\n",str1);

// 	char str11[25] = "123456";
//     char str22[] = "abcdefgh";
//     printf("%lu\n",strlcpy(str11,str22,0));
// 	printf("%s\n",str11);
//     return 0;
// }