#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
using namespace std;

int ch;       // Global variable for choicing to go back

class Sign{  // Login class 
    private:
    string pass;  // variable for storing password
    public:
    Sign(): pass("0"){} // contsructor call
    int intro(){
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tWELCOME TO FOOD MANAGEMENT SYSTEM"<<endl;
    cout<<"\t\t\t\t\t---------------------------------"<<endl;
    while(true){
        cout<<"\t\t\t\t\tEnter your Password : ";
        cin>>pass;
        if (pass != "admin"){
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tWELCOME TO FOOD MANAGEMENT SYSTEM"<<endl;
            cout<<"\t\t\t\t\t---------------------------------"<<endl;
            cout<<"\n\t\t\t\t\tWRONG PASSWORD !"<<endl;
        }
        if(pass == "admin"){
            system("cls");
            break;
        }
    }
    return 1;
    }
};   // Login class end

class User{ // User(Base) class
    public:
    int id;
    char firstname[50],lastname[50];
    float sale;

    User(): id(0),sale(0){}  // constructor call

    void input(){ // Create a user function
        system("cls");
        cout<<"\n\n\t\t\t\t\t       FOOD MANAGEMENT SYSTEM"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t Create User :"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;

        ofstream out("user.txt",ios::app); // creating out name file to store user data

        cout<<"\t\t\t\t\tUser ID : ";
        cin>>id;

        out<<id<<" ";

        cout<<"\t\t\t\t\tEnter First name : ";
        cin>>firstname;

        out<<firstname<<" ";

        cout<<"\t\t\t\t\tEnter Last name : ";
        cin>>lastname;

        out<<lastname<<" ";

        sale = 0;
        out<<sale<<endl;

        output(); // show function call

        out.close(); // closing file
    }

    void output(){  // Show user function
        system("cls");
    	int t; // Variable of Total

        ifstream in("user.txt",ios::app); // creating in name file to show user data

        cout<<"\n\n\t\t\t\t\t       FOOD MANAGEMENT SYSTEM"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t Show User :"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;  
        while(in>>id>>firstname>>lastname>>sale){
            cout<<"\t\t\t\t\tId : "<<id<<endl;
            cout<<"\t\t\t\t\tFirst name : "<<firstname<<endl;
            cout<<"\t\t\t\t\tLast name : "<<lastname<<endl;
            cout<<"\t\t\t\t\tSales of "<<sale<<" according to 10% commission will be : "<<sale*0.1<<endl;
            cout<<"\t\t\t\t\t------------------------------------------------------------------"<<endl;
            t+=sale;
        }
        cout<<"\t\t\t\t\tTotal Sales of "<<t<<" according to 10% Total commission will be : "<<t*0.1<<endl;
        cout<<"\t\t\t\t\t-----------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t\tEnter 0 to go back : ";
        cin>>ch;
        if(ch == 0){
            system("cls");
        }
        in.close();
    }

    void del(){  //Delete user function
        system("cls");
    	int n;  // Variable of Selecting User id

        cout<<"\n\n\t\t\t\t\t       FOOD MANAGEMENT SYSTEM"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t Delete User :"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
    	cout<<"\t\t\t\t\tEnter Id to Delete: ";
    	cin>>n;

    	ifstream d;
        d.open("user.txt");  // Opening old file
    	ofstream e;
        e.open("new.txt");   // Opening new file

    	while(d>>id>>firstname>>lastname>>sale){
    		if(id != n){ 
                e<<id<<" ";  

				e<<firstname<<" ";

				e<<lastname<<" ";

				e<<sale<<endl;
			}else{
                cout<<"\t\t\t\t\tDeleted User:"<<endl;
                cout<<"\t\t\t\t\tId : "<<id<<endl;
                cout<<"\t\t\t\t\tFirst name : "<<firstname<<endl;
                cout<<"\t\t\t\t\tlast name : "<<lastname<<endl;
                cout<<"\t\t\t\t\tSale : "<<sale<<endl;
                cout<<"\t\t\t\t\tThe User has been Deleted successfully"<<endl;
			}
		}

        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\tEnter 0 to go back : ";
        cin>>ch;
        if(ch == 0){
            system("cls");
        }
		e.close();  // closing new file
		d.close();  // closing old file
    	remove("user.txt");  // Removing old File
		rename("new.txt","user.txt"); // Renameing new File
    }

    void update(){  // Update User function
        system("cls");
    	int n;  // Variable of Selecting User id

        cout<<"\n\n\t\t\t\t\t       FOOD MANAGEMENT SYSTEM"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t Update User :"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
    	cout<<"\t\t\t\t\tEnter Id to Update: ";
    	cin>>n;

    	ifstream d;
        d.open("user.txt"); // Opening old file
    	ofstream e;
        e.open("new.txt");  // Opening new file

    	while(d>>id>>firstname>>lastname>>sale){
    		if(id != n){
				e<<id<<" ";

				e<<firstname<<" ";

				e<<lastname<<" ";

				e<<sale<<endl;
			}else{
                cout<<"\t\t\t\t\tUpadate to be User"<<endl;
                cout<<"\t\t\t\t\tId : "<<id<<endl;
                cout<<"\t\t\t\t\tFirst name : "<<firstname<<endl;
                cout<<"\t\t\t\t\tLast name : "<<lastname<<endl;
                cout<<"\t\t\t\t\tSale : "<<sale<<endl;
                cout<<"\t\t\t\t\t---------------------------------"<<endl;
				cout<<"\t\t\t\t\tEnter ID same/change : ";
                cin>>id;

                e<<id<<" ";

                cout<<"\t\t\t\t\tEnter First Name : ";
                cin>>firstname;

                e<<firstname<<" ";

                cout<<"\t\t\t\t\tEnter last name : ";
                cin>>lastname;

                e<<lastname<<" ";

                sale = 0;
                e<<sale<<endl;

				cout<<"\t\t\t\t\tThe User has been Updated successfully"<<endl;
			}
		}

        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\tEnter 0 to go back : ";
        cin>>ch;
        if(ch == 0){
            system("cls");
        }
		e.close(); // closing new file
		d.close(); // closing old file
    	remove("user.txt"); // Removing old File
		rename("new.txt","user.txt"); // Renameing new File
    }
};

class Food: public virtual User{ // Food(child) Class Derived from User(Base) class
    public:
    int quantity; // Variable for store quantity
    Food(): User(),quantity(0){} // default constructor call

    void input(){  // Food storing function
        system("cls");
        cout<<"\n\n\t\t\t\t\t       FOOD MANAGEMENT SYSTEM"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t Create Food :"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;

        ofstream out("food.txt",ios::app); // creating out name file to store food

        cout<<"\t\t\t\t\tEnter ID : ";
        cin>>id;

        out<<id<<" ";

        cout<<"\t\t\t\t\tFood Brand/type name : ";
        cin>>firstname;

        out<<firstname<<" ";

        cout<<"\t\t\t\t\tFood name : ";
        cin>>lastname;

        out<<lastname<<" ";

        cout<<"\t\t\t\t\tEnter Food Quantity : ";
        cin>>quantity;

        out<<quantity<<" ";

        cout<<"\t\t\t\t\tEnter Food price per Item : ";
        cin>>sale;

        out<<sale<<endl;

        output(); // show function call

        out.close(); // closing file
    }

    void output(){ // Food Showing function
        system("cls");
    	int t;

        ifstream in("food.txt",ios::app); // creating in name file to store food data

        cout<<"\n\n\t\t\t\t\t       FOOD MANAGEMENT SYSTEM"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t Show Food :"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;  
        while(in>>id>>firstname>>lastname>>quantity>>sale){
            cout<<"\t\t\t\t\tId : "<<id<<endl;
            cout<<"\t\t\t\t\tFood Brand/type name : "<<firstname<<endl;
            cout<<"\t\t\t\t\tFood name : "<<lastname<<endl;
            cout<<"\t\t\t\t\tFood Quantity : "<<quantity<<endl;
            cout<<"\t\t\t\t\tFood price per Item: "<<sale<<endl;
            cout<<"\t\t\t\t\t---------------------------------"<<endl;
        }

        cout<<"\t\t\t\t\tEnter 0 to go back : ";
        cin>>ch;
        if(ch == 0){
            system("cls");
        }
        in.close(); // closing file
    }

    void del(){  // Deleting food function
        system("cls");
    	int n; // Variable of Selecting User id

        cout<<"\n\n\t\t\t\t\t       FOOD MANAGEMENT SYSTEM"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t Delete Food :"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
    	cout<<"\t\t\t\t\tEnter Id to Delete: ";
    	cin>>n;

    	ifstream d;
        d.open("food.txt"); // Opening old file
    	ofstream e;
        e.open("new.txt"); // Opening new file

    	while(d>>id>>firstname>>lastname>>quantity>>sale){
    		if(id != n){
                e<<id<<" ";

				e<<firstname<<" ";

                e<<lastname<<" ";

				e<<quantity<<" ";

				e<<sale<<endl;
			}else{
                cout<<"\t\t\t\t\tDeleted Food:"<<endl;
                cout<<"\t\t\t\t\tId : "<<id<<endl;
                cout<<"\t\t\t\t\tFood Brand/type name : "<<firstname<<endl;
                cout<<"\t\t\t\t\tFood name : "<<lastname<<endl;
                cout<<"\t\t\t\t\tFood Quantity : "<<quantity<<endl;
                cout<<"\t\t\t\t\tFood price per Item : "<<sale<<endl;
                cout<<"\t\t\t\t\tThe Food has been Deleted successfully"<<endl;
			}
		}
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\tEnter 0 to go back : ";
        cin>>ch;
        if(ch == 0){
            system("cls");
        }
		e.close(); // closing new file
		d.close(); // closing old file
    	remove("food.txt"); // Removing old File
		rename("new.txt","food.txt"); // Renameing new File
    }

    void update(){ // Updating Food function
        system("cls");
    	int n; // Variable of Selecting User id
        cout<<"\n\n\t\t\t\t\t       FOOD MANAGEMENT SYSTEM"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t Update Food :"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
    	cout<<"\t\t\t\t\tEnter Id to Update: ";
    	cin>>n;

    	ifstream d; // Opening old file
        d.open("food.txt");
    	ofstream e; // Opening new file
        e.open("new.txt");
        
    	while(d>>id>>firstname>>lastname>>quantity>>sale){
    		if(id != n){
				e<<id<<" ";

				e<<firstname<<" ";

				e<<lastname<<" ";

                e<<quantity<<" ";

				e<<sale<<endl;
			}else{
                cout<<"\t\t\t\t\tUpadate to be Food"<<endl;
                cout<<"\t\t\t\t\tId : "<<id<<endl;
                cout<<"\t\t\t\t\tFood Brand/type name : "<<firstname<<endl;
                cout<<"\t\t\t\t\tFood name : "<<lastname<<endl;
                cout<<"\t\t\t\t\tFood Quantity : "<<quantity<<endl;
                cout<<"\t\t\t\t\tFood price per Item : "<<sale<<endl;
                cout<<"\t\t\t\t\t---------------------------------"<<endl;
				cout<<"\t\t\t\t\tEnter ID same/change : ";
                cin>>id;

                e<<id<<" ";

                cout<<"\t\t\t\t\tEnter Food Brand/type name : ";
                cin>>firstname;

                e<<firstname<<" ";

                cout<<"\t\t\t\t\tEnter Food name : ";
                cin>>lastname;

                e<<lastname<<" ";

                cout<<"\t\t\t\t\tEnter Food Quantity : ";
                cin>>quantity;

                e<<quantity<<" ";

                cout<<"\t\t\t\t\tEnter Food price per Item : ";
                cin>>sale;

                e<<sale<<endl;

				cout<<"\t\t\t\t\tThe Food has been Updated successfully"<<endl;
			}
		}
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\tEnter 0 to go back : ";
        cin>>ch;
        if(ch == 0){
            system("cls");
        }
		e.close(); // closing new file
		d.close(); // closing old file
    	remove("food.txt"); // Removing old File
		rename("new.txt","food.txt"); // Renameing new File
    }
};
class Receipt:public virtual User,public Food{ // Reciept(child) class derived from user(base) class and Food(base) class making hybrid inheritance
    public:
    Receipt(): User(),Food(){} // default constructor call

    void receipt(){
        int fid,uid,t = 0,quan = 0,q = 0; // Variable for selecting user,food id's & t for total quan for needed quantity & q for storing remaining quantity
        while(1){
        cout<<"\n\n\t\t\t\t\t       FOOD MANAGEMENT SYSTEM"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t Receipt :"<<endl;
        cout<<"\t\t\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\tEnter your User Id : ";
        cin>>uid;
        cout<<"\t\t\t\t\t-------------------------------------------------------------------"<<endl;
        ifstream in("user.txt",ios::app); // creating in name file to store user data
        ifstream inn("food.txt",ios::app); // creating inn name file to store Food data

        while(in>>id>>firstname>>lastname>>sale){
            if(uid == id){
            cout<<"\t\t\t\t\tUser Id : "<<id<<" | User name :"<<firstname<<" "<<lastname<<" | User total sale : "<<sale<<endl;
            break;
            }
        }
        cout<<"\t\t\t\t\t-------------------------------------------------------------------"<<endl;

        if(uid == id){
            while(inn>>id>>firstname>>lastname>>quantity>>sale){
                cout<<"\t\t\t\t\tId : "<<id<<endl;
                cout<<"\t\t\t\t\tFood Brand/type name : "<<firstname<<endl;
                cout<<"\t\t\t\t\tFood name : "<<lastname<<endl;
                cout<<"\t\t\t\t\tFood Quantity : "<<quantity<<endl;
                cout<<"\t\t\t\t\tFood price per Item: "<<sale<<endl;
                cout<<"\t\t\t\t\t---------------------------------"<<endl;
            }
            in.close(); // closing in file
            inn.close(); // closing inn file

            ifstream s("food.txt",ios::app); // creating s name file to store food data

            cout<<"\t\t\t\t\tEnter Food id to Buy : ";
            cin>>fid;

            cout<<"\t\t\t\t\tEnter Food quantity to Buy : ";
            cin>>quan;

            while(s>>id>>firstname>>lastname>>quantity>>sale){
                if(id == fid){
                    cout<<"\t\t\t\t\tId : "<<id<<endl;
                    cout<<"\t\t\t\t\tFood Brand/type name : "<<firstname<<endl;
                    cout<<"\t\t\t\t\tFood name : "<<lastname<<endl;
                    cout<<"\t\t\t\t\tFood Quantity : "<<quantity<<endl;
                    cout<<"\t\t\t\t\tFood price per Item: "<<sale<<endl;
                    cout<<"\t\t\t\t\t---------------------------------"<<endl;
                    q = quantity - quan;
                    t = sale * quan;
                }
            }

            cout<<"\t\t\t\t\tTOTAL BILL : "<< t <<endl;

            ifstream a;
            a.open("user.txt"); // Opening old file
            ofstream b;
            b.open("new1.txt"); // Opening new file

            while(a>>id>>firstname>>lastname>>sale){
                if(id != uid){
                    b<<id<<" ";

                    b<<firstname<<" ";

                    b<<lastname<<" ";

                    b<<sale<<endl;
                }else{
                    b<<id<<" ";

                    b<<firstname<<" ";

                    b<<lastname<<" ";

                    sale += t;
                    b<<sale<<endl;
                }
            }
            b.close(); // closing new file
            a.close(); // closing old file
            remove("user.txt"); // Removing old File
            rename("new1.txt","user.txt"); // Renameing new File
            }

            ifstream d;
            d.open("food.txt"); // Opening old file
            ofstream e; 
            e.open("new.txt"); // Opening new file

            while(d>>id>>firstname>>lastname>>quantity>>sale){
                if(id != fid){
                    e<<id<<" ";

                    e<<firstname<<" ";

                    e<<lastname<<" ";

                    e<<quantity<<" ";

                    e<<sale<<endl;
                }else{
                    e<<id<<" ";

                    e<<firstname<<" ";

                    e<<lastname<<" ";

                    quantity = q;
                    e<<quantity<<" ";

                    e<<sale<<endl;
                }
            }
            e.close(); // closing new file
            d.close(); // closing old file
            remove("food.txt"); // Removing old File
            rename("new.txt","food.txt"); // Renameing new File
            cout<<"\t\t\t\t\t---------------------------------"<<endl;
            cout<<"\t\t\t\t\tEnter 0 to go back : ";
            cin>>ch;
            if(ch == 0){
                system("cls");
                break;
            }
        }
    }
};

int main(){
    int choice; // Variable of Selecting option

    Sign interval1; // interval1(object) of Sign class

    User user1; // user1(object) of User class

    Food food1; // food1(object) of Food class

    Receipt r1; // r1(object) of Receipt class

    if(interval1.intro() == 1){
        start: // Label of Goto statement
        while(1){
            cout<<"\n\n\t\t\t\t\tWELCOME TO FOOD MANAGEMENT SYSTEM"<<endl;
            cout<<"\t\t\t\t\t---------------------------------"<<endl;
            cout<<"\t\t\t\t\t\t    Main menu :"<<endl;
            cout<<"\t\t\t\t\t---------------------------------"<<endl;
            cout<<"\t\t\t\t\t1)Make a User"<<endl;
            cout<<"\n\t\t\t\t\t2)Food Inventory"<<endl;
            cout<<"\n\t\t\t\t\t3)Make a receipt"<<endl;
            cout<<"\t\t\t\t\t---------------------------------"<<endl;
            cout<<"\n\t\t\t\t\tPlease enter your option number : ";
            cin>>choice;
            if(choice == 1|choice == 2|choice == 3){
                system("cls");
                break;
            }else
            system("cls");
            cout<<"\t\t\t\t\t       !!ENTER VALID NUMBER!!";
        }
    }

    if(choice == 1){
        while(true){
            cout<<"\n\n\t\t\t\t\t       FOOD MANAGEMENT SYSTEM"<<endl;
            cout<<"\t\t\t\t\t---------------------------------"<<endl;
            cout<<"\t\t\t\t\t\tUser Informantion :"<<endl;
            cout<<"\t\t\t\t\t---------------------------------"<<endl;
            cout<<"\t\t\t\t\t1)Create User"<<endl;
            cout<<"\n\t\t\t\t\t2)Show User"<<endl;
            cout<<"\n\t\t\t\t\t3)Update User"<<endl;
            cout<<"\n\t\t\t\t\t4)Delete User"<<endl;
            cout<<"\t\t\t\t\t---------------------------------"<<endl;
            cout<<"\n\t\t\t\t\tPlease enter your option number : ";
            cin>>choice;
            switch (choice)
            {
            case 1:
                user1.input(); 
                break;
            case 2:
                user1.output();
                break;
            case 3:
                user1.update();
                break;
            case 4:
                user1.del();
                break;
            }
            if(choice == 1 | choice == 2 | choice == 3 | choice == 4){
                break;
            }else{
            system("cls");
            cout<<"\t\t\t\t\t       !!ENTER VALID NUMBER!!";
            }
        }
        goto start;
    }

    if(choice == 2){
        while(true){
            cout<<"\n\n\t\t\t\t\t       FOOD MANAGEMENT SYSTEM"<<endl;
            cout<<"\t\t\t\t\t---------------------------------"<<endl;
            cout<<"\t\t\t\t\t\tFood Informantion :"<<endl;
            cout<<"\t\t\t\t\t---------------------------------"<<endl;
            cout<<"\t\t\t\t\t1)Create Food"<<endl;
            cout<<"\n\t\t\t\t\t2)Show Food"<<endl;
            cout<<"\n\t\t\t\t\t3)Update Food"<<endl;
            cout<<"\n\t\t\t\t\t4)Delete Food"<<endl;
            cout<<"\t\t\t\t\t---------------------------------"<<endl;
            cout<<"\n\t\t\t\t\tPlease enter your option number : ";
            cin>>choice;
            switch (choice)
            {
            case 1:
                food1.input();
                break;
            case 2:
                food1.output();
                break;
            case 3:
                food1.update();
                break;
            case 4:
                food1.del();
                break;
            }
            if(choice == 1 | choice == 2 | choice == 3 | choice == 4){
                break;
            }else{
            system("cls");
            cout<<"\t\t\t\t\t       !!ENTER VALID NUMBER!!";
            }
        }
        goto start; 
    }  

    if(choice == 3){
        r1.receipt();
        goto start;
    }
    
return 0;
}
