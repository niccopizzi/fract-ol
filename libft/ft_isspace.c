/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:07:19 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/18 08:08:53 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isspace(char c)
{
    if (c == 32 || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
        return (TRUE);
    return (FALSE);
}