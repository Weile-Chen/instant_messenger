#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int print_message(char *sender, char *message);
char* write_message();

int print_message(char *sender, char *message){
	printf("%s:%s\n", sender, message);
	return 0;
}

char* write_message(){
	char *message;
	char format[MAX_SIZE] = "gegema:";
	char format2[MAX_SIZE] = "world:";


	int base_line = 24;
	static char chats[MAX_SIZE];
	system("clear");
	printf("\033[%d;%dH", 0, 0);
	printf("%s", chats);
	printf("\033[%d;%dHMe:", base_line, 0);
	printf("\033[K");
	printf("\033[%d;%dH", base_line, 4);
	fgets(message, 1000, stdin);
	strcat(format, message);
	strcat(chats, format);
	printf("\033[%d;%dH", 0, 0);
	printf("%s", chats);
	return message;
}


int main(){
	system("clear");
	while(1){
		write_message();
	}
	return 0;
}
