#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//宏定义区
#define MAX_USERS 100
#define BUFFER_SIZE 20
#define MAX_BOOKS 100

typedef struct book_system{
    char name[20];//书名
    char author[20];//作者
    char press[20];//出版社
    char isbn[20];//唯一标识码isbn
    char category[20];//类别
    int price;//价格
    int num;//数量
}Book;
typedef struct user_system{
    char id[20];//用户id
    char name[20];//用户名
    char password[20];//密码
    char phone[20];//电话号码
    int num;//借阅数量
}User;
typedef struct borrow_system{
    char id[20];//用户id
    char book_name[20];//书名
    char isbn[20];//唯一标识码isbn
    int num;//借阅数量
    int time;//借阅时间
    int price;//罚款金额
}Borrow;
//函数区
int File_open();//启动检测函数
void menu1();//菜单1
void about_menu();//关于
void menu2();//菜单2
void menu3();//菜单3
//读者注册函数
void user_register();
//读者登录相关函数区
int user_login();//读者登录
int user_login_verify(char password[20]);//读者密码验证
void all_book();//全部图书
void borrow_book(char id[20]);//借阅图书
void return_book(char id[20]);//还书
void user_info(char id[20]);//读者信息
void print_user_info(const User *user);//输出读者信息
void modify_user_info(User *user);//修改读者信息
void load_books(FILE *file, Book books[], int *count);//读取图书信息
void load_borrows(FILE *file, Borrow borrows[], int *count);//读取借阅信息
void save_books(FILE *file, Book books[], int count);//保存图书信息
void save_borrows(FILE *file, Borrow borrows[], int count);//保存借阅信息
//管理员相关函数区
void Administrator();//管理员主函数
#define ADMIN_password "123456"//管理员登录密码
void add_book();//增加图书
void delete_book();//删除图书
void modify_book();//修改图书信息
void search_book();//查询图书
void all_user();//全部读者信息
void all_borrow();//全部借阅信息


int main(){
    int flag=0,k;
    flag = File_open();
    if(flag==0){
        printf("程序文件打开失败，请检查\n");
        printf("按任意键退出...\n");
        getchar();
        exit(0);//退出程序
    }else{
        printf("程序文件打开成功\n");
        printf("正在打开图书管理程序\n");
        while(1){
            menu1();
            printf("请输入您的选择：");
            scanf_s("%d",&k,3);
            switch(k){
                case 1:
                    printf("您当前在用户登录页面！\n");
                    user_login();
                    break;
                case 2:
                    user_register();
                    break;
                case 3:
                    printf("您当前在管理员页面！\n");
                    Administrator();
                    break;
                case 4:
                    printf("您当前在关于页面！\n");
                    about_menu();
                    break;
                case 5:
                    printf("感谢您的使用，再见！\n");
                    exit(0);
                default:
                    printf("您的输入有误，请重新输入！\n");
                    break;
            }
        }
    }
}
void all_borrow(){
    FILE *p1 = fopen("borrow.txt", "r");
    if (p1 == NULL) {
        perror("文件打开失败");//打开文件失败
        return;
    }
    Borrow borrows[MAX_BOOKS];
    int number = 0;
    while (number < MAX_BOOKS && fscanf(p1, "%19s %49s %19s %d %d %d",
                                        borrows[number].id, borrows[number].book_name,
                                        borrows[number].isbn, &borrows[number].num,
                                        &borrows[number].time, &borrows[number].price) == 6) {
        number++;
    }
    fclose(p1);
    printf("序号\t用户id\t图书名称\tisbn\t借阅数量\t借阅时间\t罚款金额\n");
    for (int i = 0; i < number; i++) {
        printf("%d\t%s\t%s\t%s\t%d\t%d\t%d\n", i + 1, borrows[i].id, borrows[i].book_name,
               borrows[i].isbn, borrows[i].num, borrows[i].time, borrows[i].price);
    }
}
void all_user() {
    FILE *p1 = fopen("user.txt", "r");
    if (p1 == NULL) {
        perror("文件打开失败");//打开文件失败
        return;
    }

    User users[MAX_USERS];
    int number = 0;
    while (number < MAX_USERS && fscanf(p1, "%19s %49s %19s %14s %d",
                                        users[number].id, users[number].name,
                                        users[number].password, users[number].phone,
                                        &users[number].num) == 5) {
        number++;
    }

    fclose(p1);

    printf("序号\t用户id\t用户名\t密码\t电话号码\t借阅数量\n");
    for (int i = 0; i < number; i++) {
        printf("%d\t%s\t%s\t%s\t%s\t%d\n", i + 1, users[i].id, users[i].name, users[i].password, users[i].phone, users[i].num);
    }
}
void search_book(){
    FILE *p1;
    int number = 0, flag = 1, i,flag2=1,found=0;
    char name[20], choice[3],choice1[3],choice2[2];
    Book books[MAX_BOOKS];
    p1 = fopen("book.txt", "r");
    load_books(p1, books, &number);
    fclose(p1);
    while(flag){
        printf("请输入你要查询的书籍名称：");
        scanf_s("%s", name, 20);
        for(i=0;i<number;i++){
            if(strcmp(name,books[i].name)==0){
                found=1;
                break;
            }
        }
        if(found){
            printf("该图书存在，以下为查询的书籍信息：\n");
            printf("序号\t书名\t作者\t出版社\tisbn\t类别\t价格\t数量\n");
            printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",i+1,books[i].name,books[i].author,books[i].press
                   ,books[i].isbn,books[i].category,books[i].price,books[i].num);
            printf("是否继续查询？（y/n）");
            scanf_s("%s",choice,3);
            if(choice[0]=='y'||choice[0]=='Y'){
                flag=1;
            }else{
                flag = 0;
            }
        }else{
            printf("该图书不存在，请重新输入或检查！\n");
            printf("是否重新查询？（y/n）");
            scanf_s("%s",choice1,3);
            if(choice1[0]=='y'||choice1[0]=='Y'){
                flag=1;
            }else{
                flag = 0;
            }
        }
    }
}
void modify_book(){
    FILE *p1;
    int number = 0, flag = 1, i,flag2=1,found=0;
    char name[20], choice[3],choice1[3],choice2[2];
    Book books[MAX_BOOKS];
    p1 = fopen("book.txt", "r");
    load_books(p1, books, &number);
    fclose(p1);
    while(flag){
        printf("请输入你要修改的书籍名称：");
        scanf_s("%s", name, 20);
        for(i=0;i<number;i++){
            if(strcmp(name,books[i].name)==0){
                found=1;
                break;
            }
        }
        if(found){
            printf("该图书存在，是否确认修改？（y/n）");
            scanf_s("%s",choice,3);
            if(choice[0]=='y'||choice[0]=='Y'){
                flag2=1;
            }else{
                printf("你已取消修改操作！\n");
                flag2 = 0;
                flag = 0;
            }
        }else{
            printf("该图书不存在，请重新输入或检查！\n");
            flag2 = 0;
            flag = 1;
        }
        if(flag2){
            printf("你可以通过序号来进行书籍详细信息的修改\n");
            printf("1.书名  2.作者  3.出版社  4.isbn  5.类别  6.价格  7.数量  8.取消修改\n");
            scanf_s("%d",choice1,3);
            switch(choice1[0]){
                case 1:
                    printf("请输入新的书名：");
                    scanf_s("%s", books[i].name, 20);
                    break;
                case 2:
                    printf("请输入新的作者：");
                    scanf_s("%s", books[i].author, 20);
                    break;
                case 3:
                    printf("请输入新的出版社：");
                    scanf_s("%s", books[i].press, 20);
                    break;
                case 4:
                    printf("请输入新的isbn：");
                    scanf_s("%s", books[i].isbn, 20);
                    break;
                case 5:
                    printf("请输入新的类别：");
                    scanf_s("%s", books[i].category, 20);
                    break;
                case 6:
                    printf("请输入新的价格：");
                    scanf_s("%d", &books[i].price, 3);
                    break;
                case 7:
                    printf("请输入新的数量：");
                    scanf_s("%d", &books[i].num, 3);
                    break;
                case 8:
                    printf("取消修改\n");
                    break;
                default:
                    printf("输入有误，请重新输入！\n");
                    break;
            }
            p1 = fopen("book.txt", "w");
            save_books(p1, books, number);
            fclose(p1);
            printf("图书信息修改成功！\n");
            printf("请问是否继续修改？（y/n）");
            scanf_s("%s", choice2, 3);
            if(choice2[0]=='y'||choice2[0]=='Y'){
                flag = 1;
            }else{
                flag = 0;
            }
        }
    }
}
void delete_book() {
    FILE *p1, *p2;  // 新增一个文件指针用于临时文件
    int number = 0, flag = 0, i;
    char name[20], choice[3];
    printf("你当前在删除图书界面");
    Book books[MAX_BOOKS];
    p1 = fopen("book.txt", "r");
    if (p1 == NULL) {
        perror("打开文件book.txt失败");
        return;
    }
    load_books(p1, books, &number);
    fclose(p1);

    printf("请输入你要删除的书籍（注意，若只删除该书在书库里的一本书，请使用修改图书信息！）");
    printf("请输入要删除的书籍名称：");
    scanf_s("%s", name, 20);

    for (i = 0; i < number; i++) {
        if (strcmp(name, books[i].name) == 0) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("该图书存在，是否确认删除？（y/n）");
        scanf_s("%s", choice, 3);
        if (choice[0] == 'y' || choice[0] == 'Y') {
            p2 = fopen("temp_book.txt", "w");  // 打开临时文件用于写入保留的数据
            if (p2 == NULL) {
                perror("打开临时文件temp_book.txt失败");
                return;
            }
            for (int j = 0; j < number; j++) {
                if (j!= i) {
                    fprintf(p2, "%s %s %s %s %s %d %d\n", books[j].name, books[j].author,
                            books[j].press, books[j].isbn, books[j].category, books[j].price,
                            books[j].num);
                }
            }
            fclose(p2);
            fclose(p1);
            remove("book.txt");  // 删除原文件
            rename("temp_book.txt", "book.txt");  // 将临时文件重命名为原文件名
            if (remove("book.txt")!= 0) {
                perror("删除book.txt文件失败");
                return;
            }
            if (rename("temp_book.txt", "book.txt")!= 0) {
                perror("重命名临时文件失败");
                return;
            }
            printf("图书信息删除成功！\n");
            printf("按任意键继续...\n");
            getchar();
        } else {
            printf("你已取消删除操作！\n");
        }
    } else {
        printf("该图书不存在，请重新输入！\n");
    }
}
void add_book(){
    FILE *p1;
    int flag=1,number=0,flag1=0,price,num;
    char name[20],author[20],press[20],isbn[20],category[20],choice[3];
    printf("你当前在增加图书界面\n");
    printf("请注意检查是否重复添加图书，如需修改已有图书数据，请使用修改图书选项！\n");
    Book books[MAX_USERS];
    int count=0;
    p1 = fopen("book.txt", "r");
    load_books(p1, books, &count);
    fclose(p1);
    while(flag){
        printf("请输入图书名称：");
        scanf_s("%s",name,20);
        for(int i=0;i<count;i++){//判断是否重复添加图书
            if(strcmp(name,books[i].name)==0){
                flag1 = 1;
                break;
            }
        }
        if(flag1){
            printf("该图书已存在，请重新输入！\n");
            flag = 1;
        }else{
            printf("请输入图书作者：");
            scanf_s("%s",author,20);
            printf("请输入图书出版社：");
            scanf_s("%s",press,20);
            printf("请输入图书isbn：");
            scanf_s("%s",isbn,20);
            printf("请输入图书类别：");
            scanf_s("%s",category,20);
            printf("请输入图书价格：");
            scanf_s("%d",&price,5);
            printf("请输入图书数量：");
            scanf_s("%d",&num,5);
            p1 = fopen("book.txt", "a");
            fprintf(p1, "\n%s %s %s %s %s %d %d", name, author, press, isbn, category, price, num);
            fclose(p1);
            printf("图书添加成功！\n");
            printf("是否继续添加图书？（y/n）");
            scanf_s("%s",choice,3);
            if(choice[0]=='y'||choice[0]=='Y'){
                flag = 1;
            }else{
                flag = 0;
            }
        }
    }
}
void Administrator(){
    int flag=1,k;
    char password[20];
    printf("请输入管理员密码：");
    scanf_s("%s",password,20);
    if(strcmp(password,ADMIN_password)==0){
        printf("管理员登录成功！\n");
        printf("正在打开管理员页面\n");
        while(flag){
            menu3();
            printf("请输入您的选择：");
            scanf_s("%d",&k,3);
            switch(k){
                case 1:
                    //增加图书
                    add_book();
                    break;
                case 2:
                    //删除图书
                    delete_book();
                    break;
                case 3:
                    //修改图书信息
                    modify_book();
                    break;
                case 4:
                   //查询图书
                    search_book();
                    break;
                case 5:
                    //显示所有图书信息
                    all_book();
                    break;
                case 6:
                    //显示所有用户信息
                    all_user();
                    break;
                case 7:
                    //显示所有借阅信息
                    all_borrow();
                    break;
                case 8:
                    //退出管理员系统
                    flag = 0;
                    break;
                default:
                    printf("您的输入有误，请重新输入！\n");
                    break;
            }
        }
    }else{
        printf("管理员登录失败,请检查密码！\n");
    }
}
void user_register() {
    FILE *p1;
    User user_system[MAX_USERS];
    int number = 0, flag = 1, flag1 = 1;
    char n[BUFFER_SIZE], k[BUFFER_SIZE], g[BUFFER_SIZE], a[BUFFER_SIZE], m[3];

    printf("欢迎使用用户注册功能！\n");

    // 读取现有用户信息
    p1 = fopen("user.txt", "r");
    if (p1 == NULL) {
        printf("无法打开文件 user.txt\n");
        return;
    }
    while (fscanf(p1, "%s %s %s %s %d", user_system[number].id, user_system[number].name, user_system[number].password, user_system[number].phone, &user_system[number].num) == 5 && number < MAX_USERS) {
        number++;
    }
    fclose(p1);

    while (flag) {
        printf("请输入您的用户名：");
        scanf_s("%s", n, BUFFER_SIZE);
        printf("请输入您的密码：");
        scanf_s("%s", k, BUFFER_SIZE);
        printf("请输入您的电话号码：");
        scanf_s("%s", g, BUFFER_SIZE);
        printf("请输入您的id：");
        scanf_s("%s", a, BUFFER_SIZE);

        flag1 = 1;
        for (int i = 0; i < number; i++) {
            if (strcmp(user_system[i].id, a) == 0) {
                printf("该id已被注册，请重新输入！\n");
                flag1 = 0;
                break;
            }
        }

        if (flag1) {
            printf("好的，您的注册信息已经保留！欢迎您的使用\n");
            p1 = fopen("user.txt", "a");
            if (p1 == NULL) {
                printf("无法打开文件 user.txt\n");
                return;
            }
            fprintf(p1, "%s %s %s %s %d\n", a, n, k, g, 0);
            fclose(p1);
        } else {
            continue;
        }

        printf("是否要继续注册？（y/n）");
        scanf_s("%s", m, 3);
        if (m[0] == 'y' || m[0] == 'Y') {
            flag = 1;
        } else {
            flag = 0;
        }
    }
}
void user_info(char *id) {
    FILE *p1 = NULL;
    int flag = 1, number = 0;
    char n[3], k[3], g[3], a[3];
    User user_system[MAX_USERS];

    printf("欢迎使用读者信息查询功能！\n");

    while (flag) {
        p1 = fopen("user.txt", "r");
        if (p1 == NULL) {
            printf("无法打开文件 user.txt\n");
            return;
        }

        while (number < MAX_USERS && fscanf(p1, "%s %s %s %s %d", user_system[number].id, user_system[number].name,
                                           user_system[number].password, user_system[number].phone,
                                           &user_system[number].num) == 5) {
            number++;
        }
        fclose(p1);

        int found = 0;
        for (int i = 0; i < number; i++) {
            if (strcmp(user_system[i].id, id) == 0) {
                found = 1;
                printf("您的信息如下：\n");
                print_user_info(&user_system[i]);

                printf("是否要修改您的信息？（y/n）");
                scanf_s("%s", n, _countof(n));

                if (n[0] == 'y' || n[0] == 'Y') {
                    modify_user_info(&user_system[i]);

                    p1 = fopen("user.txt", "w");
                    if (p1 == NULL) {
                        printf("无法打开文件 user.txt\n");
                        return;
                    }

                    for (int j = 0; j < number; j++) {
                        fprintf(p1, "%s %s %s %s %d\n", user_system[j].id, user_system[j].name,
                                user_system[j].password, user_system[j].phone, user_system[j].num);
                    }
                    fclose(p1);

                    printf("修改成功！\n");
                    printf("是否查看你修改后的信息？（y/n）");
                    scanf_s("%s", g, _countof(g));

                    if (g[0] == 'y' || g[0] == 'Y') {
                        print_user_info(&user_system[i]);
                        printf("是否要继续使用？（y/n）");
                        scanf_s("%s", a, _countof(a));
                        if (a[0] != 'y' && a[0] != 'Y') {
                            printf("感谢您的使用，再见！\n");
                            flag = 0;
                        }
                    } else {
                        printf("感谢您的使用，再见！\n");
                        flag = 0;
                    }
                } else {
                    printf("感谢您的使用，再见！\n");
                    flag = 0;
                }
                break;
            }
        }

        if (!found) {
            printf("未找到匹配的用户信息。\n");
            flag = 0;
        }
    }
}
void return_book(char *id) {
    FILE *p1, *p2;
    int number = 0, number1 = 0;
    char choice1[20], choice2[3];
    Book book_system[1000];
    Borrow borrow_system[1000];

    // Load data from files
    if ((p1 = fopen("book.txt", "r")) == NULL) {
        printf("无法打开 book.txt 文件。\n");
        return;
    }
    if ((p2 = fopen("borrow.txt", "r")) == NULL) {
        fclose(p1);
        printf("无法打开 borrow.txt 文件。\n");
        return;
    }

    load_books(p1, book_system, &number);
    load_borrows(p2, borrow_system, &number1);

    fclose(p1);
    fclose(p2);

    printf("你当前借阅的图书如下：\n");
    printf("读者id\t书名\tisbn\t借阅数量\t借阅时间\t罚款金额\n");
    for (int t = 0; t < number1; t++) {
        if (strcmp(borrow_system[t].id, id) == 0) {
            printf("%s\t%s\t%s\t%d\t%d\t%d\n", borrow_system[t].id, borrow_system[t].book_name,
                   borrow_system[t].isbn, borrow_system[t].num, borrow_system[t].time, borrow_system[t].price);
        }
    }

    int flag = 1;
    while (flag) {
        printf("请输入要归还的书名：");
        scanf("%19s", choice1);

        int index = -1;
        for (int i = 0; i < number1; i++) {
            if (strcmp(borrow_system[i].book_name, choice1) == 0 && strcmp(borrow_system[i].id, id) == 0) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            printf("是否确认归还？（y/n）");
            scanf("%2s", choice2);

            if (choice2[0] == 'y' || choice2[0] == 'Y') {
                // 更新图书库存数量
                int book_index = -1;
                for (int j = 0; j < number; j++) {
                    if (strcmp(book_system[j].name, choice1) == 0) {
                        book_index = j;
                        break;
                    }
                }

                if (book_index == -1) {
                    printf("出现错误，未找到对应图书信息。\n");
                    return;
                }

                book_system[book_index].num += borrow_system[index].num;

                // 删除借阅记录
                for (int k = index; k < number1 - 1; k++) {
                    borrow_system[k] = borrow_system[k + 1];
                }
                number1--;

                // 保存更新后的数据到文件
                if ((p1 = fopen("book.txt", "w")) == NULL) {
                    printf("无法打开 book.txt 文件。\n");
                    return;
                }
                if ((p2 = fopen("borrow.txt", "w")) == NULL) {
                    fclose(p1);
                    printf("无法打开 borrow.txt 文件。\n");
                    return;
                }

                save_books(p1, book_system, number);
                save_borrows(p2, borrow_system, number1);

                fclose(p1);
                fclose(p2);

                printf("还书成功！\n");
            }
        } else {
            printf("未找到您当前所借书籍，是否重试？（y/n）");
            scanf("%2s", choice2);
            if (choice2[0] != 'y' && choice2[0] != 'Y') {
                flag = 0;
            }
        }

        if (flag) {
            printf("是否继续还书？（y/n）");
            scanf("%2s", choice2);
            if (choice2[0] != 'y' && choice2[0] != 'Y') {
                flag = 0;
            }
        }
    }
}
void borrow_book(char *id){
    FILE *p1 , *p2;
    int number = 0,number1 = 0,n,flag = 0;
    char choice1;
    char choice2[20];
    Book book_system[1000];
    Borrow borrow_system[1000];
    p1 = fopen("book.txt", "r");
    p2 = fopen("borrow.txt", "r");
    while(number < 1000 && fscanf(p1, "%s %s %s %s %s %d %d\n", book_system[number].name, book_system[number].author,
                                  book_system[number].press, book_system[number].isbn,book_system[number].category,
                                  &book_system[number].price, &book_system[number].num)) {
        number++;
    }
    while (number1 < 1000 && fscanf(p2, "%s %s %s %d %d %d\n", borrow_system[number1].id, borrow_system[number1].book_name,
                                      borrow_system[number1].isbn, &borrow_system[number1].num,
                                      &borrow_system[number1].time, &borrow_system[number1].price)) {
        number1++;
    }
    fclose(p1);//关闭文件
    fclose(p2);
    for (n = 0; n < number; n++) {
        printf("请输入要借阅的书名：");
        scanf_s("%s",choice2,20);
        if (strcmp(book_system[number].name,choice2) == 0) {
            flag = 1;
            break;
        }else{
            printf("未找到所借书籍，是否重试？（y/n）");
            char i;
            scanf_s("%s", &i, 3);
            if(i == 'y'|| i == 'Y'){
                continue;
            }else{
                printf("您已取消借阅！\n");
                return;
            }
        }
    }
    if(flag){
        printf("您要借阅的书在馆，是否确认借阅？（y/n）");
        scanf_s("%s", &choice1, 3);
        if (choice1 == 'y'|| choice1 == 'Y') {
            p2 = fopen("borrow.txt", "a");
            fprintf(p2, "%s %s %s %d %d %d\n", id, book_system[number].name, book_system[number].isbn, 1, 0, 0);
            printf("借阅成功！\n");
            fclose(p2);
        } else {
            printf("您已取消借阅！\n");

        }
    }
}
void all_book() {
    FILE *p2;
    int number = 0, n;
    Book *book_system = (Book *)malloc(MAX_BOOKS * sizeof(Book));
    if (book_system == NULL) {
        printf("内存分配失败\n");
        return;
    }//动态分配内存，使以下number小于1000的时候不会读取出错误的空信息，而只读取有效信息！

    printf("图书信息如下：\n");
    p2 = fopen("book.txt", "r");
    if (p2 == NULL) {
        printf("无法打开文件 book.txt\n");
        free(book_system);
        return;
    }

    while (number < MAX_BOOKS && fscanf(p2, "%99s %99s %99s %19s %49s %d %d",
                                        book_system[number].name, book_system[number].author,
                                        book_system[number].press, book_system[number].isbn,
                                        book_system[number].category, &book_system[number].price,
                                        &book_system[number].num) == 7) {
        number++;
    }

    fclose(p2);
    printf("以下为馆藏信息：\n");
    printf("序号\t书名\t作者\t出版社\tisbn\t类别\t价格\t数量\n");
    for (n = 0; n < number; n++) {
        printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n", n + 1, book_system[n].name, book_system[n].author,
               book_system[n].press, book_system[n].isbn, book_system[n].category, book_system[n].price,
               book_system[n].num);
    }
    free(book_system);//释放内存
}
int user_login(){
    FILE *p1;
    User user_system[100];
    int number = 0,n,k = 5,b;
    char id[20], password[20],choice1;
    int flag = 0;
    p1 = fopen("user.txt", "r");
    while (number < 100 && fscanf(p1, "%s %s %s %s %d\n", user_system[number].id, user_system[number].name,
                                  user_system[number].password, user_system[number].phone, &user_system[number].num)) {
        number++;
    }//循环读取文件中的数据
    fclose(p1);//关闭文件
    printf("请输入您的id：");
    scanf_s("%s", id,20);
    for (n = 0; n < number; n++) {
        if (strcmp(user_system[n].id, id) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        while (k > 0) {
            if (user_login_verify(user_system[n].password)) {//密码核对
                printf("核对正确！进入用户登录界面...");
                while (1) {
                    menu2();
                    printf("请输入您的选择：");
                    scanf_s("%d", &b, 3);
                    switch (b) {
                        case 1:
                            //查询图书馆藏信息
                            all_book();
                            break;
                        case 2:
                            //借阅图书
                            borrow_book(id);
                            break;
                        case 3:
                            //还书
                            return_book(id);
                            break;
                        case 4:
                            //账户信息
                            user_info(id);
                            break;
                        case 5:
                            //查询图书
                            search_book();
                            break;
                        case 6:
                            printf("您已成功退出登录！\n");
                            return 0;
                        default:
                            printf("您的输入有误，请重新输入！\n");
                            break;
                    }
                }
            } else {
                --k;
                if (k > 0) {
                    printf("您的密码输入有误!还有%d次机会重新输入密码！", k);
                    printf("您是否要继续输入密码(y/n): ");
                    choice1 = getchar();
                    while ((choice1 != 'Y') && (choice1 != 'y') && (choice1 != 'N') && (choice1 != 'n')) {
                        choice1 = getchar();
                    }
                    if (choice1 == 'Y' || choice1 == 'y') {
                        continue;
                    } else {
                        return 2;
                    }
                } else {
                    printf("您输入次数已用完！按任意键退出...");
                    getchar();
                    return 0;
                }
            }
        }
    } else {
        printf("该ID还未注册！\n");
        return 0;
    }
    return 0;
}
int user_login_verify(char *password){
    int i=0;
    char compare[20];
    fflush(stdin);
    printf("密码(password):");
    scanf_s("%s",compare,20);
    if(strcmp(password,compare)==0)
    {
        printf("\a");  //响铃
        return 1;
    }
    else
    {
        printf("\a");  //响铃
        return 0;
    }
}
int File_open(){
    FILE *p1,*p2,*p3;
    if((p1=fopen("book.txt","r"))==NULL){
        printf("图书文件打开失败\n");
        return 0;
    }else{
        printf("图书文件打开成功\n");
        if((p2=fopen("user.txt","r"))==NULL){
            printf("用户文件打开失败\n");
            return 0;
        }else{
            printf("用户文件打开成功\n");
            if((p3=fopen("borrow.txt","r"))==NULL){
                printf("借阅文件打开失败\n");
                return 0;
           }else{
            printf("借阅文件打开成功\n");}
        }
    }
    return 1;
}
void print_user_info(const User *user) {
    printf("读者id\t用户名\t密码\t电话号码\t借阅数量\n");
    printf("%s\t%s\t%s\t%s\t%d\n", user->id, user->name, user->password, user->phone, user->num);
}
void modify_user_info(User *user) {
    char choice[3];
    printf("请输入要修改的信息(注：可对1.用户名  2.密码  3.电话号码  进行修改)：");
    scanf_s("%s", choice, _countof(choice));

    if (choice[0] == '1') {
        printf("请输入新的用户名：");
        scanf_s("%s", user->name, _countof(user->name));
    } else if (choice[0] == '2') {
        printf("请输入新的密码：");
        scanf_s("%s", user->password, _countof(user->password));
    } else if (choice[0] == '3') {
        printf("请输入新的电话号码：");
        scanf_s("%s", user->phone, _countof(user->phone));
    } else {
        printf("输入有误，请重新输入！\n");
    }
}
void load_books(FILE *file, Book books[], int *count) {
    while (*count < 1000 && fscanf(file, "%s %s %s %s %s %d %d\n",
                                   books[*count].name, books[*count].author,
                                   books[*count].press, books[*count].isbn,
                                   books[*count].category, &books[*count].price,
                                   &books[*count].num) == 7) {
        (*count)++;
    }
}
void load_borrows(FILE *file, Borrow borrows[], int *count) {
    while (*count < 1000 && fscanf(file, "%s %s %s %d %d %d\n",
                                   borrows[*count].id, borrows[*count].book_name,
                                   borrows[*count].isbn, &borrows[*count].num,
                                   &borrows[*count].time, &borrows[*count].price) == 6) {
        (*count)++;
    }
}
void save_books(FILE *file, Book books[], int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s %s %s %d %d\n", books[i].name, books[i].author,
                books[i].press, books[i].isbn, books[i].category,
                books[i].price, books[i].num);
    }
}
void save_borrows(FILE *file, Borrow borrows[], int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s %d %d %d\n", borrows[i].id, borrows[i].book_name,
                borrows[i].isbn, borrows[i].num,
                borrows[i].time, borrows[i].price);
    }
}
void menu1(){
    printf("\n\n");
    printf("\t\t\t*=======================================================*\n");
    printf("\t\t\t||-------------------欢饮使用图书管理程序-------------------||\n");
    printf("\t\t\t*     [1]     读者登录                                    *|\n");
    printf("\t\t\t||    [2]     读者注册                                   ||\n");
    printf("\t\t\t|*    [3]     管理员登录                                  *|\n");
    printf("\t\t\t||    [4]     关于                                      ||\n");
    printf("\t\t\t|*    [5]     退出                                      *|\n");
    printf("\t\t\t*=======================================================*\n");
}
void menu2(){
    printf("\n\n");
    printf("\t\t\t*=======================================================*\n");
    printf("\t\t\t||------------------------用户登录 ---------------------||\n");
    printf("\t\t\t||    [1]     查询馆藏图书信息                            ||\n");
    printf("\t\t\t|*    [2]     借阅图书                                   *|\n");
    printf("\t\t\t||    [3]     归还图书                                   ||\n");
    printf("\t\t\t|*    [4]     账户信息                                   *|\n");
    printf("\t\t\t||    [5]     查询图书                                   ||\n");
    printf("\t\t\t||    [6]     退出登录                                   ||\n");
    printf("\t\t\t*=======================================================*\n");
}
void menu3(){
    printf("\n\n");
    printf("\t\t\t*=======================================================*\n");
    printf("\t\t\t||-----------------------管理员登录 ---------------------||\n");
    printf("\t\t\t||    [1]     增加图书                                   ||\n");
    printf("\t\t\t|*    [2]     删除图书                                   *|\n");
    printf("\t\t\t||    [3]     修改图书信息                                ||\n");
    printf("\t\t\t|*    [4]     查找图书                                   *|\n");
    printf("\t\t\t||    [5]     显示所有图书信息                             ||\n");
    printf("\t\t\t||    [6]     显示所有用户信息                             ||\n");
    printf("\t\t\t||    [7]     显示所有借阅信息                              ||\n");
    printf("\t\t\t||    [8]     退出管理员系统                               ||\n");
    printf("\t\t\t*=======================================================*\n");
}
void about_menu(){
    printf("\n\n");
    printf("\t\t\t*=======================================================*\n");
    printf("\t\t\t||------------------------ 关于 ------------------------||\n");
    printf("\t\t\t|            软件241夏宇昂    202400406040                |\n");
    printf("\t\t\t|                                                       |\n");
    printf("\t\t\t|             C_V1.0  图书馆管理程序  24/12/10             |\n");
    printf("\t\t\t|                                                       |\n");
    printf("\t\t\t|       思路及实现:清华大学出版社-C语言从入门到精通             |\n");
    printf("\t\t\t|                知乎-@Jarry                             |\n");
    printf("\t\t\t|                       按任意键返回                      |\n");
    printf("\t\t\t*=======================================================*\n");
    getchar();
}