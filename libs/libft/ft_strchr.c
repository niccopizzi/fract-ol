/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:57:59 by nicco             #+#    #+#             */
/*   Updated: 2024/10/31 11:26:37 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;

	i = 0;
	d = c;
	if (d == 0)
	{
		while (s[i] != 0)
			i++;
		return ((char *)(s + i));
	}
	while (s[i] != 0)
	{
		if (s[i] == d)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
