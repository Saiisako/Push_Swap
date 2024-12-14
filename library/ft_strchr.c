/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:37:14 by skock             #+#    #+#             */
/*   Updated: 2024/11/12 16:41:23 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == uc)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == uc)
		return ((char *)&str[i]);
	return (NULL);
}
