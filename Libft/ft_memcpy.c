/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:30:06 by dconza            #+#    #+#             */
/*   Updated: 2023/10/13 19:55:45 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t size)
{
	char	*p;
	char	*m;
	size_t	i;

	p = (char *)src;
	m = (char *)dst;
	i = 0;
	if ( p == NULL && m == NULL)
		return(NULL);
	while( i < size)
	{
		m[i] = p[i];
		i++;
	}
	return (dst);
}
