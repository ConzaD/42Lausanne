/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:18:08 by dconza            #+#    #+#             */
/*   Updated: 2023/10/11 15:26:07 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle == NULL || needle[0] == '\0')
		return ((char *)haystack);
	while ( haystack[i] != '\0' && i < n)
	{
		if ( haystack[i] == needle[i])
		{
			while ( haystack[i+j] == needle[j] && ((i + j) < n))
			{
				if (needle[j+1] == '\0' )
				{
					return((char *)haystack + i);
					j++;
				}
				j = 0;
			}
		}
		i++;
	}
	return(NULL);
}