#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

class employee
 {
 public:
    int eid;
    char name [20];
    char lname [20];
    float sal;
 public:
    char post[20];
 void accept()
  {
    cout<<endl<<"Enter employee id        : ";
    cin>>eid;
    cout<<endl<<"Enter first name         : ";
    cin>>name;
    cout<<endl<<"Enter last name          : ";
    cin>>lname;
    cout<<endl<<"Enter salary withdrawn   : ";
    cin>>sal;
    cout<<endl<<"Enter post of employee   : ";
    cin>>post;
  }

 void display()
  {
    cout<<endl<<"Employee-ID              : "<<eid;
    cout<<endl<<"First name               : "<<name;
    cout<<endl<<"Last name                : "<<lname;
    cout<<endl<<"Salary withdrawn         : "<<sal;
    cout<<endl<<"Post of employee         : "<<post;
  }
 };
///=====================================================end of class==========================================================
employee obj;                       /// THIS IS GLOBAL OBJECT...
    void addnewemployee()
     {
      obj.accept();
      fstream wr;                     // wr is object of fstream.
      wr.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt",ios::app);
      wr.write((char*)&obj,sizeof(obj));
      cout<<endl<<"--------------------------Data Written Successfully---------------------------\n";
     }
///============================================== Show functions =============================================================
    void showallemployee()
     {
       cout<<endl<<"_____________________________________________________________________________\n";
       fstream rd;
       rd.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt",ios::in);
       rd.seekg(0,ios::end);           /// Now cursor at end
       int n=rd.tellg();               /// n=total number of data present
       n=n/sizeof(obj);
       rd.seekg(0,ios::beg);
       for(int i=1;i<=n;i++)
        {
           rd.read((char*)&obj,sizeof(obj));
           obj.display();
           cout<<endl<<"_____________________________________________________________________________\n";
        }
     }
///===================================================== search functions ====================================================
    void searchbyeid()
     {
       int eid2;
       cout<<endl<<"Enter employee-id        : ";
       cin>>eid2;
       fstream rd;
       rd.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt",ios::in);
       rd.seekg(0,ios::end);
       int n2=rd.tellg();
       n2=n2/sizeof(obj);
       rd.seekg(0,ios::beg);
       for (int i=1;i<=n2;i++)
        {
           rd.read((char*)&obj,sizeof(obj));
           if (eid2==obj.eid)
            {
                obj.display();
                cout<<endl<<"_______________________________________________________________________________\n";
            }
        }
      }
    void searchbyname()
      {
         char name2[20];
         char lname2[20];
         cout<<endl<<"Enter name               : ";
         cin>>name2;
         cout<<endl<<"Enter last name          : ";
         cin>>lname2;
         fstream rd;
         rd.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt",ios::in);
         rd.seekg(0,ios::end);
         int n3=rd.tellg();
         n3=n3/sizeof(obj);
         rd.seekg(0,ios::beg);
         for (int i=1;i<=n3;i++)
          {
             rd.read((char*)&obj,sizeof(obj));
             if(stricmp(name2,obj.name)==0&&stricmp(lname2,obj.lname)==0)
              {
                 obj.display();
                 cout<<endl<<"______________________________________________________________________________\n";
              }
          }
     }
    void searchbypost()
      {
          char post2[20];
          cout<<endl<<"Enter designation        : ";
          cin>>post2;
          fstream rd;
          rd.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt",ios::in);
          rd.seekg(0,ios::end);
          int n4=rd.tellg();
          n4=n4/sizeof(obj);
          rd.seekg(0,ios::beg);
          for(int i=1;i<=n4;i++)
          {
              rd.read((char*)&obj,sizeof(obj));
              if ((stricmp(post2,obj.post)==0))
              {
                  obj.display();
                  cout<<endl<<"_____________________________________________________________________________\n";
              }
          }
      }
///====================================================== Remove an employee==================================================
    void removeemployeebyeid()
      {
          int eid3;
          cout<<endl<<"Enter employee id        : ";
          cin>>eid3;
          fstream rd;
          fstream wr;    /// or we can write it as fstream wr,rd
          rd.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt",ios::in);
          rd.seekg(0,ios::end);
          int n5=rd.tellg();
          n5=n5/sizeof(obj);
          rd.seekg(0,ios::beg);
          wr.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\temp.txt",ios::out);
          for (int i=1;i<=n5;i++)
          {
              rd.read((char*)&obj,sizeof(obj));
              if (eid3==obj.eid)
               {
                 cout<<endl<<"--------------------------Employee have been removed---------------------------";
               }
              else
               {
                  wr.write((char*)&obj,sizeof(obj));
               }
          }
          rd.close();
          wr.close();
          remove("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt");
          rename("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\temp.txt","C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt");
      }
///====================================================== Update employee ====================================================
    void updateemployee()
      {
          int eid4;
          cout<<"Enter employee id you want to update : ";
          cin>>eid4;
          fstream rd,wr;
          rd.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt",ios::in);
          rd.seekg(0,ios::end);
          int n6=rd.tellg();
          n6=n6/sizeof(obj);
          rd.seekg(0,ios::beg);
          wr.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\temp.txt",ios::out);
          for(int i=1;i<=n6;i++)
            {
              rd.read((char*)&obj,sizeof(obj));
              if (eid4==obj.eid)
               {
                  obj.accept();
                  wr.write((char*)&obj,sizeof(obj));
               }
              else
               {
                  wr.write((char*)&obj,sizeof(obj));
               }
            }
          rd.close();
          wr.close();
          remove("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt");
          rename("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\temp.txt","C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt");
      }
///======================================================new class salary=====================================================
    class salary
     {
         public:
         int eid5;
         char month[20];
         char year[4];
         float sal2;
         int c;

         void accept()
           {
               cout<<endl<<"Enter employee id        : ";
               cin>>eid5;
               fstream rd;
               rd.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt",ios::in);
               rd.seekg(0,ios::end);
               int n7=rd.tellg();
               n7=n7/sizeof(obj);
               rd.seekg(0,ios::beg);
               for(int i=1;i<=n7;i++)
                {
                  rd.read((char*)&obj,sizeof(obj));
                  if (eid5==obj.eid)
                    {
                      obj.display();
                    }
                }
               cout<<endl<<"\nEnter salary dissipated  : ";
               cin>>sal2;
               cout<<endl<<"Enter month              : ";
               cin>>month;
               cout<<endl<<"Enter year               : ";
               cin>>year;
            }

         void display()
           {
               cout<<endl<<eid5;
               for (int i=1;i<=(strlen("Employee id")-4);i++)
                 {
                   cout<<" ";
                 }
               float c;                                  /*Creating on my own*/
               fstream rd;
               rd.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\employeedata.txt",ios::in);
               rd.seekg(0,ios::end);
               int n0=rd.tellg();
               rd.seekg(0,ios::beg);
               for (int i=1;i<=n0;i++)
                {
                  rd.read((char*)&obj,sizeof(obj));
                  if (eid5==obj.eid)
                    {
                      c=obj.sal;
                    }
                }

               cout<<"\t"<<sal2<<" of "<<c;
               for (int i=1;i<=(strlen("Salary given")-5);i++)
                 {
                   cout<<" ";
                 }
               cout<<"\t"<<month;
               for (int i=1;i<=(strlen("Month    ")-strlen(month));i++)
                 {
                   cout<<" ";
                 }
               cout<<"\t"<<year;
               for (int i=1;i<=(strlen("Year")-strlen(year));i++)
                 {
                   cout<<" ";
                 }
           }
     };
//================================================end of class================================================================
     salary salobj;

     void salarygiven()
       {
           salobj.accept();
           fstream wr;
           wr.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\salary.txt",ios::app);
           wr.write((char*)&salobj,sizeof(salobj));
           cout<<"Salary given successfully to employee";
       }
     void  salarydisplay()
        {
         char month2[20];
         char year2[20];
         cout<<endl<<"Enter month              : ";
         cin>>month2;
         cout<<endl<<"Enter year               : ";
         cin>>year2;
         fstream rd;
         rd.open("C:\\Users\\Piyush Khanna\\Documents\\C & C++\\Project C++ Employee\\Company-data\\Files\\salary.txt",ios::in);
         rd.seekg(0,ios::end);
         int n8=rd.tellg();
         n8=n8/sizeof(salobj);
         rd.seekg(0,ios::beg);
         cout<<endl<<"Employee id\tSalary given        \tMonth    \tYear\n";
         for(int i=1;i<=n8;i++)
           {
              rd.read((char*)&salobj,sizeof(salobj));
              if(stricmp(salobj.month,month2)==0 && stricmp(salobj.year,year2)==0)
              {
                 salobj.display();
              }
           }
        }
///====================================================== Main Section =======================================================
 main()

  {
     int x,e=1;
     while (e!=0)
     {
         cout<<endl<<"\n                  * * * * * * * * * * * * * * * * * * * * * * * *";
         cout<<endl<<"                  *                    CHOICES                  *";
         cout<<endl<<"                  *                  ===========                *";
         cout<<endl<<"                  *  Enter 1 to add employee                    *";
         cout<<endl<<"                  *  Enter 2 to see all employees               *";
         cout<<endl<<"                  *  Enter 3 to search employee                 *";
         cout<<endl<<"                  *  Enter 4 to remove an employee              *";
         cout<<endl<<"                  *  Enter 5 to edit employee data              *";
         cout<<endl<<"                  *  Enter 6 to dissipate employee salary       *";
         cout<<endl<<"                  *  Enter 7 to see salary status of employees  *";
         cout<<endl<<"                  *  Enter 0 to exit the application            *";
         cout<<endl<<"                  *                                             *";
         cout<<endl<<"                  * * * * * * * * * * * * * * * * * * * * * * * *\n\n";
         cout<<endl<<"Enter your choice number : ";
         cin>>x;
         switch (x)
             {
             case 1:
                {
                    addnewemployee();
                    break;
                }
             case 2:
                {
                    showallemployee();
                    break;
                }
             case 3:
                {
                    int y,e2=1;
                    while (e2!=0)
                    {
                      cout<<endl<<"\n                  * * * * * * * * * * * * * * * * * * * * * * * *";
                      cout<<endl<<"                  *                    CHOICE                   *";
                      cout<<endl<<"                  *                  ==========                 *";
                      cout<<endl<<"                  *  Enter 1 to search employee by employee id  *";
                      cout<<endl<<"                  *  Enter 2 to search employee by name         *";
                      cout<<endl<<"                  *  Enter 3 to search employee by post         *";
                      cout<<endl<<"                  *  Enter 0 to exit the application            *";
                      cout<<endl<<"                  *                                             *";
                      cout<<endl<<"                  * * * * * * * * * * * * * * * * * * * * * * * *\n\n";
                      cout<<endl<<"Enter your choice number for search : ";
                      cin>>y;
                      switch (y)
                        {
                           case 1:
                             {
                                 searchbyeid();
                                 break;
                             }
                           case 2:
                             {
                                 searchbyname();
                                 break;
                             }
                           case 3:
                             {
                                 searchbypost();
                                 break;
                             }
                           case 0:
                             {
                                e2=0;
                                break;
                             }
                        }
                     }
                     cout<<"\n-------------------------------------------------------------------------------";
                     break;
                }
             case 4:
                {
                    removeemployeebyeid();
                    break;
                }
             case 5:
                {
                    updateemployee();
                    break;
                }
             case 6:
                {
                    salarygiven();
                    break;
                }
             case 7:
                {
                    salarydisplay();
                    break;
                }
             case 0:
                {
                    e=0;
                    break;
                }

             }

     }
     cout<<endl<<"Bye Bye !";
  }
