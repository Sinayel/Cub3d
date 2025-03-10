/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:45:55 by judenis           #+#    #+#             */
/*   Updated: 2025/03/10 11:20:10 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

// char	*ft_strdup(const char *src)
// {
// 	int		i;
// 	int		len;
// 	char	*ptr;

// 	i = 0;
// 	len = ft_strlen(src);
// 	ptr = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!ptr)
// 		return (NULL);
// 	while (i < len)
// 	{
// 		ptr[i] = src[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!str)
// 		return (NULL);
// 	while (s1[j])
// 	{
// 		str[i] = s1[j];
// 		i++;
// 		j++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		str[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	str[i] = 0;
// 	return (str);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	unsigned int	i;
// 	char			*str;

// 	if (ft_strlen(s) <= start)
// 	{
// 		str = (malloc(sizeof(char)));
// 		str[0] = '\0';
// 		return (str);
// 	}
// 	i = 0;
// 	while ((s[start + i]) && (i < len))
// 		i++;
// 	str = (char *)malloc(i + 1);
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while ((s[start + i]) && (i < len))
// 	{
// 		str[i] = s[start + i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }
