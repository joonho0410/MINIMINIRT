/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:34:44 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/22 12:11:30 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/scene.h"

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

t_object	*ofirst(void)
{
	t_color3	color;

	color.x = 0;
	color.y = 0;
	color.z = 0;
	return (object(-1, NULL, color));
}
