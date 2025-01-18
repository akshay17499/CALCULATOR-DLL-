#include"header.h"

void get_help()
{   
    printf(" \n\n         !!!!!!!!!ERROR!!!!!!!!!     ");
    printf("\n\n     Error in entered format\n");
     printf("     Correct format given below : \n");
    printf("     <sign(optional)><number>   no alphabets , special characters , space\n");
    printf("     Try again in this format\n\n");

}

bool check_valid(char*str)
{
    int i=0;
    if(*str=='-'||*str=='+')
    i++;
    while(*(str+i)!='\0')
    {
        if(!(*(str+i)>='0'&&*(str+i)<='9'))
        return false;
        i++;
    }
    return true;
}

bool validation(Dlists*dlists)
{
    if(check_valid(dlists->str1)&&check_valid(dlists->str2))
    return true;
    return false;
}

void compare_assign(Dlists*dlist)
{
    if(strlen(dlist->str1)<=strlen(dlist->str2)){
        if(strlen(dlist->str1)<strlen(dlist->str2))
        {
        char*temp = dlist->str1;
        char sign = dlist->sign_str1;
        dlist->str1 = dlist->str2;
        dlist->sign_str1 = dlist->sign_str2;
        dlist->str2 = temp;
        dlist->sign_str2 = sign;
         int size = dlist->size1;
         dlist->size1 = dlist->size2;
         dlist->size2 = size;
        dlist->sign_str3 = dlist->sign_str1;
        return;
        }
    if(strcmp(dlist->str1,dlist->str2)<0)
    {
        char*temp = dlist->str1;
        char sign = dlist->sign_str1;
        dlist->str1 = dlist->str2;
        dlist->sign_str1 = dlist->sign_str2;
        dlist->str2 = temp;
        dlist->sign_str2 = sign;

        dlist->sign_str3 = dlist->sign_str1;
        return;
    }
    }
    dlist->sign_str3 = dlist->sign_str1;
}
void sign_check(Dlists*dlist)
{
    if(*(dlist->str1)=='-')
    {
        dlist->sign_str1 = '-';
        dlist->str1 = (dlist->str1+1);
    }
    else if(*(dlist->str1)=='+')
    {
        dlist->sign_str1 = '+';
        dlist->str1 = (dlist->str1+1);
    }
    if(*(dlist->str2)=='-')
    {
        dlist->sign_str2 = '-';
        dlist->str2 = dlist->str2+1;
    }
    else if(*(dlist->str2)=='+')
    {
        dlist->sign_str2 = '+';
        dlist->str2 = dlist->str2+1;
    }
    int size1 = strlen(dlist->str1);
    int count=0;
    int flag=0;
    for(int i = 0;i<size1;i++)
    {
         if(dlist->str1[i]!='0')
         break;
         count++;
    }
   // printf("count %d : \n",count);
    if(count==size1)
    dlist->str1 = (dlist->str1 + size1-1);
    else{
       dlist->str1 = (dlist->str1 + count);  
    }
    size1 = strlen(dlist->str2);
    count=0;
    for(int i = 0;i<size1;i++)
    {
         if(dlist->str2[i]!='0')
         break;
         count++;
    }
    if(count==size1)
    dlist->str2 = (dlist->str2 + size1-1);
    else{
       dlist->str2 = (dlist->str2 + count);  
    }
}
node* create_dll(char*str,int count,node**tail1)
{
    //printf("str from create dl : %s\n\n",str);
    node*head=NULL;
    node*tail = NULL;
    int adj=0;
    if(count%4)
    adj=4-count%4;
    int k=0;
    while(count>0)
    {
       
        node*newnode = malloc(sizeof(node));
        for(int i =0;i<4;i++)
        {
            if(adj>0)
            {
                newnode->ch[i]='0';
                adj--;
                continue;
            }
            if(count<=0)
            {
               break;
            }
            newnode->ch[i]=str[k++];
            count--;
        }
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head==NULL)
        {
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail=newnode;
        }
    }
    *tail1=tail;
    return head;   
}
 
 void print(Dlists*dlists)
 {
    if(dlists->sign_str3=='-')
    printf("%c",dlists->sign_str3);
    node*head = dlists->list3_head;
    int flag=0;
    while(head!=NULL)
    {
        for(int i=0;i<4;i++)
        {
            if(head->ch[i]!='0'||flag==1)
            {
               printf("%c",head->ch[i]);
               flag=1;
            }
           
        }
         if(head->next!=NULL)
           printf(",");
        head=head->next;
    }
    printf("\n");
 }

void copy_str_to_dll(Dlists*dlists)
{
    dlists->list1_head = create_dll(dlists->str1,dlists->size1,&dlists->list1_tail);
    dlists->list2_head = create_dll(dlists->str2,dlists->size2,&dlists->list2_tail);
}

void insert_begining(node**head,node**tail)
{
    node*newnode = malloc(sizeof(node));
    newnode->prev = NULL;
    for(int i=0;i<4;i++)
    newnode->ch[i]='0';
    if(*head==NULL)
    {
        *head=*tail=newnode;
        newnode->next=NULL;
        return;
    }
    (*head)->prev = newnode;
    newnode->next = *head;
    *head = newnode;
}

void calling_free(node*temp)
{
    //node*prev;
    while(temp->next!=NULL)
    {
       // prev=temp;
        temp=temp->next;
        free(temp->prev);
    }
    //printf("\n");
    free(temp);
}

void substract(Dlists*dlists)
{
    int temp;
    int diff=0;
    node*temp1_tail=dlists->list1_tail;
    node*temp2_tail=dlists->list2_tail;
    dlists->list3_head = NULL;
    dlists->list3_tail = NULL;
    while(temp1_tail!=NULL&&temp2_tail!=NULL)
    {
        insert_begining(&dlists->list3_head,&dlists->list3_tail);
        for(int i=3;i>=0;i--)
        {
            temp = (temp1_tail->ch[i]-48) - (temp2_tail->ch[i]-48) + diff;
            //printf("temp- > %d\n",temp);
            // printf("temp-> %d  temp1_tail->ch[i]->%c\n",temp,temp1_tail->ch[i]);
            if(temp<0)
            {
                diff=-1;
                temp = 10+temp;
            }
            else{
                diff=0;
            }
            dlists->list3_head->ch[i] = temp+48;
        }
        temp1_tail = temp1_tail->prev;
        temp2_tail = temp2_tail->prev;
    }
    while(temp1_tail!=NULL)
    {
        insert_begining(&dlists->list3_head,&dlists->list3_tail);
        for(int i=3;i>=0;i--)
        {
            temp = temp1_tail->ch[i]-48 + diff ;
            if(temp<0)
            {
                temp=10+temp;
                diff=-1;
            }
            else{
                diff = 0;
            }
         dlists->list3_head->ch[i]=temp+48;
        }
        temp1_tail=temp1_tail->prev;

    }
     /*while(temp2_tail!=NULL)
    {
        insert_begining(&dlists->list3_head,&dlists->list3_tail);
        for(int i=3;i>=0;i--)
        {
            temp = temp2_tail->ch[i]-48 + diff ;
            if(temp<0)
            {
                temp=10+temp;
                diff=-1;
            }
            else{
                diff = 0;
            }
         dlists->list3_head->ch[i]=temp+48;
        }
        temp2_tail=temp2_tail->prev;

    }*/
    //print(dlists);
   // printf("over");
}




void addition(Dlists*dlists)
{
    if(dlists->sign_str1==dlists->sign_str2){
    node*temp1_tail=dlists->list1_tail;
    node*temp2_tail=dlists->list2_tail;
     int temp ;
     int carry=0;
     dlists->list3_head = NULL;
     dlists->list3_tail = NULL;
    while(temp1_tail!=NULL&&temp2_tail!=NULL)
    { 
        insert_begining(&dlists->list3_head,&dlists->list3_tail);
        for(int i=3;i>=0;i--)
        {
            temp = temp1_tail->ch[i]-48 + temp2_tail->ch[i]-48 +carry;
            
            if(temp>9)
            {
                temp=temp%10;
                carry=1;
            }
            else{
                carry =0;
            }
         dlists->list3_head->ch[i]=temp+48;
         
        }
        temp1_tail=temp1_tail->prev;
        temp2_tail=temp2_tail->prev;
        if(temp1_tail==NULL&&temp2_tail==NULL&&carry>0)
        {
            insert_begining(&dlists->list3_head,&dlists->list3_tail);
            for(int j=3;j>=0;j--)
            dlists->list3_head->ch[j]='0';
             dlists->list3_head->ch[3]='1';
        }
    }
    while(temp1_tail!=NULL)
    {
        insert_begining(&dlists->list3_head,&dlists->list3_tail);
        for(int i=3;i>=0;i--)
        {
            temp = temp1_tail->ch[i]-48 + carry ;
            if(temp>9)
            {
                temp=temp%10;
                carry=1;
            }
            else{
                carry =0;
            }
         dlists->list3_head->ch[i]=temp+48;
        }
        temp1_tail=temp1_tail->prev;

        if(temp1_tail==NULL&&carry>0)
        {
            insert_begining(&dlists->list3_head,&dlists->list3_tail);
            for(int j=3;j>=0;j--)
            dlists->list3_head->ch[j]='0';
             dlists->list3_head->ch[3]='1';
        }
    }
    while(temp2_tail!=NULL)
    {
        insert_begining(&dlists->list3_head,&dlists->list3_tail);
        for(int i=3;i>=0;i--)
        {
            temp = temp2_tail->ch[i]-48 + carry ;
            if(temp>9)
            {
                temp=temp%10;
                carry=1;
            }
            else{
                carry =0;
            }
         dlists->list3_head->ch[i]=temp+48;
        }
        temp2_tail=temp2_tail->prev;
         if(temp1_tail==NULL&&carry>0)
        {
            insert_begining(&dlists->list3_head,&dlists->list3_tail);
            for(int j=3;j>=0;j--)
            dlists->list3_head->ch[j]='0';
            dlists->list3_head->ch[3]='1';
        }
    }
    //helper_print_next(dlists->list3_head);
    return;
    }
    else if(dlists->sign_str1!=dlists->sign_str2)
    {
        substract(dlists);
    }
}
void add(Dlists*dlists)
{
    
    copy_str_to_dll(dlists);
    addition(dlists);
    print(dlists);
}

void sub(Dlists*dlists)
{
    copy_str_to_dll(dlists);    
    addition(dlists);
     print(dlists);
}
void helper_print_next(node*temp)
{
  while(temp!=NULL)
    {
        for(int i=0;i<4;i++)
        printf("%c",temp->ch[i]);
        temp=temp->next;
    }
    printf("\n");
}
void helper_print_prev(node*temp)
{
  while(temp!=NULL)
    {
        for(int i=3;i>=0;i--)
        printf("%c",temp->ch[i]);
        temp=temp->prev;
    }
    printf("\n");
}
void mul(Dlists*dlists)
{
    if(*(dlists->str1)=='0'||*(dlists->str2)=='0')
    {
        printf("0");
        return;
    }
     copy_str_to_dll(dlists);
    node*temp = malloc(sizeof(node));
    temp->next=NULL;
    temp->prev=NULL;

    Dlists dlists1;
    dlists1.list1_head=dlists->list2_head;
    dlists1.list1_tail=dlists->list2_tail;
    node*temp2_tail=dlists1.list1_tail;
    /**/

    for(int i = 3;i>=0;i--)
    temp->ch[i]='0';
    temp->ch[3]='1';

    dlists1.list2_head=temp;
    dlists1.list2_tail=temp;
    
    dlists->list2_head=dlists->list1_head;
    dlists->list2_tail=dlists->list1_tail;   //here first memory block of list 1 is used;
     
     int count=0;
     int flag=0;
    while(1)
    {
       //printf("1");
        addition (dlists);
       // printf("\n");
      if(dlists->list1_head!=NULL&&flag==1)
      {
        node*temp=dlists->list1_head;
        calling_free(temp);   
      } 
       
        dlists->list1_head = dlists->list3_head;
        dlists->list1_tail = dlists->list3_tail;
        
       temp = dlists->list3_head;
      
        substract(&dlists1);  //printf("\n");
        if(dlists1.list1_head!=NULL)
        {
        node*temp=dlists1.list1_head;
         calling_free(temp);
        } 
        dlists1.list1_head = dlists1.list3_head;
        dlists1.list1_tail = dlists1.list3_tail;

        if(dlists1.list3_head->next==NULL)
        { 
          for(int i=0;i<4;i++)
          {
            if(dlists1.list3_head->ch[i]=='0')
            count++;
          }
          if(count==3&&dlists1.list3_head->ch[3]=='1')   //when dlists1.list3_head->ch=0001 stop bec we are startin from the same val so no need to reach 0000
          {
            print(dlists);
            return;
          }
          else{
            count=0;
          }
        }
        flag=1;
    }
    print(dlists);
}

int check_for_exit(Dlists*dlists)
{
    int node_count1=0;
    node*temp1=dlists->list1_head;
    while(temp1!=NULL)
    {
        node_count1++;
        temp1 = temp1->next;
    }
    int node_count2=0;
    node*temp2 = dlists->list2_head;
     while(temp2!=NULL)
    {
        node_count2++;
        temp2 = temp2->next;
    }
    //printf("node1c->%d  node2c->%d\n\n",node_count1,node_count2);
    if(node_count1==node_count2)
    {   
        temp1=dlists->list1_head;  temp2 = dlists->list2_head;
        int flag=0;//to check for 0 in the first only check if non zero in thebegining later check for zero also
        int count1=0,count2=0; //to check if temp1 and temp2 equal 
        while(temp1!=NULL&&temp2!=NULL)
        {
           for(int i=0;i<4;i++)
           {
           // printf("outside-> %c\n",dlists->list1_head->ch[i]);
           if(temp1->ch[i]=='0'&&temp2->ch[i]=='0'&&temp1==dlists->list1_head&&flag==0) //even if u remove the flag it may sometimes work bec of continue count2 also willnot increase but its not correct
           continue;
              if(temp1->ch[i]>temp2->ch[i])
               {         
                    //printf("inside-> %c\n",temp2->ch[i]);
                    flag=1;
                    return 1; //stay in loop
                
               }
               else if(temp1->ch[i]==temp2->ch[i])
               {
                count1++;
               }
              count2++;
           }
           temp1 = temp1->next;
           temp2 = temp2->next;
        }
        if(count1==count2)
        return 1;
      
        return -1;//exit loop
    }
    else if(node_count1<node_count2)
    return -1;//exit
    else
    return 1;

}
void arrange(Dlists*dlists)
{
    node*temp = dlists->list1_head;
    int count=0;
    if(temp->next==NULL)
    return;
    while(temp!=NULL)
    {
        for(int i=0;i<4;i++)
        {
            if(temp->ch[i]=='0')
            count++;
            else
            return;
        }
        if(count==4)
        {
            temp = temp->next;
            free(temp->prev);
            dlists->list1_head = temp;
            dlists->list1_head->prev=NULL;
            return;
        }
    }
}
void division(Dlists*dlists)
{          
        if(*(dlists->str2)=='0')
        {
            printf(" INFO : Division by 0 is not Possible\n\n");
            return;
        }
        else if(*(dlists->str1)=='0')
        {
            printf("0");
            return;
        }
      if(strlen(dlists->str1)<=strlen(dlists->str2))
      {
        if(strlen(dlists->str1)<strlen(dlists->str2))
        {
            printf("0");
            return;
        }
        if(strcmp(dlists->str1,dlists->str2)<0)
        {
            printf("0");
            return;
        }
      }
        copy_str_to_dll(dlists);
        int count =0;
        int n=  110;
        while(1)
        {
            substract(dlists);
            calling_free(dlists->list1_head);

            dlists->list1_head = dlists->list3_head;
            dlists->list1_tail = dlists->list3_tail;
            arrange(dlists);
             //helper_print(dlists->list1_head);
            count++; 
            if(check_for_exit(dlists)==-1)
            break;
        }
        if(dlists->sign_str3=='-')
        printf("%c",dlists->sign_str3);
     printf("%d",count);  

}
