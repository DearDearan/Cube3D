/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                 ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 05:34:50 by rboutelo          #+#    #+#             */
/*   Updated: 2026/09/20 03:32:23 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_list.h"

static uint16_t	get_size(t_type type)
{
	if (type == N8)
		return (sizeof(uint8_t));
	if (type == N16)
		return (sizeof(uint16_t));
	if (type == N32)
		return (sizeof(uint32_t));
	if (type == N64)
		return (sizeof(uint64_t));
	if (type == PTR)
		return (sizeof(void *));
	if (type == FLOAT)
		return (sizeof(float));
	if (type == DOUBLE)
		return (sizeof(double));
	if (type == LDOUBLE)
		return (sizeof(long double));
	return (UINT16_MAX);
}

void	*ft_extend_array(void **arr)
{
	t_header	*header;

	header = (t_header *)*arr - 1;
	header->capacity *= 2;
	header = (t_header *)ft_realloc(*arr,
			get_size(header->type) * header->capacity + sizeof(t_header));
	return (header);
}

void	*ft_init_array(t_elem elem)
{
	t_header	*result;

	result = malloc(get_size(elem.type) * ARR_DEFAULT_SIZE + sizeof(t_header));
	ft_bzero(result, get_size(elem.type) * ARR_DEFAULT_SIZE + sizeof(t_header));
	result->type = elem.type;
	result->count = 0;
	result->capacity = ARR_DEFAULT_SIZE;
	return (result + 1);
}

void	ft_arr_free(void **arr)
{
	free(((t_header *)*arr) - 1);
	*arr = NULL;
}

bool	ft_arr_is_empty(void **arr)
{
	t_header	*header;

	header = (t_header *)*arr - 1;
	return (header->count == 0);
}
