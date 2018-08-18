#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define Books "Books.txt"
#define Users "Users.txt"
#define Adminstrators "Administrators.txt"
#define Books_tmp "Books_tmp.txt"
#define Users_tmp "Users_tmp.txt"
#define Adeministrators_tmp "Administrators_tmp.txt"

void Main_meun();
void User_meun();
void Administrator_meun();
int Log_in(char file[]);
void Register(char file[]);
int search(char book_name[],char file[]);
void Borrow_book(char book_name[],char file[]);
void Add_book(char file[]);
void Modify_book(char file[]);
void return_book(char file[]);
void EXIT();

struct BOOK{
    long long num;    //序号
    char title[100];  //书名
    char author[100]; //作者
    char press[100];  //出版社
    int can_borrow;   //能否借用
    char user_name[100]; //使用者名字
    char user_ID[100];   //使用者ID
};
struct USER{
    char name[100];
    char sex[100];
    char ID[100];
    char password[100];
}now_user;
int main() {
Main_meun:
    Main_meun();
    int command;
    fflush(stdin);
Again_9:scanf("%d",&command);
    switch (command) {
        case 1:  //用户系统
        {
            printf("------------------------\n");
            printf(" [1]登陆    [2]注册       \n");
            printf("------------------------\n");
            printf("如果你还没有账户，请先完成注册。\n");
            printf("请选择：");
            int subcommand,back=0;
            
        Again_6:scanf("%d",&subcommand);
            switch (subcommand) {
                case 1:
                {
                    back=Log_in(Users);
                    break;
                }
                case 2:
                {
                    Register(Users);
                    back=Log_in(Users);
                    break;
                }
                default:
                {
                    printf("你输入的指令错误！请重新输入:");
                    goto Again_6;
                    break;
                }
            }
            if(back==2) goto Main_meun;
            if(back==1)
            {
            User_meun:
                User_meun();
                int subcommand;
                scanf("%d",&subcommand);
                switch (subcommand) {
                    case 1:
                    {
                        char book_name[100];
                    search_1:  printf("请输入您想查阅的书名:");
                        fflush(stdin);
                        scanf("%s",book_name);
                        search(book_name,Books);
                        printf("------------------------------------\n");
                        printf("[1]继续查找 [2]返回上级菜单 [0]退出系统\n");
                        printf("------------------------------------\n");
                        printf("请选择:");
                        int subcommand;
                    Again_1:scanf("%d",&subcommand);
                        switch (subcommand) {
                            case 1:
                            {
                                goto search_1;
                                break;
                            }
                            case 2:
                            {
                                goto User_meun;
                                break;
                            }
                            case 0:
                            {
                                EXIT();
                            }
                            default:
                            {
                                printf("你输入的指令错误！请重新输入:");
                                goto Again_1;
                                break;
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        char book_name[100];
                    R:  printf("请输入您要借阅的书名:");
                        fflush(stdin);
                        scanf("%s",book_name);
                        Borrow_book(book_name,Books);
                        printf("---------------------------------\n");
                        printf("[1]继续借阅  [2]返回上级菜单  [0]退出系统\n");
                        printf("--------------------------------\n");
                        int subcommand;
                    Again_2:scanf("%d",&subcommand);
                        switch (subcommand) {
                            case 1:
                            {
                                goto R;
                                break;
                            }
                            case 2:
                            {
                                goto User_meun;
                                break;
                            }
                            case 0:
                            {
                                EXIT();
                            }
                            default:
                            {
                                printf("你输入的指令错误！请重新输入:");
                                goto Again_2;
                                break;
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                    return_book:return_book(Books);
                        printf("---------------------------------\n");
                        printf("[1]继续归还  [2]返回上级菜单  [0]退出系统\n");
                        printf("--------------------------------\n");
                        int subcommand;
                    Again_8:scanf("%d",&subcommand);
                        switch (subcommand) {
                            case 1:
                            {
                                goto return_book;
                                break;
                            }
                            case 2:
                            {
                                goto User_meun;
                                break;
                            }
                            case 0:
                            {
                                EXIT();
                                break;
                            }
                            default:
                            {
                                printf("你输入的指令错误！请重新输入:");
                                goto Again_8;
                                break;
                            }
                        }
                        break;
                    }
                    case 4:
                        goto Main_meun;
                        break;
                    case 0:
                    {
                        EXIT();
                    }
                    default:
                        break;
                }
            }
            break;
        }
        case 2:   //管理员系统
        {
            printf("------------------------\n");
            printf(" [1]登陆    [2]注册       \n");
            printf("------------------------\n");
            printf("如果你还没有账户，请先完成注册。\n");
            printf("请选择：");
            int subcommand,back=0;
        Again_7:scanf("%d",&subcommand);
            switch (subcommand) {
                case 1:
                {
                    back=Log_in(Adminstrators);
                    break;
                }
                case 2:
                {
                    Register(Adminstrators);
                    back=Log_in(Adminstrators);
                    break;
                }
                default:
                {
                    printf("你输入的指令错误！请重新输入:");
                    goto Again_7;
                    break;
                }
            }
            if(back==2) goto Main_meun;
            if(back==1)
            {
            Administrator_meun:
                Administrator_meun();
                int subcommand;
            Again_10:scanf("%d",&subcommand);
                switch (subcommand) {
                    case 1:
                    {
                        char book_name[100];
                    search_2:
                        printf("请输入您想查阅的书名:");
                        fflush(stdin);
                        scanf("%s",book_name);
                        search(book_name,Books);
                        printf("------------------------------------\n");
                        printf("[1]继续查找 [2]返回上级菜单 [0]退出系统\n");
                        printf("------------------------------------\n");
                        printf("请选择:");
                        int subcommand;
                    Again_3:scanf("%d",&subcommand);
                        switch (subcommand) {
                            case 1:
                            {
                                goto search_2;
                                break;
                            }
                            case 2:
                            {
                                goto Administrator_meun;
                                break;
                            }
                            case 0:
                            {
                                EXIT();
                            }
                            default:
                            {
                                printf("你输入的指令错误！请重新输入:");
                                goto Again_3;
                                break;
                            }
                        }
                        break;
                        
                    }
                    case 2:
                    {
                    Add_book:  Add_book(Books);
                        printf("------------------------------------\n");
                        printf("[1]继续录入 [2]返回上级菜单 [0]退出系统\n");
                        printf("------------------------------------\n");
                        printf("请选择:");
                        int subcommand;
                    Again_4:scanf("%d",&subcommand);
                        switch (subcommand) {
                            case 1:
                            {
                                goto Add_book;
                                break;
                            }
                            case 2:
                            {
                                goto Administrator_meun;
                                break;
                            }
                           case 0:
                            {
                                EXIT();
                                break;
                            }
                            default:
                            {
                                printf("你输入的指令错误！请重新输入:");
                                goto Again_4;
                                break;
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                    Modify_book:  Modify_book(Books);
                        printf("------------------------------------\n");
                        printf("[1]继续修改 [2]返回上级菜单 [0]退出系统\n");
                        printf("------------------------------------\n");
                        printf("请选择:");
                        int subcommand;
                    Again_5:scanf("%d",&subcommand);
                        switch (subcommand) {
                            case 1:
                            {
                                goto Modify_book;
                                break;
                            }
                            case 2:
                            {
                                goto Administrator_meun;
                                break;
                            }
                            case 0:
                            {
                                EXIT();
                                break;
                            }
                            default:
                            {
                                printf("你输入的指令错误！请重新输入:");
                                goto Again_5;
                                break;
                            }
                        }
                        break;
                    }
                    case 4:
                        goto Administrator_meun;
                        break;
                    case 0:
                    {
                        EXIT();
                    }
                    default:
                    {
                        printf("你输入的指令错误！请重新输入:");
                        goto Again_10;
                        break;
                    }
                }
            }
            break;
        }
        case 0:
        {
            EXIT();
        }
        default:
        {
            printf("你输入的指令错误！请重新输入:\n");
            goto Again_9;
            break;
        }
    }
    return 0;
}

void Main_meun(){ //开始界面
    system("cls");
    printf("*******************************************\n");
    printf("*                                         *\n");
    printf("*            欢迎使用图书馆管理系统           *\n");
    printf("*                                         *\n");
    printf("*    [1]用户登陆  [2]管理员登陆  [0]退出系统   *\n");
    printf("*                                         *\n");
    printf("*******************************************\n");
    printf("请选择：\n");
}

void User_meun(){
    system("cls");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*            [1]查阅图书信息              *\n");
    printf("*            [2]办理借书手续              *\n");
    printf("*            [3]办理还书手续              *\n");
    printf("*            [4]返回上级菜单              *\n");
    printf("*            [0]退出系统                 *\n");
    printf("*                                       *\n");
    printf("*****************************************\n");
    printf("请选择：\n");
}

void Administrator_meun(){
    system("cls");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*            [1]图书信息查询              *\n");
    printf("*            [2]新书信息录入              *\n");
    printf("*            [3]图书信息修改              *\n");
    printf("*            [4]返回上级菜单              *\n");
    printf("*            [0]退出系统                 *\n");
    printf("*                                       *\n");
    printf("*****************************************\n");
    printf("请选择：\n");
    
}

void Register(char file[]){//注册
Again:
    system("cls");
    char name[100],sex[10],ID[100],password[100],_password[100];
    fflush(stdin);
    printf("------------------------\n");
    printf("请输入您的信息：           \n");
    printf("姓名:");
    scanf("%s",name);
    printf("性别:");
    scanf("%s",sex);
    printf("ID:");
    scanf("%s",ID);
    printf("Password:");
    scanf("%s",password);
    printf("Repert Password:");
    scanf("%s",_password);
    if(strcmp(password,_password)!=0)
    {
        printf("您输入的密码不一致，请重新输入。");
        goto Again;
    }
    
    FILE *fp;
    fp=fopen(file,"r");
    struct USER user;
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s\n",user.name,user.sex,user.ID,user.password);
        if(strcmp(ID,user.ID)==0)
        {
            printf("该ID已存在，请重新注册。\n");
            fclose(fp);
            goto Again;
        }
    }
    fclose(fp);
    printf("注册成功！\n");
    fp=fopen(file,"a+");
    fprintf(fp,"%s %s %s %s\n",name,sex,ID,password);
    fclose(fp);
}

int Log_in(char file[]){//用户登陆
    
Again:
    system("cls");
    char ID[100],password[100],c;
    int i=0;
    printf("=========================\n");
    printf("-----------登陆----------\n");
    printf("请输入：\n");
    printf("ID:");
    scanf("%s",ID);
    getchar();
    printf("PASSWORD:");
    while((c=getchar())!='\n')
    {
        password[i++]=c;
        putchar('*');
    }
    FILE *fp=NULL;
    struct USER user;
    int flag=0;
    fp=fopen(file, "r");
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s\n",user.name,user.sex,user.ID,user.password);
        if(strcmp(user.ID,ID)==0 &&strcmp(user.password,password)==0)
        {
            printf("登陆成功！尊敬的%s %s,欢迎你的使用！\n",user.name,strcmp(user.sex,"男")==0?"先生":"女士");
            now_user=user;
            flag=1;
        }
        if(strcmp(user.ID,ID)==0 &&strcmp(user.password,password)!=0)
        {
            printf("您输入的密码错误！\n");
            flag=2;
        }
    }
    fclose(fp);
    if(flag==1)return 1;
    else
    {
        if(flag==0) printf("对不起，该用户不存在！\n");
        
        printf("----------------------------------\n");
        printf("[1]重新登录 [2]返回上级菜单 [0]退出系统\n");
        printf("----------------------------------\n");
        printf("请输入:");
        int command;
        scanf("%d",&command);
        switch (command) {
            case 1:
                goto Again;
                break;
            case 2:
                return 2;
            case 0:
                EXIT();
            default:
                break;
        }
    }
    return 0;
}

int search(char book_name[],char file[]){ //查阅图书
    system("cls");
    int tot=0,can_borrow=0;
    struct BOOK book;
    
    printf("====================================================================\n");
    printf("序号       书名        作者             出版社                   可借\n");
    printf("--------------------------------------------------------------------\n");
    FILE *fp=NULL;
    fp=fopen(file,"r");
    while(!feof(fp))
    {
        //fread(&book,sizeof(book),1,fp);
        fscanf(fp,"%lld %s %s %s %d %s %s\n",&book.num,book.title,book.author,book.press,&book.can_borrow,book.user_name,book.user_ID);
        if(strcmp(book_name,book.title)==0)
        {
            
            printf("%08lld  %8s %8s %8s %4d\n",book.num,book.title,book.author,book.press,book.can_borrow);
            tot++;
            if(book.can_borrow)
                can_borrow++;
        }
        if(strcmp(book_name,"ALL")==0)
        {
            printf("%08lld  %8s %8s %8s %4d\n",book.num,book.title,book.author,book.press,book.can_borrow);
            tot++;
            if(book.can_borrow)
                can_borrow++;
        }
    }
    fclose(fp);
    printf("=====================================================================\n");
    if(tot>0)
    {
        printf("总共找到 %d本，可借的有 %d本。\n",tot,can_borrow);
    }
    else
    {
        printf("没有找到 %s 。\n",book_name);
        printf("----------------------------------\n");
    }
    return can_borrow;

}

void Borrow_book(char book_name[],char file[]){
    int can_borrow;
    can_borrow=search(book_name,file);
    if(can_borrow>0)
    {
        long long book_num;
        printf("请输入您想借书的序号:");
        scanf("%lld",&book_num);
        printf("---------------------\n");
        printf("[1]是 [2]否\n");
        printf("---------------------\n");
        int subcommand;
    Again:scanf("%d",&subcommand);
        switch (subcommand) {
            case 1:
            {
                struct BOOK book;
                FILE *fp=NULL,*fp_tmp=NULL;
                fp=fopen(file,"r");
                fp_tmp=fopen(Books_tmp,"w");
                while(!feof(fp))
                {
                    fscanf(fp,"%lld %s %s %s %d %s %s\n",&book.num,book.title,book.author,book.press,&book.can_borrow,book.user_name,book.user_ID);
                    if(strcmp(book_name,book.title)==0 &&book.num==book_num &&book.can_borrow>0)
                    {
                        book.can_borrow=0;
                        strcpy(book.user_name,now_user.name);
                        strcpy(book.user_ID, now_user.ID);
                        fprintf(fp_tmp,"%lld %s %s %s %d %s %s\n",book.num,book.title,book.author,book.press,book.can_borrow,book.user_name,book.user_ID);
                    }
                    else
                    {
                        fprintf(fp_tmp,"%lld %s %s %s %d %s %s\n",book.num,book.title,book.author,book.press,book.can_borrow,book.user_name,book.user_ID);
                    }
                }
                fclose(fp);
                fclose(fp_tmp);
                remove(file);
                rename(Books_tmp,file);
                printf("借书完成！\n");
                break;
            }
            case 2:
            {
                return;
                break;
            }
            default:
            {
                printf("你输入的指令错误！请重新输入。。。\n");
                goto Again;
                break;
            }
        }
    }
    else
    {
        printf("Sorry!该书暂时没有可借的。\n");
    }
}

void Add_book(char file[]){
    struct BOOK book;
    
    long long Length=0;
    FILE *fp=NULL;
    fp=fopen(file,"r");
    while(!feof(fp))
    {
        fscanf(fp,"%lld %s %s %s %d %s %s\n",&book.num,book.title,book.author,book.press,&book.can_borrow,book.user_name,book.user_ID);
        Length++;
    }
    fclose(fp);
    fflush(stdin);
    printf("请输入您要录入的新书:\n");
    printf("书名:");
    scanf("%s",book.title);
    printf("作者:");
    scanf("%s",book.author);
    printf("出版社:");
    scanf("%s",book.press);
    book.can_borrow=1;
    
    book.num=Length+1;
    strcpy(book.user_name,"None");
    strcpy(book.user_ID,"None");
    fp=fopen(file,"a+");
    //fwrite(&book,sizeof(book),1,fp);
    fprintf(fp,"%lld %s %s %s %d %s %s\n",book.num,book.title,book.author,book.press,book.can_borrow,book.user_name,book.user_ID);
    fclose(fp);
}

void Modify_book(char file[]){
    char book_name[100];
    struct BOOK new_book;
    long long book_num;
    struct BOOK book;
    fflush(stdin);
    printf("请输入您要修改的书名:");
    scanf("%s",book_name);
    search(book_name,file);//bug
    printf("请输入您想修改的书的序号:");
    scanf("%lld",&book_num);
    FILE *fp=NULL,*fp_tmp=NULL;;
    fp=fopen(file,"r");
    fp_tmp=fopen(Books_tmp,"w");
    while(!feof(fp))
    {
        fscanf(fp,"%lld %s %s %s %d %s %s\n",&book.num,book.title,book.author,book.press,&book.can_borrow,book.user_name,book.user_ID);
        if(strcmp(book_name,book.title)==0 &&book_num==book.num)
        {
            printf("请输入修改的信息:\n");
            printf("书名:");
            scanf("%s",new_book.title);
            printf("作者:");
            scanf("%s",new_book.author);
            printf("出版社:");
            scanf("%s",new_book.press);
            new_book.num=book.num;
            new_book.can_borrow=book.can_borrow;
            strcpy(new_book.user_name, book.user_name);
            strcpy(new_book.user_ID, book.user_ID);
            printf("您确定要修改吗？\n");
            printf("------------\n");
            printf("[1]是  [2]否\n");
            printf("------------\n");
            printf("请选择:");
            int subcommand;
        Again:scanf("%d",&subcommand);
            switch (subcommand) {
                case 1:
                {
                    fprintf(fp_tmp,"%lld %s %s %s %d %s %s\n",new_book.num,new_book.title,new_book.author,new_book.press,new_book.can_borrow,new_book.user_name,new_book.user_ID);
                    break;
                }
                case 2:
                {
                    fprintf(fp_tmp,"%lld %s %s %s %d %s %s\n",book.num,book.title,book.author,book.press,book.can_borrow,book.user_name,book.user_ID);
                    break;
                }
                default:
                {
                    printf("你输入的指令错误！请重新输入:\n");
                    goto Again;
                    break;
                }
            }
        }
        else
        {
            fprintf(fp_tmp,"%lld %s %s %s %d %s %s\n",book.num,book.title,book.author,book.press,book.can_borrow,book.user_name,book.user_ID);
        }
    }
    fclose(fp);
    fclose(fp_tmp);
    remove(file);
    rename(Books_tmp,file);
}

void return_book(char file[]){
    system("cls");
    struct BOOK book;
    FILE *fp=NULL,*fp_tmp=NULL;
    fp=fopen(file,"r");
    printf("====================================================================\n");
    printf("序号       书名        作者             出版社                   使用者\n");
    printf("--------------------------------------------------------------------\n");
    while(!feof(fp))
    {
        fscanf(fp,"%lld %s %s %s %d %s %s\n",&book.num,book.title,book.author,book.press,&book.can_borrow,book.user_name,book.user_ID);
        if(strcmp(now_user.name, book.user_name)==0)
        {
            printf("%08lld %s %s %s %s\n",book.num,book.title,book.author,book.press,book.user_name);
        }
    }
    printf("====================================================================\n");
    fclose(fp);
    char book_name[100];
    long long book_num;
    printf("请输入您想还书的序号:");
    scanf("%lld",&book_num);
    printf("请输入您想还书的书名:");
    scanf("%s",book_name);
    fp=fopen(file,"r");
    fp_tmp=fopen(Books_tmp,"w");
    while (!feof(fp))
    {
        fscanf(fp,"%lld %s %s %s %d %s %s\n",&book.num,book.title,book.author,book.press,&book.can_borrow,book.user_name,book.user_ID);
        if(strcmp(book_name,book.title)==0 &&book_num==book.num)
        {
            strcpy(book.user_name,"None");
            strcpy(book.user_ID, "None");
            book.can_borrow=1;
            
            printf("您确认归还吗？\n");
            printf("--------------\n");
            printf("[1]是  [2]否\n");
            printf("--------------\n");
            printf("请选择:");
            int subcommand;
        Again:scanf("%d",&subcommand);
            switch (subcommand) {
                case 1:
                {
                    fprintf(fp_tmp,"%lld %s %s %s %d %s %s\n",book.num,book.title,book.author,book.press,book.can_borrow,book.user_name,book.user_ID);
                    printf("还书完成！\n");
                    break;
                }
                case 2:
                {
                    break;
                }
                default:
                {
                    printf("你输入的指令错误！请重新输入:\n");
                    goto Again;
                    break;
                }
            }

        }
        else
        {
            fprintf(fp_tmp,"%lld %s %s %s %d %s %s\n",book.num,book.title,book.author,book.press,book.can_borrow,book.user_name,book.user_ID);
        }
    
    
    }
    fclose(fp);
    fclose(fp_tmp);
    remove(file);
    rename(Books_tmp,file);
    
}

void EXIT(){
    system("cls");
    printf("感谢你的使用！再见\n");
    exit(0);
}
