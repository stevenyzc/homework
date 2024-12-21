#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

// 一本书的信息
class BookData{
public:
    char isbn[14]; // 该书的ISBN号
    char bookTitle[51]; // 书名
    int qtyOnHand; // 该书的库存量
    double retail; // 该书的零售价
};
BookData book[100]; // 定义一个具有100个元素的对象数组空间存储该书店的100本书

void show_main_menu() // 显示主菜单
{
    cout<<"           XXX图书管理系统"<<endl;
    cout<<"               主菜单"<<endl<<endl;
    cout<<"1.收银模块"<<endl;
    cout<<"2.书库管理模块"<<endl;
    cout<<"3.报表模块"<<endl;
    cout<<"4.退出系统"<<endl<<endl;
    cout<<"   输入选择:"<<endl;
    cout<<"   请输入1-4之间的数"<<endl;
}

void show_system_date() // 输出系统日期
{
    time_t now = time(nullptr); // 获取当前时间,使用time函数得到time_t类型
    tm *now_tm = localtime(&now); // 转换为tm结构以便操作时间的各个部分
    // 输出系统日期
    cout<< "日期:" << 1900 + now_tm->tm_year << "年" << 1 + now_tm->tm_mon << "月" << now_tm->tm_mday << "日" <<endl;
}

void show_cashier_module(int buy,BookData Book) // 显示收银模块界面
{
    double gross_sales=buy*Book.retail; // 销售合计=购书量*零售价
    double retail_sales_tax=0.06*gross_sales; // 零售税=6%销售合计
    double sum=gross_sales+retail_sales_tax; // 应付总额=销售合计+零售税
    cout<<"                        前台销售模块"<<endl;
    show_system_date(); // 输出系统日期
    cout<<"数量";
    int isbn_len=strlen(Book.isbn); // isbn号长度
    int space=isbn_len/2-1; // 多输出的空格数
    for (int i=0;i<space;i++) cout<<" ";
    cout<<"ISBN号";
    for (int i=0;i<space;i++) cout<<" ";
    int bookTitle_len=strlen(Book.bookTitle);
    double space2=bookTitle_len/3.2-1; // 多输出的空格数
    for (int i=0;i<space2;i++) cout<<" ";
    cout<<"书名";
    for (int i=0;i<space2;i++) cout<<" ";
    cout<<"    单价        ";
    cout<<"金额"<<endl;
    cout<<" "<<buy<<"   "<<Book.isbn<<"   "<<Book.bookTitle<<"   RMB "<<Book.retail<<"   RMB "<<gross_sales<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"销售合计:RMB "<<gross_sales<<endl;
    cout<<"零售税:RMB "<<retail_sales_tax<<endl;
    cout<<"应付总额:RMB "<<sum<<endl<<endl;
    cout<<"谢谢光临!"<<endl;
}

void show_library_operation_menu() // 显示书库操作菜单
{
    cout<<"       XXX 图书管理系统"<<endl;
    cout<<"         书库管理模块"<<endl<<endl;
    cout<<"1.查找某本书的信息"<<endl;
    cout<<"2.增加书"<<endl;
    cout<<"3.修改书的信息"<<endl;
    cout<<"4.删除书"<<endl;
    cout<<"5.返回到主菜单"<<endl<<endl;
    cout<<"输入选择:"<<endl;
}

void show_report_menu() // 显示报表菜单
{
    cout<<"     XXX 图书管理系统"<<endl;
    cout<<"         报表模块"<<endl<<endl;
    cout<<"1.书库列表"<<endl;
    cout<<"2.零售价列表"<<endl;
    cout<<"3.返回到主菜单"<<endl<<endl;
    cout<<"输入选择:"<<endl;
}

void show_editBook() // 提示用户输入想修改的数据项
{
    cout<<"请输入项修改的数据项:"<<endl;
    cout<<"1.ISBN号"<<endl;
    cout<<"2.书名"<<endl;
    cout<<"3.库存量"<<endl;
    cout<<"4.零售价"<<endl;
    cout<<"   输入选择:"<<endl;
    cout<<"   请输入1-4之间的数"<<endl;
}

void BookInfo(BookData Book) // 输出某本书的信息
{
    cout<<"         XXX 图书管理系统"<<endl;
    cout<<"             书的资料"<<endl;
    cout<<"ISBN 号:"<<Book.isbn<<endl;
    cout<<"书 名:"<<Book.bookTitle<<endl;
    cout<<"库存量:"<<Book.qtyOnHand<<endl;
    cout<<"零售价:"<<Book.retail<<endl;
}

int isEmpty(int i) // 判断结构体是否为空
{
    int flag=0; // 初始状态为结构体不为空
    if (book[i].bookTitle[0]=='\0') flag=1; // 结构体为空
    return flag;
}

void lookUpBook(int i) // 查找某本书的信息
{
    int flag=0; // 初始状态为未找到该书
    cout<<"请输入要查找的书名:"<<endl;
    char book_title[51];
    cin>>book_title;
    for (int j=0;j<=i;j++)
    {
        if (strcmp(book_title,book[j].bookTitle)==0) // 书名相符
        {
            flag=1; // 找到该书
            BookInfo(book[j]); // 输出某本书的信息
            break;
        }
    }
    if (flag==0) cout<<"书库中没有该书"<<endl;
}

void setTitle(char* bookTitle) // 设置书名 参数(书名)
{
    cout<<"清输入书名:"<<endl;
    cin.get();
    cin.getline(bookTitle,51);
}

void setISBN(char* isbn) // 设置书的ISBN号 参数(该书的ISBN号)
{
    cout<<"请输入该书的ISBN号:"<<endl;
    cin.getline(isbn,14);
}

void setQty(int &qtyOnHand) // 设置书的库存量 参数(该书库存量)
{
    cout<<"请输入该书的库存量:"<<endl;
    cin>>qtyOnHand;
}

void setRetail(double &retail) // 设置书的零售价 参数(零售价)
{
    cout<<"请输入该书的零售价:"<<endl;
    cin>>retail;
}

void addBook(int &i) // 增加书
{
    for (i=0;i<100;i++)
    {
        int flag=isEmpty(i); // 判断结构体是否为空
        if (flag==1) // 结构体为空
        {
            setTitle(book[i].bookTitle); // 设置书名
            setISBN(book[i].isbn); // 设置书的ISBN号
            setQty(book[i].qtyOnHand); // 设置书的库存量
            setRetail(book[i].retail); // 设置书的零售价
            break;
        }
    }
}

void editBook(int &i) // 修改书的信息
{
    char s[51];
    cout<<"请输入想修改的书名或其ISBN号:"<<endl;
    cin>>s;
    int j,flag=1; // 初始状态为用户输入的是ISBN号
    for (j=0;s[j]!='\0';j++)
    {
        if (s[j]<'0'||s[j]>'9') // 用户输入的内容存在非阿拉伯数字0-9的字符
        {
            flag=0; // 用户输入的是书名
            break;
        }
    }
    int Flag=0; // 初始状态为未找到该书
    if (flag==0) // 用户输入的是书名
    {
        for (j=0;j<=i;j++)
        {
            if (strcmp(s,book[j].bookTitle)==0) // 书名相符
            {
                Flag=1; // 找到该书
                break;
            }
        }
    }
    if (flag==1) // 用户输入的是ISBN号
    {
        for (j=0;j<=i;j++)
        {
            if (strcmp(s,book[j].isbn)==0) //ISBN号相符
            {
                Flag=1; // 找到该书
                break;
            }
        }
    }
    if (Flag==0) cout<<"书库中没有该书"<<endl;
    else // 找到该书
    {
        BookInfo(book[j]); // 显示该书的信息
        show_editBook(); // 提示用户输入想修改的数据项
        int data; // 数据项数
        cin>>data;
        switch (data)
        {
            case 1:
                cout<<"请输入该书的新ISBN号:"<<endl;
                char new_isbn[14];
                cin>>new_isbn;
                strcpy(book[j].isbn,new_isbn);
                break;
            case 2:
                cout<<"请输入新书名:"<<endl;
                char new_bookTitle[51];
                cin>>new_bookTitle;
                strcpy(book[j].bookTitle,new_bookTitle);
                break;
            case 3:
                cout<<"请输入该书的新库存量:"<<endl;
                int new_qtyOnHand;
                cin>>new_qtyOnHand;
                book[j].qtyOnHand=new_qtyOnHand;
                break;
            case 4:
                cout<<"请输入该书的新零售价:"<<endl;
                double new_retail;
                cin>>new_retail;
                book[j].retail=new_retail;
                break;
            default:
                cout<<"输入错误，请输入1-4之间的数"<<endl;
                break;
        }
    }
}

void removeBook(int &i,int j) // 从数组中移除由BookData对象数组的下标参数指定的数组中的结构体元素 参数(BookData对象数组的下标)
{
    for (int k=j;k<i;k++) book[k]=book[k+1]; // 移除该书
    i--; // 书的总数减少1本
}

void deleteBook(int &i) // 删除书
{
    int flag=0; // 初始状态为未找到该书
    cout<<"请输入要删除的书名:"<<endl;
    char book_title[51];
    cin>>book_title;
    for (int j=0;j<=i;j++)
    {
        if (strcmp(book_title,book[j].bookTitle)==0)
        {
            flag=1; // 找到该书
            removeBook(i,j); // 移除该书
        }
    }
    if (flag==0) cout<<"书库中没有该书"<<endl;
}

void Book_list(int i) // 书库列表
{
    for (int j=0;j<=i;j++)
    {
        cout<<"ISBN号:"<<book[j].isbn<<"   ";
        cout<<"书名:"<<book[j].bookTitle<<"   ";
        cout<<"库存量:"<<book[j].qtyOnHand<<"   ";
        cout<<"零售价:"<<book[j].retail<<endl;
    }
}

void retail_list(int &i) // 零售价列表
{
    for (int j=0;j<=i;j++)
    {
        cout<<"ISBN号:"<<book[j].isbn<<"   ";
        cout<<"书名:"<<book[j].bookTitle<<"   ";
        cout<<"零售价:"<<book[j].retail<<"   ";
        double total=book[j].qtyOnHand*book[j].retail; // 零售价总额=库存量*零售价
        cout<<"零售价总额:"<<total<<endl;
    }
}

void cashier_module(int &i) // 1.收银模块
{
    重新输入ISBN号:;
    int j,flag=0; // 初始状态为未找到该书
    cout<<"请输入要购买的书的ISBN号:"<<endl;
    char ISBN[14];
    cin>>ISBN;
    for (j=0;j<=i;j++)
    {
        if (strcmp(ISBN,book[j].isbn)==0)
        {
            flag=1; // 找到该书
            break;
        }
    }
    if (flag==0)
    {
        cout<<"书库中没有该书"<<endl;
        cout<<"是否重新输入ISBN号？"<<endl;
        cout<<"1 是     2 否，退出收银模块     请输入1或2"<<endl;
        int choice;
        重新输入choice:;
        cin>>choice;
        switch (choice)
        {
            case 1:
                goto 重新输入ISBN号;
            case 2:
                cout<<"已退出收银模块"<<endl;
                return; // 退出收银模块并返回到主菜单
            default:
                cout<<"输入错误，请输入1或2"<<endl;
                goto 重新输入choice;
        }
    }
    重新输入购书量:;
    cout<<"请输入购书量:"<<endl;
    int buy;
    cin>>buy;
    if (buy<=0) // 购书量不是正整数
    {
        cout<<"输入错误，请输入正整数"<<endl;
        goto 重新输入购书量;
    }
    else if (buy>book[j].qtyOnHand) // 购书量大于库存量
    {
        cout<<"该书库存量不足，当前库存量为"<<book[j].qtyOnHand<<endl;
        cout<<"是否重新输入购书量？"<<endl;
        cout<<"1 是     2 否，重新输入ISBN号     3 否，退出收银模块     请输入1或2或3"<<endl;
        int Choice;
        重新输入Choice:;
        cin>>Choice;
        switch (Choice)
        {
            case 1:
                goto 重新输入购书量;
            case 2:
                goto 重新输入ISBN号;
            case 3:
                cout<<"已退出收银模块"<<endl;
                return; // 退出收银模块并返回到主菜单
            default:
                cout<<"输入错误，请输入1或2或3"<<endl;
                goto 重新输入Choice;
        }
    }
    else
    {
        show_cashier_module(buy,book[j]); // 显示收银模块界面
        book[j].qtyOnHand-=buy; // 库存量=原库存量-购书量
        if (book[j].qtyOnHand==0)
            removeBook(i,j); // 移除该书
    }
}

void stack_room_management_module(int &i) // 2.书库管理模块
{
    while (true)
    {
        show_library_operation_menu(); // 显示书库操作菜单
        int module2; // 模块数
        cin>>module2; // 输入要进入的模块数
        switch (module2)
        {
            case 1:
                lookUpBook(i); // 1.查找某本书的信息
                break;
            case 2:
                addBook(i); // 2.增加书
                break;
            case 3:
                editBook(i); // 3.修改书的信息
                break;
            case 4:
                deleteBook(i); // 4.删除书
                break;
            case 5:
                cout<<"已退出书库管理模块"<<endl; // 5.返回到主菜单
                return; // 退出书库管理模块并返回到主菜单
            default:
                cout<<"输入错误，请输入1-5之间的数"<<endl;
                break;
        }
    }
}

void report_module(int &i) // 3.报表模块
{
    while (true)
    {
        show_report_menu(); // 显示报表菜单
        int module3; // 模块数
        cin>>module3; // 输入要进入的模块数
        switch (module3)
        {
            case 1:
                Book_list(i); // 1.书库列表
                break;
            case 2:
                retail_list(i); // 2.零售价列表
                break;
            case 3:
                cout<<"已退出报表模块"<<endl; // 3.返回到主菜单
                return; // 退出报表模块并返回到主菜单
            default:
                cout<<"输入错误，请输入1-3之间的数"<<endl;
                break;
        }
    }
}

int main() {
    //for (int j=0;j<100;j++) book[j].bookTitle[0]='\0'; // 初始化结构体为空，以书名为空代表
    int i=-1; // 书库中书本个数减1
    while (true) {
        show_main_menu(); // 显示主菜单
        int module; // 模块数
        cin>>module; // 输入要进入的模块数
        switch (module)
        {
            case 1:
                cashier_module(i); // 1.收银模块
                break;
            case 2:
                stack_room_management_module(i); // 2.书库管理模块
                break;
            case 3:
                report_module(i); // 3.报表模块
                break;
            case 4:
                cout<<"已退出系统，欢迎下次使用"<<endl; // 4.退出系统
                system("pause");
                return 0;
            default:
                cout<<"输入错误，请输入1-4之间的数"<<endl;
                break;
        }
    }
}