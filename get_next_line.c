/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsucre-v <jsucre-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:51:44 by jsucre-v          #+#    #+#             */
/*   Updated: 2020/07/09 20:20:21 by jsucre-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_leer(char **str, int fd)
{
	int		ret;
	char	*s;
	char	buf[BUFFER_SIZE + 1];
	if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
		return (-1);
	buf[ret] = '\0';
	s = *str;
	*str = ft_strjoin(*str, buf);
	if (s != NULL)
	{
		free(s);
	}
	return (ret);
}

static int		ft_get_linea(char **str, char **line, char *s,  int ret)
{
	int		i;
	char	*tmp;

	i = 0;
	
	if (*s == '\n')
		i = 1;
	*s = 0;
	printf("estoy aqui");
	*line = ft_strdup(*str);
	if (i == 0 && ft_strlen(*str) != 0)
	{
		printf("y entre aqui");
		*str = ft_strdup("");
		return (0);
	}
	else if (i == 0 && !(ft_strlen(*str)))
	{
		*str = ft_strdup("");
		//		printf("termine de leer");
		return (0);
	}
	tmp = *str;
	//printf("ft_strdup de S + 1 %s", ft_strdup(s + 1));
	*str = ft_strdup(s + 1);
	free(tmp);
	printf("retorne 1\n");
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int			ret;
	char		*s;
	static char	*str[4096];
	char		buf[BUFFER_SIZE + 1];

	if (line == NULL || BUFFER_SIZE < 1 || fd < 0)
		return (-1);

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if(!str[fd]){
			str[fd] = ft_strdup(buf);
		}else{
			printf("vallor de bufer %s", buf);
			printf("valor de ret %i", ret);
			s = ft_strjoin(str[fd], buf);
			free(str[fd]);
			str[fd] = s;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;

	}
	if (ret == -1)
		return (-1);
		printf("que mando pr str %s\n", str[fd]);
	return (ft_get_linea(&str[fd], line, s, ret));
}

int main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	char			*lineadress[66];
	
	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("alphabet", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 66)
		printf("\nRight number of lines\n");
	else if (j != 66)
		printf("\nNot Good - Wrong Number Of Lines\n");
	while (--j > 0)
		free(lineadress[j - 1]);
	j = 1;
}