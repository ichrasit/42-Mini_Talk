/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhaoz <muhaoz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:41:47 by muhaoz            #+#    #+#             */
/*   Updated: 2025/03/01 15:05:16 by muhaoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	my_string_writer(char *string)
{
	while (*string)
	{
		write(1, string, 1);
		string++;
	}
}

int	my_ascii_to_integer(char *string)
{
	int	result;
	int	index_counter;
	int	sign;

	result = 0;
	index_counter = 0;
	sign = 1;
	while ((string[index_counter] >= 9 && string[index_counter] <= 13)
		|| string[index_counter] == 32)
		index_counter++;
	if (string[index_counter] == '-' || string[index_counter] == '+')
	{
		if (string[index_counter] == '-')
			sign *= -1;
		index_counter++;
	}
	while (string[index_counter] >= '0' && string[index_counter] <= '9')
	{
		result = (result * 10) + (string[index_counter] - '0');
		index_counter++;
	}
	return (result * sign);
}

void	my_char_sender(int server_pid, char c)
{
	int	bit_position;

	bit_position = 7;
	while (bit_position >= 0)
	{
		if (c & (1 << bit_position))
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		bit_position--;
		usleep(100);
	}
}

void	my_message_sender(int server_pid, char *message)
{
	while (*message)
	{
		my_char_sender(server_pid, *message);
		message++;
	}
	my_char_sender(server_pid, '\0');
}

int	main(int ac, char **av)
{
	int	server_pid;

	if (ac != 3)
	{
		my_string_writer("Usage: ./client [server-pid] [message]\n");
		return (1);
	}
	server_pid = my_ascii_to_integer(av[1]);
	if (server_pid < 0)
	{
		ft_printf("Error: PID is negative\n");
		return (1);
	}
	my_message_sender(server_pid, av[2]);
	return (0);
}
