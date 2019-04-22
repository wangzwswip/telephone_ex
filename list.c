/* list.c -- 支持链表操作的函数 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
//局部函数原型
static void CopyToNode(Item item,Node * pnode);
//接口函数
//把链表设置为空
void InitializeList(List * plist)
{
    *plist=NULL;
}
//如果链表为空，返回Ture
bool ListIsEmpty(const List *plist)
{
    if (*plist == NULL)
        return true;
    else
        return false;
    
}
//如果链表已满，返回true
bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;
    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);
    return full;
}
//返回节点数量
unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    int men=0,women=0;
    Node *pnode = *plist;//设置链表的开始
    while (pnode != NULL)
    {
        ++count;
        if(strcmp(pnode->item.sex,"man")==0)
            men++;
        if(strcmp(pnode->item.sex,"woman")==0)
            women++;
        pnode=pnode->next;//设置下一个节点
    }
    printf("women=%d\nmen=%d\n",women,men);
    return count;
}
//查询
List * ListFind(const List *plist)
{
    Node * scan = *plist;
    char input;
    puts("请输入姓名信息：");
    scanf("%s",&input);
    while(getchar()!='\n')
    {
        continue;
    }
    while (scan && strcmp(scan->item.name,input))
    {
        scan=scan->next;
    }
    return scan;
}
//创建存储项的节点，并将其添加至由plist指向的链表末尾（较慢的实现）
bool AddItem(Item item,List *plist)
{
    Node * pnew;
    Node * scan = *plist;
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
        return false;//失败时退出函数
    CopyToNode(item,pnew);
    pnew->next = NULL;
    if (scan == NULL)
        *plist=pnew;//空链表，放在开头
    else
    {
        while(scan->next != NULL)
            scan=scan->next;
        scan->next=pnew;
    }
    return true;   
}
//修改
bool ListModify( List *plsit)
{
    Node temp1;
    Item tem_item;
    temp1 = ListFind(*plsit);
    if (temp1 == NULL)
    {
        puts("未找到要修改的联系人！");
    }
    else
    {
        puts("请输入新的编号：");
        s_gets(temp1->item.number,10);
        puts("请输入姓名：");
        s_gets(temp1->item.name,10);
        puts("请输入性别：");
        s_gets(temp1->item.sex,6);
        puts("请输入电话号码：");
        s_gets(temp1->item.telephone,11);
        pus("修改成功！");
    }
    
}
//删除
void DeleteNode(List *plist)
{
    Node * temp1;
    Node * temp2 = *plist;
    temp1=ListFind(*plist);
    if (temp1==NULL)
    {
        puts("没有查询到要删除的联系人信息");
    }
    else
    {
        while(temp2 && temp->next!=temp1){
            temp2=temp2->next;
        }
        temp2->next=temp1->next;
        free(temp1);
        puts("删除成功！");

        
    }
    

}
//访问每个节点并执行pfun指向的函数
void Traverse(const List *plist,void(*pfun)(Item item))
{
    Node *pnode=*plist;//设置链表的开始
    while (pnode != NULL)
    {
        (*pfun)(pnode->item);//应用函数
        pnode=pnode->next;//前进下一项
    }
}
//释放由malloc分配的内存
//设置链表指针为NULL
void EmptyTheList(List *plist)
{
    Node *psave;
    while(*plist != NULL)
    {
        psave=(*plist)->next;
        free(*plist);
        *plist=psave;
    }
}
//局部函数定义
//把一个项拷贝进节点中
static void CopyToNode(Item item,Node * pnode)
{
    pnode->item=item;
    
}