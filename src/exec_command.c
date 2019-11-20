/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:16:28 by mnguyen           #+#    #+#             */
/*   Updated: 2018/12/12 19:19:26 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_md5.h"

char	*command_to_string(enum e_command command)
{
	if (command == MD5)
		return ("MD5");
	else if (command == SHA224)
		return ("SHA224");
	else if (command == SHA256)
		return ("SHA256");
	else if (command == SHA384)
		return ("SHA384");
	else if (command == SHA512)
		return ("SHA512");
	return ("UNKNOW COMMAND");
}

void	exec_opt_p(t_args *args)
{
	t_buffer	result;
	void		*hash_struct;

	args->i = 0;
	if (args->opts & OPT_P || args->opts & OPT_NO)
	{
		hash_struct = args->disp.set(args->data[args->i]);
		result = args->disp.hash(hash_struct);
		args->disp.free(hash_struct);
		if (args->opts & OPT_P)
			print_buffer(args->data[args->i]);
		print_buffer_hex(result);
		ft_putchar('\n');
		free(result.bytes);
		args->i++;
	}
}

void	exec_print_opt_s(t_args *args, t_buffer result)
{
	if (args->opts & OPT_Q)
	{
		print_buffer_hex(result);
		ft_putchar('\n');
	}
	else if (args->opts & OPT_R)
	{
		print_buffer_hex(result);
		ft_putstr(" \"");
		print_buffer(args->data[args->i]);
		ft_putstr("\"\n");
	}
	else
	{
		ft_putstr(command_to_string(args->command));
		ft_putstr(" (\"");
		print_buffer(args->data[args->i]);
		ft_putstr("\") = ");
		print_buffer_hex(result);
		ft_putchar('\n');
	}
}

void	exec_opt_s(t_args *args)
{
	t_buffer	result;
	int			i;
	void		*hash_struct;

	i = 0;
	while (i < args->opt_s_nb)
	{
		hash_struct = args->disp.set(args->data[args->i]);
		result = args->disp.hash(hash_struct);
		args->disp.free(hash_struct);
		exec_print_opt_s(args, result);
		free(result.bytes);
		args->i++;
		i++;
	}
}

void	exec_command(t_args args)
{
	exec_opt_p(&args);
	exec_opt_s(&args);
	exec_files(&args);
	free_args(&args);
}
