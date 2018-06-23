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
	  int num=0;    //计算工资总和
	  float gwgz1,xjgz1,zwjt1,jxgz1;
	  int flag=0;
	  char gonghao[10];
	  printf("请输入要修改员工编号:");
	  scanf("%s",gonghao);
      printf("请依次输入要修改员工工资:");
      printf("岗位工资:");
      scanf("%f",&gwgz1);
	  printf("薪级工资:");
	  scanf("%f",&xjgz1);
	  printf("职位津贴:");
	  scanf("%f",&zwjt1);
      printf("绩效工资:");
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
		  printf("修改失败");
	  }
	  else
	  {
		  printf("修改成功");
		  write(S,n);
	      system("pause");
		 
	  }
}
void add(struct staff S[])
{   
	 
	  FILE *fp;
	  if((fp=fopen("gz.dat","w"))==NULL)
	  {
		  printf("文件打开失败\n");
		  exit(-1);
	  }
	  if(n>100)
	  {
		  printf("员工信息已满!");
		  exit(-1);
	  }
	  else{
		  
		   struct staff a;
		   printf("\n");
		   printf("请输入员工编号:");
		   scanf("%s",a.number);
		   printf("请输入员工姓名:");
           scanf("%s",a.name);
		   printf("请输入岗位工资:");
		   scanf("%f",&a.gwgz);
		   printf("请输入薪级工资:");
		   scanf("%f",&a.xjgz);
		   printf("请输入职位津贴:");
		   scanf("%f",&a.zwjt);
		   printf("请输入绩效工资:");
		   scanf("%f",&a.jxgz);
		   a.yfgz=a.gwgz+a.xjgz+a.zwjt+a.jxgz;
		   S[n++]=a;
		   write(S,n);
	  }
	  if(fclose(fp))
	  {   cout<<n<<endl;
		  printf("\n文件关闭失败");
		  exit(-1);
	  }
}
     
	
int main()
{   struct staff zggz[100];
	read(zggz);
    //write(zggz,n);
	//find(zggz);
	//list(zggz);
	//modify(zggz);
	add(zggz);
	return 0;
}
