#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<iostream>
using namespace std;
int n=0;    //ȫ�ֱ�������¼ְ������
struct staff
{
  char number[10];
  char name[10];
  float gwgz,xjgz,zwjt,jxgz,yfgz,gs,sfgz;
}zggz[100],*q;

 int read()    //��ȡְ����������
  {
	FILE *fp;
	q=zggz;
	if((fp=fopen("gz.dat","rb"))==NULL)
	{
		printf("�޷����ļ�\n");
		getch();
		exit(-1);
	}
	 for(;fread(q,sizeof(struct staff),1,fp);)
	 {
        q++;
        n++;
	 }
	 fclose(fp);
	printf("�Ѷ�ȡ%dλԱ��\n",n);
	return n;
 }
void write(struct staff S[],int n)    //����ְ����������
{     
	  int i;
	  FILE *fp;
	  q=zggz;
	  if((fp=fopen("gz.dat","wb"))==NULL)
	  {
		  printf("��ʧ��\n");
		  exit(0);
	  }
	  for(i=0;i<n;i++)
	  {
		  fwrite(q,sizeof(struct staff),1,fp);
		  q++;
		  
	  }
	      fclose(fp);
	      printf("�ļ�����ɹ�\n");
  }
int grsds(float yfgz)
{   
	float tax;
	if(yfgz<=500)
		tax=yfgz*0.05;
	else if(yfgz>500 && yfgz<=2000)
        tax=yfgz*0.1;
	else if(yfgz>2000 && yfgz<=5000)
		tax=yfgz*0.15;
	else if(yfgz>5000 && yfgz<=20000)
		tax=yfgz*0.2;
	else if(yfgz>20000 && yfgz<=40000)
	    tax=yfgz*0.25;
	else if(yfgz>40000 && yfgz<=60000)
		tax=yfgz*0.3;
	else if(yfgz>60000 && yfgz<=80000)
        tax=yfgz*0.35;
	else if(yfgz>80000 && yfgz<=100000)
		tax=yfgz*0.4;
	else if(yfgz>100000 )
        tax=yfgz*0.45;
	return tax;
}	 
void find(struct staff S[])    //��ѯְ���������ݺ���
  {
	  int i;
	  int flag=0;
	  char number[10];
	  printf("������Ҫ��ѯԱ�����:");
	  scanf("%s",number);
	  for(i=0;i<n;i++)
	  {   
		  if(strcmp(S[i].number,number)==0)
		  {  flag=1;
		    
		     break;
		  }
	  }
	  if(flag)
	  {
		  printf("���\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
		  printf("%s\t",S[i].number);
		  printf("%s\t",S[i].name);
		  printf("%f\t",S[i].gwgz);
		  printf("%f\t",S[i].xjgz);
		  printf("%f\t",S[i].zwjt);
		  printf("%f\t",S[i].jxgz);
		  printf("%f\t",S[i].yfgz);
		  printf("%f\t",S[i].gs);
		  printf("%f\t",S[i].sfgz);
	  }
	  else
	  {
		  printf("û���ҵ��ñ��Ա��!\n");
	  }
	  printf("\n");
	  system("pause");
  }



void modify(struct staff S[])
{
      int i;
	  int num=0;    //���㹤���ܺ�
	  float gwgz1,xjgz1,zwjt1,jxgz1;
	  int flag=0;
	  char gonghao[10];
	  printf("������Ҫ�޸�Ա�����:");
	  scanf("%s",gonghao);
      printf("����������Ҫ�޸�Ա������:");
      printf("��λ����:");
      scanf("%f",&gwgz1);
	  printf("н������:");
	  scanf("%f",&xjgz1);
	  printf("ְλ����:");
	  scanf("%f",&zwjt1);
      printf("��Ч����:");
	  scanf("%f",&jxgz1);
	  for(i=0;i<n;i++)
	  {
		  S[i].gwgz=gwgz1;
		  S[i].xjgz=xjgz1;
		  S[i].zwjt=zwjt1;
		  S[i].jxgz=jxgz1;
		  S[i].yfgz=S[i].gwgz+S[i].xjgz+S[i].zwjt+S[i].jxgz;

		  flag=1;
	  }
	  if(flag==0)
	  {
		  printf("�޸�ʧ��");
	  }
	  else
	  {
		  printf("�޸ĳɹ�");
		  write(S,n);
	      system("pause");
		 
	  }
}
void add(struct staff S[])
{     
	  if(n>100)
	  {
		  printf("Ա����Ϣ����!");
		  exit(-1);
	  }
	  else{
		   printf("\n");
		   printf("������Ա�����:");
		   scanf("%s",S[n].number);
		   printf("������Ա������:");
           scanf("%s",S[n].name);
		   printf("�������λ����:");
		   scanf("%f",&S[n].gwgz);
		   printf("������н������:");
		   scanf("%f",&S[n].xjgz);
		   printf("������ְλ����:");
		   scanf("%f",&S[n].zwjt);
		   printf("�����뼨Ч����:");
		   scanf("%f",&S[n].jxgz);
		   S[n].yfgz=S[n].gwgz+S[n].xjgz+S[n].zwjt+S[n].jxgz;
		   S[n].gs=grsds(S[n].yfgz);
		   S[n].sfgz=S[n].yfgz-S[n].gs;
           n++;
		   write(S,n);
	  }	  
}
void del(struct staff S[])
{
	char del_number[10];    //�洢��Ҫɾ��Ա���ı��
    int flag=0;            //�����û�и�Ա��
	int del_count=0;      //��¼��ɾ��Ա����
	printf("\n");
	printf("��������Ҫɾ��Ա�����:");
	scanf("%s",del_number);
	
	
		  for(int i=0;i<n;i++){
			if(strcmp(S[i].number,del_number)==0){    //�ҵ���Ҫɾ����Ա�����
				flag=1;
				if(flag){
					for(int j=i;j<n;j++){
						S[j]=S[j+1];					
					}
					del_count++;    //ɾ��һ���ͼ�һ
				}
			}
		}
	n=n-del_count;
	if(flag==1){
		printf("��Ա����Ϣ��ɾ��");
	}
	write(S,n);
}
void list(struct staff S[])    //���ְ���������ݺ���
{ 
	int i;
	for(i=0;i<n;i++)
	{     printf("���     ����     ��λ����     н������     ְ�����     ��Ч����     Ӧ������     ��������˰     ʵ������\n");
		  printf("%s\t",S[i].number);    
		  printf("%s\t",S[i].name);	  
		  printf("%.2f\t",S[i].gwgz);	  
		  printf("%.2f\t",S[i].xjgz);		  
		  printf("%.2f\t",S[i].zwjt);		  
		  printf("%.2f\t",S[i].jxgz);		 
		  printf("%.2f\t",S[i].yfgz);		  
		  printf("%.2f\t",S[i].gs);
		  printf("%.2f\n",S[i].sfgz);
		  puts("********************************************************************************");
	}

}
int main()
{   int choose;
	n=read();
	puts("\n");
	    puts("       ###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ  ###    ");
	puts("\n");
	do{
		
		puts("       ��ѡ��<0 - 5> :   ");
		puts("      =================================================================");
		puts("      |       1������Ա����Ϣ                                         |");
		puts("      |       2���޸�Ա����Ϣ                                         |");
		puts("      |       3�����Ա����Ϣ                                         |");
		puts("      |       4��ɾ��Ա����Ϣ                                         |");
		puts("      |       5����ʾԱ����Ϣ                                         |");
		puts("      |       0���˳�����                                             |");
		puts("      =================================================================");
        puts("\n");
		puts("      ���ѡ����:    ");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			find(zggz);
			break;
		case 2:
			modify(zggz);
			break;
		case 3:
			add(zggz);
			break;
		case 4:
			del(zggz);
			break;
		case 5:
			list(zggz);
			break;
		case 0:
			puts("\nллʹ��\n");
			return 0;
		default:
			printf("\n�������,����������");
			scanf("%d",&choose);
			break;
		}
		
	}while(choose != -1 );
		return 0;
}

