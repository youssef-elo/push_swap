/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:40:36 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/12 01:45:15 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (slen);
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*r;

	len = ft_strlen(s1) + 1;
	r = (char *)malloc(len * sizeof(char));
	if (r == NULL)
		return (NULL);
	ft_strlcpy(r, s1, len);
	return (r);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > (slen - start))
		len = (slen - start);
	r = (char *)malloc(len + 1);
	if (r == NULL)
		return (NULL);
	ft_strlcpy(r, s + start, len + 1);
	return (r);
}
char	**ft_freearray(char **s, int i)
{
	while (i)
	{
		free(s[i - 1]);
		i--;
	}
	free(s);
	return (NULL);
}

int	ft_cwords(char *s, char c)
{
	int	co;
	int	i;

	i = 0;
	co = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			co++;
		i++;
	}
	return (co);
}

char	**ft_strs(char *s, char **rs, char c)
{
	int	len;
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			rs[j] = ft_substr(s, (i - len), len);
			if (rs[j] == NULL)
				return (ft_freearray(rs, j));
			j++;
		}
	}
	return (rs);
}

char	**ft_split(char *s, char c)
{
	int		w;
	char	**rs; 

	if (s == NULL) 
		return (NULL);
	w = ft_cwords(s, c);
	rs = (char **)malloc((w + 1) * sizeof(char *));
	if (rs == NULL)
		return (NULL);
	rs[w] = NULL;
	return (ft_strs(s, rs, c));
}
