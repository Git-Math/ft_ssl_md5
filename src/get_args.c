/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:21:38 by mnguyen           #+#    #+#             */
/*   Updated: 2018/12/12 19:23:40 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl_md5.h"

void	get_command(int ac, char **av, t_args *args)
{
	if (ac < 2)
		error(NO_COMMAND, "");
	else if (ft_strlen(av[1]) == 3 && !memcmp(av[1], "md5", 3))
		args->command = MD5;
	else if (ft_strlen(av[1]) == 6 && !memcmp(av[1], "sha224", 6))
		args->command = SHA224;
	else if (ft_strlen(av[1]) == 6 && !memcmp(av[1], "sha256", 6))
		args->command = SHA256;
	else if (ft_strlen(av[1]) == 6 && !memcmp(av[1], "sha384", 6))
		args->command = SHA384;
	else if (ft_strlen(av[1]) == 6 && !memcmp(av[1], "sha512", 6))
		args->command = SHA512;
	else
		error(INVALID_COMMAND, av[1]);
}

void	get_opts(int ac, char **av, t_args *args, int *i)
{
	args->opts = 0;
	args->opt_s_nb = 0;
	args->i = 0;
	while (*i < ac && av[*i][0] == '-')
	{
		if (ft_strlen(av[*i]) != 2)
			error(INVALID_OPTS, av[*i]);
		else if (av[*i][1] == 'p')
			args->opts = args->opts | OPT_P;
		else if (av[*i][1] == 'q')
			args->opts = args->opts | OPT_Q;
		else if (av[*i][1] == 'r')
			args->opts = args->opts | OPT_R;
		else if (av[*i][1] == 's')
		{
			args->opts = args->opts | OPT_S;
			*i += 1;
			args->opt_s_nb += 1;
		}
		else
			error(INVALID_OPTS, av[*i]);
		*i += 1;
	}
	if (*i == ac && !(args->opts & OPT_S))
		args->opts = args->opts | OPT_NO;
}

void	get_opts_s(int ac, char **av, t_args *args)
{
	int i;

	if (!(args->opts & OPT_S))
		return ;
	i = 2;
	while (i < ac && av[i][0] == '-')
	{
		if (ft_strlen(av[i]) == 2 && av[i][1] == 's')
		{
			i += 1;
			if (i == ac)
				error_free_args(OPT_S_NO_DATA, "", args);
			else if (ft_strlen(av[i]) == 0)
				error_free_args(OPT_S_NO_DATA, "", args);
			else if (ft_strlen(av[i]) > DATA_SIZE_MAX)
				error_free_args(OPT_S_TOO_BIG, "", args);
			args->data[args->i].bytes = (t_byte *)av[i];
			args->data[args->i].size = ft_strlen(av[i]);
			args->i++;
		}
		i += 1;
	}
}

void	get_filenames(int ac, char **av, t_args *args, int *i)
{
	while (*i < ac)
	{
		if (ft_strlen(av[*i]) >= FILENAME_SIZE_MAX)
			error_free_args(FILENAME_TOO_BIG, "", args);
		args->data[args->i].bytes = (t_byte *)av[*i];
		args->data[args->i].size = ft_strlen(av[*i]);
		args->i++;
		*i += 1;
	}
}

t_args	get_args(int ac, char **av)
{
	t_args		args;
	int			i;

	i = 2;
	get_command(ac, av, &args);
	set_dispatcher(&args);
	get_opts(ac, av, &args, &i);
	set_mem_data(ac, &args, &i);
	get_opts_s(ac, av, &args);
	get_filenames(ac, av, &args, &i);
	return (args);
}
