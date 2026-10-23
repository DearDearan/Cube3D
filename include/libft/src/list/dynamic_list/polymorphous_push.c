/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphous_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 00:37:58 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_list.h"

static void	cast_set(void *arr, t_elem elem)
{
	t_header *const	header = (t_header *)arr - 1;

	if (elem.type == N8)
		((uint8_t *)arr)[header->count++] = elem.value.c;
	else if (elem.type == N16)
		((uint16_t *)arr)[header->count++] = elem.value.u16;
	else if (elem.type == N32)
		((uint32_t *)arr)[header->count++] = elem.value.u32;
	else if (elem.type == N64)
		((uint64_t *)arr)[header->count++] = elem.value.u64;
	else if (elem.type == PTR)
		((void **)arr)[header->count++] = elem.value.ptr;
	else if (elem.type == FLOAT)
		((float *)arr)[header->count++] = elem.value.f;
	else if (elem.type == DOUBLE)
		((double *)arr)[header->count++] = elem.value.d;
	else if (elem.type == LDOUBLE)
		((long double *)arr)[header->count++] = elem.value.ld;
}

void	ft_arr_push(void **arr, t_elem elem)
{
	t_header	*header;

	if (!*arr)
		*arr = ft_init_array(elem);
	header = (t_header *)(*arr) - 1;
	if (header->count >= (header->capacity - 1))
		ft_extend_array(*arr);
	cast_set(*arr, elem);
}
