/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:30:06 by dconza            #+#    #+#             */
/*   Updated: 2023/10/11 12:56:39 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_memcpy(void *dst, const void *src, size_t size)
{
	char	*p;
	char	*m;
	int		i;

	p = (char *)src;
	m = (char *)dst;
	i = 0;
	while( i < size)
	{
		m[i] = p[i];
		i++;
	}
	return (dst);
}
