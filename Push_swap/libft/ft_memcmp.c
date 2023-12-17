/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:04:09 by dconza            #+#    #+#             */
/*   Updated: 2023/10/17 20:16:24 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	k;
	char	*p;
	char	*m;

	p = (char *)s1;
	m = (char *)s2;
	k = 0;
	while (k < n)
	{
		if (p[k] != m[k])
			return ((unsigned char )p[k] - (unsigned char )m[k]);
		k++;
	}
	return (0);
}
