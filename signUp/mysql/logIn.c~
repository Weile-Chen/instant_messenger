#include <stdio.h>
#include <string.h>
#include "mysql.h"


const char* global_HostName = "localhost";
const char* global_UsrName = "root";
const char* global_Password = "199694";
const char* global_DBName = "test";
int global_port = 18184;

int initConnector(MYSQL *ConnectorCore)
{
	mysql_init(ConnectorCore);
	
	mysql_real_connect(ConnectorCore, global_HostName, global_UsrName, global_Password, global_DBName, global_port, NULL, 0);
	
	
}

int isExist(char *number, char *password_real, MYSQL *ConnectorCore)
{
	MYSQL_RES *result_setsPtr;
	char command [49] = "SELECT password FROM user WHERE number = ";
	strcat(command,number);	
	int i;	
	char *row;
	
	if ( mysql_real_query(ConnectorCore, command, strlen(command) ) == 0){
		if ( (result_setsPtr = mysql_store_result (ConnectorCore)) !=NULL )
		{
				row = *(mysql_fetch_row(result_setsPtr));
			
				for(i = 0; i < 16;i++)	
				{
					password_real[i] = row[i];
				}					
				return 1;
		}	
		else 
			{
				
				return 0;
			}
	}
	else 
		
		
		return 2;	
}

int isMatch(char *password,char *password_real)
{
	int i;
	for(i=0;i<16;i++)
	{
		if(password[i] == '\0' && password_real[i] == '\0')
		{
			return 1;
		}
		else 
		if (password[i] == password_real[i])
		{

		}
		else return 0;

	}
	return 1;
}

int logIn(char *number, char *password)
{
	char password_real[16];
	MYSQL Connector;
	
	initConnector(&Connector);


	if( isExist(number, password_real, &Connector) == 1)
	{
		if(isMatch(password, password_real) == 1)
		{
			return 1;
		}
		else 
		{
			printf("密码错误。请重新输入");
			return 0;
		}

	}
	else 
	{
		printf("用户不存在。请重新输入");
		return 0;
	}
}

int signUp()
{
	char number[8];
	char password_f[16],password_s[16];
	char *password;
	MYSQL connector;
	int i;
	char command[100] = "INSERT INTO user VALUES(\"";
	char command2[] = "\",\"";
	char command3[] = "\")";

	initConnector(&connector);

	do
	{	
		printf("Please enter your number:");
		scanf("%s",number);

		i = isExist(number, password, &connector);

	}while(i == 0);

	do
	{
		printf("Please enter your password:");
		scanf("%s",password_f);

		printf("Please enter your password again:");
		scanf("%s",password_s);
		
		i = isMatch(password_f, password_s);
	}while(i == 0);

	strcat(command,number);
	strcat(command,command2);
	strcat(command,password_s);
	strcat(command,command3);
	
	mysql_real_query(&connector, command, strlen(command));
}
		
int main(void)
{
	char number[8];
	char password[16];
	int i;
	
	scanf("%d",&i);
	if(i == 1)
	{
		do
		{
			printf("please enter number:\n");
			scanf("%s",number);		

			printf("please enter password:\n");
			scanf("%s",password);				

		}while(logIn(number,password) == 0);	
	}else
		signUp();	
}

