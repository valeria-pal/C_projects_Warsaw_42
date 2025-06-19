/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:06:29 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/19 16:06:32 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libftprintf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	send_char(pid_t server_pid, char c);

#endif