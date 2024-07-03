/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:06:08 by anarama           #+#    #+#             */
/*   Updated: 2024/05/21 12:11:10 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_lst;

	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		last_lst = lst;
		lst = lst->next;
	}
	return (last_lst);
}
