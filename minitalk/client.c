#include "minitalk.h"

void send_char(pid_t server_pid, char c)
{
    int i = 0;
    unsigned char bit_mask;

    while (i < 8)
    {
        bit_mask = 1 << (7 - i);
        if (c & bit_mask)
            kill(server_pid, SIGUSR2); 
        else
            kill(server_pid, SIGUSR1); 
        usleep(100);
        i++;
    }
}


int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_printf("Use please : ./client <server_pid> <message>\n");
        return (1);
    }

    pid_t server_pid = atoi(argv[1]);
    char *message = argv[2];

    while (*message)
    {
        send_char(server_pid, *message);
        message++;
    }

    send_char(server_pid, '\0'); 
    return (0);
}