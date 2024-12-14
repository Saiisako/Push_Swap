/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:36:51 by skock             #+#    #+#             */
/*   Updated: 2024/11/12 16:41:16 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*to;
	const unsigned char	*from;

	to = (unsigned char *)dest;
	from = (const unsigned char *)src;
	if (to < from)
	{
		i = 0;
		while (i < n)
		{
			to[i] = from[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			to[i] = from[i];
		}
	}
	return (dest);
}
