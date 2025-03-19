/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:22:49 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/18 16:48:13 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned char c = 0;

static void put_zero(int sig)
{
	(void)sig;
	/*c = c << 1;*/
	write(1, "0", 1);
}

static void put_one(int sig)
{
	(void)sig;
	write(1, "1", 1);
	/*c = c << 1 | 1;*/
}

int main(void)
{
	signal(SIGUSR1, put_zero);
	signal(SIGUSR2, put_one);
	printf("PID: %i\n", getpid());
	while (1)
	{
		pause();
	}
}
