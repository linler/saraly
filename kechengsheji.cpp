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

 int read()    //读取职工工资数据
  {
	FILE *fp;
	q=zggz;
	if((fp=fopen("gz.dat","rb"))==NULL)
	{
		printf("无法打开文件\n");
		getch();
		exit(-1);
	}
	 for(;fread(q,sizeof(struct staff),1,fp);)
	 {
        q++;
        n++;
	 }
	 fclose(fp);
	printf("已读取%d位员工\n",n);
	return n;
 }
void write(struct staff S[],int n)    //保存职工工资数据
{     
	  int i;
	  FILE *fp;
	  q=zggz;
	  if((fp=fopen("gz.dat","wb"))==NULL)
	  {
		  printf("打开失败\n");
		  exit(0);
	  }
	  for(i=0;i<n;i++)
	  {
		  fwrite(q,sizeof(struct staff),1,fp);
		  q++;
		  
	  }
	      fclose(fp);
	      printf("文件保存成功\n");
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
	  if(n>100)
	  {
		  printf("员工信息已满!");
		  exit(-1);
	  }
	  else{
		   printf("\n");
		   printf("请输入员工编号:");
		   scanf("%s",S[n].number);
		   printf("请输入员工姓名:");
           scanf("%s",S[n].name);
		   printf("请输入岗位工资:");
		   scanf("%f",&S[n].gwgz);
		   printf("请输入薪级工资:");
		   scanf("%f",&S[n].xjgz);
		   printf("请输入职位津贴:");
		   scanf("%f",&S[n].zwjt);
		   printf("请输入绩效工资:");
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
	char del_number[10];    //存储需要删除员工的编号
    int flag=0;            //标记有没有该员工
	int del_count=0;      //记录已删除员工数
	printf("\n");
	printf("请输入需要删除员工编号:");
	scanf("%s",del_number);
	
	
		  for(int i=0;i<n;i++){
			if(strcmp(S[i].number,del_number)==0){    //找到需要删除的员工编号
				flag=1;
				if(flag){
					for(int j=i;j<n;j++){
						S[j]=S[j+1];					
					}
					del_count++;    //删除一个就加一
				}
			}
		}
	n=n-del_count;
	if(flag==1){
		printf("该员工信息已删除");
	}
	write(S,n);
}
void list(struct staff S[])    //浏览职工工资数据函数
{ 
	int i;
	for(i=0;i<n;i++)
	{     printf("编号     姓名     岗位工资     薪级工资     职务津贴     绩效工资     应发工资     个人所得税     实发工资\n");
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
	    puts("       ###  欢迎使用广西民族大学软件与信息安全学院职工工资管理系统  ###    ");
	puts("\n");
	do{
		
		puts("       请选择<0 - 5> :   ");
		puts("      =================================================================");
		puts("      |       1、查找员工信息                                         |");
		puts("      |       2、修改员工信息                                         |");
		puts("      |       3、添加员工信息                                         |");
		puts("      |       4、删除员工信息                                         |");
		puts("      |       5、显示员工信息                                         |");
		puts("      |       0、退出程序                                             |");
		puts("      =================================================================");
        puts("\n");
		puts("      你的选择是:    ");
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
			puts("\n谢谢使用\n");
			return 0;
		default:
			printf("\n输入错误,请重新输入");
			scanf("%d",&choose);
			break;
		}
		
	}while(choose != -1 );
		return 0;
}

