/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:32:41 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/10/18 14:33:39 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ans;

	ans = (char *)s;
	while (*ans != (char)c)
	{
		if (*ans == '\0')
			return (0);
		ans++;
	}
	return (ans);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char str[] = "abcdefghijklmnabcdefghijklmn", *p;
// 	int c;
// 	printf("検索文字を入力してください。");
// 	c = getchar();
// 	p = ft_strchr(str, c);
// 	if (p != NULL) {
// 		printf("%cは文字列の%ld番目にあります。\n", c, p-str);
// 		printf("以降の文字列は%sです。\n", p);
// 	}
// 	else
// 		printf("%cは見つかりませんでした\n", c);
// 	return 0;
// }