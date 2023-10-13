/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:51:08 by dconza            #+#    #+#             */
/*   Updated: 2023/10/13 16:26:04 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int  c, size_t n)
{
	size_t	i;
	char *p;

	p = (char *)s;
	i = 0;
	while ( i < n)
	{
		if ((unsigned char)p[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return(NULL);
}
