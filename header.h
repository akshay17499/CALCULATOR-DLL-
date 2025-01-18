#ifndef HEADER_H
#define HEADER_H


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
    char ch[4];
    struct node* next;
    struct node* prev;
}node;

typedef struct dlists
{
    node*list1_head;
    node*list1_tail;
    node*list2_head;
    node*list2_tail;
    node*list3_head;
    node*list3_tail;
    char*str1;
    char sign_str1;
    char*str2;
    char sign_str2;
    char sign_str3;
    int size1;
    int size2;
}Dlists;

void get_help();

bool check_valid(char*str); 

bool validation(Dlists*dlists);

void compare_assign(Dlists*dlist);

void sign_check(Dlists*dlist);

node* create_dll(char*str,int count,node**tail1);

void print(Dlists*dlists);

void copy_str_to_dll(Dlists*dlists);

void insert_begining(node**head,node**tail);

void substract(Dlists*dlists);

void addition(Dlists*dlists);

void add(Dlists*dlists);

void sub(Dlists*dlists);

void mul(Dlists*dlists);

void division(Dlists*dlists);

void helper_print_next(node*temp);

int check_for_exit(Dlists*dlists);

void arrange(Dlists*dlists);

void helper_print_prev(node*temp);

#endif
