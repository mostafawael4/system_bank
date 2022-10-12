#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void welcome();
void menu();
void new_acc();
void search();
void view_acc();
void viewlist();
void edit();
void sort();
void transact();
void delete_acc();
void close_program();
void typedec(int );
int info[20][7],transaction[20][20];
char name[20][30], address[20][30], phone[20][12], citynum[20][15];
static int user =0,trans=1;
int index, temp, mexit,o,r,i,j,h;
int main()
{
    welcome();
    menu();
    new_acc();
    view_acc();
    search();
    edit();
    delete_acc();
    viewlist();
    transact();
    sort();

    return 0;
}
void welcome(void)
{
    printf("\n\n\n\n\n");
    printf("\n\t             ==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-");
    printf("\n\t             =                WELOME                     =");
    printf("\n\t             =                  TO                       =");
    printf("\n\t             =                 BANK                      =");
    printf("\n\t             =              MANAGEMENT                   =");
    printf("\n\t             =                SYSTEM                     =");
    printf("\n\t             ==-==-==-==-==-==-==-==-==-==-==-==-==-==-==- \n");
    printf("\t\t\t       enter any key to continue \n");
    getch();
    system("cls");
}
void menu()
{
    char menu[30];
    printf("\t\t\t\xB2\xB2\xB2\ MAIN MENU \xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\t1:New Account");
    printf("\n\t\t\t2:Search By Id");
    printf("\n\t\t\t3:Edit");
    printf("\n\t\t\t4:Transact");
    printf("\n\t\t\t5:Delete Account");
    printf("\n\t\t\t6:Search By Name");
    printf("\n\t\t\t7:View List");
    printf("\n\t\t\t8:view accounts sorted by name\n");
    printf("\n\t\t\t9:close program\n");
    printf("enter your choice: \n");
    do {
        switch(getch()) {
        case '1':
            system("cls");
            new_acc();
            break ;
        case'2':
                system("cls");
            view_acc();
            break ;
        case '3':
            system("cls");
            edit();
            break ;
        case '4':
            system("cls");
            transact();
            break ;
        case '5':
            system("cls");
            delete_acc();
            break;
        case '6':
            system("cls");
            search();
            break ;
        case '7':
            system("cls");
            viewlist();
            break;
        case '8':
            system("cls");
            sort();
            break;
        case '9':
            system("cls");
            close_program(0);
        default :
            printf("wrong answer \n");
            printf("please enter number from 1 to 8\n");
        }
    } while(getch()>8 || getch()<1);
}



void typedec(int y )
{
    if(y == 1) {
        printf("Saving\n");
    } else if(y == 2) {
        printf("Current\n");
    } else if(y == 3) {
        printf("Fixed\n");
    }
}
void new_acc()
{
     int size;
    printf("\t\t\t\xB2\xB2\xB2\ CREAT ACCOUNT \xB2\xB2\xB2\xB2");
    printf("\nPlease enter your name: ");
    scanf(" %[^\n]s", &name[user]);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d", &info[user][0],&info[user][1],&info[user][2]);
under_age:
    printf("\nPlease enter your age (make sure you are over 18): ");
    scanf("%d", &info[user][3]);
    if(info[user][3] <= 17) {
        printf("\n\t\tYou Are Underage You cant Make A Bank Account \n");
        goto under_age;
    }
    do{
    printf("\nEnter your National ID:");
    scanf("%s", &citynum[user]);
      size = strlen(citynum[user]);
     }while(size != 14);
     do {
    printf("\nEnter your phone number: ");
    scanf("%s", &phone[user]);
    size = strlen(phone[user]);
    } while(size != 11);
    printf("\nEnter your address:");
    scanf(" %[^\n]s", &address[user]);
    printf("\nEnter the amount to deposit: $");
    scanf("%d", &info[user][4]);
    transaction[user][0]=info[user][4];
    printf("\nType of account:\n\t1.Saving\n\t2.Current\n\t3.Fixed\n\n\tEnter your choice(1~3):");
    //
    do {
        scanf("%d", &info[user][5]);
    } while(info[user][5] < 1 || info[user][5] > 3);
    info[user][6]=2510000+(info[user][2]%100)*1000+info[user][5]*100+user;
    //    info[user][6] is the bank ID
    printf("your bank ID is: %d\n",info[user][6]);
    printf("your account has been created successfully!\n");
    user++;
    printf("\n\n\n\t\tEnter 1 to go to the main menu and any number to exit:");
    int cont;
    scanf("%d", &cont);
    if(cont == 1) {
        system("cls");
        menu();
    } else {
        system("cls");
        close_program();
    }
}
void view_acc(void)
{
    printf("\t\t\t\xB2\xB2\xB2\ SEARCH BY ID \xB2\xB2\xB2\xB2");
  printf("\nEnter Your Id account :" );
    scanf("%d",&j);
    for(i=0; i<user; i++){
        if(j==info[i][6]) {
            printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ACCOUNT LIST \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            printf(" NAME : %s ",name[i]);
            printf("\n DATE OF BIRTH(mm/dd/yyyy) : %d/%d/%d",info[i][0],info[i][1],info[i][2]);
            printf("\n AGE : %d ",info[i][3]);
            printf("\n LAST DEPOSIT : %d ",info[i][4]);
            printf("\n TYPE OF YOUR ACCOUNT (1.Saving  2.Current  3.Fixed) : %d ",info[i][5]);
            printf("\n PHONE NUMBER : %s ",phone[i]);
            printf("\n ADDRESS : %s \n",address[i]);
            printf("if you want to try again press 1 and if you want to go to main menu press 0 : ");
            scanf("%d",&h);
            if(h==1){
                    system("cls");
                view_acc();
                }
            else{
                  system("cls");
                menu();
            }
        }}
            printf("ID you entered does not match with us or the account has deleted \n\n if you want to try again press 1 and if you want to go to main menu press 0 : ");
            scanf("%d",&h);
            if(h==1){
                system("cls");
                view_acc();
            }
            else{
                        system("cls");
                menu();
            }
}

void transact(void)
{
 int k,p=0,money,x,q,i;
    printf("\t\t\t\xB2\xB2\xB2\ TRANSCATION \xB2\xB2\xB2\xB2");
    printf("\nEnter your ID account:\n");
    scanf("%d",&k);
    int l=0;
    for(i=0; i<user; ++i) {
        if(k==info[i][6]) {
wrong_choice:
            printf("1:deposite\n2:withdraw\n");
            scanf("%d",&p);
            if(p==1) {
                printf("Enter the amount of money you want to depose:\n");
                scanf("%d",&money);
                info[i][4]=info[i][4]+money;
            } else if(p==2) {

                printf("Enter your amount of money that you want to withdraw\n");
                scanf("%d",&money);

                if(info[i][4]<money) {
                    printf("sorry,you can not take more than %d",info[i][4]);
                    goto sorry;
                } else {
                    info[i][4]=(info[i][4]-money);
                }

            } else {
                system("cls");
                printf("your choice wrong\n");
                goto wrong_choice;

            }

        }
    }


sorry:
    printf("\n\tEnter 1 to transact again or any key to menu:\n");
    scanf("%d",&x);
    if (x==1) {
        system("cls");
        transact();
    }
     else
        {
        system("cls");
        menu();
    }

    {
        for(i=0; i<user; ++i)
            if(k!=info[i][6]) {
                printf("ID you entered is not exist \n enter 1 to transact again or any key to menu");
                scanf("%d",&q);

                if(q==1)
                    {
                    system("cls");
                    transact();
                } else
                {
                    system("cls");
                    menu();
                }
            }
    }
}
void delete_acc(void)
{
    printf("\t\t\t\xB2\xB2\xB2\ DELETE ACCOUNT \xB2\xB2\xB2\xB2");
   printf("\nEnter Your ID account ");
    scanf("%d",&r);
    for(i=0; i<user; i++)
        if(r==info[i][6]) {

            info[i][6]='\0';
            name[i][20]='\0';
            info[i][0]='\0';
            info[i][1]='\0';
            info[i][2]='\0';
            info[i][3]='\0';
            info[i][4]='\0';
            info[i][5]='\0';
            citynum[i][20]='\0';
            phone[i][20]='\0';
            address[i][20]='\0';
            puts("the account has deleted~");
        }
    if(info[i][3]!=0) {

        printf("your does not exist \n\n enter 1 to delete another account or any key to menu:\n");
        scanf("%d",&o);
        if(o==0) {
            system("cls");
            delete_acc();
        } else {
            system("cls");
            menu();
        }

    }
    printf("enter 1 to delete another account or any key to menu:\n");
    scanf("%d",&o);
    system("cls");
    if(o==1){
            system("cls");
        delete_acc();
    }else {
        system("cls");
        menu();
    }
}

void edit(void)
{
   int x,size;
    printf("\t\t\t\xB2\xB2\xB2\ UPDATE YOUR ACCOUNT \xB2\xB2\xB2\xB2");
printf("\nEnter Your ID account : ");
scanf("%d",&index);
for(i=0;i<user ;i++){
    if(index==info[i][6]){
        do {
            printf("\n\nDo you want to edit:\n1.Address.\n2.Phone number.\n3.Both.\n\n\n\t Choose your operation from 1 ~ 3:");
            scanf("%i",&x);
        } while(x!=1&&x!=2&&x!=3);
        if(x==1){
            printf("\nEnter your new address: ");
            scanf("%s",address[i]);
            printf("\nThe new address is: %s\n", address[i]);
            printf("The Edit is done successfully ^-^");
            printf("if you want to try again press 1 and if you want to go to menu press 0 :");
            scanf("%d",&x);
            if(x==1){
                system("cls");
                edit();
                }else {
                    system("cls");
                    menu();
                }
            }
        else if(x==2){
         do {
                printf("\nEnter your new phone number: ");
                scanf(" %s", &phone[i]);
                size = strlen(phone[i]);
            } while(size != 11);
            printf("\nThe new phone number  is: %s\n", phone[i]);
             printf("The Edit is done successfully ^-^");
             printf("if you want to try again press 1 and if you want to go to menu press 0 :");
            scanf("%d",&x);
            if(x==1){
                system("cls");
                edit();
                }else {
                    system("cls");
                    menu();
                }



       }else {

            printf("\nEnter your new address: ");
            scanf("%s",address[i]);

            do {
                printf("\nEnter your new phone number: ");
                scanf("%s", &phone[i]);
                size = strlen(phone[i]);
            } while(size != 11);
             printf("The Edit is done successfully ^-^");
            printf("\nThe new phone number  is: %s\n", phone[i]);
             printf("\nThe new address is: %s\n", address[i]);
             printf("if you want to try again press 1 and if you want to go to menu press 0 :");
            scanf("%d",&x);
            if(x==1){
                system("cls");
                edit();
               } else {
                    system("cls");
                    menu();
                }



        }

    }}
        printf("Sorry,Your Id Account does not exist \n\n If you want to try again press 1 and if you want to go to mainmenu press 0 : ");
        scanf("%d",&x);
        if(x==1){
            system("cls");
            edit();
        }else {
        system("cls ");
        menu();
        }
        }
void search(void)
{
int choice,i;
    char name_check[30];
        printf("\t\t\t\xB2\xB2\xB2\ SEARCH BY NAME \xB2\xB2\xB2\xB2");


    printf("\n\t\tPlease enter the user's name : ");
    scanf(" %[^\n]s", &name_check);
    for(i = 0; i<user; ++i) {
        if(strcmp(name_check,name[i]) == 0) {
            printf("\n\tAccount ID: %d\n", info[i][6]);
            printf("\tName: %s\n",name[i]);
            printf("\tCitizenship number: %s \n", citynum[i]);
            printf("\tAge: %d\n", info[i][3]);
            printf("\tPhone Number: %s\n",phone[i]);
            printf("\tAccount type: %d\n", info[i][5]);
            printf("\tAddress: %s\n\n", address[i]);
            printf("-----------------\n");
        } else {
            if(i==user-1) {
                //printf("\n\t\tNo Users with this name");
                goto try_again1;
            }
            continue;
        }
    }

try_again1:
    printf("\n\tEnter 1 to search again, 2 to main menu, and 0 to exit: ");
    scanf("%d",&mexit);
    if (mexit==1) {
        system("cls");
        search();
    } else if (mexit==0) {
        system("cls");
        close_program();
    } else if (mexit==2) {
        system("cls");
        menu();
    } else {
        printf("\n\n\tInvalid, please try again.");
        system("cls");
        goto try_again1;
    }
}


void viewlist(void)
{
   int view_choice,i ;
    system("cls");

    for(i = 0; i<user; i++) {
        if(info[i][6]==0)
            continue ;
        printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ACCOUNT LIST \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf(" NAME : %s \n",name[i]);
        printf(" ID : %d ",info[i][6]);
        printf("\n DATE OF BIRTH(mm/dd/yyyy) : %d/%d/%d",info[i][0],info[i][1],info[i][2]);
        printf("\n AGE : %d ",info[i][3]);
        printf("\n LAST DEPOSIT : %d ",info[i][4]);
        printf("\n TYPE OF YOUR ACCOUNT (1.Saving  2.Current  3.Fixed) : %d ",info[i][5]);
        printf("\n PHONE NUMBER : %s ",phone[i]);
        printf("\n ADDRESS : %s ",address[i]);

    }
    //user ++;
    printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n please enter 1 to mainmenu or any to exit :");

    scanf("%d", &view_choice);
    if(view_choice == 1) {
        system("cls");
        menu();
    } else {
        system("cls");
        close_program();
    }
}

void sort(void)
{
        printf("\t\t\t\xB2\xB2\xB2\ VIEW ACCOUNTS SORTED BY NAME \xB2\xB2\xB2\xB2");

    int i,j,k;
    char s[20],temp[20][20];
    for(i=0; i<user; ++i) {
        strcpy(temp[i],name[i]);

    }
    for(i=0; i<user; i++) {
        for(j=i+1; j<user; j++) {
            if(strcmp(temp[i],temp[j])>0) {
                //change name
                strcpy(s,temp[i]);
                strcpy(temp[i],temp[j]);
                strcpy(temp[j],s);
            }
        }
    }
    for(j=0; j<user; j++) {
        for(i = 0; i<user; ++i) {
            if(strcmp(temp[j],name[i]) == 0) {
                if(info[j][3]==0) {
                    printf("\n\nNo data found for account number (%d)\n\n",j+1);
                    printf("----------------------------\n");
                } else {
                    printf("\nAccount ID: %d\n", info[i][6]);
                    printf("Name: %s\n",name[i]);
                    printf("Citizenship number: %s \n", citynum[i]);
                    printf("Age: %d\n", info[i][3]);
                    printf("Phone Number: %s\n",phone[i]);
                    printf("Account type: ");
                    typedec(info[index][5]);
                    printf("Address: %s\n\n", address[i]);
                    printf("-----------------\n");
                }
            }
        }
    }
    printf("\n\n\n\t\tEnter 1 to go to the main menu and any number to exit:");
    int cont;
    scanf("%d", &cont);
    if(cont == 1) {
        system("cls");
        menu();
    } else {
        system("cls");
        close_program();
    }
}
void close_program(){

printf("THANK YOU ^-^");
exit(0);
}
