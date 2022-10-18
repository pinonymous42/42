/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:35:57 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/10/18 14:33:13 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (n)
	{
		if (*tmp1 != *tmp2)
			return ((*tmp1 - *tmp2));
		tmp1++;
		tmp2++;
		n--;
	}
	return (0);
}

// #include        <stdio.h>
// #include        <string.h>

// int main(void)
// {
//         char buf1[] = "\0abc\0de";      /* 途中に空文字のある文字列 */
//         char buf2[] = "\0abc\0de";
//         char buf3[] = "\0abcdef";
//         if (memcmp(buf1, buf2, 7) == 0)
//                 printf("buf1 = buf2\n");
//         else
//                 printf("buf1 != buf2\n");

//         if (memcmp(buf1, buf3, 7) == 0)
//                 printf("buf1 = buf3\n");
//         else
//                 printf("buf1 != buf3\n\n");

// 		char buf11[] = "\0abc\0de";      /* 途中に空文字のある文字列 */
//         char buf22[] = "\0abc\0de";
//         char buf33[] = "\0abcdef";
//         if (ft_memcmp(buf11, buf22, 7) == 0)
//                 printf("buf11 = buf22\n");
//         else
//                 printf("buf11 != buf22\n");

//         if (ft_memcmp(buf11, buf33, 7) == 0)
//                 printf("buf11 = buf33\n");
//         else
//                 printf("buf11 != buf33\n\n");

//         return 0;
// }