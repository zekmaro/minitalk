/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:57:57 by anarama           #+#    #+#             */
/*   Updated: 2024/04/08 11:05:17 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size_lst;

	if (lst == NULL)
		return (0);
	size_lst = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size_lst++;
	}
	return (size_lst);
}
