#include<stdio.h>
#include<stdlib.h>
#define WRITE 0
#define READ 1
#define ERROR 2
int wr_flag=22;//����д�����ı�־
int get_info_from_html(char string[50])
{
	char *data;
	printf("Content-Type:text/html\n\n");
	//��ӡHTMLͷ
	printf("<title>CGI���Խ����ҳ</title>");
	printf("<h2>��ҳ�����ն˲��Գ���</h2>\n");
	data=getenv("QUERY_STRING"); //�����ҳ�����������
	//��ȡ��������  
	if(data==NULL)
	{
		printf("<p>Error!Error in passing data to script</p>\n");
		return ERROR;
	}
	else
	{
		wr_flag=strncmp(data,"write",5)?READ:WRITE;//�ж���ҳ����������д����,strncmp()�ַ����Ƚ���ȷ���0
		if(wr_flag==WRITE)
		{
			if(sscanf(data,"write=%s",string)!=1)//��data���������Ϣ��%s�ĸ�ʽ����string�������
			{  
				printf("<p>Error!Invalid data.Data must be string.</p>\n");	
				return ERROR;
			}
			else	
			{
				printf("<p>���ݷ��ͳɹ���</p>\n");
				return WRITE;
			}			
		}
		else	//������ҳ���ж�����
		{
			return READ;
		}

	}
	
		
}

