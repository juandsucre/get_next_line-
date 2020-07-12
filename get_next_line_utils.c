/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsucre-v <jsucre-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:43:01 by jsucre-v          #+#    #+#             */
/*   Updated: 2020/07/02 16:18:58 by jsucre-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char			*temp;
	unsigned long	len;
	unsigned long	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	if ((temp = (char*)malloc(len + 1)) == NULL)
		return(NULL);
	i = len;
	len = 0;
	while (len < i)
	{
		temp[len] = src[len];
		len++;
	}
	temp[len] = '\0';
	//free(temp);
	return (temp);
}

int		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*retu;

	if (!(s1 && s2))
		return (0);
	if ((retu = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		retu[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		retu[i + j] = s2[j];
		j++;
	}
	retu[i + j] = '\0';
	return (retu);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	carac;
	unsigned int	i;
	char			*dest;

	i = 0;
	if (!(s))
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	carac = len - start;
	if (((dest = (char*)malloc(sizeof(char) * (len + 1))) == NULL))
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == c)
	{
		return ((char *)&s[i]);
	}
	return (0);
}
