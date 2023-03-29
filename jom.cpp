#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

	bool exist(string number){
		string num , name,  relate, line;
		fstream read("contactdata.txt", ios::in);
		while (read >> num >> name>> relate ){
			if (num == number)
			{
				return true; 
			}
		}
		return false;
	    }
int main()
{
    int fill;
    char fill2;
    string num, nnname, rel;
    
    system("cls"); //clear console.
    cout << "================================== \n";
    cout << "\tCMS MAIN MENU" << endl;
    cout << "================================== \n";
    cout << "\t[1] NEW CONTACT \n";
    cout << "\t[2] SHOW CONTACT \n";
    cout << "\t[3] DELETE CONTACT\n";
    cout << "\t[4] END PROGRAM.\n";
    cout << "================================== \n";
    cout << "INPUT:  ";
    
    cin >> fill;

    switch (fill)
    {
    case 1:
    {
        // Adding/Saving data.
        cout <<"Connecting Input..."<<endl;
        sleep (2);
        system("cls"); //clear console
        cout << "=============================== \n";
        cout << "======ADD NEW CONTACT====== \n";
        cout << "===============================\n";
        cout << "Enter Cellphone Number: \n";
        cin >> num;
        cout <<"Checking Number... "<< endl;
        sleep (2);
        if(!exist (num)){
        cout << "Enter Name or Nickname: \n";
        cin >> nnname;
        cout << "Relation: \n";
        cin >> rel;
        cout << "=============================== \n";
		cout <<"Saving Data..."<<endl;
        sleep (2);
        fstream data;
        data.open("contactdata.txt", ios::out | ios::app);
        data << num << "\n " << nnname << "\n " << rel << endl;
        data.close();
        cout << " DATA SUCCESSFULLY SAVED!!!\n";
    }
    else{
    	cout << "Sorry! This number is already used. " << endl;
	}
        system("pause"); //pause.
        main();//return main.
        break;
    }
    case 2:
    {
        // Showing Contact data.
        int count = 1;
        cout <<"SHOWING CONTACT..."<<endl;
        sleep (2);
        string shownum, shownnname, showrel;
        system("cls"); //clear console
        cout << "========================================= \n";
        cout << "=============SHOW CONTACT=============\n";
        cout << "========================================= \n";
        fstream myData("contactdata.txt", ios::in);
        while (myData >> shownum >> shownnname >> showrel)
        {
        	
        	cout <<"_______C_O_N_T_A_C_T_#_"<<count<<"______"<< endl;
            cout <<"NUMBER:  "<<shownum<<"\t "<<endl;
            cout <<"NAME:. "<<shownnname<<"\t "<< endl;
            cout <<"RELATION:  "<<showrel<<"\t "<<endl;
            count++;
        }
        system("pause"); //pause.
        main(); //return main.
        break;
    }
    case 3:
    {
        //Delete Contact data.
        system("cls"); //clear console
        cout << "============================================\n";
        cout << "============DELETE WARNING!!!============\n";
        cout << "============================================\n";
        cout << "Are you sure you want to delete all Contacts?\n";
        cout << "\t\t[Y] Yes\n";
        cout << "\t\t[N] No\n";
        cout << "Answer: ";
        cin >> fill2;

        system("cls"); //clear console
        if (toupper(fill2) == 'Y')
        {
        	cout <<"Deleting All Data..."<<endl;
        	sleep (2);
            fstream delcondata;
            delcondata.open("contactdata.txt", ios::out | ios::trunc);
            delcondata.close();
            cout << "SUCCESSFULLY DELETED!\n";
            system("pause"); //pause.
            system("cls"); //clear console.
            main(); //return main.
        }
        else
        {
            main(); //return main 
        }
        break;
    }
    case 4:
    {
        cout << " THANK'S FOR USING !!! ";
        system("exit"); //exit program
        break;
    }
    default:
        cout << "Please Choose 1-4 okay?" << endl;
        system("pause"); //pause
        system("cls"); //clear console.
        main(); //return main.
    }
    return 0;
}


