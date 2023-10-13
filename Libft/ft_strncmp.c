/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:14:23 by dconza            #+#    #+#             */
/*   Updated: 2023/10/13 16:54:41 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, char *s2,size_t n)
{
	size_t	k;


	k = 0;
	while ((s1[k] != '\0' || s2[k] != '\0') && k < n)
	{
		if (s1[k] < s2[k])
			return ((unsigned char )s1[k] - (unsigned char )s2[k]);
		else if (s1[k] > s2[k])
			return ((unsigned char )s1[k] - (unsigned char )s2[k]);
		k++;
	}
	return (0);
}
