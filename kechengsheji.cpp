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

  int read(struct staff S[])    //��ȡְ����������
  {
	  
	  FILE *fp;
	  struct staff s;
	  q=zggz;
	  if((fp=fopen("gz.dat","r"))==NULL)
	  {
		  printf("�ļ���ʧ��\n");
		  exit(-1);
	  }
      while(!feof(fp))
	  {
		  fscanf(fp,"%s\t",&s.number);
		  fscanf(fp,"%s\t",&s.name);
		  fscanf(fp,"%f\t",&s.gwgz);
		  fscanf(fp,"%f\t",&s.xjgz);
		  fscanf(fp,"%f\t",&s.zwjt);
		  fscanf(fp,"%f\t",&s.jxgz);
		  fscanf(fp,"%f\t",&s.yfgz);
		  fscanf(fp,"%f\t",&s.gs);
		  fscanf(fp,"%f\t",&s.sfgz);
		  S[n]=s;
		  q++;
		  n++;
	  }
	 
	   printf("\n�Ѷ���%d��Ա����Ϣ\n",n);
	  fclose(fp);
	  return n;
	 
  }
  void write(struct staff S[],int n)    //����ְ����������
{    
	  int i;
	  FILE *fp;
	  if(n>0)
	  {
	  if((fp=fopen("gz.dat","w"))==NULL)
	  {
		  printf("�ļ���ʧ��\n");
		  exit(-1);
	  }
  for(i=0;i<n;i++)
  {
	  fprintf(fp,"%s\t",S[i].number);
	  fprintf(fp,"%s\t",S[i].name);
	  fprintf(fp,"%f\t",S[i].gwgz);
	  fprintf(fp,"%f\t",S[i].xjgz);
	  fprintf(fp,"%f\t",S[i].zwjt);
	  fprintf(fp,"%f\t",S[i].jxgz);
	  fprintf(fp,"%f\t",S[i].yfgz);
	  fprintf(fp,"%f\t",S[i].gs);
	  fprintf(fp,"%ft",S[i].sfgz);
  }
  printf("\n��д��%d��Ա����Ϣ\n",n);
  fclose(fp);
	  }
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
void list(struct staff S[])    //���ְ���������ݺ���
{ 
	int i;
	for(i=0;i<n;i++)
	{     printf("���\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
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

}
void modify(struct staff S[])
{
      int i;
	  float gwgz1,xjgz1,zwjt1,jxgz1,yfgz1,gs1,sfgz1;
	  int flag=0;
	  char gonghao[10];
	  printf("������Ҫ�޸�Ա�����:");
	  scanf("%s",gonghao);
      printf("����������Ҫ�޸�Ա������:");
      scanf("%f",&gwgz1);
	  scanf("%f",&xjgz1);
	  scanf("%f",&zwjt1);
	  scanf("%f",&jxgz1);
	  scanf("%f",&yfgz1);
	  scanf("%f",&gs1);
	  scanf("%f",&sfgz1);
	  for(i=0;i<n;i++)
	  {
		  S[i].gwgz=gwgz1;
		  S[i].xjgz=xjgz1;
		  S[i].zwjt=zwjt1;
		  S[i].jxgz=jxgz1;
		  S[i].yfgz=yfgz1;
		  S[i].gs=gs1;
		  S[i].sfgz=sfgz1;
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
	
int main()
{   struct staff zggz[100];
	read(zggz);
    //write(zggz,n);
	//find(zggz);
	//list(zggz);
	modify(zggz);
	return 0;
}
