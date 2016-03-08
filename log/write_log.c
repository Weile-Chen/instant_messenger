#include <time.h> 
#include <stdio.h>
#include <string.h>
 
int write_log(char *log_detail) 
{ 
    time_t t = time(0); 
    char log[256];
    FILE *fp;
    
    //获得当前系统时间 
    strftime( log, sizeof(log), "%Y/%m/%d %X %A ",localtime(&t));    
	strcat(log,log_detail);
    
    
	//写入日志文档
 	fp = fopen("./test","a");
 	fputs(log,fp);
 	fputs("\n",fp);
 	fclose(fp); 

	return 0;
}