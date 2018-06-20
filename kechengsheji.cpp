#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<iostream>
using namespace std;
extern int n=0;
struct staff
{
  char number[5];
  char name[10];
  float gwgz;
  float xjgz;
  float zwjt;
  float jxgz;
  float yfgz;
  float gs;
  float sfgz;
}zggz[100],*q;
  int read();
  void write();

  int read()    //读取职工工资数据
  {
	  int i;
	  FILE *fp;
	  q=zggz;
	  if((fp=fopen("gz.dat","r"))==NULL)
	  {
		  printf("Cannot open file strike any key exit\n");
		  getch();
		  exit(-1);
	  }
  for(i=0;i<100;i++)
  { 
	  if(fread(q,sizeof(struct staff),1,fp)!=0) 
	  {
		  printf("文件读写有误\n");
          break;
	  }
	      		  
  }
       n++;
       cout<<q->number<<q->name<<q->gwgz<<q->xjgz<<q->zwjt<<q->jxgz<<q->yfgz<<q->gs<<q->sfgz<<endl;
       cout<<n<<endl;
	  fclose(fp);
	  return 0 ;
  }
  void write()    //保存职工工资数据
  {   
	  int i;
	  FILE *fp;
	  if(n>0)
	  {
	  if((fp=fopen("gz.dat","wb+"))==NULL)
	  {
		  printf("Cannot open file strike any key exit\n");
		  exit(-1);
	  }
  for(i=0;i<100;i++)
	  if(fwrite(&zggz[i],sizeof(struct staff),1,fp)!=0)
		  printf("文件读写出错\n");
	  fclose(fp);
	  }
  }
int main()
{   read();
	return 0;
}
