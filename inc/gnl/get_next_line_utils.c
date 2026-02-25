/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:33:46 by beldemir          #+#    #+#             */
/*   Updated: 2024/11/23 18:24:41 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	c = (unsigned char)c;
	while (*s != c && *s != 0)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

static char	*ft_zerostr(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*res;

	if (!s1)
		s1 = ft_zerostr();
	if (!s1)
		return (NULL);
	if (!s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[i - ft_strlen(s1)])
	{
		res[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	free(s1);
	res[i] = '\0';
	return (res);
}
