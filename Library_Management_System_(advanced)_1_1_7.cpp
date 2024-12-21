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
    char author[51]; // 该书的作者
    char pub[51]; // 该书的出版社
    int dateAdded[3]; // 该书的进书日期(dateAdded[0],dateAdded[1],dateAdded[2]分别为年、月、日)
    double wholesale; // 该书的批发价
};
BookData book[100];

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
    cout<<"3.批发价列表"<<endl;
    cout<<"4.库存量排序列表"<<endl;
    cout<<"5.批发价总额排序列表"<<endl;
    cout<<"6.进书日期排序列表"<<endl;
    cout<<"7.返回到主菜单"<<endl<<endl;
    cout<<"输入选择:"<<endl;
}

void show_editBook() // 提示用户输入想修改的数据项
{
    cout<<"请输入项修改的数据项:"<<endl;
    cout<<"1.ISBN号"<<endl;
    cout<<"2.书名"<<endl;
    cout<<"3.库存量"<<endl;
    cout<<"4.零售价"<<endl;
    cout<<"5.作者"<<endl;
    cout<<"6.出版社"<<endl;
    cout<<"7.进书日期"<<endl;
    cout<<"8.批发价"<<endl;
    cout<<"   输入选择:"<<endl;
    cout<<"   请输入1-8之间的数"<<endl;
}

void BookInfo(BookData Book) // 输出某本书的信息
{
    cout<<"         XXX 图书管理系统"<<endl;
    cout<<"             书的资料"<<endl;
    cout<<"ISBN 号:"<<Book.isbn<<endl;
    cout<<"书 名:"<<Book.bookTitle<<endl;
    cout<<"库存量:"<<Book.qtyOnHand<<endl;
    cout<<"零售价:"<<Book.retail<<endl;
    cout<<"作者:"<<Book.author<<endl;
    cout<<"出版社:"<<Book.pub<<endl;
    cout<<"进书日期:"<<Book.dateAdded[0]<<"年"<<Book.dateAdded[1]<<"月"<<Book.dateAdded[2]<<"日"<<endl;
    cout<<"批发价:"<<Book.wholesale<<endl;
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

void setAuthor(char* author) // 设置书的作者 参数(作者)
{
    cout<<"请输入该书的作者:"<<endl;
    cin.get();
    cin.getline(author,51);
}

void setPub(char* pub) // 设置书的出版社 参数(出版社)
{
    cout<<"请输入该书的出版社:"<<endl;
    cin.getline(pub,51);
}

void setDateadded(int &year,int &month,int &day) // 设置进书日期 参数(年、月、日)
{
    cout<<"请输入该书的进书日期"<<endl;
    cout<<"请输入年:"<<endl;
    cin>>year;
    cout<<"请输入月:"<<endl;
    cin>>month;
    cout<<"请输入日:"<<endl;
    cin>>day;
}

void setWholesale(double &wholesale) // 设置书的批发价 参数(批发价)
{
    cout<<"请输入该书的批发价:"<<endl;
    cin>>wholesale;
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
            setAuthor(book[i].author); // 设置书的作者
            setPub(book[i].pub); // 设置书的出版社
            setDateadded(book[i].dateAdded[0],book[i].dateAdded[1],book[i].dateAdded[2]); // 设置进书日期
            setWholesale(book[i].wholesale); // 设置书的批发价
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
        if (s[j]<'0'||s[j]>'9')
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
            case 5:
                cout<<"请输入该书的新作者:"<<endl;
                char new_author[51];
                cin>>new_author;
                strcpy(book[j].author,new_author);
                break;
            case 6:
                cout<<"请输入该书的新出版社:"<<endl;
                char new_pub[51];
                cin>>new_pub;
                strcpy(book[j].pub,new_pub);
                break;
            case 7:
                cout<<"请输入该书的新进书日期:"<<endl;
                int new_year,new_month,new_day;
                cin>>new_year>>new_month>>new_day;
                book[j].dateAdded[0]=new_year;
                book[j].dateAdded[1]=new_month;
                book[j].dateAdded[2]=new_day;
                break;
            case 8:
                cout<<"请输入该书的新批发价:"<<endl;
                double new_wholesale;
                cin>>new_wholesale;
                book[j].wholesale=new_wholesale;
                break;
            default:
                cout<<"输入错误，请输入1-8之间的数"<<endl;
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
        cout<<"零售价:"<<book[j].retail<<"   ";
        cout<<"作者:"<<book[j].author<<"   ";
        cout<<"出版社:"<<book[j].pub<<"   ";
        cout<<"进书日期:"<<book[j].dateAdded[0]<<"年"<<book[j].dateAdded[1]<<"月"<<book[j].dateAdded[2]<<"日"<<"   ";
        cout<<"批发价:"<<book[j].wholesale<<endl;
    }
}

void retail_list(int &i) // 零售价列表
{
    double total; // 零售价总额
    for (int j=0;j<=i;j++)
    {
        cout<<"ISBN号:"<<book[j].isbn<<"   ";
        cout<<"书名:"<<book[j].bookTitle<<"   ";
        cout<<"零售价:"<<book[j].retail<<"   ";
        total=book[j].qtyOnHand*book[j].retail; // 零售价总额=库存量*零售价
        cout<<"零售价总额:"<<total<<endl;
    }
}

void wholesale_list(int &i) // 批发价列表
{
    double total; // 批发价总额
    for (int j=0;j<=i;j++)
    {
        cout<<"ISBN号:"<<book[j].isbn<<"   ";
        cout<<"书名:"<<book[j].bookTitle<<"   ";
        cout<<"批发价:"<<book[j].wholesale<<"   ";
        total=book[j].qtyOnHand*book[j].wholesale; // 批发价总额=库存量*批发价
        cout<<"批发价总额:"<<total<<endl;
    }
}

void qtyOnHand_sort_list(int &i) // 库存量排序列表
{
    int j;
    for (j=0;j<i;j++) // 库存量从大到小排序
	{
		for (int k=0;k<i-j;k++)
		{
			if (book[k].qtyOnHand<book[k+1].qtyOnHand) // 库存量前项小于后项时交换前后项
			{
				BookData t=book[k];
				book[k]=book[k+1];
				book[k+1]=t;
			}
		}
	}
    for (j=0;j<=i;j++)
    {
        cout<<"ISBN号:"<<book[j].isbn<<"   ";
        cout<<"书名:"<<book[j].bookTitle<<"   ";
        cout<<"库存量:"<<book[j].qtyOnHand<<endl;
    }
}

void wholesale_sort_list(int &i) // 批发价总额排序列表
{
    int j;
    double total[i+1]; // 批发价总额
    for (j=0;j<=i;j++)
        total[j]=book[j].qtyOnHand*book[j].wholesale; // 批发价总额=库存量*批发价
    for (j=0;j<i;j++) // 批发价总额从大到小排序
	{
		for (int k=0;k<i-j;k++)
		{
			if (total[k]<total[k+1]) // 批发价总额前项小于后项时交换前后项
			{
				BookData t=book[k];
				book[k]=book[k+1];
				book[k+1]=t;
                double temp=total[k];
                total[k]=total[k+1];
                total[k+1]=temp;
			}
		}
	}
    for (j=0;j<=i;j++)
    {
        cout<<"ISBN号:"<<book[j].isbn<<"   ";
        cout<<"书名:"<<book[j].bookTitle<<"   ";
        cout<<"批发价:"<<book[j].wholesale<<"   ";
        cout<<"库存量:"<<book[j].qtyOnHand<<"   ";
        cout<<"批发价总额:"<<total[j]<<endl;
    }
}

void dateAdded_sort_list(int &i) // 进书日期排序列表
{
    int j;
    for (j=0;j<i;j++) // 进书日期从小到大排序
	{
		for (int k=0;k<i-j;k++)
		{
			if (book[k].dateAdded[0] >book[k+1].dateAdded[0] // 情况 1. 进书日期 年份 前项>后项
             || book[k].dateAdded[0]==book[k+1].dateAdded[0] // 情况 2. 进书日期 年份 前项=后项
             && book[k].dateAdded[1] >book[k+1].dateAdded[1] //    且   进书日期 月份 前项>后项
             || book[k].dateAdded[0]==book[k+1].dateAdded[0] // 情况 3. 进书日期 年份 前项=后项
             && book[k].dateAdded[1]==book[k+1].dateAdded[1] //    且   进书日期 月份 前项=后项
             && book[k].dateAdded[2] >book[k+1].dateAdded[2] //    且   进书日期  日  前项>后项
               ) // 进书日期前项大于后项时交换前后项
			{
				BookData t=book[k];
				book[k]=book[k+1];
				book[k+1]=t;
			}
		}
	}
    for (j=0;j<=i;j++)
    {
        cout<<"ISBN号:"<<book[j].isbn<<"   ";
        cout<<"书名:"<<book[j].bookTitle<<"   ";
        cout<<"进书日期:"<<book[j].dateAdded[0]<<"年"<<book[j].dateAdded[1]<<"月"<<book[j].dateAdded[2]<<"日"<<endl;
    }
}

void show_cashier_module_head(int max_isbn_len,int max_bookTitle_len,int &space_isbn,int &space_bookTitle) // 输出表头
{
    space_isbn=max_isbn_len/2-1; // ISBN号多输出的空格数
    space_bookTitle=max_bookTitle_len/3-1; // 书名多输出的空格数
    cout<<"                        前台销售模块"<<endl;
    show_system_date(); // 输出系统日期
    cout<<"数量";
    for (int i=0;i<space_isbn;i++) cout<<" ";
    cout<<"ISBN号";
    for (int i=0;i<space_isbn;i++) cout<<" ";
    for (int i=0;i<space_bookTitle;i++) cout<<" ";
    cout<<"书名";
    for (int i=0;i<space_bookTitle;i++) cout<<" ";
    cout<<"    单价       ";
    cout<<"金额"<<endl;
}

void show_cashier_module_bookInfo(BookData Book,int buy,double gross_sales,int max_isbn_len,int max_bookTitle_len,
                                  int space_isbn,int space_bookTitle) // 逐个输出每本书的信息
{
    int j;
    cout<<" "<<buy<<"   ";
    int isbn_space=(max_isbn_len-strlen(Book.isbn))/2; // ISBN号多输出的空格数
    for (j=0;j<isbn_space;j++)
        cout<<" ";
    cout<<Book.isbn<<"   ";
    for (j=0;j<isbn_space;j++)
        cout<<" ";
    int bookTitle_space=(max_bookTitle_len-strlen(Book.bookTitle))/2-4; // 书名多输出的空格数
    for (j=0;j<bookTitle_space;j++)
        cout<<" ";
    cout<<Book.bookTitle;
    for (j=0;j<bookTitle_space;j++)
        cout<<" ";
    cout<<"   RMB "<<Book.retail<<"   RMB "<<gross_sales<<endl;
}

void show_cashier_module_tail(double total_gross_sales,double total_retail_sales_tax,double sum) // 输出表尾
{
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"销售合计:RMB "<<total_gross_sales<<endl;
    cout<<"零售税:RMB "<<total_retail_sales_tax<<endl;
    cout<<"应付总额:RMB "<<sum<<endl<<endl;
    cout<<"谢谢光临!"<<endl;
}

void cashier_module(int &i) // 1.收银模块
{
    int j;
    int k; // 记录下标为k的书的数据，结束一轮循环后k值为购书笔数
    int CHoice=1; // 由用户输入，判断是否再购买下一本书
    int buy[100]; // 记录每一笔的购书量
    BookData Book[100]; // 记录每一笔购书的信息
    for (k=0;CHoice==1;k++)
    {
        重新输入ISBN号:;
        int flag=0; // 初始状态为未找到该书
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
            cout<<"1 是     2 否     请输入1或2"<<endl;
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
        cin>>buy[k];
        if (buy[k]<=0) // 购书量不是正整数
        {
            cout<<"输入错误，请输入正整数"<<endl;
            goto 重新输入购书量;
        }
        else if (buy[k]>book[j].qtyOnHand) // 购书量大于库存量
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
            Book[k]=book[j]; // 将购书的数据导入下标为k的BookData对象数组成员中
            book[j].qtyOnHand-=buy[k]; // 库存量=原库存量-购书量
            if (book[j].qtyOnHand==0)
                removeBook(i,j); // 移除该书
        }
        cout<<"您是否还要购买其他书？"<<endl;
        cout<<"1 是     2 否     请输入1或2"<<endl;
        重新输入CHoice:;
        cin>>CHoice;
        if (CHoice!=1 && CHoice!=2)
        {
            cout<<"输入错误，请输入1或2"<<endl;
            goto 重新输入CHoice;
        }
    }
    int max_isbn_len=strlen(Book[0].isbn);
    int max_bookTitle_len=strlen(Book[0].bookTitle); // ISBN号长度最大值、书名长度最大值（初始化为首项）
    for (j=0;j<k-1;j++)
    {
        if (strlen(Book[j].isbn)>max_isbn_len)
            max_isbn_len=strlen(Book[j].isbn);
        if (strlen(Book[j].bookTitle)>max_bookTitle_len)
            max_bookTitle_len=strlen(Book[j].bookTitle);
    }
    int space_isbn,space_bookTitle; // ISBN号和书名要多输入的空格数
    show_cashier_module_head(max_isbn_len,max_bookTitle_len,space_isbn,space_bookTitle); // 输出表头
    double gross_sales[k]; // 一本书的销售合计
    double total_gross_sales=0; // 销售合计
    for (j=0;j<k;j++)
    {
        gross_sales[j]=buy[j]*Book[j].retail; // 一本书的销售合计=购书量*零售价
        total_gross_sales+=gross_sales[j]; // 销售合计=每一本书的销售合计之和
    }
    double total_retail_sales_tax=0.06*total_gross_sales; // 零售税=6%销售合计
    double sum=total_gross_sales+total_retail_sales_tax; // 应付总额=销售合计+零售税
    for (j=0;j<k;j++)
        show_cashier_module_bookInfo(Book[j],buy[j],gross_sales[j],max_isbn_len,max_bookTitle_len,
                                     space_isbn,space_bookTitle); // 逐个输出每本书的信息
    show_cashier_module_tail(total_gross_sales,total_retail_sales_tax,sum); // 输出表尾
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
                wholesale_list(i); // 3.批发价列表
                break;
            case 4:
                qtyOnHand_sort_list(i); // 4.库存量排序列表
                break;
            case 5:
                wholesale_sort_list(i); // 5.批发价总额排序列表
                break;
            case 6:
                dateAdded_sort_list(i); // 6.进书日期排序列表
                break;
            case 7:
                cout<<"已退出报表模块"<<endl; // 3.返回到主菜单
                return; // 退出报表模块并返回到主菜单
            default:
                cout<<"输入错误，请输入1-3之间的数"<<endl;
                break;
        }
    }
}

int main()
{
    for (int j=0;j<100;j++) book[j].bookTitle[0]='\0'; // 初始化结构体为空，以书名为空代表
    int i=-1; // 书库中书本个数减1
    while (true) {
        show_main_menu(); // 显示主菜单
        int module; // 模块数
        cin>>module; // 输入要进入的模块数
        switch (module)
        {
            case 1:{
                cashier_module(i); // 1.收银模块
                break;
            }
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
