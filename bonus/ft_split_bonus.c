/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:30:12 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/28 17:20:42 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	if (w == 0)
		return (NULL);
	rs = (char **)malloc((w + 1) * sizeof(char *));
	if (rs == NULL)
		return (NULL);
	rs[w] = NULL;
	return (ft_strs(s, rs, c));
}
