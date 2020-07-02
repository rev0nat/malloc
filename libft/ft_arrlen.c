/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:10:30 by schakor           #+#    #+#             */
/*   Updated: 2018/10/16 11:12:03 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_arrlen(char **arr)
{
	size_t	ret;

	ret = 0;
	if (!arr)
		return (ret);
	while (arr[ret] != NULL)
		ret++;
	return (ret);
}