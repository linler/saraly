#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<iostream>
using namespace std;
int n=0;    //全局变量，记录职工数量
struct staff
{
  char number[10];
  char name[10];
  float gwgz,xjgz,zwjt,jxgz,yfgz,gs,sfgz;
}zggz[100],*q;

  int read(struct staff S[])    //读取职工工资数据
  {
	  
	  FILE *fp;
	  struct staff s;
	  q=zggz;
	  if((fp=fopen("gz.dat","r"))==NULL)
	  {
		  printf("文件打开失败\n");
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
	 
	   printf("\n已读入%d个员工信息\n",n);
	  fclose(fp);
	  return n;
	 
  }
  void write(struct staff S[],int n)    //保存职工工资数据
{    
	  int i;
	  FILE *fp;
	  if(n>0)
	  {
	  if((fp=fopen("gz.dat","w"))==NULL)
	  {
		  printf("文件打开失败\n");
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
  printf("\n已写入%d个员工信息\n",n);
  fclose(fp);
	  }
}
  void find(struct staff S[])    //查询职工工资数据函数
  {
	  int i;
	  int flag=0;
	  char number[10];
	  printf("请输入要查询员工编号:");
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
		  printf("编号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
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
		  printf("没有找到该编号员工!\n");
	  }
	  printf("\n");
	  system("pause");
  }
void list(struct staff S[])    //浏览职工工资数据函数
{ 
	int i;
	for(i=0;i<n;i++)
	{     printf("编号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
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
	  printf("请输入要修改员工编号:");
	  scanf("%s",gonghao);
      printf("请依次输入要修改员工工资:");
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
		  printf("修改失败");
	  }
	  else
	  {
		  printf("修改成功");
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
