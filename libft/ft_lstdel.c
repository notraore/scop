/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:14:25 by notraore          #+#    #+#             */
/*   Updated: 2017/04/14 12:14:26 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *next;

	if ((*alst) == NULL)
		return ;
	tmp = (*alst);
	while (tmp)
	{
		(*del)((tmp)->content, (tmp)->content_size);
		next = tmp->next;
		tmp->next = NULL;
		free(tmp);
		tmp = next;
	}
	*alst = NULL;
}
