/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:34:44 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/05 20:59:38 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	oadd(t_object **list, t_object *new)
{
	t_object	*cur;

	if (*list == 0)
	{
		*list = new;
		return ;
	}
	cur = *list;
	while (cur -> next)
		cur = cur -> next;
	cur -> next = new;
}

t_object	*olast(t_object *list)
{
	if (list == 0)
		return (0);
	while (list->next)
		list = list -> next;
	return (list);
}
