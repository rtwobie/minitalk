/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:47:57 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/18 17:29:05 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"

void send_bit(pid_t pid, unsigned char octet)
{
	size_t i;

	i = 7;
	while (i > 0)
	{
		if (octet & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		--i;
	}
}

void send_byte(pid_t pid, char *s)
{
	while (*s)
	{
		send_bit(pid, *s);
		++s;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		return (1);
	send_bit(ft_atoi(argv[1]), argv[2][0]);
	/*send_byte(ft_atoi(argv[1]), argv[2]);*/
}
