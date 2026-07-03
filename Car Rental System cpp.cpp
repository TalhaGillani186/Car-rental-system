#include<iostream>      // input/output
#include<string>        // string handling
#include<fstream>       // file handling
#include<iomanip>       // formatting output
#include<string>        // for using string
#include<limits>        // numeric limits

using namespace std;    // for using english words like cout, cin and etc

/* -------- Car structure to store all details -------- */
struct cars
	{
	
		string carName , colour, ownerName, carRegID, customer_name,ownerPhoneNo,customer_phoneNum
		, customer_IdcardNo, ownerId ;
		int model,rent_perday,rent;
		bool available;     // true = available, false = rented
	
	};

/* -------- Add new car to file -------- */
void add_car() 

{
	
	cout<<"\n\t\t\t\t\t<<<<<--- Available Cars --->>>>>\n";
	
    char choice;
	
	do 
	
	{
       
	    cars a;
        ofstream file("cars_detail.txt", ios::app);   // append mode
		
  		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		// Taking owner and car details
        cout << "Car Owner Name: ";
        getline(cin, a.ownerName);

        cout << "Car Owner Phone: ";
        getline(cin, a.ownerPhoneNo);

        cout << "Car Owner ID: ";
        getline(cin, a.ownerId);

        cout << "Car Name: ";
        getline(cin, a.carName);

        cout << "Car Model: ";
        cin >> a.model;

        cout << "Car Reg ID: ";
        cin >> a.carRegID;

        cout << "Car Colour: ";
        cin >> a.colour;

        cout << "Rent per day: ";
        cin >> a.rent_perday;
        
		 // Default values to avoid garbage
        a.available = true;
        a.customer_name = "None";
        a.customer_IdcardNo = "None";
        a.customer_phoneNum = "None";
        a.rent = 0;

		 // Writing data to file
		file << a.carName << " " << a.model << " " << a.colour << " "
    	 << a.ownerName << " " << a.carRegID << " "
    	 << a.ownerPhoneNo << " " << a.ownerId << " "
    	 << a.rent_perday << " " << a.available << " "
    	 << a.customer_IdcardNo << " " << a.customer_name << " "
    	 << a.customer_phoneNum << " " << a.rent << endl;


        file.close();
        
        	cout<<"\n\n\t\t\t\t\t------ Car Added Successfully! ------\n\n\n";
		    
		    // for Displaying added car data
			 cout << string(108, '-') << endl;
            
			cout << left<< setw(15) << "Car Name"<< setw(10) << "Model"<< setw(10) << "Colour"
             << setw(15) << "Owner"<< setw(15) << "Reg ID"<< setw(15) << "Phone"<< setw(18) << "Owner ID"
             << setw(10) << "Rent/day" << endl;
       
	        cout << string(108, '-') << endl;
        
		    cout << left<< setw(15) << a.carName<< setw(10) << a.model<< setw(10) << a.colour<< setw(15)
			 << a.ownerName<< setw(15) << a.carRegID<< setw(15) << a.ownerPhoneNo
			 << setw(18) << a.ownerId << setw(10) 
			<< a.rent_perday<< endl << endl;
			
			
			cout<<"If Want To Add More Press y or Y : ";
			cin>>choice;
			cout<<endl<<endl;

        
    } 

		while (choice == 'y' || choice == 'Y');

}

/* -------- Display available cars -------- */
void available_cars()

{
   
    cout << "\n\t\t\t\t\t<<<<<-- Available Cars -->>>>>\n";

    cars a;
    ifstream file("cars_detail.txt");

	  // Read each car from file
    while (file >> a.carName >> a.model >> a.colour >> a.ownerName
           >> a.carRegID >> a.ownerPhoneNo >> a.ownerId
           >> a.rent_perday >> a.available
           >> a.customer_IdcardNo >> a.customer_name
           >> a.customer_phoneNum >> a.rent)
    {
        if (a.available)
        {
            cout << "Car Name : " << a.carName << endl;
            cout << "Car Model : " << a.model << endl;
            cout << "Car Reg ID : " << a.carRegID << endl;
            cout << "Car Colour : " << a.colour << endl;
            cout << "Rent Per Day : " << a.rent_perday << endl;
            cout << "Status : Available\n\n";
        }
    }

    file.close();
}


/* -------- for Rent a car -------- */
void rent_car()
	
{
		cars a;
		string carId;
		int days;
		bool found = false;
		
		ifstream file("cars_detail.txt");       //for reading 
		ofstream file2("cars_detail2.txt");    // temporary file to write data
		
		cout<<"\n\t\t\t\t\t<<<<<-- Rent a Car -->>>>>\n";
		
		cout<<"Enter Car Reg No. To Rent : ";
		cin>>carId;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush leftover newline
		
		//to read from a file
		while  (file >> a.carName >> a.model >> a.colour >> a.ownerName
           >> a.carRegID >> a.ownerPhoneNo >> a.ownerId
           >> a.rent_perday >> a.available
           >> a.customer_IdcardNo >> a.customer_name >> a.customer_phoneNum>>a.rent) 
				
			{
	
				if(carId==a.carRegID && a.available )
				
				{
					
					cout<<"Enter Your Name : ";
					getline(cin,a.customer_name);
				
					cout<<"Enter Your Phone Number : ";
					cin>>a.customer_phoneNum;
					
					cout<<"Enter Your ID Card No. : ";
					cin>>a.customer_IdcardNo;
					
					cout<<"Days to Rent : ";
					cin>>days;
			
					a.rent= days*a.rent_perday;
					
					cout<<"Total Rent For "<<days<<" Days : "<<a.rent<<endl<<endl;
					a.available= false ;
					
					found=true;
				
				// for Displaying rented car data	
				cout << string(115, '-') << endl;
					
                  cout << left<< setw(15) << "Car Name"<< setw(10) << "Model"<< setw(10) << "Colour"
                  << setw(15) << "Customer"<< setw(15) << "Reg ID"<< setw(15) << "Phone"<< setw(18) 
				  << "Customer ID"<< setw(10) << "Rent/day" <<setw(10)<<"Total Rent"<< endl;
       
	              cout << string(115, '-') << endl;
        
		          cout << left<< setw(15) << a.carName<< setw(10) << a.model<< setw(10) 
				  << a.colour<< setw(15) << a.customer_name << setw(15) << a.carRegID<< setw(15) 
				  << a.customer_phoneNum<< setw(18) << a.customer_IdcardNo << setw(10) 
			      << a.rent_perday<<setw(10)<<a.rent<< endl << endl;
				}
				
		    
				// Write updated data in file
				file2<< a.carName << " " << a.model << " " << a.colour << " "
           	 	<< a.ownerName << " " << a.carRegID << " "
            	<< a.ownerPhoneNo << " " << a.ownerId << " "
            	<< a.rent_perday << " " << a.available << "  "
            	<< a.customer_IdcardNo << " " << a.customer_name << " "
            	<< a.customer_phoneNum << " "<<a.rent<<endl;
            	if (found)
            	break;
				 
		
			}	
			
			
				file.close();
				file2.close();
				remove("cars_detail.txt");
				rename("cars_detail2.txt","cars_detail.txt");
				if(!found)
				cout<< "Car not found or already rented!"<<endl;
				else
				cout<<"Car Rented Successfully!\n\n\n";


}

/* -------- Search car by registration ID -------- */
void search_car() 

{

	cout<<"\n\t\t\t\t\t<<<<<-- Search a Cars -->>>>>\n";
    
	string id;
    cout << "Enter Car ID to Search: ";
    cin >> id;

    cars a;
    
	ifstream file("cars_detail.txt");  // to read from file
    bool found = false;    // to check the availability of car
   
   // to read from a file
    while (file >> a.carName >> a.model >> a.colour >> a.ownerName
           >> a.carRegID >> a.ownerPhoneNo >> a.ownerId
           >> a.rent_perday >> a.available
           >> a.customer_IdcardNo >> a.customer_name >> a.customer_phoneNum >> a.rent)   
	
	{

        //show record if id matches
	    if (id == a.carRegID) 
		
	
		{
           
		    cout << "\nCar Found!\n";
            cout << "ID: " <<a.carRegID<< endl;
            cout << "Rent/Day: Rs " << a.rent_perday  << endl;
            cout << "Status: " << (a.available ? "Available" : "Rented") << endl<<endl<<endl;
            
			found = true;
       
	    }
	    
    }

    if (!found)
        
		cout << "Car not found!\n";

    file.close();
}

/* -------- for returning a car -------- */
void return_car() 

{
	
	cout<<"\n\t\t\t\t\t<<<<<-- Return a Car -->>>>>\n";
    
	string regNo;
    cout << "Enter Car ID to Return: ";
    cin >> regNo;

    cars a;
    ifstream file("cars_detail.txt");   //to read from file
    ofstream file2("cars_detail2.txt"); //to write on file
    bool found = false;      // check the availability

   //read from file
    while (file >> a.carName >> a.model >> a.colour >> a.ownerName
           >> a.carRegID >> a.ownerPhoneNo >> a.ownerId
           >> a.rent_perday >> a.available
           >> a.customer_IdcardNo >> a.customer_name >> a.customer_phoneNum >> a.rent)  
		
		{

        if (a.carRegID == regNo && !a.available) 
		
		{
            // for showing the details
            	cout << string(115, '-') << endl;
					
                cout << left<< setw(15) << "Car Name"<< setw(10) << "Model"<< setw(10) << "Colour"
                << setw(15) << "Customer"<< setw(15) << "Reg ID"<< setw(15) << "Phone"<< setw(18) 
				<< "Customer ID"<< setw(10) << "Rent/day" <<setw(10)<<"Total Rent"<< endl;
       
	              cout << string(115, '-') << endl;
        
		          cout << left<< setw(15) << a.carName<< setw(10) << a.model<< setw(10) 
				  << a.colour<< setw(15) << a.customer_name << setw(15) << a.carRegID<< setw(15) 
				  << a.customer_phoneNum<< setw(18) << a.customer_IdcardNo << setw(10) 
			      << a.rent_perday<<setw(10)<<a.rent<< endl << endl;
			      
			//we gave values to them to avoid garbage 
			a.available = true;
            a.customer_name = "None";
            a.customer_phoneNum = "None";
            a.customer_IdcardNo = "None";
            a.rent=0;
            cout << "Car returned successfully!\n";
            found = true;
        }

        // to update the record again
         file2<< a.carName << " " << a.model << " " << a.colour << " "
            << a.ownerName << " " << a.carRegID << " "
            << a.ownerPhoneNo << " " << a.ownerId << " "
            << a.rent_perday << " " << a.available << " "
            << a.customer_IdcardNo << " " << a.customer_name << " "
            << a.customer_phoneNum << " " << a.rent << endl;
    }

    file.close();
    file2.close();
    remove("cars_detail.txt");                      //this removes the file
    rename("cars_detail2.txt", "cars_detail.txt");  // this rename the updated file as orignal

    if (!found)
        cout << "Car not rented or invalid ID!\n";


}

/* -------- for viewing rented cars -------- */	
void view_rented_cars() 

{
	
	cout<<"\n\t\t\t\t\t<<<<<-- Rented Cars -->>>>>\n";
    
	cars a;
    
	ifstream file("cars_detail.txt");  //read from file

    cout << "\n--- Rented Cars ---\n";
   
    //for reading from file
    while (file >> a.carName >> a.model >> a.colour >> a.ownerName
           >> a.carRegID >> a.ownerPhoneNo >> a.ownerId
           >> a.rent_perday >> a.available
           >> a.customer_IdcardNo >> a.customer_name >> a.customer_phoneNum >> a.rent) 
	{

        if (! a.available) 
		
		{
          
		   // for showing details
		    cout << "Car: " << a.carName << endl;
            cout << "Customer: " <<a.customer_name << endl;
            cout << "Total Rent: Rs " << a.rent << endl;
            cout << "-------------------\n";
        
		}
    
	}
    
	
	file.close();
}


/* -------- for deleting cars record -------- */	
void delete_car() 

{
	
	cout<<"\n\t\t\t\t\t<<<<<-- Available Cars -->>>>>\n\n";

    string id;
    cout << "Enter Car ID to Delete: ";
    cin >> id;

    cars a;
    
	ifstream file("cars_detail.txt");        //read from file
    ofstream file2("cars_detail2.txt");      //write on file
    
	bool deleted = false;
    
    //read data from file
    while (file >> a.carName >> a.model >> a.colour >> a.ownerName
           >> a.carRegID >> a.ownerPhoneNo >> a.ownerId
           >> a.rent_perday >> a.available
           >> a.customer_IdcardNo >> a.customer_name >> a.customer_phoneNum >> a.rent) 
		   
	{

        if (id != a.carRegID) 
		
		{
            
			//for updating file
			file2<< a.carName << " " << a.model << " " << a.colour << " "
            << a.ownerName << " " << a.carRegID << " "
            << a.ownerPhoneNo << " " << a.ownerId << " "
            << a.rent_perday << " " << a.available << " "
            << a.customer_IdcardNo << " " << a.customer_name << " "
            << a.customer_phoneNum << " " << a.rent << endl << endl;
        
		} 
		
		else 
		
		{ 
			deleted = true;	
        }
        
    }

    file.close();   //closing file 1
    file2.close();  //closing file 2
    
	remove("cars_detail.txt");              //to removing file
    rename("cars_detail2.txt", "cars_detail.txt");   // to rename the updated file

    if (deleted)
        
		cout << "Car deleted successfully!\n";
		
    else
    
        cout << "Car not found!\n";
}


/* -------- Main menu -------- */
int main()
			
{
				
				cout<<"\t\t\t\t========= Welcome to Metro Rent Autos ==========\n\n";
				 int choice;
    do 
	
	{
        // for display the choice dialogue
		cout << "\n=======================\n";
        cout << "1. Add Car\n";
        cout << "2. Available Cars\n";
        cout << "3. Rent Car\n";
        cout << "4. Search Car\n";
        cout << "5. Return Car\n";
        cout << "6. View Rented Cars\n";
        cout << "7. Delete Car\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		
		{
         
            // for switching the case as per user choice
	        case 1: add_car(); break;
            case 2: available_cars(); break;
            case 3: rent_car();   break;
            case 4: search_car(); break;
            case 5: return_car(); break;
            case 6: view_rented_cars(); break;
            case 7: delete_car(); break;
            case 8: cout << "Exiting system...\n"; break;
           
		    default: cout << "Invalid choice!\n";
       
	    }
	    
    } 
	
	while (choice != 8);

    return 0;


}
