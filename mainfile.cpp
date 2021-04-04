#include<iostream>
#include"fstream"               //For File Handling
#include"windows.h"             //for changing colors and clear screen
#include"stdio.h"               //Use for gets() function to taking all input from user
using namespace std;
struct Mobile                  //Struct for storing data\t
{
    char mName[25];         //Get Mobile Name
    char IMEI[15];     //Get Seller ID Card Numer
    float mPrice;           //Get Price
    char searchM[25];       //variable for search
};

void banner()
{
    system("Color 9");
    cout<<"\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t\t\t++                                                     ++"<<endl;
    cout<<"\t\t\t++                 PPPPPPp    FFFFFFFF                 ++"<<endl;
    cout<<"\t\t\t++                 PP    PP   FF                       ++"<<endl;
    cout<<"\t\t\t++                 PPPPPP     FFFFFFFF                 ++"<<endl;
    cout<<"\t\t\t++                 PP         FF                       ++"<<endl;
    cout<<"\t\t\t++                 PP         FF                       ++"<<endl;
    cout<<"\t\t\t++                                                     ++"<<endl;
    cout<<"\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t\t\t++                                                     ++"<<endl;
    cout<<"\t\t\t++            Final Project:~  MOBILE SHOP             ++"<<endl;
    cout<<"\t\t\t++                Muhammad Zubair Javed                ++"<<endl;
    cout<<"\t\t\t++                   (MCSM-F20-032)                    ++"<<endl;
    cout<<"\t\t\t++                                                     ++"<<endl;
    cout<<"\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t\t\t";
    Sleep(3000);
    system("CLS");

}
void pName()
{
    cout<<endl;
    system("Color 0A");
    cout<<"\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t\t\t++                                                     ++"<<endl;
    cout<<"\t\t\t++               M o b i l e   S h o p                 ++"<<endl;
    cout<<"\t\t\t++                                                     ++"<<endl;
    cout<<"\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
void menu()
{
    cout<<"\t\t\t Menu:~"<<endl;
    cout<<"\t\t\t\t1. Add New Mobile"<<endl;
    cout<<"\t\t\t\t2. Search Mobile"<<endl;
    cout<<"\t\t\t\t3. Modify/Update Mobile"<<endl;
    cout<<"\t\t\t\t4. Display All Mobile"<<endl;
    cout<<"\t\t\t\t5. Search IMEI Number"<<endl;
    cout<<"\t\t\t\t6. Exit"<<endl;

}

//Loading Function for realistic things
void loading()
{
    int speed = 200;
    cout<<"\t\t\t";
    for (int i = 0; i < 58; i++)
    {
        Sleep(speed);
        cout<<".";
        speed-=3;
    }
    cout<<endl;
    
}

int main(){

	banner();       //Showing PF Banner, My Name and Roll Number 
    Mobile M;
    ifstream fileOut("file.txt");              //Read from Files
    ofstream fileIn("file.txt");               //Write on Files
            
    while(true)
    {
        pName();        //Showing Project Name
        menu();         //Display Menu

        char getD[150];

        if(!fileIn){
            cout<<"Creating File.Please Wait..."<<endl;
            Sleep(2000);
            cout<<"File Created Successfully..."<<endl;
            Sleep(2000);
            system("CLS");
            // cout<<"Error!"<<endl;
            ofstream file("file.txt");
            if (!file)
            {
                cerr<<"File Still Not Created !!!!!"<<endl;
                exit(1);
            }
            
        }

        input:
            int choice;
            cout<<endl<<"\t\t\tEnter your choice: ";
            cin>>choice;
            switch(choice)
            {
            case 1:         //Add Mobile
                char op;
                do{
                    cout<<"\t\t\tEnter Mobile Name: ";                          cin>>M.mName;
                    cout<<"\t\t\tEnter Mobile IMEI: ";         cin>>M.IMEI;
                    cout<<"\t\t\tEnter Mobile Prize:";                           cin>>M.mPrice;
                    fileIn<<M.mName<<"\t"<<M.IMEI<<"\t"<<M.mPrice<<endl;
                    cout<<"\t\t\t\tMobile Added!"<<endl;
                    cout<<"\t\t\tAdd New [y/n] ? ";                             cin>>op;
                }while(op=='y' || op=='Y');
                fileIn.close();
                break;
            case 2:
                //
                break;
            case 3:

                break;
            case 4:
                cout<<fileOut.eof()<<endl;
            	
                cout<<"\t\t\tMobile\t   IMEI\t\tPrice"<<endl;
                while (!fileOut.eof())
                {
                    fileOut.getline(getD, 150);
                    cout<<"\t\t\t"<<getD<<endl;
                }
            fileOut.close();
                break;
            case 5:
    //            cout<<"\t\t\tEnter Mobile Name for search: ";                   cin>>M.searchM;
                
                break;
            case 6:
                exit(0);
                break;
            default:
                cout<<"\n\t\t\tEnter Wrong choice, Please select valid choice!";
                goto input;
            }
    }
    cout<<"Thank You!"<<endl;  

}
