/* films3.c --使用抽象数据类型（ADT）风格的链表 */
/* 与list,c一起编译  */
#include <stdio.h>
#include <stdlib.h> //提供exit()原型
#include <string.h>
#include "list.h"   //定义List、Item
void showadress(Item item);
char *s_gets(char *st,int n);
int main(void)
{
    int option;//用户输入选项
    int flag1=0，flag2=0;
    List adress;
    Item temp;
    //初始化
    InitializeList(&adress);
    printf("\t\t\t-------通讯录-------\n");
    printf("\t\t\t**********************");
    printf("\n\t\t\t    1.通讯录建立    ");
    printf("\n\t\t\t    2.通讯者插入    ");
    printf("\n\t\t\t    3.通讯者查询    ");
    printf("\n\t\t\t    4.通讯者删除    ");
    printf("\n\t\t\t    5.通讯者修改    ");
    printf("\n\t\t\t    6.通讯录输出    ");
    printf("\n\t\t\t    7.通讯人数查询   ");
    printf("\n\t\t\t    0.推出系统      ");
    printf("\n\t\t\t*******************");
    
    while (flag2==0)
    {
        printf("\n请选择输入菜单号：（0-7）：");
        scanf("%d",&option);
        while(getchar() != '\n')
        {
            continue;
        }
        switch (option)
        {
            case 1:
                printf("\n    1.通讯录建立    \n");
                char flag='y';
                while (flag=='y')
                {
                    puts("编号    姓名    性别    电话");
                    puts("请输入编号：");
                    s_gets(temp.number,10);
                    puts("请输入姓名：");
                    s_gets(temp.name,10);
                    puts("请输入性别：");
                    s_gets(temp.sex,6);
                    puts("请输入电话号码：");
                    s_gets(temp.telephone,11);
                    if (AddItem(temp,&adress) == false)
                    {
                        fprintf(stderr,"Problem allocating memory\n");
                        break;
                    }
                    if (ListIsFull(&movies))
                    {
                        puts("The list is now full.\n");
                        break;
                    }
                    puts("是否继续添加？继续添加请输入'y',结束输入'n'.");
                    scanf("%s",&flag);
                    while(getchar() != '\n'){
                        continue;
                    }
                }
                flag1=1;
                break;
            case 2:
            {
                if (flag1!=1)
                {
                    puts("请先输入选项1来建立初始数据库！");
                }
                else
                {
                
                    puts("通讯作者信息的插入");
                    puts("编号    姓名    性别    电话");
                    puts("请输入编号：");
                    while (s_gets(temp.number,10)!= NULL)
                    {
                        puts("请输入姓名：");
                        s_gets(temp.name,10);
                        puts("请输入性别：");
                        s_gets(temp.sex,6);
                        puts("请输入电话号码：");
                        s_gets(temp.telephone,11);
                        if (AddItem(temp,&adress) == false)
                        {
                            fprintf(stderr,"Problem allocating memory\n");
                            break;
                        }
                        if (ListIsFull(&movies))
                        {
                            puts("The list is now full.\n");
                            break;
                        }

                    }

                }
                break;   
            }
            case 3:
            {
                if (flag1!=1)
                {
                    puts("请先输入选项1来建立初始数据库！");
                }
                else
                {
                    puts("通讯录信息查询");
                    Node * p_temp;
                    p_temp=ListFind(&adress);
                    if (p_temp!=NULL)
                    {
                        printf("编号： %s\n姓名： %s\n 性别： %s\n联系电话： %s",
                        p_temp->item.number,p_temp->item.name,p_temp->item.sex,p_temp->item.telephone)
                    }
                    else
                    {
                        puts("没有查询到该通讯者！")
                    }
                
                }
                break;  
            }
            case 4:
            {
                if (flag1!=1)
                {
                    puts("请先输入选项1来建立初始数据库！");
                }
                else
                {
                    puts("通讯录信息的删除！");
                    DeleteNode(&adress);
                }
                break;
            }
            case 5:
            {
                if (flag1!=1)
                {
                    puts("请先输入选项1来建立初始数据库！");
                }
                else
                {
                    puts("修改联系人信息");
                    ListModify(&adress);
                }
                break;
            
            }
            case 6:
            {
                if (flag1!=1)
                {
                    puts("请先输入选项1来建立初始数据库！");
                }
                else
                {
                    puts("通讯录列表输出");
                    Teaverse(&adress,showadress);
                }
                break;
            }
            case 7:
            {
                if (flag1!=1)
                {
                    puts("请先输入选项1来建立初始数据库！");
                }
                else
                {
                    printf("总的联系人为：%d",ListItemCount(&adress));
                }
                break;
            }
            case 0:
            {
                puts("是否退出？（y/n)");
                char tem_char;
                tem_char=getchar();
                if (tem_char=='y'&&tem_char=='Y')
                {
                    puts("谢谢使用！");
                    flag2=1;
                }
                break;
            }
            default:
            {
                puts("输入有错，请重新输入！")
                break;
            }
            
        }
    }
//清理
EmptyTheList(&adress);
printf("Bye!\n");
    return 0;
}
void showadress(Item item)
{
    printf("Number: %s\nName: %s\nSex: %s\nTelephone: %s\n",item.number,item.name,item.sex,item.telephone);
}
char *s_gets(char *st,int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st,n,stdin);//fgets读取成功返回指向取得值的指针，包含换行符
    if (ret_val)
    {
        find = strchr(st,'\n');//查找换行符
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
        
    }
    return ret_val;
}
