/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:23:34 by fmartini          #+#    #+#             */
/*   Updated: 2022/10/17 17:23:53 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nwlst;
	t_list	*temp;

	nwlst = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (temp == NULL)
			ft_lstclear(&temp, del);
		ft_lstadd_back(&nwlst, temp);
		lst = lst->next;
	}
	return (nwlst);
}
