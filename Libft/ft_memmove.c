/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:30:12 by dconza            #+#    #+#             */
/*   Updated: 2023/10/13 19:45:16 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *s1, const void *s2, size_t n)
{
    unsigned char    *ptr1;
    unsigned char    *ptr2;

    ptr1 = (unsigned char *)s1;
    ptr2 = (unsigned char *)s2;
    if (ptr2 == NULL && ptr1 == NULL)
        return (NULL);
    if (ptr1 < ptr2)
    {
        while (n--)
            *(ptr1++) = *(ptr2++);
    }
    else
    {
        ptr1 += n;
        ptr2 += n;
        while (n--)
            *(--ptr1) = *(--ptr2);
    }
    return (s1);
}
