#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>


//------------Diary Variables
struct record
{
    char time[6];
    char name[30];
    char note[500];
} ;


//------------ Password Variables
struct Pass
{
    char Uname[20],Pass[20];
}Pass;
char Passsrch[20],Passtmp[20],Usrch[20],Utmp[20],Passsrch2[20],Usrch2[20];
char tmp[10];
FILE *fpass, *ftempass;
int logu,logp,i,count;
int a,b,c,len;




// ----------- Contacts Variables
struct list
{
    char name[20],add[50],email[30],mnum[20],hnum[20];
}list;
char srch[20],name[20];
FILE *fpmain, *ftemp;
int i,n,l,found;
char ch;



//------------Password Functions


void addrecord();
void viewrecord();
void editrecord();
void deleterecord();
void Diary();
void login()
{
    count==0;
        while(count<3)
        {
                system("cls");
                logp=0;
                logu=0;
                fpass=fopen("C:\\\\Datacom.dat","r");
                fread(&Pass,sizeof(Pass),1,fpass);
                if (strcmp(Pass.Uname,"")==0 && strcmp(Pass.Pass,"")==0)
                {
                    fclose(fpass);
                    break;
                }
                // --------------Log in Menu
                printf("\n\n^*^*^*^*^*^ Personal World ^*^*^*^*^*^");
                printf("\n\n\tLog in Menu\n(System will Close after 3 Wrong Password)\n^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n");
                printf("Name :");
                i=0;
                while(1)
                {
                     Usrch[i]=getch();
                     if(Usrch[i]=='\r')
                     {
                        Usrch[i]='\0';
                         break;
                     }
                     printf("*");
                     i++;
                }
                fflush(stdin);
                printf("\nPassword :");
                i=0;
                while(1)
                {
                     Passsrch[i]=getch();
                     if(Passsrch[i]=='\r')
                     {
                        Passsrch[i]='\0';
                         break;
                     }
                     printf("*");
                     i++;
                }
                fflush(stdin);
                printf("\n^*^*^*^*^*^*^*^*^*^*^*^*^\n");
                            if(strcmp(Usrch,Pass.Uname)==0)
                                {
                                    logu=1;
                                }
                            if(strcmp(Passsrch,Pass.Pass)==0)
                                {
                                    logp=1;
                                }
                fclose(fpass);
                if (logp==1 && logu==1)
                {
                    printf("\tPassword Match\nPress Any Key To Continue...");
                    getch(tmp);
                    break;
                }else{
                    printf("Wrong Password Press any key to Try again!");
                    count++;
                    getch(tmp);
                }
        }
        if (count==3)
            exit(1);
}
void passchange()
{
                fpass=fopen("C:\\\\Datacom.dat","r");
                fread(&Pass,sizeof(Pass),1,fpass);
                if (strcmp(Pass.Uname,"")!=0 && strcmp(Pass.Pass,"")!=0)
                {
                    fclose(fpass);
                    printf("\nConfirm Current Password to Change The Password\nPress Any Key To Continue...");
                    getch(tmp);
                    login();
                }
                else
                    fclose(fpass);
                system("cls");
                printf("\n\n\tEnter New Password\n(Just press enter if you don't want any password)\n(First Character of Name Must be Capital Letter and Greater than 2 letter\nAnd Name Must not Contain any number or Sign)\n(Password Must Contain an upper case letter and a number)\n^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n");
          while(1)
          {
                printf("Name :");
                i=0;
                while(1)
                {
                     Usrch[i]=getch();
                     if(Usrch[i]=='\r')
                     {
                        Usrch[i]='\0';
                         break;
                     }
                     printf("*");
                     i++;
                }
                if (strcmp(Usrch,"")==0)
                {
                    remove("C:\\\\Datacom.dat");
                    break;
                }
                fflush(stdin);
                printf("\nName Again :");
                i=0;
                while(1)
                {
                     Usrch2[i]=getch();
                     if(Usrch2[i]=='\r')
                     {
                        Usrch2[i]='\0';
                         break;
                     }
                     printf("*");
                     i++;
                }
                fflush(stdin);
                printf("\n");
                if (strcmp(Usrch,Usrch2)==0)
                {
                    printf("Name Matched!");
                    i=0;a=0;b=0;c=0;
                    if (isupper(Usrch[0]))
                        a=1;
                    while(Usrch[i]!='\0')
                    {
                        if (isalpha(Usrch[i]));
                        else if (isdigit(Usrch[i]))
                            b=1;
                        else
                            c=1;
                        i++;
                    }
                    len=strlen(Usrch);
                    if(a==1 && b==0 && c==0 && len >2)
                    {
                        printf(" and Ok\n");
                        break;
                    }
                    else
                    {
                        printf(" But Does not Satisfy! Press any key to Try again!\n");
                    }
                }
                else
                {
                    printf("Name Did not Match! Press any key to Try again!\n");
                }
          }
            while(1)
            {
                if (strcmp(Usrch,"")==0)
                {
                    break;
                }
                printf("Password :");
                i=0;
                while(1)
                {
                     Passsrch[i]=getch();
                     if(Passsrch[i]=='\r')
                     {
                        Passsrch[i]='\0';
                         break;
                     }
                     printf("*");
                     i++;
                }
                fflush(stdin);
                printf("\nPassword Again :");
                i=0;
                while(1)
                {
                     Passsrch2[i]=getch();
                     if(Passsrch2[i]=='\r')
                     {
                        Passsrch2[i]='\0';
                         break;
                     }
                     printf("*");
                     i++;
                }
                fflush(stdin);
                printf("\n");
                 if (strcmp(Passsrch,Passsrch2)==0)
                {
                     printf("Password Matched!");
                    i=0;a=0;b=0;c=0;
                    while(Passsrch[i]!='\0')
                    {
                        if (isalpha(Passsrch[i]))
                        {
                            if (isupper(Passsrch[i]))
                            a=1;
                        }
                        else if (isdigit(Passsrch[i]))
                            b=1;
                        else
                            c=1;
                        i++;
                    }
                    len = strlen(Passsrch);
                    if(a==1 && b==1 && len >4)
                    {
                        printf(" and Ok\n");
                        break;
                    }
                    else
                    {
                        printf(" But Does not Satisfy! Press any key to Try again!\n");
                    }
                }
                else
                {
                    printf("Password Did not Match! Press any key to Try again!\n");
                }
            }
            if (strcmp(Usrch,"")!=0)
            {
                ftempass=fopen("C:\\\\Datatmp.dat","w");
                strcpy(Pass.Uname,Usrch);
                strcpy(Pass.Pass,Passsrch);
                fwrite(&Pass,sizeof(Pass),1,ftempass);
                fclose(ftempass);
                remove("C:\\\\Datacom.dat");
                rename("C:\\\\Datatmp.dat","C:\\\\Datacom.dat");
                printf("\tPassword Changed!!");
                printf("\n^*^*^*^*^*^*^*^*^*^*^*^*^\n");
                printf("Press any key to Continue...!\n");
                getch(tmp);
            }
}



//-------------Contacts Functions



void addcontact()
{
    system("cls");
            fpmain=fopen("contacts.dat","a");
            for (;;)
            {
                fflush(stdin);
                printf("Enter blank name to exit\nName :");
                gets(list.name);
                if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                    break;
                fflush(stdin);
                printf("Mobile Number:");
                gets(list.mnum);
                fflush(stdin);
                printf("Home Number:");
                gets(list.hnum);
                fflush(stdin);
                printf("address:");
                gets(list.add);
                fflush(stdin);
                printf("Email Address:");
                gets(list.email);
                printf("\n");
                fwrite(&list,sizeof(list),1,fpmain);
            }
            fclose(fpmain);
}
void conlist()
{
        system("cls");
                printf("\n\n<^< List of Contacts >^>\n");
                printf("Name\t\t\tMobile Number\t\tHome Number\t\tEmail Address\t\t\tAddress\n");
                for(i=97;i<=122;i=i+1)
                {
                    fpmain=fopen("contacts.dat","r");
                    fflush(stdin);
                    found=0;
                    while(fread(&list,sizeof(list),1,fpmain)!=0)
                    {
                        if(list.name[0]==i || list.name[0]==i-32)
                        {
                            printf("%s\t\t\t%s\t\t%s\t\t%s\t\t%s\n",list.name,list.mnum,list.hnum,list.email,list.add);
                            found++;
                        }
                    }
                    if(found!=0)
                    printf("\n<<<<<<<<  %c  - %d >>>>>>>>>\n\n",i-32,found);
                    fclose(fpmain);
                }
}
void searchlist()
{
    system("cls");
            do
            {
                found=0;
                printf("\n\nName of contact to search: ");
                fflush(stdin);
                gets(srch);
                l=strlen(srch);
                fpmain=fopen("contacts.dat","r");
                system("cls");
                printf("\n\nSearch result for '%s' \n^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n",srch);
                printf("Name\t\t\tMobile Number\t\tHome Number\t\tEmail Address\t\t\tAddress\n");
                while(fread(&list,sizeof(list),1,fpmain)!=0)
                {
                    for(i=0;i<=l;i++)
                    name[i]=list.name[i];
                    name[l]='\0';
                    if(stricmp(name,srch)==0)
                    {
                        printf("%s\t\t\t%s\t\t%s\t\t%s\t\t%s\n",list.name,list.mnum,list.hnum,list.email,list.add);
                        found++;
                    }
                }
                if(found==0)
                    printf("\nNo match found");
                else if(found==1)
                    printf("\n%d match found",found);
                else
                    printf("\n%d matches found",found);
                fclose(fpmain);
                printf("\n\nTry again?\n1. Yes\t0. No\n");
                ch = getch();
            }while(ch=='1');

}
void editlist()
{
    system("cls");
            fpmain=fopen("contacts.dat","r");
            ftemp=fopen("temp.dat","w");
            fflush(stdin);
            printf("\n^*^ Edit contact^*^ \n\nEnter the name of contact:");
            gets(name);
            while(fread(&list,sizeof(list),1,fpmain)!=0)
            {
                if(stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ftemp);
            }
            fflush(stdin);
            printf("\n\nEditing '%s'\n(If Match not found new will be added despite of not finding '%s')\n\n",name,name);
            printf("Name :");
            gets(list.name);
            fflush(stdin);
            printf("Mobile Number:");
            gets(list.mnum);
            fflush(stdin);
            printf("HomeNumber:");
            gets(list.hnum);
            fflush(stdin);
            printf("Address:");
            gets(list.add);
            fflush(stdin);
            printf("Email Address:");
            gets(list.email);
            printf("\n");
            fwrite(&list,sizeof(list),1,ftemp);
            fclose(fpmain);
            fclose(ftemp);
            remove("contacts.dat");
            rename("temp.dat","contacts.dat");
}
void deletecontact()
{
    system("cls");
            fflush(stdin);
            printf("\n\nEnter the name of contact to delete(Use Identical Name):");
            gets(name);
            fpmain=fopen("contacts.dat","r");
            ftemp=fopen("temp.dat","w");
            while(fread(&list,sizeof(list),1,fpmain)!=0)
            {
                if (stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ftemp);
            }
            fclose(fpmain);
            fclose(ftemp);
            remove("contacts.dat");
            rename("temp.dat","contacts.dat");
            printf("Deleted");
}
void Contactsman()
{
    Conmain :
    system("cls");
    // --------------Main menu
    printf("\n\n\tContacts Menu\n^*^*^*^*^*^*^*^*^*^*^*^*^\n");
    printf("1. Contacts List\n2. Add Contact\n3. Search Contact\n4. Delete Contact\n5. Edit Contact\n6. Delete All Contacts\n0. Main Menu");
    printf("\n^*^*^*^*^*^*^*^*^*^*^*^*^\n");
    printf("Enter choice:");
    ch = getch();

    switch(ch)
    {
        case '0':
            printf("\nAre you sure You want to exit?");
            break;
    //------------Contacts List
        case '1':
            conlist();
            break;
    //------------Add contact
        case '2':
            addcontact();
            break;
    //------------Search Contacts
        case '3':
            searchlist();
            break;
    //------------Delete contacts
        case '4':
            deletecontact();
            break;
    //------------Edit contacts
        case '5':
            editlist();
            break;
    //------------Delete whole List
        case '6':
            remove("contacts.dat");
            printf("All Deleted");
            break;
        default:
            printf("Invalid choice");
            break;
    }
    printf("\n\nEnter the Choice:\n1. Contacts Menu\t0. Main Menu\n");
    ch = getch();
    switch (ch)
    {
        case '1':
            goto Conmain;
        case '0':
            break;
        default:
            printf("Invalid choice");
            goto Conmain;
    }
}
void appopen()
{
     printf("\n\n^*^*^*^*^*^ Personal World ^*^*^*^*^*^\n");
     printf("\n\tLoading  >         10");
     Sleep(400);
     system("cls");
     printf("\n\n^*^*^*^*^*^ Personal World ^*^*^*^*^*^\n");
     printf("\n\tLoading  >>        20");
     Sleep(400);
     system("cls");
     printf("\n\n^*^*^*^*^*^ Personal World ^*^*^*^*^*^\n");
     printf("\n\tLoading  >>>       30");
     Sleep(400);
     system("cls");
     printf("\n\n^*^*^*^*^*^ Personal World ^*^*^*^*^*^\n");
     printf("\n\tLoading  >>>>      40");
     Sleep(400);
     system("cls");
     printf("\n\n^*^*^*^*^*^ Personal World ^*^*^*^*^*^\n");
     printf("\n\tLoading  >>>>>     50");
     Sleep(400);
     system("cls");
     printf("\n\n^*^*^*^*^*^ Personal World ^*^*^*^*^*^\n");
     printf("\n\tLoading  >>>>>>    60");
     Sleep(400);
     system("cls");
     printf("\n\n^*^*^*^*^*^ Personal World ^*^*^*^*^*^\n");
     printf("\n\tLoading  >>>>>>>   70");
     Sleep(400);
     system("cls");
     printf("\n\n^*^*^*^*^*^ Personal World ^*^*^*^*^*^\n");
     printf("\n\tLoading  >>>>>>>>  80");
     Sleep(400);
     system("cls");
     printf("\n\n^*^*^*^*^*^ Personal World ^*^*^*^*^*^\n");
     printf("\n\tLoading  >>>>>>>>> 90");
     Sleep(400);
     system("cls");
     printf("\n\n^*^*^*^*^*^ Personal World ^*^*^*^*^*^\n");
     printf("\n\tLoading  >>>>>>>>>>100");
     Sleep(400);
}
void main()
{
    int cr;
    cr="COLOR 1A";
    system(cr);
    char choice;
    appopen();
    login();
    while(1)
    {
        Main :
        system("cls");
        printf("\n\n\tMain Menu\n^*^*^*^*^*^*^*^*^*^*^*^*^\n");
        printf("1. Personal Diary\n2. Contacts Manager\n3. Picture Manager\n4. Change Password\n0. Exit");
        printf("\n^*^*^*^*^*^*^*^*^*^*^*^*^\n");

        printf("Enter Choice:");
        choice = getch();

        switch (choice)
        {
            //----------Personal Diary
            case '1' :
                Diary();
                break;
            //-----------Contacts Manager
            case '2' :
                Contactsman();
                break;
            //-----------Picture Manager
            case '3' :
                printf("Function not added!");
                getch(tmp);
                goto Main;
            //------------Password Change
            case '4' :
                passchange();
                break;
            case '0' :
                exit(1);
            default :
                printf("Invalid Input!");
                getch(tmp);
        }
    }
    exit(1);
}


//---------------Diary Functions



Diary()
{
    char ch;
    int cr;
    cr="COLOR 1A";
    system(cr);
    printf("\t[PERSONAL DIARY]\n");
    while(1)
    {
        printf("\n\n\tMAIN MENU:");
        printf("\n\n\tEntry Notes\t[1]");
        printf("\n\tView Entries\t[2]");
        printf("\n\tEdit Entries\t[3]");
        printf("\n\tDelete Entries\t[4]");
        printf("\n\tEXIT\t\t[5]");
        printf("\n\n\tEnter Your Choice: ");
        ch=getch();
        switch(ch)
        {
            case '1':
                addrecord();
                break;
            case '2':
                viewrecord();
                break;
            case '3':
                editrecord();
                break;
            case '4':
                deleterecord();
                break;
            case '5':
                printf("\n\n\t\t\tThank You.");
                printf("\n\t\t\tAll Rights Reserved By Dark Passengers\n");
                getch();
                break;
        }
        system("cls");
        if (ch=='5')
        break;
    }
}

void addrecord( )
{
    int cr;
    cr="COLOR 2A";
    system(cr);
    system("cls");
    FILE *fp ;
    char time[10];
    struct record e ;
    char filename[15];
    int choice;
    printf("\n\n\tEnter Date:");
    fflush(stdin);
    gets(filename);
    fp=fopen(filename,"ab+" ) ;
        choice=0;
        fflush(stdin);
        printf ( "\n\tEnter Time:");
        scanf("%s",time);
        rewind(fp);
        while(fread(&e,sizeof(e),1,fp)==1)
        {
            if(strcmp(e.time,time)==0)
            {
                printf("\n\tEntry Already Exist.\n");
                choice=1;
            }
        }
        if(choice==0)
        {
            strcpy(e.time,time);
            printf("\tTitle:");
            fflush(stdin);
            gets(e.name);
            fflush(stdin);
            printf("\tNote:");
            gets(e.note);
            fwrite ( &e, sizeof ( e ), 1, fp ) ;
            printf("\nSuccessfully Added\n");
        }
    fclose ( fp ) ;
    getch();
}
void viewrecord()
{
    int cr;
    cr="COLOR 3A";
    system(cr);
    FILE *fpte ;
    system("cls");
    struct record title ;
    char time[6],choice,filename[14];
    int ch;
    printf("\t\t* List Of Entries *");
    do
    {
        printf("\n\tEnter Date Of Record To View:");
        fflush(stdin);
        gets(filename);
        fpte = fopen ( filename, "rb" ) ;
        if ( fpte == NULL )
        {
            printf( "\nRecords Does not Exist.\n");
            getch();
            return ;
        }
        system("cls");
            while ( fread ( &title, sizeof ( title ), 1, fpte ) == 1 )
            {
                printf("\n");
                printf("\nTIME: %s",title.time);
                printf("\nTitle: %s",title.name);
                printf("\nNOTE: %s",title.note);
                printf("\n");
            }
        printf("\n\nWould You Like To Continue...(Y/N):");
        fflush(stdin);
        choice=getch();
    }
    while(choice=='Y'||choice=='y');
    fclose ( fpte ) ;
    return ;
}
void editrecord()
{
    int cr;
    cr="COLOR 4A";
    system(cr);
    system("cls");
    FILE *fpte ;
    struct record title ;
    char name[6],choice,filename[14];
    int num,count=1;
    printf("\t\t* Edit Entries *");
    do
    {
        printf("\n\tEnter The Date Of Record To Edit:");
        fflush(stdin);
        gets(filename);
        printf("\n\tTitle:");
        gets(name);
        fpte = fopen ( filename, "rb+" ) ;
        if ( fpte == NULL )
        {
            printf( "\nRecords Does Not Exist" ) ;
            getch();
            return;
        }
        while ( fread ( &title, sizeof ( title ), 1, fpte ) == 1 )
        {
            if(strcmp(title.name,name)==0)
            {
                printf("\nYOUR OLD RECORD WAS AS:");
                printf("\nTIME: %s",title.time);
                printf("\nTitle: %s",title.name);
                printf("\nNOTE: %s",title.note);
                printf("\n\n\t\tWhat Would You Like to Edit?");
                printf("\n1.TIME.");
                printf("\n2.Title.");
                printf("\n3.NOTE.");
                printf("\nPress Enter to Go Back To Main Menu.");
                do
                {
                    printf("\n\tChoose Your Option:");
                    fflush(stdin);
                    scanf("%d",&num);
                    fflush(stdin);
                    printf("\nEnter New Data:");
                    switch(num)
                    {
                    case 1:
                        printf("\nDate:");
                        gets(title.time);
                        break;
                    case 2:
                        printf("\nTitle:");
                        gets(title.name);
                        break;
                    case 3:
                        printf("\nNOTE:");
                        gets(title.note);
                        break;
                    default:
                        getch();
                        return ;
                        break;
                    }
                }
                while(num<1||num>3);
                fseek(fpte,-sizeof(title),SEEK_CUR);
                fwrite(&title,sizeof(title),1,fpte);
                fseek(fpte,-sizeof(title),SEEK_CUR);
                fread(&title,sizeof(title),1,fpte);
                choice=5;
                break;
            }
        }
        if(choice!=5)
        {
            printf("\nEntry Does not Exist.\n");
            printf("\nTry Again...(Y/N)");
            scanf("%c",&choice);
            count--;
        }

        else
        {
            printf("Successfully Edited\n");
        }
    }
    while(choice=='Y'||choice=='y');
    fclose ( fpte ) ;
    getch();
}
void deleterecord( )
{
    int cr;
    cr="COLOR 5A";
    system(cr);
    system("cls");
    FILE *fp,*fptr ;
    struct record file ;
    char filename[15],another = 'Y' ,title[10];
    int choice,check;
    while ( another == 'Y' )
    {
        printf("\n\n\t[1]#Delete All");
        printf("\n\t[2]#Delete a Particular Entry By Title\t");
        do
        {
            printf("\n\tEnter Your Choice:");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                printf("\n\tDate Of File To be Deleted:");
                fflush(stdin);
                gets(filename);
                fp = fopen (filename, "wb" ) ;
                if ( fp == NULL )
                {
                    printf("\nFile Does not Exist");
                    printf("\nPress Enter to go Back.");
                    getch();
                    return ;
                }
                fclose(fp);
                remove(filename);
                printf("\nDeletion Completed!");
                break;
            case 2:
                printf("\n\tDate Of Entry:");
                fflush(stdin);
                gets(filename);
                fp = fopen (filename, "rb" ) ;
                if ( fp == NULL )
                {
                    printf("\nFile Does not Exist");
                    printf("\nPress Enter to go Back.");
                    getch();
                    return ;
                }
                printf("\n\tTitle of entry to be Deleted:");
                fflush(stdin);
                gets(title);
                while(fread(&file,sizeof(file),1,fp)==1)
                {
                    if(strcmp(file.name,title)!=0)
                        fwrite(&file,sizeof(file),1,fptr);
                }
                fclose(fp);
                fclose(fptr);
                remove(filename);
                rename("temp",filename);
                printf("\nSuccessful");
                break;
            default:
                printf("\n\tWrong Choice");
                break;
            }
        }
        while(choice<1||choice>2);
        printf("\n\tDo you want to Delete Another Record.(Y/N):");
        fflush(stdin);
        scanf("%c",&another);
    }
    printf("\n\n\tPress Enter To Exit...");
    getch();
}
