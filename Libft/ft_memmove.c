/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:30:12 by dconza            #+#    #+#             */
/*   Updated: 2023/10/11 12:56:36 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (src < dst)
	{
		i = len;
		while ( i > 0)
		{
			i--;
			((unsigned char *)dst)[i]=((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while ( i > 0)
		{
			((unsigned char *)dst)[i]=((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
