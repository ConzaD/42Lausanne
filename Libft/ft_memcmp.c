/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:04:09 by dconza            #+#    #+#             */
/*   Updated: 2023/10/11 16:12:16 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const void *s1, void *s2, size_t n)
{
	size_t	k;
	char	*p;
	char	*m;

	p = (char *)s1;
	m = (char *)s2;
	k = 0;
	while (i < n)
	{
		if (p[k] != m[k])
			return (*(unsigned char *)p - *(unsigned char *)m);
	}
	return (0);
}
