#include<stdio.h>
#include<stdlib.h>
#define WRITE 0
#define READ 1
#define ERROR 2
int wr_flag=22;//读或写操作的标志
int get_info_from_html(char string[50])
{
	char *data;
	printf("Content-Type:text/html\n\n");
	//打印HTML头
	printf("<title>CGI测试结果网页</title>");
	printf("<h2>网页控制终端测试程序</h2>\n");
	data=getenv("QUERY_STRING"); //获得网页上输入的数据
	//获取环境变量  
	if(data==NULL)
	{
		printf("<p>Error!Error in passing data to script</p>\n");
		return ERROR;
	}
	else
	{
		wr_flag=strncmp(data,"write",5)?READ:WRITE;//判断网页触发读还是写操作,strncmp()字符串比较相等返回0
		if(wr_flag==WRITE)
		{
			if(sscanf(data,"write=%s",string)!=1)//将data中输入的信息按%s的格式赋给string这个变量
			{  
				printf("<p>Error!Invalid data.Data must be string.</p>\n");	
				return ERROR;
			}
			else	
			{
				printf("<p>数据发送成功！</p>\n");
				return WRITE;
			}			
		}
		else	//否则网页进行读操作
		{
			return READ;
		}

	}
	
		
}

