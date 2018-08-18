/*本程序在提交报告后，对部分内容进行了微调。所以运行结果可能与大作业报告截屏有出入，还望助教老师谅解*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define STU 30

void hi_teacher(); /*教师登陆界面1*/
void manu_list(); /*教师登陆界面2*/
void hi_student(); /*学生登录界面1*/
void log_in(); /*学生登录界面2*/
void read_data(); /*读取文件内容*/
void write_data(); /*向文件中写入信息*/
void secret(char password[]); /*输入密码保护程序*/
void regisiter (); /*学生注册账号*/
void add(); /*增加学生信息*/
void del(); /*删除学生信息*/
void change(); /*修改学生信息*/
void find(); /*查询学生信息*/
void rank(); /*计算学生名次*/
void list(); /*将学生按总成绩降序输出*/


struct account{
    char username[20];
    char password[20];
}student_account[STU];

int n,m;

struct student{
    char name[20];
    char number[20];
    int classnumber;
    double score1;
    double score2;
    double score3;
    double sum;
    int ranking;
}stu[STU];

int main()
{
    read_data();
    int choose;
A: 	
	system("cls");
	printf("***************************************************\n");
    printf("*                                                 *\n");
    printf("*           欢迎使用学生成绩信息管理系统          *\n");
    printf("*                                                 *\n");
    printf("*       [1]教师     [2]学生    [0]退出系统        *\n");
    printf("*                                                 *\n");
    printf("***************************************************\n");

    printf("\n\t\t请选择：");
    fflush(stdin);
   
	scanf("%d",&choose);
    switch(choose)
    {
        case 1:
            hi_teacher();
			manu_list();
			break;
        case 2:
            hi_student();
        case 0:
            write_data();
			system("cls");
			printf("***************************************************\n");
			printf("*                                                 *\n");
			printf("*      期待您的下次使用，祝您生活愉快。再见！     *\n");
			printf("*                                                 *\n");
			printf("***************************************************\n");
            exit(0);
        default :
            printf("-------------------------------------------------\n");
			printf("                不乖了哦\(//?//)\\               \n");
			printf("                  请重新输入 ...                 \n");
			printf("-------------------------------------------------\n");
			printf("\n\n");
			system("pause");
            goto A;
            break;
    }
    write_data();
    return 0;
}

void read_data(){
    n=1;
    FILE *fp=NULL;
    fp=fopen("student_account.txt", "r");
    while(!feof(fp))
    {
        if(fscanf(fp,"%s %s\n",student_account[n].username,student_account[n].password)!=EOF)
            n++;
    }
    fclose(fp);
    m=1;
    fp=NULL;
    fp=fopen("student_grade.txt", "r");
    while(!feof(fp))
    {
        if(fscanf(fp,"%s %s %d %lf %lf %lf %lf %d\n",stu[m].name,stu[m].number,&stu[m].classnumber,&stu[m].score1,&stu[m].score2,&stu[m].score3,&stu[m].sum,&stu[m].ranking)!=EOF)
            m++;
    }
    fclose(fp);
}
void write_data(){
    int i;
    FILE *fp=NULL;
    fp=fopen("student_account.txt", "w");
    for(i=1;i<n;i++)
        fprintf(fp,"%s %s\n",student_account[n].username,student_account[n].password);
    fclose(fp);
    fp=NULL;
    fp=fopen("student_grade.txt", "w");
    for(i=1;i<m;i++)
        fprintf(fp,"%s %s %d %lf %lf %lf %lf %d\n",stu[i].name,stu[i].number,stu[i].classnumber,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].sum,stu[i].ranking);
    fclose(fp);
}

void hi_teacher(){
    char username[20],password[20];
B:	
	system("cls");
	printf("-------------------------------------------------\n");
	printf("      尊敬的老师，请您输入默认的用户名(admin)    \n");
	printf("-------------------------------------------------\n");
	
    scanf("%s",username);
    getchar();

	printf("-------------------------------------------------\n");
	printf("            请您输入默认的密码(admin)            \n");
	printf("-------------------------------------------------\n");

    secret(password);
    if(strcmp(username,"admin")==0 &&strcmp(password,"admin")==0){ 
		return;
	}
    else {
		printf("-------------------------------------------------\n");
		printf("          亲，这可是道送分题!\(//?//)\\          \n");
		printf("               请重新输入 ...                    \n");
		printf("-------------------------------------------------\n");
        printf("\n");
		system("pause");
        goto B;
    }
}

void manu_list()
{
C:
	system("cls");
    printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*           欢迎使用学生成绩信息管理系统!         *\n");
    printf("*                                                 *\n");
    printf("*                [1]新增学生信息                  *\n");
    printf("*                [2]删除学生信息                  *\n");
    printf("*                [3]修改学生信息                  *\n");
    printf("*                [4]查询学生信息                  *\n");
    printf("*                [5]按总成绩排序                  *\n");
    printf("*                [6]退出系统                      *\n");
    printf("*                                                 *\n");
    printf("***************************************************\n");
    printf("\n\t    请选择您需要使用的功能：");
    int choose;
    scanf("%d",&choose);
    switch (choose) {
        case 1:
            add();
			goto C;
            break;
        case 2:
            del();
			goto C;
            break;
        case 3:
            change();
			goto C;
            break;
        case 4:
            find();
			goto C;
            break;
        case 5:
            list();
			goto C;
            break;
        case 6:
			printf("\n");
			write_data();
            exit(0);
            break;
        default:
            goto C;
            break;
    }
}
void add()
{
    int num;
	system("cls");
D:
    printf("请输入要新录入学生人数：");

    scanf("%d",&num);
    if(num<1||num>STU){
        printf("\n输入数据有误，请重新输入：\n");
        goto D;
    }
	
	system("cls");
    printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*             请依次输入学生的下列信息：          *\n");
	printf("*  姓名、学号、班级、平时分、期中成绩、期末成绩   *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n");
    printf("ATTETION: 输入信息时，请以空格分隔，否则地球可能爆炸！\n\n");

    while(num--)
    {
        fflush(stdin);
        scanf("%s %s %d %lf %lf %lf",stu[m].name,stu[m].number,&stu[m].classnumber,&stu[m].score1,&stu[m].score2,&stu[m].score3);
        stu[m].sum = 0.1*stu[m].score1+0.2*stu[m].score2+0.7*stu[m].score3 ;
        m++;
    }
    rank();
    printf("\n学生信息保存成功，");
    system("pause");
}

void del(){
    fflush(stdin);
    int i,j=0;
    char del_number[20];
	system("cls");
    printf("请输入想要删除的学生学号：");
    scanf("%s",del_number);
    for(i=1;i<m;i++)
    {
        if(strcmp(stu[i].number,del_number)==0)
        {j=i;break;}
    }
    for(i=j;i<m;i++)
    {
        strcpy(stu[i].name,stu[i+1].name);
        strcpy(stu[i].number,stu[i+1].number);
        stu[i].classnumber=stu[i+1].classnumber;
        stu[i].score1=stu[i+1].score1;
        stu[i].score2=stu[i+1].score2;
        stu[i].score3=stu[i+1].score3;
        stu[i].sum=stu[i+1].sum;
    }
    m--;
	write_data();
    rank();
	printf("\n-------------------------------------------------\n");
	printf("             删除信息成功！（＾ω＾）            \n");
	printf("-------------------------------------------------\n");
    system("pause");
}

void change(){
    fflush(stdin);
    int i,j;
    char chan_number[20];
	system("cls");
    printf("请输入想要修改的学生学号：");
    scanf("%s",chan_number);
    for(i=1;i<m;i++)
    {
        if(strcmp(stu[i].number,chan_number)==0){
			j=i; 
			break;
		}
    }
	rank();
	printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*              下列信息依次为学生的：             *\n");
	printf("*  姓名、学号、班级、平时分、期中成绩、期末成绩   *\n");
	printf("*                 总成绩、总排名                  *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n\n");
    printf("%s  %s   %d   %4.1lf   %4.1lf  %4.1lf  %4.1lf  %d\n",stu[j].name,stu[j].number,stu[j].classnumber,stu[j].score1,stu[j].score2,stu[j].score3,stu[j].sum,stu[j].ranking);
	printf("\n\n");
    printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*             请依次输入学生的下列信息：          *\n");
	printf("*  姓名、学号、班级、平时分、期中成绩、期末成绩   *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n");
    printf("ATTETION: 输入信息时，请以空格分隔，否则地球可能爆炸！\n\n");

    fflush(stdin);
    scanf("%s %s %d %lf %lf %lf",stu[j].name,stu[j].number,&stu[j].classnumber,&stu[j].score1,&stu[j].score2,&stu[j].score3);
    stu[j].sum = 0.1*stu[j].score1+0.2*stu[j].score2+0.7*stu[j].score3 ;
    rank();
    printf("\n-------------------------------------------------\n");
	printf("             修改信息成功！（＾ω＾）            \n");
	printf("-------------------------------------------------\n");
    system("pause");
}

void find(){
    fflush(stdin);
    int i,j=0;
    char number[20];
	system("cls");
    printf("请输入想要查询的学生学号：");
    scanf("%s",number);
    for(i=1;i<m;i++){
        if(strcmp(stu[i].number,number)==0){
            j=i;
            break;
        }
    }
    rank();

	printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*              下列信息依次为学生的：             *\n");
	printf("*  姓名、学号、班级、平时分、期中成绩、期末成绩   *\n");
	printf("*                 总成绩、总排名                  *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n\n");

    printf("%s  %s   %d   %4.1lf   %4.1lf  %4.1lf  %4.1lf  %d\n",stu[j].name,stu[j].number,stu[j].classnumber,stu[j].score1,stu[j].score2,stu[j].score3,stu[j].sum,stu[j].ranking);
	printf("\n\n");
	system("pause");
}

void rank(){
    int i,j,count;
    for(i=1;i<m;i++)
    {
        count=1;
        for(j=1;j<m;j++)
            if(i!=j &&stu[j].sum>stu[i].sum)
                count++;
        stu[i].ranking=count;
    }
}

void list(){
    rank();
    int i,j,count=0;
	system("cls");

	printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*              下列信息依次为学生的：             *\n");
	printf("*  姓名、学号、班级、平时分、期中成绩、期末成绩   *\n");
	printf("*                 总成绩、总排名                  *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n\n");
    
    for(i=1;i<m;i++)
    {
        count++;
        for(j=1;j<m;j++)
            if(stu[j].ranking==count)
                printf(" %s  %s   %d   %4.1lf   %4.1lf  %4.1lf  %4.1lf  %d\n",stu[j].name,stu[j].number,stu[j].classnumber,stu[j].score1,stu[j].score2,stu[j].score3,stu[j].sum,stu[j].ranking);
    }
	printf("\n\n");
    system("pause");
}

void hi_student()
{
    int choose;
E:
    system("cls");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*            [1]我是尊贵的会员，登陆            *\n");
    printf("*            [2]迫不及待要注册                  *\n");
    printf("*            [0]退出系统                        *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
	printf("\n\t 亲请选择需要使用的功能(⊙_⊙)：");

    fflush(stdin);
    scanf("%d",&choose);
    
    switch(choose)
    {
        case 1:
            log_in();
            break;
        case 2:
            regisiter ();
            log_in();
            break;
        case 0:
            exit(0);
            break;
        default :
			printf("-------------------------------------------------\n");
			printf("                  听话(╯3╰)                   \n");
			printf("                   好好输入                     \n");
			printf("-------------------------------------------------\n");
			printf("\n");
			system("pause");
            goto E;
            break;
    }
    
}

void log_in(){

    int i,flag=0;
    char username[20],password[20];
F:
    system("cls");

	printf("-------------------------------------------------\n");
	printf("          尊贵的会员，请输入您的用户名           \n");
	printf("-------------------------------------------------\n");

    scanf("%s",username);
    getchar();

	printf("-------------------------------------------------\n");
	printf("                  请输入密码                     \n");
	printf("-------------------------------------------------\n");

    secret(password);

    for(i=1;i<n;i++)
    {
        if(strcmp(student_account[i].username, username)==0)
        {
            if(strcmp(student_account[i].password,password)==0)flag=1;
            else flag=2;
        }
    }
    switch (flag) {
        case 0:
            printf("\n\n");
			printf("该用户不存在。将前往注册界面。\n\n");
			system("pause");
			regisiter ();
            break;
        case 1:
            printf("\n\n*************************************************\n");
			printf("*                                               *\n");
			printf("*        恭喜您，登陆成功！（＾ω＾）           *\n");
			printf("*                                               *\n");
			printf("*************************************************\n");
			system("pause");
			find();
            break;
        case 2:
			printf("\n\n");
            printf("密码错误！\n");
			getch();
			system("cls");
			printf("*************************************************\n");
			printf("*                                               *\n");
			printf("*            [1]重新登陆                        *\n");
			printf("*            [0]返回上一层                      *\n");
			printf("*                                               *\n");
			printf("*************************************************\n");
			printf("\n\t 亲请选择您要执行的操作(⊙_⊙)：");
			int choose;
			scanf("%d",&choose);
			switch(choose)
			{
				case 1:
					goto F;
					break;
				case 0:
					break;
				default :
					printf("\n由于亲不太听话，给亲送回登陆界面(╯3╰)：");
					system("pause");
					goto F;
					break;
			}
			break;
    }
}
void regisiter ()
{
	system("cls");

	printf("-------------------------------------------------\n");
	printf("        尊贵的会员，请输入一个新的用户名         \n");
	printf("-------------------------------------------------\n");

	fflush (stdin);
    scanf("%s",student_account[n].username);
    printf("-------------------------------------------------\n");
	printf("             请输入一个能记得住的密码            \n");
	printf("-------------------------------------------------\n");
    char password[20];
    getchar();
    secret(password);
    strcpy(student_account[n].password,password);

	printf("\n-------------------------------------------------\n");
	printf("                请再输入一次密码                 \n");
	printf("-------------------------------------------------\n");
    secret(password);
    
	if(strcmp(student_account[n].password,password)==0){
			printf("\n\n*************************************************\n");
			printf("*                                               *\n");
			printf("*        恭喜您，注册成功！（＾ω＾）           *\n");
			printf("*                                               *\n");
			printf("*************************************************\n");
	}
    printf("\n\n");
	n++;
	system("pause");
}

void secret(char password[])
{
	fflush (stdin);
    char c;
    int i=0;
    while((c=getch())!='\r')
    {
        password[i++]=c;
        putchar('*');
    }
    password[i]='\0';
}
