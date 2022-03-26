/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:54:18 by elima-me          #+#    #+#             */
/*   Updated: 2021/06/07 13:16:50 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (*lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		del(temp->content);
		*lst = temp->next;
		free(temp);
	}
	*lst = NULL;
	return ;
}
