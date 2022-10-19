/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:55:55 by matsushimak       #+#    #+#             */
/*   Updated: 2022/10/19 20:39:32 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char const *s, char c)
{
	if (*s == c)
		return (1);
	return (0);
}

static int	count_sep(char const *s, char c)
{
	int	amount;
	int	count;

	amount = 0;
	count = 0;
	while (*s)
	{
		if (check(s, c))
		{
			if (amount != 0)
				count++;
			amount = 0;
		}
		else
			amount++;
		s++;
	}
	if (amount != 0)
		return (count + 1);
	return (count);
}

static char	*ft_cpy(const char *s1, int *amount, char **ans, size_t i)
{
	char	*ret;
	char	*lead;

	ret = (char *)malloc(sizeof(char) * (*amount + 1));
	if (!ret)
	{
		while (i >= 0)
			free(ans[i--]);
		free(ans);
		return (NULL);
	}
	lead = ret;
	while (*amount)
	{
		*ret = *s1;
		ret++;
		s1++;
		*amount -= 1;
	}
	*ret = '\0';
	ans[i] = lead;
	ans[++i] = NULL;
	return (lead);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	size_t	i;
	int		amount;

	i = 0;
	amount = 0;
	if (s == NULL)
		return (NULL);
	ans = (char **)malloc(sizeof(char *) * (count_sep(s, c) + 1));
	if (!ans)
		return (NULL);
	while (*s)
	{
		if (check(s, c))
		{
			if (amount != 0 && !ft_cpy(s - amount, &amount, ans, i++))
				return (NULL);
		}
		else
			amount++;
		s++;
	}
	if (amount != 0 && !ft_cpy(s - amount, &amount, ans, i++))
		return (NULL);
	return (ans);
}

// #include <stdio.h>
// int main(void)
// {
// 	char s1[] = "abzdzefza";
// 	char s = 'z';
// 	char **ans = ft_split(s1, s);
// 	while (*ans)
// 	{
// 	printf("%s\n", *ans);
// 	ans++;
// 	}
// 	return (0);
// }