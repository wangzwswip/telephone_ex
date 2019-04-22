/* list.h--通讯录头文件 */
#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
//特定程序的声明
struct adresslist
{
    char number[10];//学号
    char name[10];//姓名
    char sex[6];//性别
    char telephone[11];//电话号码
};
typedef struct adresslist Item;
typedef struct node
{
    Item item;
    struct node *next;
}Node;
typedef Node *List;
//函数原型
//初始化链表
void InitializeList(List *plist);
//确定链表是否为空
bool ListIsEmpty(const List *plist);
//确定链表是否已满
bool ListIsFull(const List *plist);
//链表数据修改
bool ListModify( List *plsit);
//确定链表中的项数
unsigned int  ListItemCount(const List *plist);
//查询
List * ListFind(const List *plist);
//在链表末尾添加项
bool AddItem(Item item,List *plist);
//删除链表中的一项
void DeleteNode(List *plist);
//把函数作用于每一项
void Teaverse(const List *plist,void(*pfun)(Item item));
//释放已分配的内存
void EmptyTheList(List *plist);
#endif



