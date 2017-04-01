//
//  main.c
//  顺序存储结构的线性表
//
//  Created by 朱佳杰 on 2017/4/1.
//  Copyright © 2017年 zjj. All rights reserved.
//

#include <stdio.h>

#define MAXSIZE 100   //存储空间的初始分配量
typedef int ElemType; //ElemType类型根据实际需要而确定
typedef struct
{
    ElemType data[MAXSIZE]; //用数组存储数据元素，最大值为MAXSIZE
    int      length;
}myList;

myList *insertList(myList *l,int i,ElemType e);
//初始化线性表
void initList(myList *l){
    l -> length = 0;
}

//向线性表中添加元素
myList *addElement(myList *l,int num){
    myList *list = l;
    if (num < 0 || num > MAXSIZE){
        printf("初始化元素失败\n");
    }else{
        for (int i = 0; i < num; i ++) {
            list = insertList(l,0,num - i);
        }
    }
    return list;
}

//在下标为i的地方插入元素
myList *insertList(myList *l,int i,ElemType e){
    int k;
    if (l -> length == MAXSIZE){
        //顺序线性表已经满
        printf("线性表已满，无法插入！\n");
        return l;
    }
    if (i < 0 || i > l -> length){
        //插入位置不合法
        printf("插入位置不合法，无法插入！\n");
        return l;
    }
    if (i >= 0 && i <= l -> length){
        //插入位置合法
        for(k = l -> length;k >= i;k --){
            //从后往前遍历插入
            l -> data[k] = l -> data[k - 1];
        }
        //将新元素插入
        l -> data[i] = e;
        l -> length++;
        return l;
    }
    return l;
}

//获取下标为i的位置的元素
void getElement(myList *l,int i){
    if (l -> length == 0){
        printf("线性表为空\n");
        return ;
    }
    if (i > MAXSIZE || i < 0){
        printf("查找位置不合法\n");
        return ;
    }
    printf("在下标为%d的位置找到元素%d\n",i,l -> data[i]);
    return ;
}

//删除下标为i的位置的元素
myList *deleteList(myList *l,int i){
    int k;
    if (l -> length == 0){
        //线性表为空
        printf("线性表为空，删除失败\n");
        return l;
    }
    if (i < 0 || i > l -> length){
        printf("删除位置不合法，删除失败\n");
        return l;
    }
    if (i < l -> length){
        //删除位置合法
        for(k = i;k < l -> length;k ++){
            //从前往后遍历删除
            l -> data[k-1] = l -> data[k];
        }
    }
    l -> length --;
    return l;
}

//当前线性表长度
void getListLength(myList *l){
    printf("线性表的长度为:%d\n",l->length);
}

//打印输出线性表
void printList(myList *l){
    for (int i = 0;i < l -> length;i ++){
        printf("listA%d元素：%d\n",i,l -> data[i]);
    }
}


int main(int argc, const char * argv[]) {
    myList listA;
    initList(&listA);
    printf("初始化后:\n");
    getListLength(&listA);
    addElement(&listA, 99);
    printf("添加后:\n");
    getListLength(&listA);
    printList(&listA);
    insertList(&listA, 0, 20); //在下标为0的位置插入
    printf("插入后:\n");
    getListLength(&listA);
    printList(&listA);
    insertList(&listA, 0, 50); //在下标为0的位置插入
    printf("插入后:\n");
    getListLength(&listA);
    printList(&listA);
    printf("获取元素:\n");
    getElement(&listA, 0);
    deleteList(&listA, 0);
    printf("删除后:\n");
    getListLength(&listA);
    printList(&listA);
    
    return 0;
}
