#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int codecount(char *path)	//�����ַ���
{
	char code;
    int count=0;
	FILE *file = fopen(path, "r");
    if(file==NULL)
	{
		printf("fail to open file!\n");
	}  
    while ((code = fgetc(file)) != EOF)
            count+= ((code== ' ') || (code== '\n') || (code != '\t'));//�ո񣬻��У�ˮƽ�Ʊ�������ַ�

    fclose(file);
    return count;
}
int wordcount(char *path)	//���㵥����
{    
    int is_word = 0;		//��¼����״̬
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
void run(char *type,char *path)		//�ж������Ǽ����ַ��������ǵ�����
{
	char *m="-c";
	char *n="-w";
	if(strcmp(type,m)==0)
	{
		printf("�ַ���:%d\n",codecount(path));
	}
	else if(strcmp(type,n)==0)
	{
	printf("������:%d\n",wordcount(path));
	}
	else
	{
	printf("type input error");
	}
}
int main(int argc,char *argv[])
{
	char path[100]="*.txt";	//���տ���̨����
	char *type;
	type=argv[1];
	strcpy(path,argv[2]);
    run(type,path);	 
	return 0;
}