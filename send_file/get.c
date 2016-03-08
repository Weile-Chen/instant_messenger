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

	sockfd_s = socket(AF_INET,SOCK_STREAM,0);
	address_s.sin_family = AF_INET;
	address_s.sin_addr.s_addr = inet_addr("127.0.0.1");			//127.0.0.1默认为localhost，即本机地址
	address_s.sin_port = 9734;
	len_s = sizeof(address_s);

	int a = bind(sockfd_s, (struct sockaddr *)&address_s, len_s);
	printf("%d",a);	
	a = listen(sockfd_s,5);
	printf("%d",a);
	FILE *file = NULL;
	file = fopen("../hehe","wb+");   //打开文件，准备写入

	char recv_buf[1024];
	int num_recv, num_write;
	int i;	
	len_c = sizeof(address_c);
	sockfd_c = accept(sockfd_s,(struct sockaddr_in *)&address_c,&len_c);

	while(1)
	{
		num_recv = recv( sockfd_c, recv_buf, 1024, 0 );
	
		if( num_recv == 0 )  
        {  
            printf( "success to receive faile from client\n" );  
            break;  
        }  
  
  
        num_write=fwrite(recv_buf,1024,1,file);  
  
        if( num_write<1 && ferror(file)!=0 )  
        {  
            printf( "failed to write file\n" );  
            return;  
        }    

	}

	close(sockfd_s);
    fclose(file);
}	
