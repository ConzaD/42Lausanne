/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:38:34 by dconza            #+#    #+#             */
/*   Updated: 2023/10/11 15:43:38 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return ((char *)s + i);
	while (s[i] != '\0')
		i++;
	while ( s[i] != '\0')
	{
		if ( s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return(NULL);
}
