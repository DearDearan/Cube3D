/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:17:46 by rboutelo          #+#    #+#             */
/*   Updated: 2026/02/18 01:06:04 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_lstsize(t_list *lst)
{
	int32_t	i;
	t_list	*cur;

	if (!lst)
		return (0);
	i = 0;
	cur = lst;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}
