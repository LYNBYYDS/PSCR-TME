#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

void fils(int rang){
    std::cout << "Je suis " << getpid() << ". ";
    std::cout << "Pere est "<< getppid() << ". ";
    std::cout << "Rang de creation: "<< rang << std::endl;
}

int main(){
    int N = 4;
    std::cout << "main pid = " << getpid() << std::endl;
    int pids[N];
    int i = 0;
    for(; i < N; ++i){
        pid_t fpid = fork();
        if(fpid == -1){
            perror("fork");
            exit(1);
        }else if (fpid == 0){ // fils
            fils(i);
            return i;
        }else{ // pere
            pids[i] = fpid;
        }
    }
    /*Q2
    for(int i = 0; i < N; ++i){
        int status;
        int pid = wait(&status);
        std::cout << "Fin du fils de pid = " << pid << " return " << WEXITSTATUS(status) << std::endl;
    }
    */
    if(i != N){
        int status;
        int pid = waitpid(pids[i], &status, 0);
        std::cout << "Fin du fils de pid = " << pid << " return " << WEXITSTATUS(status) << std::endl;
    }
    return 0;
}