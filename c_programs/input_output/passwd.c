#include <stdio.h>
#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
	int fd = open("/etc/passwd", O_RDONLY);

	if(fd == -1){
		err(1, "failed to open file");	
	}
	
	int passwd_copy = open("passwd", O_CREAT | O_WRONLY);
	
	const size_t buffer_sz = 4096;
	
	char buf[buffer_sz];
	int read_cnt = 0;
	
	while(read_cnt = read(fd, &buf, buffer_sz)){
		
		for(int i = 0; i < read_cnt; i++){
			if(buf[i] == ':'){
				buf[i] = '?';
			}
		}
		
		if(read_cnt != write(passwd_copy, &buf, read_cnt)){
			err(2, "error in writing!\n");
		}	
	}
	close(passwd_copy);
	exit(0);
}