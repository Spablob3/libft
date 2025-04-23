/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:32:22 by joapedro          #+#    #+#             */
/*   Updated: 2025/04/18 10:29:35 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*dest_p;
	const unsigned char		*src_p;

	dest_p = (unsigned char *)dest;
	src_p = (const unsigned char *)src;
	if (!dest_p && !src)
	{
		return (0);
	}
	if (dest > src)
	{
		while (n--)
		{
			dest_p[n] = src_p[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
int	main()
{
	char	str[] = "Altamente bro!";
	char	dest[] = "top";

	ft_memmove(dest, str, 9);
	printf("%s", dest);
}*/
