/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndidenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:55:48 by ndidenko          #+#    #+#             */
/*   Updated: 2018/01/06 14:55:52 by ndidenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmerge(char *a, char *b)
{
	char	*ret;

	ret = ft_strjoin(a, b);
	ft_strdel(&a);
	ft_strdel(&b);
	return (ret);
}
