/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:47:34 by javigarc          #+#    #+#             */
/*   Updated: 2022/02/04 13:09:26 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_createline(char *src, int len)
{
	int		i;
	char	*dst;

	if ((!src) || (len == 0))
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (len)
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr_gnl(char *s, int start, int len)
{
	char	*aux;
	int		i;
	int		z;

	i = start;
	if ((i >= ft_strlent(s)) || (len == 0) || (!s))
	{
		free(s);
		return (NULL);
	}
	z = 0;
	if (len > ft_strlent(s))
		len = ft_strlent(s);
	aux = (char *) malloc(len + 1);
	if (!aux)
		return (0);
	while (z < len)
	{
		aux[z] = s[i];
		z++;
		i++;
	}
	aux[z] = '\0';
	free(s);
	return (aux);
}

int	ft_strlent(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 00)
		i++;
	return (i);
}
