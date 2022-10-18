/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:19:56 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/10/18 14:34:05 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ans;
	size_t	i;

	ans = (char *)s;
	i = ft_strlen(ans);
	if ((char)c == '\0')
		return ("\0");
	while ((ans[i - 1] != (char)c) && i)
		i--;
	if (i == 0)
		return (NULL);
	return (&ans[i - 1]);
}

// #include <stdio.h>
// #include <strings.h>
// int main(void)
// {
// 	char *s = "libft-test-tokyo";
// 	printf("%s\n", 	ft_strrchr(s, '\0'));
// 	printf("%s\n", 	strrchr(s, '\0'));
// 	return (0);
// }