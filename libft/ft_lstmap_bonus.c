/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:39:03 by anarama           #+#    #+#             */
/*   Updated: 2024/04/09 12:56:37 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*clear_memory(t_list **lst, void (*del)(void *), void *f_content)
{
	ft_lstclear(lst, del);
	del(f_content);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head_new;
	void	*f_content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head_new = NULL;
	while (lst != NULL)
	{
		f_content = f(lst->content);
		if (f_content == NULL)
			return (clear_memory(&head_new, del, f_content));
		new = ft_lstnew(f_content);
		if (new == NULL)
			return (clear_memory(&head_new, del, f_content));
		ft_lstadd_back(&head_new, new);
		lst = lst->next;
	}
	return (head_new);
}
