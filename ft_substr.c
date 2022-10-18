/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:57:45 by matsushimak       #+#    #+#             */
/*   Updated: 2022/10/18 19:22:32 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	tmp;

	tmp = len;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		tmp = 0;
		return (ft_strdup(""));
	}
	if (ft_strlen(s + start) < len)
		tmp = ft_strlen(s + start);
	ret = (char *)malloc(sizeof(char) * (tmp + 1));
	if (!ret)
		return (0);
	ret[tmp] = '\0';
	ft_memcpy(ret, s + start, tmp);
	return (ret);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *s = "libft-test-tokyo";
// 	printf("%s\n", ft_substr(s, 20, 100));
// 	printf("");
// 	return (0);
// }