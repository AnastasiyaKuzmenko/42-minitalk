/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:21:28 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/04/27 13:12:40 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c &(0x01 << bit)) != 0)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(200);
		bit++;
	}
	return ;
}

static int	check_pid(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	index;

	pid = 0;
	index = 0;
	if (argc != 3 || !ft_strlen(argv[2]) || !check_pid(argv[1]))
	{
		ft_printf("%s\n", "Invalid arguments!");
		return (0);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][index] != '\0')
		{
			send_bits(pid, argv[2][index]);
			index++;
		}
		send_bits(pid, '\n');
	}
	return (0);
}
