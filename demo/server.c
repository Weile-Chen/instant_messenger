#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int sockfd_s,sockfd_c;
	int len_s,len_c;

	struct sockaddr_in address_s;
	struct sockaddr_in address_c;

	pid_t new_pid;

	sockfd_s = socket(AF_INET,SOCK_STREAM,0);

	address_s.sin_family = AF_INET;
	address_s.sin_addr.s_addr = inet_addr("127.0.0.1");			//127.0.0.1默认为localhost，即本机地址
	address_s.sin_port = 9734;
	len_s = sizeof(server_address);
	

	bind(sockfd_s, (struct sockaddr *)&address_s, len_s);

	listen(sockfd_s,5);

	while(1)
	{
		new_pid = fork() ;
		if (new_pid == 0)
		{
			len_c = sizeof(address_c);
			sockfd_c = accept(server_s,(struct sockaddr_in *)&address_c,&len_c);

			char ch[256];
			char a[]="accept!";
			read(sockfd_c,&ch,256);

			printf("%s",ch);	

			write(sockfd_c,&a,sizeof(a));

			close(sockfd_c);
			exit(0);

		}
		else
		{
			waitpid(new_pid,NULL,0);
			new_pid = 0;
		}
	}
}
