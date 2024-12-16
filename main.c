/*头文件区*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

/*宏定义区*/
#define  ADMIN_password "123456" /*管理员登录密码*/

/*结构体声明区*/
typedef struct bookinfo/*系统图书信息 */
{
    char number[15];/*图书编号*/
    char name[30];/*图书名称*/
    char author[20];/*作者*/
    char press[30];/*出版社*/
    char category[20]; /*类别*/
    float price;/*单价*/
    int  quantity;/*馆藏量*/
    int  time;/*借书次数*/
}BOOKINFO;

typedef struct bookgrasp/*会员借出的书籍信息*/
{
    char number[15];/*图书编号*/
    char name[30];/*图书名称*/
    char author[20];/*作者*/
    char press[30];/*出版社*/
    char category[20]; /*类别*/
    float price;/*单价*/
    char account[30];/*借书者ID*/
}BOOKGRASP;

typedef struct member/*会员个人信息 */
{
    char name[30];
    char ID[20];
    char password[30];
    char sex[15];
    char password_key[30];
}MEMBER;

/*菜单函数区*/
void menu1();
void menu2();
void menu3();
void AboutMe();

/*工具函数区*/
int compare_password(char password[20]);/*密码比对函数 */
void clock_delay(); /*时间延时函数*/
void password_circle();/*密码框装饰函数*/
void find_account_circle();/*找回帐户弹出框函数*/

/*读者信息系统层级函数区*/
int user_account(char account[20]);/*个人账户信息*/
void member_log_up();/*读者注册函数*/
int member_log_in(char account[20]);/*读者登录函数*/
void ADMIN_watch_member();/*查看读者信息函数*/
void display_memberbook();/*查看所有图书借阅信息函数*/
int check_repeat_ID(char id_account[20]);/*检查账户重复性函数*/
void find_account();/*账户找回函数*/

/*图书信息系统层级函数区*/
void add_book();/*输入新进的图书信息*/
void delete_book();/*根据图书名称对图书信息进行删除*/
void modify_book();/*修改图书信息*/
void display_book();/*显示全部图书信息*/
void search_book();/*根据图书名称显示图书的信息*/
void borrow_book(char account[20]);/*借书*/
void return_book(char account[20]);/*还书*/
void display_price_lower();/*根据价格列出图书信息*/
/*void dispaly_popular();/*图书受欢迎度排行榜*/
int check_repeat_book(char number[30]);/*查重书籍编号*/


void menu1() {
    system("color E9");
    printf("|=================================================================================|\n");
    printf("|                                                                                 |\n");
    printf("|                               欢迎使用图书管理系统                                  |\n");
    printf("|                                                                                 |\n");
    printf("|=================================================================================|\n");
    printf("|                                      菜单                                        |\n");
    printf("|---------------------------------------------------------------------------------|\n");
    printf("|               |               |               |                |                |\n");
    printf("|               |               |               |                |                |\n");
    printf("|      1.       |               |       3.      |       4.       |       5.       |\n");
    printf("|    用户登录    |                |    管理员登录   |       关于      |       退出      |\n");
    printf("|               |               |               |                |                |\n");
    printf("|               |               |               |                |                |\n");
    printf("|=================================================================================|\n");

}

void menu2(){
    system("color BC");
    printf("\n\n");
    printf("\t\t\t*=======================================================*\n");
    printf("\t\t\t||------------------------用户登录 ---------------------||\n");
    printf("\t\t\t*                                                      *|\n");
    printf("\t\t\t||    [1]     查询馆藏图书信息                            ||\n");
    printf("\t\t\t|*    [2]     借阅图书                                   *|\n");
    printf("\t\t\t||    [3]     归还图书                                   ||\n");
    printf("\t\t\t|*    [4]     账户信息                                   *|\n");
    printf("\t\t\t||    [5]     退出登录                                   ||\n");
    printf("\t\t\t*=======================================================*\n");
}


void menu3(){
    system("color 1B");
    printf("\n\n");
    printf("\t\t\t*=======================================================*\n");
    printf("\t\t\t||-----------------------管理员登录 ---------------------||\n");
    printf("\t\t\t*                                                      *|\n");
    printf("\t\t\t||    [1]     增加图书                                   ||\n");
    printf("\t\t\t|*    [2]     删除图书                                   *|\n");
    printf("\t\t\t||    [3]     查找图书                                   ||\n");
    printf("\t\t\t|*    [4]     修改图书信息                                *|\n");
    printf("\t\t\t||    [5]     显示全部图书信息                             ||\n");
    printf("\t\t\t||    [6]     显示所有用户信息                             ||\n");
    printf("\t\t\t||    [7]     显示当前图书借阅信息                          ||\n");
    printf("\t\t\t||    [8]     退出管理员系统                               ||\n");
    printf("\t\t\t*=======================================================*\n");
}


void AboutMe(){
    system("color 1D");
    printf("\n\n");
    printf("\t\t\t*=======================================================*\n");
    printf("\t\t\t||------------------------ 关于 ------------------------||\n");
    printf("\t\t\t|            软件241夏宇昂    202400406040                |\n");
    printf("\t\t\t|                                                       |\n");
    printf("\t\t\t|             C_V1.0  图书馆管理程序  24/12/10             |\n");
    printf("\t\t\t|                                                       |\n");
    printf("\t\t\t|       思路及实现:清华大学出版社-C语言从入门到精通             |\n");
    printf("\t\t\t|                知乎-@Jarry                             |\n");
    printf("\t\t\t|                       按任意键退出                      |\n");
    printf("\t\t\t*=======================================================*\n");
    getch();
}

void add_book() /*输入新进的图书信息*/
{
    char choice;
    FILE *p1;
    BOOKINFO newbook;
    int flag;
    system("cls");
    while(1)
    {
        flag=0;
        fflush(stdin);
        printf("请输入图书编号:");
        gets(newbook.number);

        if(check_repeat_book(newbook.number))
        {
            printf("该图书编号已被使用！");
            printf("\n按任意键重新注册\n\n");
            getch();
            flag=1;
        }
        else{
            fflush(stdin);
            printf("请输入书名:");
            gets(newbook.name);

            printf("请输入作者:");
            gets(newbook.author);

            printf("请输入出版社:");
            gets(newbook.press);

            printf("请输入类别(文学/科学/理学/工学/等):");
            gets(newbook.category);

            printf("请输入价格:");
            scanf("%f",&newbook.price);

            printf("请输入馆藏量:");
            scanf("%d",&newbook.quantity);

            printf("请输入借阅次数(新书输入0):");
            scanf("%d",&newbook.time);
            fflush(stdin);
            printf("是否保存该条书目(y/n):");
            choice=getch();
            while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
                choice=getch();
            printf("%c",choice);
            if(choice=='Y'||choice=='y')
            {
                p1=fopen("library.txt","a");
                fprintf(p1,"%s %s %s %s %s %f %d %d\n",
                        newbook.number,newbook.name,newbook.author,newbook.press,
                        newbook.category,newbook.price,newbook.quantity,newbook.time);
                fclose(p1);
                printf("\n该条书目已添加到library.txt文件中!\n");
            }
            else
            {
                printf("\n本条书目未保存!\n");
            }
            printf("\n\n是否继续添加书目(y/n):");
            choice=getch();
            while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
                choice=getch();
            printf("%c",choice);
            printf("\n");
        }
        if(choice=='Y'||choice=='y'||flag==1)
            continue;
        else
            break;
    }
}

void display_book()/*显示全部图书信息*/
{
    FILE *p1;
    int n;
    BOOKINFO bookinfo[100];
    int booknumber=0;
    system("cls");
    fflush(stdin);
    p1=fopen("library.txt","r");
    while(!feof(p1))
    {
        fscanf(p1,"%s %s %s %s %s %f %d %d\n",
               bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
               bookinfo[booknumber].press,bookinfo[booknumber].category,
               &bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
        booknumber++;
    }
    fclose(p1);
    printf("当前图书馆内有%d目书籍\n\n",booknumber);
    if(bookinfo[0].quantity==0)
    {
        printf("\n没有任何图书信息!\n\n");
    }
    else
    {
        n=0;
        printf("|---------------------------------图书信息---------------------------------|\n");
        printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
        printf("|                                                                          |\n");
        while(n<booknumber)
        {
            printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                   bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            n++;
        }
    }
    printf("\n\n按任意键返回上一级菜单!\n");
    getch();
}

void search_book()/*根据图书名称显示图书的信息*/
{
    int flag=1,flag1=1;
    char select;
    char name_compare[30]="";/*name_compare用来存放要查询的书名*/
    char number_compare[30]=""; /*number_compare用来存放要查询的书籍编号*/
    char author_compare[30]="";/*author_compare用来存放要查询的作者姓名*/
    char search[30]="";/*search是比对数组,将需要查找的数组读进比对数组*/
    char compare[30]="";/*compare是比对数组,将书库中的数组读进比对数组*/
    int n=0;
    FILE *p1;
    char choice;
    BOOKINFO bookinfo[100];
    int booknumber=0;

    system("cls");
    fflush(stdin);
    p1=fopen("library.txt","r");
    while(!feof(p1))
    {
        fscanf(p1,"%s %s %s %s %s %f %d %d\n",
               bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
               bookinfo[booknumber].press,bookinfo[booknumber].category,
               &bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
        booknumber++;
    }
    fclose(p1);

    while(flag)
    {
        system("cls");
        while(flag1)
        {
            system("cls");
            fflush(stdin);
            printf("您想通过\n\n1.<-图书编号->\n\n2.<-书名->\n\n3.<-作者名->\n\n哪种方式查询图书:");
            select=getch();
            printf("%c",select);
            printf("\n\n请您输入查找信息:");
            switch(select)
            {
                case '1':gets(number_compare);strcpy(search,number_compare);flag1=0;break;
                case '2':gets(name_compare);strcpy(search,name_compare);flag1=0;break;
                case '3':gets(author_compare);strcpy(search,author_compare);flag1=0;break;
                default :
                    printf("\n不要输入菜单之外的数字~按任意键继续！");
                    fflush(stdin);
                    getch();
            }
        }

        flag1=1;
        if(bookinfo[0].quantity==0)
        {
            printf("书库中没有任何信息!\n\n");
            printf("按任意键回到主菜单!\n\n");
            getch();
            break;
        }
        else
        {
            for(n=0;n<booknumber;n++)
            {
                switch(select)
                {
                    case '1':strcpy(compare,bookinfo[n].number);break;
                    case '2':strcpy(compare,bookinfo[n].name);break;
                    case '3':strcpy(compare,bookinfo[n].author);break;
                }
                if(strcmp(compare,search)==0)
                {
                    printf("|---------------------------------图书信息---------------------------------|\n");
                    printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
                    printf("|                                                                          |\n");
                    printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                           bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
                    break;
                }
            }
            if(n>=booknumber)
                printf("\n没有查找符合您要求的书籍!\n");

            printf("\n\n是否继续查询(y/n):");
            choice=getch();
            while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
                choice=getch();
            printf("%c",choice);
            printf("\n");
            if(choice=='Y'||choice=='y')
                flag=1;
            else
                flag=0;

        }
    }
}

void delete_book()/*根据图书名称对图书信息进行删除*/
{
    char search[20]="";/*search用来存放要删除的书名*/
    int n,i;
    FILE *p1;
    char choice;
    BOOKINFO bookinfo[100];
    int booknumber;

    system("cls");
    while(1)
    {
        fflush(stdin);
        printf("输入要删除的书本名称:");
        gets(search);
        p1=fopen("library.txt","r");
        booknumber=0;
        while(!feof(p1))
        {
            fscanf(p1,"%s %s %s %s %s %f %d %d\n",
                   bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
                   bookinfo[booknumber].press,bookinfo[booknumber].category,
                   &bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
            booknumber++;
        }
        fclose(p1);
        if(bookinfo[0].quantity==0)
        {
            printf("书库中没有任何信息!\n\n");
            printf("按任意键回到主菜单!\n\n");
            getch();
            break;
        }/*if结束*/
        else
        {
            for(n=0;n<booknumber;n++)
                if(strcmp(bookinfo[n].name,search)==0)
                {
                    break;
                }
            if(n>=booknumber)
                printf("\n没有查找该书的任何信息!\n");
            else
            {
                printf("\n是否确认需要删除该条书目(Y/N):");
                choice=getch();
                while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
                    choice=getch();
                printf("%c",choice);
                if(choice=='Y'||choice=='y')
                {
                    for(i=n;i<booknumber-1;i++)
                        bookinfo[i]=bookinfo[i+1];
                    booknumber--;
                    p1=fopen("library.txt","w");
                    for(n=0;n<booknumber;n++)
                        fprintf(p1,"%s %s %s %s %s %f %d %d\n",
                                bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                                bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
                    fclose(p1);
                    printf("\n删除成功!");
                }
                else
                    printf("\n该条书目没有被删除!");
            }
            printf("\n\n是否继续进行删除操作(y/n):");
            choice=getch();
            while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
                choice=getch();
            printf("%c",choice);
            printf("\n");
            if(choice=='Y'||choice=='y')
                continue;
            else
                break;
        }/*else结束*/
    }/*while(1)结束*/
}

void display_price_lower()/*根据价格列出图书信息*/
{
    float price;
    FILE *p1;
    int n;
    int count=0;
    BOOKINFO bookinfo[100];
    int booknumber;

    system("cls");
    printf("请输入你的理想价格,我们将推荐比您理想价位稍低的书籍:");
    scanf("%f",&price);
    p1=fopen("library.txt","r");
    booknumber=0;
    while(!feof(p1))
    {
        fscanf(p1,"%s %s %s %s %s %f %d %d\n",
               bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
               bookinfo[booknumber].press,bookinfo[booknumber].category,
               &bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
        booknumber++;
    }
    fclose(p1);
    if(bookinfo[0].quantity==0)
    {
        printf("\n没有任何图书信息!\n");
    }
    else
    {
        for(n=0;n<booknumber;n++)
        {
            if(bookinfo[n].price<=price)
                count++;
        }
        if(count==0)
            printf("书库中没有比%.1f元价格更低的图书。",price);
        else
        {
            printf("\n价格低于%.1f元的图书信息有%d本\n",price,count);
            printf("|---------------------------------图书信息---------------------------------|\n");
            printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
            printf("|                                                                          |\n");
            for(n=0;n<booknumber;n++)
            {
                if(bookinfo[n].price<=price)
                    printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                           bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            }
        }
    }
    printf("\n\n按任意键回到主菜单!\n");
    getch();
}

void modify_book()
{
    int flag=1,flag1=1,flag2,n;
    char change,choice;
    char number[15];/*图书编号*/
    char name[30];/*图书名称*/
    char author[20];/*作者*/
    char press[30];/*出版社*/
    char category[20];/*类别*/
    int  quantity;/*藏书量*/
    float price;/*单价*/

    char search[30];/*要修改的书名*/
    FILE *p1;
    BOOKINFO bookinfo[100];
    int booknumber;
    while(flag)
    {
        flag2=0;
        system("cls");
        fflush(stdin);
        printf("输入要修改信息的书本名:");
        gets(search);
        p1=fopen("library.txt","r");
        booknumber=0;
        while(!feof(p1))
        {
            fscanf(p1,"%s %s %s %s %s %f %d %d\n",
                   bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
                   bookinfo[booknumber].press,bookinfo[booknumber].category,
                   &bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
            booknumber++;
        }
        fclose(p1);
        if(bookinfo[0].quantity==0)
        {
            printf("书库中没有任何信息!\n\n");
            printf("按任意键回到主菜单!\n\n");
            getch();
            break;
        }
        else
        {
            for(n=0;n<booknumber;n++)
                if(strcmp(bookinfo[n].name,search)==0)
                {
                    printf("\n");
                    printf("|---------------------------------图书信息---------------------------------|\n");
                    printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
                    printf("|                                                                          |\n");
                    printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                           bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);

                    while(flag1){
                        printf("\n1.书籍编号\n2.书籍名称\n3.书籍作者\n4.出版社\n5.书籍类别\n6.书籍单价\n7.藏书量\n\n您想要修改的是:");
                        change=getch();
                        while(change!='1'&&change!='2'&&change!='3'&&change!='4'&&change!='5'&&change!='6'&&change!='7')
                            change=getch();
                        printf("%c",change);
                        printf("\n请输入新的字条:");
                        fflush(stdin);
                        switch(change)
                        {
                            case '1':gets(number);flag1=0;flag2=check_repeat_book(number);
                                if(!flag2)
                                    strcpy(bookinfo[n].number,number);
                                break;
                            case '2':gets(name);strcpy(bookinfo[n].name,name);flag1=0;break;
                            case '3':gets(author);strcpy(bookinfo[n].author,author);flag1=0;break;
                            case '4':gets(press);strcpy(bookinfo[n].press,press);flag1=0;break;
                            case '5':gets(category);strcpy(bookinfo[n].category,category);flag1=0;break;
                            case '6':scanf("%f",&price);bookinfo[n].price=price;flag1=0;break;
                            case '7':scanf("%d",&quantity);bookinfo[n].quantity=quantity;flag1=0;break;
                            default:break;/*虽然压根不会读到default情况，但是怕后来开发者漏掉新加的case的while处理，所以加上*/
                        }
                    }
                    flag1=1;
                    break;
                }
            if(n>=booknumber)
                printf("\n没有查找该书的任何信息!");
            else if(!flag2)
            {
                p1=fopen("library.txt","w");
                for(n=0;n<booknumber;n++)
                    fprintf(p1,"%s %s %s %s %s %f %d %d\n",
                            bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                            bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
                fclose(p1);
                printf("\n修改成功!");
            }
            else
                printf("您想修改的图书信息与馆内信息重复。");
            printf("\n是否继续进行修改(y/n):");
            choice=getch();
            while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
                choice=getch();
            printf("%c",choice);
            printf("\n");
            if(choice=='Y'||choice=='y')
                flag=1;
            else
                flag=0;
        }
    }
}

void borrow_book(char account[20])
{
    FILE *p1,*p3;
    BOOKINFO bookinfo[100];
    char search[30],choice;
    int flag=1,n;
    int booknumber1;
    system("cls");

    while(flag)
    {
        printf("输入要借阅的书本名:");
        gets(search);
        p1=fopen("library.txt","r");
        booknumber1=0;
        while(!feof(p1))
        {
            fscanf(p1,"%s %s %s %s %s %f %d %d\n",
                   bookinfo[booknumber1].number,bookinfo[booknumber1].name,bookinfo[booknumber1].author,
                   bookinfo[booknumber1].press,bookinfo[booknumber1].category,
                   &bookinfo[booknumber1].price,&bookinfo[booknumber1].quantity,&bookinfo[booknumber1].time);
            booknumber1++;
        }
        fclose(p1);

        if(bookinfo[0].quantity==0)
        {
            printf("\n书库中没有任何信息!\n");
            printf("按任意键回到主菜单!\n\n");
            getch();
            break;
        }
        else
        {
            for(n=0;n<booknumber1;n++)
                if(strcmp(bookinfo[n].name,search)==0)
                {
                    bookinfo[n].quantity--;
                    bookinfo[n].time++;

                    p3=fopen("memberbook.txt","a");  /*借书以a追加的方式，在文件中增加一本书*/
                    fprintf(p1,"%s %s %s %s %s %f %s\n",
                            bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,bookinfo[n].press,
                            bookinfo[n].category,bookinfo[n].price,account);
                    fclose(p3);
                    break;
                }
        }
        if(n>=booknumber1)
            printf("\n没有查找该书的任何信息!\n");
        else
        {
            p1=fopen("library.txt","w");
            for(n=0;n<booknumber1;n++)
                fprintf(p1,"%s %s %s %s %s %f %d %d\n",
                        bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,bookinfo[n].press,
                        bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            fclose(p1);
            printf("\n借书成功!\n");
        }
        printf("\n是否继续借书(y/n):");
        choice=getch();
        while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
            choice=getch();
        printf("%c",choice);
        printf("\n");
        if(choice=='Y'||choice=='y')
            flag=1;
        else
            flag=0;
    }
}

void return_book(char account[20])
{
    FILE *p1,*p3;
    BOOKINFO bookinfo[100];
    BOOKGRASP bookgrasp[100];
    char search[30],choice;
    int flag=1,flag2=0,n,i,k,j,t=0;
    int booknumber,booknumber2;
    system("cls");

    while(flag)
    {
        flag2=0;
        fflush(stdin);
        p1=fopen("library.txt","r");
        booknumber=0;
        while(!feof(p1))
        {
            fscanf(p1,"%s %s %s %s %s %f %d %d\n",
                   bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
                   bookinfo[booknumber].press,bookinfo[booknumber].category,
                   &bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
            booknumber++;
        }
        fclose(p1);

        p3=fopen("memberbook.txt","r");
        booknumber2=0;
        while(!feof(p3))
        {
            fscanf(p3,"%s %s %s %s %s %f %s\n",
                   bookgrasp[booknumber2].number,bookgrasp[booknumber2].name,bookgrasp[booknumber2].author,bookgrasp[booknumber2].press,
                   bookgrasp[booknumber2].category,&bookgrasp[booknumber2].price,bookgrasp[booknumber2].account);
            booknumber2++;
        }
        fclose(p3);

        printf("您所借阅的所有图书信息如下:\n");
        printf("|----------------------------图书借阅信息--------------------|\n");
        printf("|编号  书名        作者      出版社          类别    单价    |\n");
        while(t<booknumber2)
        {
            if(strcmp(bookgrasp[t].account,account)==0)
            {
                printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f|\n",bookgrasp[t].number,
                       bookgrasp[t].name,bookgrasp[t].author,bookgrasp[t].press,
                       bookgrasp[t].category,bookgrasp[t].price);
            }
            t++;
        }

        printf("\n输入要归还的书本名:");
        gets(search);
        if(bookinfo[0].quantity==0)
        {
            printf("\n书库中没有任何信息!\n");
            printf("按任意键回到主菜单!\n\n");
            getch();
            break;
        }
        else
        {
            for(n=0;n<booknumber;n++)
                if(strcmp(bookinfo[n].name,search)==0)
                {
                    bookinfo[n].quantity++;

                    if(bookgrasp[0].price==0)
                        printf("\n您没有借书信息。");
                    else{
                        for(k=0;k<booknumber2;k++)
                            if(!strcmp(bookgrasp[k].account,account)&&!strcmp(bookgrasp[k].name,search))
                            {
                                flag2=1;
                                for(i=k;i<booknumber2-1;i++)
                                    bookgrasp[i]=bookgrasp[i+1];
                                booknumber2--;
                                break;
                            }

                        p3=fopen("memberbook.txt","w");
                        for(j=0;j<booknumber2;j++)
                        {
                            fprintf(p3,"%s %s %s %s %s %f %s\n",
                                    bookgrasp[j].number,bookgrasp[j].name,bookgrasp[j].author,bookgrasp[j].press,
                                    bookgrasp[j].category,bookgrasp[j].price,bookgrasp[j].account);
                        }
                        fclose(p3);
                    }
                    break;
                }
        }
        if(n==booknumber||flag2==0)
            printf("您并没有这条借阅信息!\n");
        if(n<booknumber&&flag2==1)
        {
            p1=fopen("library.txt","w");
            for(n=0;n<booknumber;n++)
                fprintf(p1,"%s %s %s %s %s %f %d %d\n",
                        bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                        bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            fclose(p1);
            printf("\n还书成功！");
        }
        else
            printf("\n还书失败！");

        fflush(stdin);
        printf("\n是否继续还书(y/n):");
        choice=getch();
        while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
            choice=getch();
        printf("%c",choice);
        printf("\n");
        if(choice=='Y'||choice=='y')
            flag=1;
        else
            flag=0;
    }
}