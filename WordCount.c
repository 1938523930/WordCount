#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int codecount(char *path)	//计算字符数
{
	char code;
    int count=0;
	FILE *file = fopen(path, "r");
    if(file==NULL)
	{
		printf("fail to open file!\n");
	}  
    while ((code = fgetc(file)) != EOF)
            count+= ((code== ' ') || (code== '\n') || (code != '\t'));//空格，换行，水平制表符均算字符

    fclose(file);
    return count;
}
int wordcount(char *path)	//计算单词数
{    
    int is_word = 0;		//记录单词状态
    int count = 0;
	char word;
    FILE *file = fopen(path, "r");
    if(file==NULL)
	{
			printf("fail to open file!\n");
	}
    while ((word=fgetc(file)) != EOF) 
	{
        if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z')) 
		{         
            count += (is_word == 0);
            is_word = 1;   
        }
        else 
            is_word = 0;    
    }
    fclose(file);
    return count;
}
void run(char *type,char *path)		//判断命令是计算字符数，还是单词数
{
	char *m="-c";
	char *n="-w";
	if(strcmp(type,m)==0)
	{
		printf("字符数:%d\n",codecount(path));
	}
	else if(strcmp(type,n)==0)
	{
	printf("单词数:%d\n",wordcount(path));
	}
	else
	{
	printf("type input error");
	}
}
int main(int argc,char *argv[])
{
	char path[100]="*.txt";	//接收控制台传参
	char *type;
	type=argv[1];
	strcpy(path,argv[2]);
    run(type,path);	 
	return 0;
}