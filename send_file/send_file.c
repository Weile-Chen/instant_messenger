#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
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

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	bind(sockfd,(struct sockaddr_in *)&addr_c,len_c); 
	printf("%d\n",connect(sockfd, (struct sockaddr_in *)&addr_s, len_s));	
	

	FILE *file = NULL;

	file = fopen("./2.rmvb","rb"); //以二进制方式打开文件

	int num_send=0;               
    char send_buf[1024]={0}; 

    while(1)
    {
    	int nRead = fread(send_buf, 1024, 1, file);

    	num_send = send(sockfd, send_buf, 1024, 0 );

		printf("%d\n",num_send);

    	if(feof(file))  
        {  
            printf("success to transmit file to server\n");  
            break;  
        }      
    }

    close(sockfd);
    fclose(file);
	
}
