/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:24:12 by skock             #+#    #+#             */
/*   Updated: 2024/11/28 14:55:15 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	start_function(int fd, char **temp)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	*temp = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!*temp)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*str[4096];
	char			*temp;
	char			*line;
	int				bytes_read;

	if (start_function(fd, &temp) == 0)
		return (NULL);
	while (!ft_strchr_2(str[fd], '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(temp);
			if (bytes_read == 0)
				break ;
			return (NULL);
		}
		temp[bytes_read] = '\0';
		str[fd] = ft_strjoin_2(str[fd], temp);
	}
	if (ft_strchr_2(str[fd], '\n'))
		free(temp);
	line = ft_str_n_chr_cpy(str[fd]);
	str[fd] = ft_remove_line(str[fd], line);
	return (line);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	int fd2 = open("test copy.txt", O_RDONLY);
// 	if (fd == -1) 
// 	{
// 		perror("Erreur lors de l'ouverture du fichier");
// 			return 1;
// 	}
// 	char *line;
// 	int i = 0;
// 	while (i < 10)
// 	{
// 		i++;
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// }