#include"header.h"


int main()
{
    Dlists dlist;
    dlist.sign_str1 = '+';
    dlist.sign_str2 = '+';
    dlist.sign_str3 = '+';
    dlist.str1 = malloc(1024*sizeof(char));
    dlist.str2 = malloc(1024*sizeof(char));
    printf("Enter num 1 : ");
    scanf("%s",dlist.str1);
    printf("Enter num 2 : ");
    scanf("%s",dlist.str2);
    if(!validation(&dlist))
    {
      get_help();
      return 0;
    }
    sign_check(&dlist);
    //printf("str1 ->%s\n",dlist.str1);
    dlist.size1 = strlen(dlist.str1);
    dlist.size2 = strlen(dlist.str2);
    //printf(" str 2 >%s\n",dlist.str2);
    
    //dlist.str1 = realloc(dlist.str1,dlist.size1);
    //dlist.str2 = realloc(dlist.str2,dlist.size2);         //why it is failing
    if(dlist.str1==NULL||dlist.str2==NULL)
    {
        printf("DMA failed\n");
        return 0;
    }
    int operation;
    printf("1.Addition(num1+num2)\n2.Subtraction(num1-num2)\n3.Multiplication(num1*num2)\n4.Division(num1/num2)\n5.Exit\nEnter : ");
    scanf("%d",&operation);
    switch(operation)
    {
        case 1 : 
                  if(dlist.sign_str1=='-')
                  printf("%c%s",dlist.sign_str1,dlist.str1);
                  else if (dlist.sign_str1=='+')      
                    printf("%s",dlist.str1);
                  if(dlist.sign_str2=='-')
                  printf(" + %c%s = ",dlist.sign_str2,dlist.str2);
                  else if (dlist.sign_str2=='+')      
                    printf(" + %s = ",dlist.str2);
                    compare_assign(&dlist);
                   add(&dlist);break;

       case 2 :if(dlist.sign_str1=='-')
                  printf("%c%s",dlist.sign_str1,dlist.str1);
                  else if (dlist.sign_str1=='+')      
                    printf("%s",dlist.str1);
                  if(dlist.sign_str2=='-')
                  printf(" - %c%s = ",dlist.sign_str2,dlist.str2);
                  else if (dlist.sign_str2=='+')      
                    printf(" - %s = ",dlist.str2);
                if(dlist.sign_str2=='-')
                 {
                    dlist.sign_str2='+';
                 }
                 else{
                    dlist.sign_str2 = '-';
                 }
                 
                compare_assign(&dlist);
                sub(&dlist);break;

        case 3 : if(dlist.sign_str1=='-')
                  printf("%c%s",dlist.sign_str1,dlist.str1);
                  else if (dlist.sign_str1=='+')      
                    printf("%s",dlist.str1);
                  if(dlist.sign_str2=='-')
                  printf(" * %c%s = ",dlist.sign_str2,dlist.str2);
                  else if (dlist.sign_str2=='+')      
                    printf(" * %s = ",dlist.str2);
                    compare_assign(&dlist);
                  if(dlist.sign_str1!=dlist.sign_str2)
                  {
                    dlist.sign_str3 = '-';
                    dlist.sign_str1=dlist.sign_str2;
                    printf("-");
                  } 
                  if(dlist.sign_str1 == dlist.sign_str2)
                  dlist.sign_str3 = '+';                 
                  mul(&dlist); break;

        case 4 : if(dlist.sign_str1=='-')
                  printf("%c%s",dlist.sign_str1,dlist.str1);
                  else if (dlist.sign_str1=='+')      
                    printf("%s",dlist.str1);
                  if(dlist.sign_str2=='-')
                  printf(" / %c%s = ",dlist.sign_str2,dlist.str2);
                  else if (dlist.sign_str2=='+')      
                    printf(" / %s = ",dlist.str2);
                    
                  if(dlist.sign_str1!=dlist.sign_str2)
                  {
                     dlist.sign_str3 = '-';
                     dlist.sign_str1=dlist.sign_str2;
                  }
                   //printf("str3 sign %c\n",dlist.sign_str3);
                  
                  division(&dlist); break;
        
        case 5: return 0;
    }

}
