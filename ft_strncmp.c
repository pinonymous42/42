/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:32:47 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/10/18 14:34:00 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (n && (*tmp1 != '\0' || *tmp2 != '\0'))
	{
		if (*tmp1 != *tmp2)
			return ((*tmp1 - *tmp2));
		tmp1++;
		tmp2++;
		n--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char str[] = "ABC";
//     printf("ABC: ABD   = %d\n", strncmp(str, "ABD", 0));
//     printf("ABC: ABC   = %d\n", strncmp(str, "ABC", 2));
//     printf("ABC: AAA   = %d\n", strncmp(str, "AAA", 2));
//     printf("ABC: ABCD  = %d\n", strncmp(str, "ABCD", 2));
//     printf("ABC: AB    = %d\n", strncmp(str, "AB", 2));
//     printf("ABC: B     = %d\n", strncmp(str, "B", 2));
//     printf("ABC: A     = %d\n\n", strncmp(str, "A", 2));
// 	char str1[] = "ABC";
//     printf("ABC: ABD   = %d\n", ft_strncmp(str1, "ABD", 0));
//     printf("ABC: ABC   = %d\n", ft_strncmp(str1, "ABC", 2));
//     printf("ABC: AAA   = %d\n", ft_strncmp(str1, "AAA", 2));
//     printf("ABC: ABCD  = %d\n", ft_strncmp(str1, "ABCD", 2));
//     printf("ABC: AB    = %d\n", ft_strncmp(str1, "AB", 2));
//     printf("ABC: B     = %d\n", ft_strncmp(str1, "B", 2));
//     printf("ABC: A     = %d\n", ft_strncmp(str1, "A", 2));
//     return 0;
// }