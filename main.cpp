#include <iostream>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;
class Book
{
    char bno[6];
    char bname[30];
    char aname[20];
public:
   void createBook()
   {
       cout<<"\n\t\tBOOK RECORD ENTRY";
       cout<<"\n\tEnter Book Number   : ";
       cin>>bno;
       cin.ignore();
       cout<<"\n\tEnter Book Name   : ";
       gets(bname);
       cout<<"\n\tEnter Author Name : ";
       gets(aname);
       cout<<"\nBook Record Created....";
   }
   void showBook()
   {
       cout<<"\n\n\t\tBOOK DETAILS ";
       cout<<"\n\tBook Number   : "<<bno;

       cout<<"\n\tBook Name   : ";
       puts(bname);
       cout<<"\n\tAuthor Name : ";
       puts(aname);
   }
   void modifyBook()
   {

       cout<<"\n\tBook Number   : "<<bno;
       cout<<"\n\tEnter Book Name   : ";
       cin.ignore();
       gets(bname);
       cout<<"\n\tEnter Author Name : ";
       gets(aname);

   }
   char* returnBookNumber()
   {
       return bno;
   }
   void report()
   {
       cout<<bno<<setw(28)<<bname<<setw(24)<<aname<<endl;
   }

};
class Student
{
    char admno[6];
    char name[30];
    char stbno[6];
    int token;
public:
   void createStudent()
   {
       cout<<"\n\t\t\tSTUDENT RECORD ENTRY";
       cout<<"\n\n\n\tEnter Admission Number   : ";
       cin>>admno;
       cin.ignore();
       cout<<"\n\n\tEnter Student Name   : ";
       gets(name);
       stbno[0]='\0';
       token=0;
       cout<<"\n\nStudent Record Created....\n\n";
   }
   void showStudent()
   {
       cout<<"\n\n\t\tStudent DETAILS ";
       cout<<"\n\tStudent Number   : "<<admno;

       cout<<"\n\tStudent Name   : ";
       puts(name);
       cout<<"\n\tNumber of book issued : "<<token;
       if(token==1)
       {
        cout<<"\n\tBook number :";
        puts(stbno);
       }
   }
   void modifyStudent()
   {

       cout<<"\n\tAdmission Number   : "<<admno;
       cout<<"\n\tEnter  Name   : ";
       cin.ignore();
       gets(name);

   }
   char* returnAdmissionNumber()
   {
       return admno;
   }
   int returnToken()
   {
       return token;
   }
   void addToken()
   {
       token=1;
   }
   void resetToken()
   {
       token=0;
   }
   char* returnStudentBookNumber()
   {
       return stbno;
   }
   void studentBookNumber(char num[])
   {
       strcpy(stbno,num);
   }
   void report()
   {
       cout<<"\t"<<admno<<setw(23)<<name<<setw(13)<<token<<endl;
   }

};
fstream fp,fp1;
Book bk;
Student st;

void writeBook()
{  char ch;
    fp.open("book.txt",ios::out|ios::app);
    do{
            system("cls");
       bk.createBook();
       fp.write((char*)&bk,sizeof(bk));
       cout<<"\n\n\tPress 'Y' to create another record or 'N' to back  ";
       cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}
void writeStudent()
{  char ch;
    fp.open("student.txt",ios::out|ios::app);
    do{
            system("cls");
       st.createStudent();
       fp.write((char*)&st,sizeof(st));
       cout<<"\n\n\tPress 'Y' to create another record or 'N' to back  ";
       cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}
void displaySpecificBook(char n[])
{
    int flag=0;
    cout<<"\n\t\tSPECIFIC BOOK DETAIL\n";
    fp.open("book.txt",ios::in);
    if(!fp)
    cout<<"\nFile is not opened\n";
    else{
        while(fp.read((char*)&bk,sizeof(bk)))
        {
            if(strcmp(bk.returnBookNumber(),n)==0)
            {
                bk.showBook();
                flag=1;
            }
        }
        if(flag==0)
            cout<<"\nBook does not exist\n";
    }
    fp.close();
    cout<<"\n\n\n\nPress any key...";
    getch();
}
void displaySpecificStudent(char n[])
{
    int flag=0;
    cout<<"\n\t\tSPECIFIC STUDENT DETAIL\n";
    fp.open("student.txt",ios::in);
    if(!fp)
    cout<<"\nFile is not opened\n";
    else{
        while(fp.read((char*)&st,sizeof(st)))
        {
            if(strcmp(st.returnAdmissionNumber(),n)==0)
            {
                st.showStudent();
                flag=1;
            }
        }
        if(flag==0)
            cout<<"\nStudent does not exist\n";
    }
    fp.close();
    cout<<"\n\n\n\nPress any key...";
    getch();
}
void modifyBookRecord()
{   int found=0;
    char bn[6];
    system("cls");
    cout<<"\n\tEnter book number  ";
    cin>>bn;
    fp.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(bk)) && found==0)
    {
        if(strcmp(bk.returnBookNumber(),bn)==0)
        {
            bk.showBook();
             cout<<"\n\n\t\t\tMODIFY BOOK RECORD";
             cout<<"\n\tEnter New Details..\n";
            bk.modifyBook();
            int pos=-1;
            pos=-1*sizeof(bk);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&bk,sizeof(bk));
            cout<<"\nBook Record Updated....";
            found=1;
        }
    }
    fp.close();
    if(found==0)
        cout<<"\nBook Record does not Found....\n";
cout<<"\nPress any key ... ";
getch();
}
void modifyStudentRecord()
{   int found=0;
    char sn[6];
    system("cls");
    cout<<"\n\tEnter admission number  ";
    cin>>sn;
    fp.open("student.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(st)) && found==0)
    {
        if(strcmp(st.returnAdmissionNumber(),sn)==0)
        {
            st.showStudent();
             cout<<"\n\n\t\t\tMODIFY STUDENT RECORD";
             cout<<"\n\tEnter New Details..\n";
            st.modifyStudent();
            int pos=-1;
            pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st,sizeof(st));
            cout<<"\nStudent Record Updated....";
            found=1;
        }
    }
    fp.close();
    if(found==0)
        cout<<"\nBook record does not Found....\n";
cout<<"\nPress any key ... ";
getch();
}
void deleteStudentRecord()
{
    int flag=0;
    char sn[6];
    system("cls");
    cout<<"\n\n\t\t\tDELETE STUDENT\n";
    cout<<"\n\tEnter admission number  ";
    cin>>sn;
    fp.open("student.txt",ios::in|ios::out);
    fstream fp2;
    fp2.open("temp.txt",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&st,sizeof(st)))
    {
        if(strcmp(st.returnAdmissionNumber(),sn)!=0)
        {
            fp2.write((char*)&st,sizeof(st));
        }
        else
            flag=1;
    }
    fp2.close();
    fp.close();

    remove("student.txt");
    rename("temp.txt","student.txt");
    if(flag==1)
        cout<<"\n\tRecord Deleted successfully\n";
    else
        cout<<"\n\nRecord not found\n";
    cout<<"\n\nPress any key ...  ";
    getch();
}
void deleteBookRecord()
{
    int flag=0;
    char bn[6];
    system("cls");
    cout<<"\n\tEnter Book number  ";
    cin>>bn;
    fp.open("book.txt",ios::in|ios::out);
    fstream fp2;
    fp2.open("temp.txt",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(bk)))
    {
        if(strcmp(bk.returnBookNumber(),bn)!=0)
        {
            fp2.write((char*)&bk,sizeof(bk));
        }
        else
            flag=1;
    }
    fp.close();
    fp2.close();
    remove("book.txt");
    rename("temp.txt","book.txt");
    if(flag==1)
        cout<<"\n\tRecord Deleted successfully\n";
    else
        cout<<"Record not found\n";
    cout<<"\n\n\nPress any key ...  ";
    getch();
}
void displayAllStudent()
{
    system("cls");
fp.open("student.txt",ios::in);
if(!fp)
cout<<"File is not opened\n";
else
{
cout<<"\n\n\t\tSTUDENT LIST\n\n";
	cout<<"========================================================================\n";
	cout<<"\tAdmission Number"<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
	cout<<"========================================================================\n";

while(fp.read((char*)&st,sizeof(st)))
{
    st.report();
}
}
fp.close();
cout<<"\n\n\nPress any key ...  ";
getch();
}
void displayAllBooks()
{
    system("cls");
fp.open("book.txt",ios::in);
if(!fp)
{cout<<"File is not opened\n";
  getch();
  return;
}
else
{
cout<<"\n\n\t\tBOOK LIST\n\n";
	cout<<"========================================================================\n";
	cout<<"Book Number"<<setw(20)<<"Name"<<setw(25)<<"Book Issued\n";
	cout<<"========================================================================\n";

while(fp.read((char*)&bk,sizeof(bk)))
{
    bk.report();
}
}
fp.close();
cout<<"\n\nPress any key ...  ";
getch();
}
void bookIssue()
{
    char sn[6],bn[6];
    int found=0,flag=0;
    system("cls");
    cout<<"\n\n\t\t\tBOOK ISSUE ";
    cout<<"\n\n\nEnter the admission number of student ...  ";
    cin>>sn;
    fp.open("student.txt",ios::in|ios::out);
    fp1.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(st)) && found==0)
    {
        if(strcmp(st.returnAdmissionNumber(),sn)==0)
        {
            found=1;
            if(st.returnToken()==0)
            {
                cout<<"\n\nEnter the book number ..  ";
                cin>>bn;
                while(fp1.read((char*)&bk,sizeof(bk)) && flag==0)
                {
                    if(strcmp(bk.returnBookNumber(),bn)==0)
                    {
                        bk.showBook();
                        flag=1;
                        st.addToken();
                        st.studentBookNumber(bk.returnBookNumber());
                        int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(st));
                        cout<<"\n\n\t Book issued successfully\n\nNote: Please Write the current date in backside of your book and submit within 15 days,,else fine Rs. 1 for each day after 15 days period";
                    }
                }
                if(flag==0)
                    cout<<"\n\n\tBook number does not exist.. ";
            }
            else
                cout<<"\n\nYou have not returned the last book .. ";
        }
    }
    if(found==0)
        cout<<"\n\nStudent record does not exist... ";

    fp.close();
    fp1.close();

    cout<<"\n\nPress any key ...  ";
    getch();
}
void bookDeposit()
{
    char sn[6];
    int found=0,flag=0,fine=0,day=0;
    system("cls");

    cout<<"\n\n\t\tBOOK DEPOSIT  ";
    cout<<"\nEnter the admission number of student ...  ";
    cin>>sn;
    fp.open("student.txt",ios::in|ios::out);
    fp1.open("book.txt",ios::in|ios::out);

    while(fp.read((char*)&st,sizeof(st)) && found==0)
    {
        if(strcmp(st.returnAdmissionNumber(),sn)==0)
        {
            found=1;
            if(st.returnToken()==1)
            {
                while(fp1.read((char*)&bk,sizeof(bk)) && flag==0)
                {
                    if(strcmp(st.returnStudentBookNumber(),bk.returnBookNumber())==0)
                    {
                        bk.showBook();
                        flag=1;
                        cout<<"\nBook deposited in Number of days  ,,, ";
                        cin>>day;
                        if(day>15)
                        {
                            fine=(day-15)*1;
                            cout<<"\n\nYou have to pay fine of Rs. "<<fine;
                        }
                        st.resetToken();
                        int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(st));
                        cout<<"\n\n\tBook Deposited Successfully  ....  ";
                    }
                }
                if(flag==0)
                    cout<<"Book record does not exist  ...  ";
            }
            else
                cout<<"\nNo book is issue ,,please check .... ";
        }
    }
    if(found==0)
        cout<<"\n\nStudent record does not exist ...";

    fp.close();
    fp1.close();
    cout<<"\n\nPress any key ...  ";
    getch();
}
void administrator_Menu()
{
    int choice;

    system("cls");
    cout<<"\n\n";
    cout<<"\n\n\t1.CREATE STUDENT";
    cout<<"\n\n\t2.DISPLAY ALL STUDENTS";
    cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT";
    cout<<"\n\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\t6.CREATE BOOK";
    cout<<"\n\n\t7.Display ALL BOOKS";
    cout<<"\n\n\t8.Display SPECIFIC BOOK";
    cout<<"\n\n\t9.MODIFY BOOK RECORD";
    cout<<"\n\n\t10.DELETE BOOK RECORD";
    cout<<"\n\n\t11.BACK TO MAIN MENU";
    cout<<"\n\tEnter your choice between(1-11)  ";
    cin>>choice;
    switch(choice)
    {

    case 1: writeStudent();
        break;
    case 2: displayAllStudent();
        break;
    case 3:
             {char num[6];
             system("cls");
             cout<<"\n\n\tEnter Admission Number ";
             cin>>num;
             displaySpecificStudent(num);
             break;}
    case 4:
        modifyStudentRecord();
        break;
    case 5:
       deleteStudentRecord();
        break;
    case 6:
        writeBook();
        break;
    case 7:
        displayAllBooks();
        break;
    case 8:
        {char num[6];
             system("cls");
             cout<<"\n\n\tEnter Book Number ";
             cin>>num;
             displaySpecificBook(num);
             break;}
    case 9:
      modifyBookRecord();
        break;
    case 10:
        deleteBookRecord();
        break;
    case 11:
        return;
    default:
        cout<<"\nInvalid choice,,Press any key  ...  ";
        getch();

}
    administrator_Menu();
}


void Intro()
{
    cout<<"\n\n\n";
    cout<<setw(35)<<"LIBRARY\n";
    cout<<setw(38)<<"MANAGEMENT\n";
    cout<<setw(34)<<"SYSTEM\n";
     cout<<"\n\n\n";
      cout<<"Name    : Shivam \n";
      cout<<"College : TIT,Bhopal\nPress any key ...";
      getch();
}
void menu1()
{  int choice;
    do
   {  system("cls");
    cout<<"\n\t1.Book Issue";
    cout<<"\n\t2.Book Deposit";
    cout<<"\n\t3.Administrator Menu";
    cout<<"\n\t4.Exit\n";
    cout<<"\n\tEnter your choice between (1-4) ";
    cin>>choice;
    switch(choice)
    {
    case 1:bookIssue();
        break;
    case 2: bookDeposit();
        break;
    case 3:
        administrator_Menu();
        break;
    case 4:
        //exit
        break;
    default :

        cout<<"\nInvalid choice,,Try Again... ";
        cin>>choice;
    }
   }while(choice!=4);
}
int main()
{
   Intro();
   menu1();

}

