#include <stdio.h>
#include <string.h>
char *add_message(char *sender,char *receiver,char *body,char *type,char *packet)
{
	strcat(packet, "PIM");
	strcat(packet, type);
	strcat(packet, receiver);
	strcat(packet, sender);
	strcat(packet, body);	

	return packet;	
}

int cut_message(char *sender,char *receiver,char *body,char *type,char *packet)
{
	int i = 1;
	
	if( !((packet[0] == 'P') && (packet[1] == 'I') && (packet[2] == 'M')) )
		return 1;

	i = 0;
	while( i < 3 )
	{
		type[i] = packet[i + 3];
		i++;
	}
	
	i = 0;
	while( i < 9 )
	{
		receiver[i] = packet[i + 6];
		i++;
	}
	
	i = 0;
	while( i < 9 )
	{
		sender[i] = packet[i + 15];
		i++;
	}

	i = 0;
	while( i < 234)
	{
		body[i] = packet[i + 24];
		i++;	
	}
	
	return 0;
}

int main(void)
{
	char sender[10] = "",receiver[10] = "",body[241],type[4] = "000",packet[256] = "";
	char message[241] = "";

	gets(message);
	
	strcat(receiver, "751689250");
	strcat(sender, "123456789");
	
	add_message(sender,receiver,message,type,packet);
	
	printf("%s\n",packet);
	
	char sender1[10] = "",receiver1[10] = "",body1[241],type1[4] = "";
	
	cut_message(sender1,receiver1,body1,type1,packet);
	
	printf("%s\n%s\n%s\n%s\n",sender1,receiver1,type1,body1);
}
