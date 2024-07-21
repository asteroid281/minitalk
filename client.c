/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:44:28 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/10 20:27:40 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	long	i;
	long	num;

	i = 0;
	num = 0;
	while (str[i] != '\0' && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
	{
		i++;
	}
	if (str[i] != '\0' && str[i] == '-')
	{
		return (0);
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = (num * 10) + (str[i++] - '0');
		else
			return (0);
	}
	return (num);
}

void	signal_distributor(int pid, char c)
{
	char	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		ft_printf("Hatali giris yaptiniz.\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (!pid)
	{
		ft_printf("PID girisi yanlis.\n");
		return (0);
	}
	i = 0;
	while (av[2][i])
	{
		signal_distributor(pid, av[2][i]);
		i++;
	}
	signal_distributor(pid, '\n');
	signal_distributor(pid, '\0');
	return (0);
}
