#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	char buf[2048]={0};                       //缓冲区
	FILE *fp=NULL;
	FILE *fpw=NULL;
	long length=0;							//写入文件总长度

	if(argc!=3)        //总共输入三个参数cp,要写入的文件名，复制的文件名
	{
		printf("argc error!");
		exit(1);
	}
	fp=fopen(argv[1],"r");                 //打开文件错误
	if(fp==NULL)
	{
		printf("file open error!");
		exit(1);
	}
	fpw=fopen(argv[2],"w");            //写入文件打开错误
	if(fpw==NULL)
	{
		printf("create file error!");
		exit(1);
	}
	fseek(fp,0,SEEK_END);            //偏移文件末尾
 	length=ftell(fp);						//算文件长度
	fseek(fp,0,SEEK_SET);				//指针偏移到文件开头
	fread(buf,length,1,fp);				//读出文件
	fwrite(buf,length,1,fpw);				//写入文件
	fclose(fp);
	fclose(fpw);
	return 0;
} 	
