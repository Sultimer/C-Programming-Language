/*���������ύ����󣬶Բ������ݽ�����΢�����������н�����������ҵ��������г��룬����������ʦ�½�*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define STU 30

void hi_teacher(); /*��ʦ��½����1*/
void manu_list(); /*��ʦ��½����2*/
void hi_student(); /*ѧ����¼����1*/
void log_in(); /*ѧ����¼����2*/
void read_data(); /*��ȡ�ļ�����*/
void write_data(); /*���ļ���д����Ϣ*/
void secret(char password[]); /*�������뱣������*/
void regisiter (); /*ѧ��ע���˺�*/
void add(); /*����ѧ����Ϣ*/
void del(); /*ɾ��ѧ����Ϣ*/
void change(); /*�޸�ѧ����Ϣ*/
void find(); /*��ѯѧ����Ϣ*/
void rank(); /*����ѧ������*/
void list(); /*��ѧ�����ܳɼ��������*/


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
    printf("*           ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ          *\n");
    printf("*                                                 *\n");
    printf("*       [1]��ʦ     [2]ѧ��    [0]�˳�ϵͳ        *\n");
    printf("*                                                 *\n");
    printf("***************************************************\n");

    printf("\n\t\t��ѡ��");
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
			printf("*      �ڴ������´�ʹ�ã�ף��������졣�ټ���     *\n");
			printf("*                                                 *\n");
			printf("***************************************************\n");
            exit(0);
        default :
            printf("-------------------------------------------------\n");
			printf("                ������Ŷ\(//?//)\\               \n");
			printf("                  ���������� ...                 \n");
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
	printf("      �𾴵���ʦ����������Ĭ�ϵ��û���(admin)    \n");
	printf("-------------------------------------------------\n");
	
    scanf("%s",username);
    getchar();

	printf("-------------------------------------------------\n");
	printf("            ��������Ĭ�ϵ�����(admin)            \n");
	printf("-------------------------------------------------\n");

    secret(password);
    if(strcmp(username,"admin")==0 &&strcmp(password,"admin")==0){ 
		return;
	}
    else {
		printf("-------------------------------------------------\n");
		printf("          �ף�����ǵ��ͷ���!\(//?//)\\          \n");
		printf("               ���������� ...                    \n");
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
	printf("*           ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ!         *\n");
    printf("*                                                 *\n");
    printf("*                [1]����ѧ����Ϣ                  *\n");
    printf("*                [2]ɾ��ѧ����Ϣ                  *\n");
    printf("*                [3]�޸�ѧ����Ϣ                  *\n");
    printf("*                [4]��ѯѧ����Ϣ                  *\n");
    printf("*                [5]���ܳɼ�����                  *\n");
    printf("*                [6]�˳�ϵͳ                      *\n");
    printf("*                                                 *\n");
    printf("***************************************************\n");
    printf("\n\t    ��ѡ������Ҫʹ�õĹ��ܣ�");
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
    printf("������Ҫ��¼��ѧ��������");

    scanf("%d",&num);
    if(num<1||num>STU){
        printf("\n���������������������룺\n");
        goto D;
    }
	
	system("cls");
    printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*             ����������ѧ����������Ϣ��          *\n");
	printf("*  ������ѧ�š��༶��ƽʱ�֡����гɼ�����ĩ�ɼ�   *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n");
    printf("ATTETION: ������Ϣʱ�����Կո�ָ������������ܱ�ը��\n\n");

    while(num--)
    {
        fflush(stdin);
        scanf("%s %s %d %lf %lf %lf",stu[m].name,stu[m].number,&stu[m].classnumber,&stu[m].score1,&stu[m].score2,&stu[m].score3);
        stu[m].sum = 0.1*stu[m].score1+0.2*stu[m].score2+0.7*stu[m].score3 ;
        m++;
    }
    rank();
    printf("\nѧ����Ϣ����ɹ���");
    system("pause");
}

void del(){
    fflush(stdin);
    int i,j=0;
    char del_number[20];
	system("cls");
    printf("��������Ҫɾ����ѧ��ѧ�ţ�");
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
	printf("             ɾ����Ϣ�ɹ������ަأޣ�            \n");
	printf("-------------------------------------------------\n");
    system("pause");
}

void change(){
    fflush(stdin);
    int i,j;
    char chan_number[20];
	system("cls");
    printf("��������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
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
	printf("*              ������Ϣ����Ϊѧ���ģ�             *\n");
	printf("*  ������ѧ�š��༶��ƽʱ�֡����гɼ�����ĩ�ɼ�   *\n");
	printf("*                 �ܳɼ���������                  *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n\n");
    printf("%s  %s   %d   %4.1lf   %4.1lf  %4.1lf  %4.1lf  %d\n",stu[j].name,stu[j].number,stu[j].classnumber,stu[j].score1,stu[j].score2,stu[j].score3,stu[j].sum,stu[j].ranking);
	printf("\n\n");
    printf("***************************************************\n");
	printf("*                                                 *\n");
	printf("*             ����������ѧ����������Ϣ��          *\n");
	printf("*  ������ѧ�š��༶��ƽʱ�֡����гɼ�����ĩ�ɼ�   *\n");
	printf("*                                                 *\n");
	printf("***************************************************\n");
    printf("ATTETION: ������Ϣʱ�����Կո�ָ������������ܱ�ը��\n\n");

    fflush(stdin);
    scanf("%s %s %d %lf %lf %lf",stu[j].name,stu[j].number,&stu[j].classnumber,&stu[j].score1,&stu[j].score2,&stu[j].score3);
    stu[j].sum = 0.1*stu[j].score1+0.2*stu[j].score2+0.7*stu[j].score3 ;
    rank();
    printf("\n-------------------------------------------------\n");
	printf("             �޸���Ϣ�ɹ������ަأޣ�            \n");
	printf("-------------------------------------------------\n");
    system("pause");
}

void find(){
    fflush(stdin);
    int i,j=0;
    char number[20];
	system("cls");
    printf("��������Ҫ��ѯ��ѧ��ѧ�ţ�");
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
	printf("*              ������Ϣ����Ϊѧ���ģ�             *\n");
	printf("*  ������ѧ�š��༶��ƽʱ�֡����гɼ�����ĩ�ɼ�   *\n");
	printf("*                 �ܳɼ���������                  *\n");
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
	printf("*              ������Ϣ����Ϊѧ���ģ�             *\n");
	printf("*  ������ѧ�š��༶��ƽʱ�֡����гɼ�����ĩ�ɼ�   *\n");
	printf("*                 �ܳɼ���������                  *\n");
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
    printf("*            [1]�������Ļ�Ա����½            *\n");
    printf("*            [2]�Ȳ�����Ҫע��                  *\n");
    printf("*            [0]�˳�ϵͳ                        *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
	printf("\n\t ����ѡ����Ҫʹ�õĹ���(��_��)��");

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
			printf("                  ����(�s3�t)                   \n");
			printf("                   �ú�����                     \n");
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
	printf("          ���Ļ�Ա�������������û���           \n");
	printf("-------------------------------------------------\n");

    scanf("%s",username);
    getchar();

	printf("-------------------------------------------------\n");
	printf("                  ����������                     \n");
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
			printf("���û������ڡ���ǰ��ע����档\n\n");
			system("pause");
			regisiter ();
            break;
        case 1:
            printf("\n\n*************************************************\n");
			printf("*                                               *\n");
			printf("*        ��ϲ������½�ɹ������ަأޣ�           *\n");
			printf("*                                               *\n");
			printf("*************************************************\n");
			system("pause");
			find();
            break;
        case 2:
			printf("\n\n");
            printf("�������\n");
			getch();
			system("cls");
			printf("*************************************************\n");
			printf("*                                               *\n");
			printf("*            [1]���µ�½                        *\n");
			printf("*            [0]������һ��                      *\n");
			printf("*                                               *\n");
			printf("*************************************************\n");
			printf("\n\t ����ѡ����Ҫִ�еĲ���(��_��)��");
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
					printf("\n�����ײ�̫�����������ͻص�½����(�s3�t)��");
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
	printf("        ���Ļ�Ա��������һ���µ��û���         \n");
	printf("-------------------------------------------------\n");

	fflush (stdin);
    scanf("%s",student_account[n].username);
    printf("-------------------------------------------------\n");
	printf("             ������һ���ܼǵ�ס������            \n");
	printf("-------------------------------------------------\n");
    char password[20];
    getchar();
    secret(password);
    strcpy(student_account[n].password,password);

	printf("\n-------------------------------------------------\n");
	printf("                ��������һ������                 \n");
	printf("-------------------------------------------------\n");
    secret(password);
    
	if(strcmp(student_account[n].password,password)==0){
			printf("\n\n*************************************************\n");
			printf("*                                               *\n");
			printf("*        ��ϲ����ע��ɹ������ަأޣ�           *\n");
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
