#include<stdio.h>
#include<string.h>

int mian(void)
{
	char buf[128]={0};                      //创建缓冲区
	FILE *fp=fopen("foo.txt","r");			  //打开文件
	if(fp==NULL)							            //文件不存在
	{
	    printf("file doesn't exist!");
		return 1;
	}
	while(fread(buf,1,128,fp))				  //每次读出一个文件内容
	{
	    printf("%s",buf);				        //将读到的字符串显示出来
		memset(buf,0,128);			  	      //每次使用完buf清空，防止对下次干扰
	}
	fclose(fp);
	return 0;
}
