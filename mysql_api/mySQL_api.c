#include <stdio.h>
#include <string.h>
#include "mysql.h"

/*考虑写到profile里面，写一个读profile的接口*/
/*should read from profile, implement it later*/ 
const char* global_HostName = "localhost";
const char* global_UsrName = "root";
const char* global_Password = "199694";
const char* global_DBName = "test";
int global_port = 18184;

/*初始化并创建数据库连接*/
/*Init and create connect of database*/ 
int create_DBconnnector(MYSQL *connector)
{
	mysql_init(connector);
	
	if (&connector == NULL)
	{
		printf("Fault to init");
		return 0;
	}
		
	mysql_real_connect(connector, global_HostName, global_UsrName, global_Password, global_DBName, global_port, NULL, 0);
	if (&connector == NULL)
	{
		printf("Fault to create");
		return 0;
	}
	else
		return 1;
}


/*将信息插入数据库table中，mysql命令为“INSERT INTO tablename (column1,column2....)
 VALUES (value1,value2....)”*/
/*insert the imformation into table,mySQL command is "INSERT INTO tablename (column1,column2....)
 VALUES (value1,value2....)"*/
int insert(char *table, char *column, char *value, MYSQL connector)
{
	char command[100] = "INSERT INTO";
	strcat(command,table)
	strcat(command,cloumn);
	strcat(command,"VAUES");
	strcat(command,value);

	if ( mysql_real_query(&connector, command, strlen(command) ) == 0)
	{
		return 1;
	}
	else
	{
		printf("Fault to insert message into %s",table);
		return 0;
	}

}

/*mySQL command "SELECT column FROM table WHERE require"*/
int select(char *table, MYSQL connector, char *column, char *result, char *require)
{
	char command[50] = "SELECT"


	strcat(command,cloumn);
	strcat(command,"FROM");
	strcat(command,table);
	strcat(command,"WHERE");
	strcat(command,require);

	if ( mysql_real_query(&connector, command, strlen(command) ) == 0)
	{
		if ( (result_setsPtr = mysql_store_result (&connector)) !=NULL )
		{
				char **row = mysql_fetch_row(result_setsPtr);
				result = *row[0];			
				return 1;
		}	
		else 
		{
			printf("It returned nothing.");
			return 0;
		}
	}
	else 
		printf("Fault to get imformation from %s",table);	
}

