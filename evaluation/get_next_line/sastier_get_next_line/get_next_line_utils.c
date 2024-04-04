/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:11:55 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/25 12:46:13 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//find the first \n in str, return its index.
int	find_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

//add i bytes of memory to the end of str
//copy to a new place and free the old one
char	*ft_realloc(char *str, int i)
{
	char	*temp;
	int		count;
	int		size;

	size = 0;
	if (str)
	{
		while (str[size])
			size++;
	}
	temp = (char *)malloc((size + i + 1) * sizeof(char));
	if (!temp)
	{
		free(str);
		return (temp);
	}
	count = 0;
	while (count < size)
	{
		temp[count] = str[count];
		count++;
	}
	temp[count] = '\0';
	free(str);
	return (temp);
}

//dup the src from beginning to the first \n
//with null terminator at the end
//return the new string, but keep the old one
char	*ft_strdup(const char *src)
{
	int		count;
	int		i;
	char	*dest;

	count = 0;
	i = 0;
	while (src[count] != '\n' && src[count])
		count++;
	if (src[count] == '\n')
		count++;
	dest = (char *)malloc((count + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < count)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

//copy the content from first \n to the end of src
//with null terminator at the end
//return new string, free the old one
char	*ft_substr(char *src)
{
	char	*res;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (src[i] != '\n' && src[i])
		i++;
	if (src[i] == '\n')
		i++;
	while (src[count + i])
		count++;
	res = malloc(sizeof(char) * (count + 1));
	if (!res)
		return (NULL);
	count = 0;
	while (src[count + i])
	{
		res[count] = src[count + i];
		count++;
	}
	res[count] = '\0';
	free(src);
	return (res);
}
