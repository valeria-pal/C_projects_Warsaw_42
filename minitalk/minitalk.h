#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libftprintf/ft_printf.h"

void send_char(pid_t server_pid, char c);


#endif