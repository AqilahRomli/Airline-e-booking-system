#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include <fstream>
#include <conio.h>
using namespace std;

struct passengerinfo
{
  string name;
  int age;
  long int mykad;
  long int cont;
};
void menu();  //function menu for sign up & log in
void detpages();  //function detail
void getpassengerinfo (passengerinfo *pt_pass); //get data
void file();  //function for create new file for first time user.
void book();  //function for booking 
void seat();  //function for select seat
void pay();   //function for payment
void location(); //name of destination
void checkin(); //function booking comfirm -ticket display
char oldname[] = "example.txt", newname[]= "file_new.txt", text[]=".txt", user[]="user",k;
char arr[7][5];
string p,s[20],profile,destination,origin;
int choice,ori=0,des=0,date[3],times[2],pass[2],t,m;
float payment,totalpayment;



int main()
 {
 	menu();
 	system("CLS");
 	book();
 	system("CLS");
 	seat();
 	system("CLS");
 	pay();
 	system("CLS");
 	checkin();
 	
 	
 	return 0;
 	
}

void menu()
{
	cout<<"\n\n\t\t\t\t=========================================================="<<endl;
 	cout<<"\t\t\t\t\t\t         WELCOME TO\n";
 	cout<<"\t\t\t\t\t      SENTOSA AIRLINES BOOKING SYSTEM\n";
 	cout<<"\t\t\t\tKUALA LUMPUR - PENANG - LANGKAWI - KOTA KINABALU - KUCHING \n";
 	cout<<"\t\t\t\t=========================================================="<<endl;
 	cout<<"\n\n\t\t\t\t\t\t       [1] = SIGN UP ";
 	cout<<"\n\n\t\t\t\t\t\t       [2] = LOG IN";
 	cout<<"\n\n\t\t\t\t\t For FIRST TIME user select 1 for register \n";
 	
	do //loop if enter choice>2 || choice<1
	{
		cout<<"\n\n\n\t\t\t\t\t\t    SELECT YOUR CHOICE =  ";
		cin>>choice;
		if (choice>2 || choice<1)
			cout<<"\t\t\t\t    You have entered the wrong number. PLEASE TRY AGAIN!\n";
	} while (choice>2 || choice<1);
	
	if (choice==1)
	{
		system("CLS");
		detpages();
	}
	if (choice==2)
	{
		system("CLS");
		cout<<"\n\n\t\t\t\t==================================================="<<endl;
 		cout<<"\t\t\t\t\t\t      LOG IN\n"; //MASUKKAN DLM FILE 
 		cout<<"\t\t\t\t==================================================="<<endl;
		cout<<"\n\n\t\t\t\t\t   USERNAME : ";
		cin>>newname;
		strcat(newname,text);//to combine username with .txt ; newname as variable to file name
		ifstream ifile;
   		ifile.open(newname);
   		if(ifile) 
		{
      	cout<<"\n\n\n\t\t\t\tSuccessfully open file";
      	cout<<"\n\t\t\t\tPress ENTER to continue...";
		cin.ignore(1,'\n');
		cin.get(k);//holds the screen
   		} 
		else {
      	cout<<"\n\n\n\t\t\t\tUnable to open file. please register first";
      	cout<<"\n\t\t\t\tPress ENTER to continue...";
		cin.ignore(1,'\n');
		cin.get(k);//holds the screen
      	system("CLS");
		detpages();
   		}
  		
  		
	}		
}

void detpages()
{
	cout<<"\n\n\t\t\t\t==================================================="<<endl;
 	cout<<"\t\t\t\t\t\t  PASSENGER DETAIL\n"; //MASUKKAN DLM FILE 
 	cout<<"\t\t\t\t==================================================="<<endl;
 	cout<<"\n\n\t\t\t\t\t   USERNAME : ";
 	cin>>user;
	passengerinfo pass;
	getpassengerinfo (&pass);
			
}

void getpassengerinfo (passengerinfo *pt_pass)
{
	file();
 	ofstream myfile;
	myfile.open(newname);
  	cout<<"\n\t\t\t\t\t   NAME : ";
 	cin.ignore(1,'\n');
 	getline (cin, pt_pass->name); //get info guna pointer
 	myfile << pt_pass->name <<endl;
 	cout<<"\n\t\t\t\t\t   AGE : ";
 	cin>>pt_pass->age;
 	myfile <<pt_pass->age<< endl;
 	cout<<"\n\t\t\t\t\t   MYKAD NO. (00012345678): ";
 	cin>>pt_pass->mykad;
 	myfile << setw(12)<<setfill('0')<<pt_pass->mykad << endl;
 	cout<<"\n\t\t\t\t\t   CONTACT NO. (0123456789): ";
 	cin>>pt_pass->cont;
 	myfile << setw(11)<<setfill('0')<<pt_pass->cont << endl;
	cin.ignore(1,'\n');
	myfile.close();
}

void file()
{
  // Create and open a text file
	ofstream myfile;
	myfile.open("example.txt");
	myfile << "Writing this text to a file." << endl;
	myfile.close();
  
	strcat(user,text);
	strcpy(newname,user); //save new file name as variable newname.
	
	/*	Deletes the file if exists */
	if (rename(oldname, newname) != 0)
		perror("\t\t\t\tError renaming file");
	else
		cout << "\t\t\t\tFile renamed successfully";	
}


void book()
{
	cout<<"\n\n\t\t\t\t==================================================="<<endl;
 	cout<<"\t\t\t\t\t\tBOOKING REGISTRATION\n";
 	cout<<"\t\t\t\t==================================================="<<endl;
 	cout<<"\n\n\t\t\t\t\t\t[1]- KUALA LUMPUR\n";
 	cout<<"\t\t\t\t\t\t[2]- PULAU PINANG\n";
 	cout<<"\t\t\t\t\t\t[3]- LANGKAWI\n";
 	cout<<"\t\t\t\t\t\t[4]- KOTA KINABALU\n";
 	cout<<"\t\t\t\t\t\t[5]- KUCHING\n";
	do //looping for origin
 	{
 		cout<<"\n\n\t\t\t\t\t   SELECT ORIGIN (1-5) : ";
 		cin>>ori;
 		if (ori>5){
 			cout<<"\t\t\t\t You have entered the wrong number. PLEASE TRY AGAIN!\n";
		 }
	 }while(ori>5); // loop if enter ori other than 1-5
	
	do //looping for destination
 	{
 		cout<<"\n\n\t\t\t\t\t   SELECT DESTINATION (1-5) : ";
 		cin>>des;
 		if (des>5){
 			cout<<"\t\t\t\t You have entered the wrong number. PLEASE TRY AGAIN!\n";
		 }
	 }while(des>5); // loop if enter des else 1-5
 	
 	cout<<"\n\n\t\t\t\t\t   DEPARTURE DATE (dd mm yyyy): ";
 	cin>>date[0]>>date[1]>>date[2];
 	cout<<"\n\n\t\t\t\t\t   DEPARTURE TIME (hh min): ";
 	cin>>times[0]>>times[1];
 	cout<<"\n\n\t\t\t\t\t   NUMBER OF PASSENGER--> ADULT:  ";
 	cin>>pass[0];//number of adult
 	cout<<"\t\t\t\t\t\t\t\t  CHILD: ";
 	cin>>pass[1];//number of child
 	t=pass[0]+pass[1]; //total passenger
}

void location()
{
	if(ori==1)
	origin="KUALA LUMPUR";
	if(ori==2)
	origin="PULAU PINANG";
	if(ori==3)
	origin="LANGKAWI";
	if(ori==4)
	origin="KOTA KINABALU";
	if(des==5)
	origin="KUCHING";
	if(des==1)
	destination="KUALA LUMPUR";
	if(des==2)
	destination="PULAU PINANG";
	if(des==3)
	destination="LANGKAWI";
	if(des==4)
	destination="KOTA KINABALU";
	if(des==5)
	destination="KUCHING";	
}



void seat()
{
	cout<<"\n\n\t\t\t\t==================================================="<<endl;
 	cout<<"\t\t\t\t\t\t    SELECT SEAT\n";
 	cout<<"\t\t\t\t==================================================="<<endl;
 	cout<<"\n"; 
	for(int i=0;i<7;i++){
		//forst column is row number
		arr[i][0]=i+1+'0';
		for(int j=1;j<5;j++){
			//to represent sit number A,B,C,D respectively
			arr[i][j]='A'+j-1; 
		}
	}
	//display seat
	for(int i=0;i<7;i++){
		cout<<"\t\t\t\t\t\t  ";
		for(int j=0;j<5;j++){
			cout<<" "<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
 	cout<<"\n\t\t\t\t==================================================="<<endl;
	
	for (int i = 0; i < t; i++)
  	{
  	cout<<"\n\t\t\t\t\t   ENTER VALID SEAT "<<i+1<<" NO.(1A): ";
	cin>>s[i];
  	}
  	
}

void pay()
{
	cout<<"\n\n\t\t\t\t==================================================="<<endl;
 	cout<<"\t\t\t\t\t\t   PAYMENT SECTION\n";
 	cout<<"\t\t\t\t==================================================="<<endl;
 	cout<<"\n";
 	
 	if((ori==1&&des==2)||(ori==2&&des==1)||(ori==1&&des==3)||(ori==3&&des==1))
 	{
 		payment=(pass[0]*50)+(pass[1]*45);
	 }
 	
 	if((ori==3&&des==2)||(ori==2&&des==3)||(ori==5&&des==4)||(ori==4&&des==5))
 	{
 		payment=(pass[0]*40)+(pass[1]*35);
	 }
	
	if((ori==2&&des==5)||(ori==5&&des==2)||(ori==4&&des==3)||(ori==3&&des==4))
 	{
 		payment=(pass[0]*70)+(pass[1]*65);
	 }
	 
	if((ori==1&&des==5)||(ori==5&&des==1)||(ori==1&&des==4)||(ori==4&&des==1))
 	{
 		payment=(pass[0]*60)+(pass[1]*55);
	 }
	 
	if((ori==5&&des==3)||(ori==3&&des==5)||(ori==2&&des==4)||(ori==4&&des==2))
 	{
 		payment=(pass[0]*65)+(pass[1]*60);
	 }
	 
	totalpayment = (t*0.63)+payment;
	
	cout<<"\t\t\t\t\t\tpayment = RM "<<payment<<endl;
 	cout<<"\t\t\t\t\t\ttotal payment = RM "<<totalpayment<<endl;
 	cout<<"\n\t\t\t\t==================================================="<<endl;
	cout<<"\n\t\t\t\t\t\t   METHOD PAYMENT\n";
 	cout<<"\n\n\t\t\t\t\t\t[1]- DEBIT/CREDIT CARD\n";
 	cout<<"\t\t\t\t\t\t[2]- E-WALLET\n";
 	cout<<"\n\t\t\t\t\t\tSELECT METHOD PAYMENT : ";
 	cin>>m;
	cout<<"\n\n\n\t\t\t\tPress ENTER to continue...";
	cin.ignore(1,'\n');
	cin.get(k);//holds the screen
	cout<<"\n\t\t\t\tpayment receive...\n";
	cout<<"\t\t\t\tTHANK YOU, your payment was successful...\n";
	cout<<"\n\t\t\t\tPress ENTER to continue...";
	cin.ignore(1,'\n');
	cin.get(k);//holds the screen
}

void checkin()
{
	location();
	cout<<"\n\n\t\t\t\t=========================================================="<<endl;
 	cout<<"\t\t\t\t\t\t    BOOKING COMFORMATION\n";
 	cout<<"\t\t\t\t=========================================================="<<endl;
	cout<<"\n\n\t\t\t\t=========================================================="<<endl;
 	cout<<"\t\t\t\t\t      SENTOSA AIRLINES BOOKING SYSTEM\n\n";
 	cout<<"\t\t\t\t\t\t"<<origin<<" - "<<destination<<"\n\n";
 	cout<<"\t\t\t\tberlepas/departure: "<<endl;
 	cout<<"\t\t\t\t\t\t  "<<date[0]<<"/"<<date[1]<<"/"<<date[2]<<"    "<<times[0]<<":"<<times[1]<<endl;
 	cout<<"\t\t\t\t\t\t\t "<<endl;
	ifstream myfile (newname);
	while (getline(myfile, profile)) {
    // output the line
    cout << "\t\t\t\t"<<profile <<endl;
    // now we loop back and get the next line in 'str'
	}
	myfile.close();
	cout <<"\t\t\t\tSEAT: "; //display seat
	for (int i = 0; i < t; i++)
  	{
  	cout <<s[i]<<"  ";
  	}
  	cout <<"\n\t\t\t\tMYR "<<totalpayment<<endl;
  	cout<<"\n\t\t\t\t\t     Please be at the airport an hour early\n";
 	cout<<"\t\t\t\t=========================================================="<<endl;
}