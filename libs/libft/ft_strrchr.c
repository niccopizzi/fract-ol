/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:37:04 by nicco             #+#    #+#             */
/*   Updated: 2024/10/31 11:29:49 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	d;

	i = 0;
	d = c;
	while (s[i] != 0)
		i++;
	if (d == 0)
		return ((char *)(s + i));
	while (i >= 0)
	{
		if (s[i] == d)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}