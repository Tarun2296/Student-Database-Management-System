#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string.h>
using namespace std;

class student
{
public:
    char Id[15],Name[30],Branch[10],Sec,Sex[2],Father_Name[30],Add[50],Year[20];
    int age;
    long int pincode,Phone_no;
    long long int Mob_no;

    student()
    {
        Sec = 'D';
    }

void get_data()
{
   cout<<"Enter ID:\n";
   cin>>Id;
   cin.ignore();
   cout<<"Enter Student Name:\n";
   gets(Name);
   cout<<"Enter Father Name:\n";
   gets(Father_Name);
   cout<<"Enter your Address:\n";
   gets(Add);
   cout<<"Enter your Pin Code:\n";
   cin>>pincode;
   cout<<"Enter Sex:\n";
   cin>>Sex;
   cout<<"Enter Age:\n";
   cin>>age;
   cout<<"Enter Branch:\n";
   cin>>Branch;
   cout<<"Enter Year:\n";
   cin>>Year;
   cout<<"Enter your Mobile Number: \n";
   cin>>Mob_no;
   cout<<"Enter your Phone Number:\n";
   cin>>Phone_no;
try
{
    if(age<0 || pincode<0 || Phone_no<0 || Mob_no<0 || strlen(Id)>15 || strlen(Name)>30 || strlen(Branch)>10 || strlen(Sex)>2 || strlen(Father_Name)>30 || strlen(Add)>50 || strlen(Year)>20)
    {
        throw(age);
        throw(pincode);
        throw(Phone_no);
        throw(Mob_no);
        throw(Id);
        throw(Name);
        throw(Branch);
        throw(Sex);
        throw(Father_Name);
        throw(Add);
        throw(Year);
    }
}
catch(...)
{
    cout<<"\n\aInvalid Input\n\n"<<"Exception caught\n\n";
}
}
void put_data()
{
    cout<<"Student ID : "<<Id<<endl;
    cout<<"Name : ";puts(Name);
    cout<<"Father Name : ";puts(Father_Name);
    cout<<"Address : ";puts(Add);
    cout<<"Pin Code : "<<pincode<<endl;
    cout<<"Sex : "<<Sex<<endl;
    cout<<"Age : "<<age<<endl;
    cout<<"Branch : "<<Branch<<endl;
    cout<<"Year : "<<Year<<endl;
    cout<<"Sec : "<<Sec<<endl;
    cout<<"CONTACT INFO : "<<endl;
    cout<<"Mobile Number : "<<Mob_no<<"\t"<<"Phone Number : "<<Phone_no<<endl;
}
};
int main()
{
    fstream file;
    fstream file1;
    fstream file2;
    student obj;
    int num,f=0,h,g,n;
    char var[15];
    cout<<"\t\tWELCOME TO THE STUDENT DATABASE MANAGEMENT SYSTEM\n\n";
    do
    {
        cout<<"\nWhat you wish to do !!!\n";
        cout<<"1. Add New Record\n";
        cout<<"2. Search Record\n";
        cout<<"3. View All Records\n";
        cout<<"4. Modify Record\n";
        cout<<"5. Delete Record\n";
        cout<<"6. EXIT\n\n";
        cout<<"Enter your choice\n";
        cin>>num;
        switch(num)
        {
        case 1:
            system("CLS");
            file.open("Data.DAT",ios::in | ios::out | ios::ate | ios::app | ios::binary);
            obj.get_data();
            file.write((char *) & obj , sizeof(obj));
            cout<<"\nYour Data has been Successfully Uploaded in File\n\n";
            file.close();
            break;

        case 2:
            system("CLS");
            file.open("Data.DAT",ios::in | ios::out | ios::ate | ios::app | ios::binary);
            cout<<"Enter Student ID for which you want information\n";
            cin>>var;
            file.seekg(0);
            while(file.read((char *) & obj , sizeof(obj)))
            {
                f=0;
                if(strcmp(obj.Id,var)==0)
                {
                    obj.put_data();
                    f=1;
                    cout<<endl;
                    break;
                }
            }
            if(f!=1)
            {
                cout<<"\a\nYou have entered Wrong Id\n\n";
            }
            file.close();
            break;

        case 3:
            system("CLS");
            file.open("Data.DAT",ios::in | ios::binary);
            while(file.read((char *) & obj , sizeof(obj)))
            {
                obj.put_data();
                cout<<endl;
            }

            file.close();
            break;

        case 4:
            system("CLS");
            file.open("Data.DAT",ios::in | ios::out | ios::ate | ios::binary);
            file2.open("Data2.DAT",ios::out | ios::app | ios::binary);
            cout<<"Enter the Id for which Modification is to be Done\n";
            cin>>var;
            file.seekg(0,ios::beg);
            file2.seekg(0,ios::beg);
            while(file.read((char *) & obj , sizeof(obj)))
            {
                h = 0;
                if(strcmp(obj.Id,var)==0)
                {
                    h=1;
                    obj.get_data();
                    file2.write((char *) & obj , sizeof(obj));
                    file.seekg(0,ios::beg);
                    while(file.read((char *) & obj , sizeof(obj)))
                    {
                        if(strcmp(obj.Id,var)!=0)
                        {
                           file2.write((char *) & obj , sizeof(obj));
                        }
                    }
                    file.close();
                    file2.close();
                    cout<<"\nYour Record has been successfully Modified\n\n";
                    remove("Data.DAT");
                    rename("Data2.DAT","Data.DAT");
                }
            }
            if(h!=1)
               {
                   cout<<"\a\nRecord not Found \n\n";
               }
            file.close();
            break;

        case 5:
            system("CLS");
            file.open("Data.DAT",ios::in | ios::binary);
            file1.open("Data1.DAT",ios::out | ios::binary);
            cout<<"Enter the Id for which Deletion is to be Done\n";
            cin>>var;
            file.seekg(0,ios::beg);
            file1.seekg(0,ios::beg);
            while(file.read((char *) & obj , sizeof(obj)))
            {
                g=0;
                if(strcmp(obj.Id,var)==0)
                {
                    g=1;
                    file.seekg(0,ios::beg);
                    while(file.read((char *) & obj , sizeof(obj)))
                    {
                        if(strcmp(obj.Id,var)!=0)
                        {
                           file1.write((char *) & obj , sizeof(obj));
                        }
                    }
                    file.close();
                    file1.close();
                    cout<<"\nYour Record has been successfully Deleted\n\n";
                    remove("Data.DAT");
                    rename("Data1.DAT","Data.DAT");
                }
            }
            if(g!=1)
            {
                cout<<"\aRecord Not Found\n\n";
            }
            break;

        case 6:
            system("CLS");
            cout<<"\t\t\tTHANK YOU\n"<<"Projet submitted by:\n"<<"\nTARUN GOYAL(14CSU219)\nSUNIL THAKUR(14CSU215)\nTUSHAR DUREJA(14CSU211)\n";
            exit(1);

        default:
            system("CLS");
            cout<<"\aYou have entered WRONG choice\n\n";
            cout<<"Enter Your CHOICE again\n\n";
        }
    }while(num<6 || num>=6);
return 0;
}
