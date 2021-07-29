#include<bits/stdc++.h>
#include<conio.h>
#include<iomanip>
#include<windows.h>
using namespace std;

string FLIGHTS[30][6];//ID, NAME, FROM,TO,DUR,PRICE
string SEAT_MATRIX[30][8][6];

int ID=0;

void CONSTRUCTION()
{
    for (int i=0; i<30; i++)
        for (int j=0; j<8; j++)
            for (int k=0; k<6; k++)
                SEAT_MATRIX[i][j][k]="X";
}

int FIND_NO(string FLIGHT_CODE)
{
    int SERIAL_NO=-1;
    for(int i=0; i<ID; i++)
    {
        if(FLIGHTS[i][0]==FLIGHT_CODE)
        {
            SERIAL_NO=i;
            break;
        }
    }
    return SERIAL_NO;
}


int CHECK_WINDOW(int SERIAL_NO,int Class,string username ,int nos)
{
    //window check kro

    int x,j;
    int choice;
    system("cls");
    cout<<"1. Left Window"<<endl;
    cout<<"2. Right Window"<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            j=0;break;
        }
    case 2:
        {
            j=5;break;
        }

    }

    cout<<"Enter Row no: ";cin>>x;
    if(SEAT_MATRIX[SERIAL_NO][x-1][j]=="X")
    {
        SEAT_MATRIX[SERIAL_NO][x-1][j]=username;
        cout<<"Seat booked! ";
        nos--;

        while(nos!=0)
        {
            j++;
            if(j==6)
                break;
            SEAT_MATRIX[SERIAL_NO][x-1][j]=username;
            cout<<"Adjacent seat booked! "<<endl;
            nos--;
        }

        return 1;
    }

    return -1;

};

int CHECK_AISLE(int SERIAL_NO,int Class,string username,int nos)
{
    //aisle check karo

    int x,y;
    int choice;
    system("cls");
    cout<<"Enter Column no. from 2 to 5: ";cin>>y;
    cout<<"Enter Row no. : ";cin>>x;

    if(SEAT_MATRIX[SERIAL_NO][x-1][y-1]=="X")
    {
        SEAT_MATRIX[SERIAL_NO][x-1][y-1]=username;
        cout<<"Seat booked! ";

        nos--;

        while(nos!=0)
        {
            y++;
            if(y==6)
                break;
            SEAT_MATRIX[SERIAL_NO][x-1][y-1]=username;
            cout<<"Adjacent seat booked! "<<endl;

            nos--;
        }
        return 1;
    }

    return -1;
    //return -1 nahi available ho to
};


int CHECK_VACANCY(int SERIAL_NO,string username,int nos)
{

    int choice,Class;
    cout<<"1. FIRST CLASS\n2. ECONOMY CLASS\n";
    cin>>Class;
    if(Class!=1 && Class!=2)
    {
        cout<<"Invalid Input"<<endl;
        return -1;

    }

    int flag=-1;

    HERE:
    cout<<"1. WINDOW SEAT\n2. AISLE SEAT\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            flag=CHECK_WINDOW(SERIAL_NO,Class,username,nos);
            break;
        }
    case 2:
        {
            flag=CHECK_AISLE(SERIAL_NO,Class,username,nos);
            break;
        }
    }

    if(flag==-1)
    {
        cout<<"Seat not available";
        goto HERE;

    }
}



void BOOK_SEAT(string usernameName,string phone,string FLIGHT_CODE)
{
    system("cls");
    cout<<"\t\tSEAT BOOKING WINDOW\n\n";

    int nos;
    cout<<"Number of seats desired: ";cin>>nos;

    string TICKET_NO="";

    int SERIAL_NO=FIND_NO(FLIGHT_CODE);

    CHECK_VACANCY(SERIAL_NO,usernameName,nos);

    TICKET_NO=FLIGHT_CODE+phone;
    cout<<"TIKCET NUMBER IS:  "<<TICKET_NO<<"\n";

    _getche();

}


void TICKET_DETAILS(string usernameName,string phone,string flight)
{
    system("cls");
    cout<<"\t\tUser Ticket Menu\n\n";
    string TICKET_NO=flight+phone[5];

    //check class

    string usernameClass="Economy Class";

    int SERIAL_NO=FIND_NO(flight);
    for (int j=0; j<3; j++)
        for (int k=0; k<6; k++)
        {
            if(SEAT_MATRIX[SERIAL_NO][j][k]==usernameName)
            {
                usernameClass="First Class";
                break;
            }
        }
    cout<<"Showing Ticket of "<<usernameName<<"\n";
    cout<<"Ticket No.: "<<TICKET_NO<<"\n";
    cout<<"\nUser Name: "<<usernameName<<"\n";
    cout<<"\nUser phone No.: "<<phone<<"\n";
    cout<<"\nFlight No.: " <<flight<<"\n";
    cout<<"\nClass: " <<usernameClass<<"\n";

    _getche();
}


void SCHEDULE(string flight)
{
    system("cls");
    cout<<"Flight Arrival and Departure query\n\n";

    int SERIAL_NO=FIND_NO(flight);

    if(SERIAL_NO==-1)
    {
        cout<<"Flight doesn't exist!\n";

    }
    else
    {
        cout<<left<<setw(20)<<"Flight No";
        cout<<left<<setw(20)<<"Flight Name";
        cout<<left<<setw(20)<<"Flight From";
        cout<<left<<setw(20)<<"Flight Destination";
        cout<<left<<setw(20)<<"Flight Time";
        cout<<left<<setw(20)<<"Flight Amount\n";

        cout<<left<<setw(20)<<FLIGHTS[SERIAL_NO][0];
        cout<<left<<setw(20)<<FLIGHTS[SERIAL_NO][1];
        cout<<left<<setw(20)<<FLIGHTS[SERIAL_NO][2];
        cout<<left<<setw(20)<<FLIGHTS[SERIAL_NO][3];
        cout<<left<<setw(20)<<FLIGHTS[SERIAL_NO][4];
        cout<<left<<setw(20)<<FLIGHTS[SERIAL_NO][5]<<"\n";


    }
    _getche();
}


void APPEND()
{
    system("cls");
    cout<<"\t\tFLIGHT APPEND WINDOW\n\n";

    if(ID>=30)
    {
        cout<<"FLIGHT LIST FULL !\n";

    }
    else
    {
        cout<<"FLIGHT NUMBER: ";cin>>FLIGHTS[ID][0];
        cout<<"FLIGHT NAME: ";cin>>FLIGHTS[ID][1];
        cout<<"FROM: ";cin>>FLIGHTS[ID][2];
        cout<<"TO: ";cin>>FLIGHTS[ID][3];
        cout<<"FLIGHT DURATION: ";cin>>FLIGHTS[ID][4];
        cout<<"PRICE: ";cin>>FLIGHTS[ID][5];
        cout<<"FLIGHT ADDED !\n";

        ID++;

        _getche();

    }
}

void UPDATE()
{
    system("cls");
    cout<<"\t\tUPDATE FLIGHT WINODW\n\n";

    string FLIGHT_CODE="";

    cout<<"FLIGHT CODE: ";
    cin.ignore();
    getline(cin, FLIGHT_CODE);
    int SERIAL_NO= FIND_NO(FLIGHT_CODE);

    if(SERIAL_NO==-1)
    {
        cout<<"Flight doesn't exist!\n";

    }
    else
    {
        cout<<"FLIGHT NO: ";cin.ignore();getline(cin, FLIGHTS[SERIAL_NO][0]);
        cout<<"FLIGHT NAME: ";cin.ignore();getline(cin, FLIGHTS[SERIAL_NO][1]);
        cout<<"FROM: ";cin.ignore();getline(cin, FLIGHTS[SERIAL_NO][2]);
        cout<<"TO: ";cin.ignore();getline(cin, FLIGHTS[SERIAL_NO][3]);
        cout<<"DURATION: ";cin.ignore();getline(cin, FLIGHTS[SERIAL_NO][4]);
        cout<<"PRICE: ";cin.ignore();getline(cin, FLIGHTS[SERIAL_NO][5]);

    }
}

void REMOVE()
{
    system("cls");
    cout<<"\t\tREMOVE FLIGHT WINDOW\n\n";

    string FLIGHT_CODE="";
    cout<<"FLIGHT CODE: ";cin.ignore();getline(cin, FLIGHT_CODE);
    int SERIAL_NO=FIND_NO(FLIGHT_CODE);

    if(SERIAL_NO==-1)
    {
        cout<<"Flight doesn't exist!\n";

    }
    else
    {

        while(SERIAL_NO!=ID)
        {
            FLIGHTS[SERIAL_NO][0]=FLIGHTS[SERIAL_NO+1][0];
            FLIGHTS[SERIAL_NO][1]=FLIGHTS[SERIAL_NO+1][1];
            FLIGHTS[SERIAL_NO][2]=FLIGHTS[SERIAL_NO+1][2];
            FLIGHTS[SERIAL_NO][3]=FLIGHTS[SERIAL_NO+1][3];
            FLIGHTS[SERIAL_NO][4]=FLIGHTS[SERIAL_NO+1][4];
            FLIGHTS[SERIAL_NO][5]=FLIGHTS[SERIAL_NO+1][5];

            for(int i=0; i<8; i++)
                for(int j=0; j<6; j++)
                    SEAT_MATRIX[SERIAL_NO][i][j]=SEAT_MATRIX[SERIAL_NO+1][i][j];
            SERIAL_NO++;
        }
        ID--;

    }
}


void DETAILS()
{
    system("cls");
    cout<<"\t\t\t\tFLIGHT DETAILS\n\n";

    cout<<left<<setw(20)<<"FLIGHT NO";
    cout<<left<<setw(20)<<"FLIGHT NAME";
    cout<<left<<setw(20)<<"FROM";
    cout<<left<<setw(20)<<"TO";
    cout<<left<<setw(20)<<"DURATION";
    cout<<left<<setw(20)<<"PRICE\n";

    cout<<endl;


    for(int i=0; i<ID; i++)
    {
        cout<<left<<setw(20)<<FLIGHTS[i][0];
        cout<<left<<setw(20)<<FLIGHTS[i][1];
        cout<<left<<setw(20)<<FLIGHTS[i][2];
        cout<<left<<setw(20)<<FLIGHTS[i][3];
        cout<<left<<setw(20)<<FLIGHTS[i][4];
        cout<<left<<setw(20)<<FLIGHTS[i][5]<<"\n";
    }

    _getche();

}

void PRINT_SEATS(string flight)
{
    system("cls");
    cout<<"\t\tSEAT MATRIX\n\n";

    int SERIAL_NO=FIND_NO(flight);
    if(SERIAL_NO==-1)
    {
        cout<<"Flight doesn't exist!\n";

    }
    else
    {

        for (int i=0;i<8; i++)
        {
            if(i==0)
                cout<<setw(10)<<"FIRST CLASS \n";
            else if(i==3)
                cout<<setw(10)<<"ECO CLASS \n";

            cout<<setw(2)<<(i+1)<<"  ";
            cout<<setw(10)<<SEAT_MATRIX[SERIAL_NO][i][0];
            cout<<setw(10)<<SEAT_MATRIX[SERIAL_NO][i][1];
            cout<<setw(10)<<SEAT_MATRIX[SERIAL_NO][i][2];
            cout<<"|| ||";
            cout<<setw(10)<<SEAT_MATRIX[SERIAL_NO][i][3];
            cout<<setw(10)<<SEAT_MATRIX[SERIAL_NO][i][4];
            cout<<setw(10)<<SEAT_MATRIX[SERIAL_NO][i][5]<<"\n";
        }

        cout<<endl<<endl;
        cout<<"NOTE: 'X' represent Empty Seats..."<<endl;

    }
    _getche();
}


void FLIGHT_SEAT_MATRIX()
{
    string FLIGHT_CODE="";
    cout<<"\n\nFLIGHT NO: ";cin.ignore();getline(cin, FLIGHT_CODE);
    PRINT_SEATS(FLIGHT_CODE);

}
////////////////////////////////////////////////////////////////////////////////////

void ADMIN()
{
    system("cls");

    string keycode ="";
    cout<<"Enter keycode: ";
    cin.ignore();
    getline(cin,keycode);

    if(keycode!="admin")
    {
        cout<<"Wrong Password\n";

        return;
    }

    while(1)
    {
        system("cls");

        cout<<"\t\tADMIN MENU\n\n"<<"1. APPEND \n"<<"2. UPDATE\n"<<"3. REMOVE\n"<<"4. FLIGHT DETAILS\n"<<"5. FLIGHT SEAT MATRIX\n"<<"6. SIGN OUT\n";

        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
            APPEND();
            break;
        case 2:
            UPDATE();
            break;
        case 3:
            REMOVE();
            break;
        case 4:
            DETAILS();
            break;
        case 5:
        {
            FLIGHT_SEAT_MATRIX();
            break;
        }
        case 6:
        {
            cout<<"Are you sure? (y/n): ";
            char exit;
            cin>>exit;
            if(exit=='y' || exit=='Y')
                return;
            break;
        }
        default:
            cout<<"Wrong input\n";
        }
    }
}


void USER()
{
    system("cls");
    string username ="";
    string phone="";


    cout<<"USERNAME : ";cin>>username;
    cout<<"PHONE NO.: ";cin>>phone;
    string flight="";
    cout<<"FLIGHT NO.: ";cin>>flight;


    while(1)
    {
        system("cls");

        cout<<"\t\t\t\tUSER MENU\n\n"<<"1. BOOK SEAT\n"<<"2. TICKET DETAILS\n"<<"3. FLIGHT SCHEDULE\n"<<"4. SEAT MATRIX\n"<<"5. SIGN OUT\n";

        int choice;
        cin>>choice;
        switch (choice)
        {
            case 1:
            {
                if(flight!="")
                {
                    BOOK_SEAT(username, phone,flight);
                }
                else
                {
                     cout<<"Invalid flight no."<<"\n";

                }
                break;
            }
            case 2:
            {
                TICKET_DETAILS(username, phone, flight);
                break;
            }
            case 3:
            {
                SCHEDULE(flight);
                break;
            }
            case 4:
            {
                PRINT_SEATS(flight);
                break;
            }
            case 5:
            {
                cout<<"Are you sure? (y/n): ";
                char exit;
                cin>>exit;
                if(exit=='y' || exit=='Y')
                    return;
                break;
            }
            default:
                cout<<"Wrong input\n";
        }
    }
}

int main()
{

    system("title INDIAN AIRLINES");
    CONSTRUCTION();
    system("Color 0D");
    while(1)
    {
        system("cls");
        cout<<"\t\t\t\t\tRESERVATION SYSTEM\n\n";
        cout<<"SIGN IN MENU\n\n";
        cout<<"1. ADMIN\n";
        cout<<"2. USER\n";
        cout<<"3. Exit Program\n";
        int choice;
        cin>>choice;

        switch(choice)
        {
        case 1:
            {
                ADMIN();break;
            }
        case 2:
            {
                USER();break;
            }
        case 3:
            {
                cout << "Exit the program? (y/n): ";
                char exit;
                cin>>exit;
                if(exit=='y' || exit=='Y')
                return 0;

            }
        }
    }

    return 0;
}

