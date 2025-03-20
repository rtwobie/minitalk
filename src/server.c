/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:22:49 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/20 19:20:18 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

static unsigned char	g_c;

static void	put_bit(int sig, unsigned char *g_c)
{
	if (sig == SIGUSR1)
		*g_c = *g_c << 1;
	if (sig == SIGUSR2)
		*g_c = *g_c << 1 | 1;
}

static void signal_handler(int sig)
{
	static int		size = 0;

	if (!size)
		g_c = 0;
	put_bit(sig, &g_c);
	if (++size == 8)
	{
		ft_putchar_fd((char)g_c, 1);
		size = 0;
	}
}

int main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	printf("PID: %i\n", getpid());
	while (1)
	{
		pause();
	}
}
