#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{
	int sockfd;
	struct sockaddr_in addr_s,addr_c;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	addr_c.sin_family = AF_INET;
	addr_c.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr_c.sin_port = 10000;
	int len_c = sizeof(addr_c);
	
		

	addr_s.sin_family = AF_INET;
	addr_s.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr_s.sin_port = 9734;
	int len_s = sizeof(addr_s);



	bind(sockfd,(struct sockaddr_in *)&addr_c,len_c); 
	

	char a[256];

	connect(sockfd, (struct sockaddr_in *)&addr_s, len_s);

	scanf("%s",a);
	int str_len = sizeof(a);

	write(sockfd,&a,str_len);
	read(sockfd,&a,str_len);

	printf("%s",a);
	close(sockfd);

}
