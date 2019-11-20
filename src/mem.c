/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:48:19 by mnguyen           #+#    #+#             */
/*   Updated: 2019/01/14 14:49:20 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_md5.h"

void	set_mem_data(int ac, t_args *args, int *i)
{
	args->data_size = ac - *i + args->opt_s_nb;
	if (args->opts & OPT_P || args->opts & OPT_NO)
		args->data_size++;
	args->data = malloc(sizeof(t_buffer) * args->data_size);
	if (args->data == NULL)
		error(MALLOC_FAILED, "");
	if (args->opts & OPT_P || args->opts & OPT_NO)
	{
		args->data[args->i].bytes = malloc(sizeof(unsigned char) \
											* (DATA_SIZE_MAX + 1));
		if (args->data[args->i].bytes == NULL)
			error(MALLOC_FAILED, "");
		args->data[args->i].size = read(0, args->data[args->i].bytes \
										, DATA_SIZE_MAX + 1);
		if (args->data[args->i].size > DATA_SIZE_MAX)
			error_free_args(OPT_P_TOO_BIG, "", args);
		args->i++;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (dest != src)
		while (n--)
			*d++ = *s++;
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char *swap;

	if (n)
	{
		swap = s;
		while (n--)
			*swap++ = (char)c;
	}
	return (s);
}
