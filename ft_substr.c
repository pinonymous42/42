/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:57:45 by matsushimak       #+#    #+#             */
/*   Updated: 2022/10/18 14:34:10 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	tmp;

	tmp = len;
	if (ft_strlen(s) < start)
		tmp = 0;
	if (ft_strlen(s + start) < len)
		tmp = ft_strlen(s + start);
	ret = (char *)malloc(sizeof(char) * (tmp + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, tmp + 1);
	return (ret);
}

// #include <stdio.h>
// int main(void)
// {
// 	// char s[] = "abcdefghijk";
// 	printf("%s\n", ft_substr("tripouille", 15, 1));
// 	return (0);
// }