//============================================================================
// Name        : IPC.cpp
// Author      : KL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

using namespace std;

int main() {

	int fd[2];//file descriptor, read,write
	pid_t pid;
	char buff[20];

	if(pipe(fd) < 0){
		cout<<"Create Pipe Error!\n";
		exit(0);
	}

	if((pid = fork()) < 0){
		cout<<"Fork failed!\n";
		exit(0);
	}else if(pid > 0){
		//parent process
		close(fd[0]);//close read;
		sleep(30);
		cout<<"parent process writing...\n";
		cout << "parent id is " << getpid() << endl << endl;
		cout << "child id is " << pid << endl;
		write(fd[1],"hello world\n",12);
	}else{
		//child process
		close(fd[1]);//close write;
		cout<<"child process reading\n";
		cout << getpid() << endl << endl;
		read(fd[0],buff,20);
		cout<<buff;
	}

	return 0;
}
