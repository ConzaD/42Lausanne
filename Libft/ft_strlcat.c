/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:25:37 by dconza            #+#    #+#             */
/*   Updated: 2023/10/11 15:44:08 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (dst[i] &&  i < size)
		i++;
	while (src[j] && (j+i+1) < size)
	{
		dst[j+i] = src[j];
		j++;
	}
	if ( i < size)
		dst[i] = '\0';
	return( i + ft_strlen(src));
}
