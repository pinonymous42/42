/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:07:43 by matsushimak       #+#    #+#             */
/*   Updated: 2022/10/18 14:32:21 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(const char *str, int *pcount, int *mcount)
{
	*pcount = 0;
	*mcount = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '+')
			*pcount += 1;
		else if (*str == '-')
			*mcount += 1;
		str++;
	}
	if (*pcount > 1 || *mcount > 1 || (*pcount == 1 && *mcount == 1))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	pcount;
	int	mcount;
	int	i;

	i = 0;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (count(str, &pcount, &mcount))
		return (0);
	str += (pcount + mcount);
	while ('0' <= *str && *str <= '9')
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	if (mcount)
		return (-i);
	return (i);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
// 	printf("%d\n", atoi("		  \n-2147483649"));
// 	return (0);
// }