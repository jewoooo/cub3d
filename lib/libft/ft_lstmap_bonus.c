/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:48:09 by minhulee          #+#    #+#             */
/*   Updated: 2023/10/16 20:24:35 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new;
	void	*content;

	if (!lst || !del)
		return (0);
	result = 0;
	while (lst)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (!new || !content)
		{
			if (content)
				del(content);
			if (new)
				ft_lstdelone(new, del);
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
