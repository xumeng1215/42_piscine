/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthompso <pthompso@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:44:06 by pthompso          #+#    #+#             */
/*   Updated: 2024/03/11 16:44:07 by pthompso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (*to_find == '\0')
		return ((char *) str);
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && i + j < n)
			{
				if (to_find[j + 1] == '\0')
					return ((char *) str + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
