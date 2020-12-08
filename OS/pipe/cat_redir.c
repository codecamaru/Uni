// redir_output.c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc,char *argv[]) {
    int fd;
    char *arch = "ls_salida.txt";
    mode_t fd_mode = S_IRWXU;// file premissions

    fd = open(arch,O_RDONLY | O_CREAT,fd_mode);
    if (dup2(fd,STDIN_FILENO) == -1) { 
        printf("Error calling dup2\n");
        exit(-1);
    }
    if (execl("/bin/cat","cat",arch,NULL) < 0){
        printf("error");
    };
    
    close(fd);
    return(0);
}


