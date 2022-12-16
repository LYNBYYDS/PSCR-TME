#include <iostream>
#include <unistd.h>

int main () {
	const int N = 3;
	std::cout << "main pid=" << getpid() << std::endl;
    int nb_fils = 0;
	for (int i=1, j=N; i <= N && j == N; i++ ) {
        pid_t fpid = fork();
        if (fpid != 0) {
            nb_fils++;
            continue;
        } else {
            nb_fils = 0;
        }
        //std::cout << " i:j " << i << ":" << j << std::endl;
        for (int k = 1; k <= i && j == N; k++) {
            fpid = fork();
            if (fpid != 0) {
                nb_fils++;
                continue;
            } else {
                nb_fils = 0;
            }
            j = 0;
            //std::cout << " k:j " << k << ":" << j << std::endl;
		}
    }

	for(int i = 0; i < nb_fils; i++){
	    int status;
	    int pid = wait(&status);
    }
    std::cout << "Fin du processus " << getpid() << ", pere : " << getppid() << std::endl;
	return 0;
}
