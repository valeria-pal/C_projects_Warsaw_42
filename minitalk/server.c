#include "minitalk.h"


static void handle_signal(int sig, siginfo_t *info, void *context)
{
    (void)info; 
    (void)context; 

    static int bit_count = 0;
    static char character = 0;
    unsigned char bit_mask;

    if (sig == SIGUSR2)
    {
        bit_mask = 1 << (7 - bit_count);
        character |= bit_mask;
    }
    
    bit_count++;
    
    if (bit_count == 8)
    {
        ft_printf("%c", character);
        bit_count = 0;
        character = 0;
    }
}


int main(void)
{
    struct sigaction sa;
    pid_t pid = getpid();

    ft_printf("Server PID: %d\n", pid);

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();
}
