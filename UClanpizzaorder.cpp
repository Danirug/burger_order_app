/*Name : Mallika Arachchige Daniru Gihen
  Reg no : 212855889*/

#include <iostream>
#include <string>
#include <iomanip>




using namespace std;

//constants for the pizza sizes and the prices
const string pizzasizes[] = {"Small","Medium","Large"};
const double pizzaprice[] = {5.0,8.50,10.25};
const int numsizes = sizeof (pizzasizes) / sizeof(pizzasizes[0]);

//constants for the pizza toppings and the prices 
const string toppings[] = {"Ham","Mushrooms","Pepperoni","Peppers","Onions","Extra cheese"};
const double toppingprice[] = {0.80,0.50,1.0,0.80,0.40,1.50};
const int numtoppings = sizeof(toppings) / sizeof (toppings[0]);




void topupcredits(double &credits) //function to topup credits
{
	double amount;
	cout << "\n----------------------------\n";
	cout << "please enter the amount you want to top-up for the balance: ";
	while (!(cin >> amount ))
	{
		cout << "Invalid input, enter a number: ";
		cin.clear();
		cin.ignore(100, '\n');
		
	}
	credits += amount; // adding the topped up credits
	cout << "Top-up is successful New balance is = " <<fixed<<setprecision(2)<< credits << " credits\n";
	
	
}

void mainmenu (double credits) // fucntion to display the main menu
{
	cout << "\n------------------------------\n";
	cout << " UCLan PIZZA";
	cout << "\n------------------------------\n";
	cout << "MAIN MENU\n";
	cout << "1.Top-up Credits (current credit balance = " << credits << ")\n";
	cout << "2.Order pizza\n";
	cout << "0.Exit\n";
	cout << "\nplease enter a number: ";
	
	
}

int selectpizzasize() // function to select the pizza size
{
	int option;
	
	
	cout << "\nORDER PIZZA- Select Size\n";
	cout << "\nplease choose from the following list:\n";
	for ( int a = 0 ; a < numsizes; a++)
	{
		cout << a + 1 << "."<< pizzasizes[a]<< " [" <<pizzaprice[a]<<" credits]\n";
	}
	cout << "0. Return to Main menu" << endl;
	cout << "\n..................................\n";
	cout << "please enter number:\t";
	cin >> option;
	
	

	if (option == 0) // returning to main menu
	{
		return 0;
	}
	else if ( option >= 1 && option <= numsizes) // 
	{
		cout << "You have selected a " << pizzasizes[option - 1]<<" pizza." << endl;
		cout << "...................................\n";
		return option;
	}
	else
	{
		cout << "Invalid option! please choose an number between 0 and " << numsizes << "." <<endl;
		return selectpizzasize(); // goes back to the function if the iput in invalid
	}
     
}

void selecttoppings(double &totalcost) // function to select the topping prefernces
{
	
	cout <<"\nPlease choose from the following toppings:\n";
	int toppingpreference;
	char moretoppings ;
	
	for (int b = 0; b < numtoppings; b++) //  displaying the available toppings
		{	
	
			cout << b + 1 << "." << toppings[b] <<" [" << toppingprice[b] << " credits]\n";
		
		}
		
		cout << "0.Return to Main menu "<< endl;
	
	do{	
		
		
		cout << "Plese enter a number: ";
		cin >> toppingpreference;
		
		if (toppingpreference < 0 || toppingpreference > numtoppings)
		{
			if (toppingpreference !=0)
			{
				cout << "Invalid topping preference!\n";
			}
		}
		
		else if (toppingpreference != 0)
		{
			totalcost += toppingprice[toppingpreference -1]; // calculating the cost of toppings to the final price 
			cout << "\nYou have added " << toppings[toppingpreference-1]<< " to your pizza the current price is: "<<fixed<<setprecision(2)<<totalcost<<" credits.\n";
		}
		
	    } while (toppingpreference !=0); // loop continues until the user chooses to return to mian menu
	    
	
	   	
		
	
}

void orderpizza(double &credits) // function to  place the order for thr pizza 
{
	int sizechoice = selectpizzasize();
	
	if (sizechoice == 0)
	{
		return ;
	}
	
	double totalcost = pizzaprice[sizechoice -1]; //setting intial cost to pizza base price
	selecttoppings (totalcost); 
	
	if (totalcost > credits) // checking if the user has enough credit balance 
	{
		cout << "Available Balance : " << credits << " credits" <<endl;
		cout << "price of pizza is: "<< totalcost << " credits" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "you dont have sufficient balance to order. the required amount is " << totalcost << " credits."<<endl;
		
		char option;
		cout << "would you like to Top-up? please enter 'Y' for yes 'N' for no: ";
		cin >> option;
		
		if (option == 'Y' || option == 'y')
		{
			topupcredits(credits);
			cout << "---------------------------------------" << endl;
			cout << "new balance = " << credits << " credits" << endl;
			cout << "would you like to continue your order?please enter 'Y' for yes 'N' for no: ";
			cin >> option;
			
			if (option == 'N' || option == 'n')
			{
				cout << "Thank you, goodbye! "<< endl;
				return;
			}
			
		}
		
		else
		{
			cout << "Thank you, goodbye! "<<endl;
			return;
			
				
		}
	}
		
	cout << "--------------------------------------" << endl;
	cout << "Available blance: " << fixed << setprecision(2) << credits << " credits" << endl;
	cout << "Pizza price: " << fixed << setprecision(2) << totalcost << " credits" << endl;
	cout << "--------------------------------------" <<endl;
	credits -= totalcost;
	cout << "Your new balance = " << fixed << setprecision (2) << credits << endl;
	
	char option;
	cout << "do you want  to order another pizza? please enter 'Y' for yes 'N' for no: ";
	cin >> option;
	
	if(option == 'Y' || option == 'y')
	{
		orderpizza(credits);
	}
	
	else
	{
		cout <<"Thank you, goodbye!" <<endl;
	}
			
}



int main() // main function
{
	double credits = 0.00; // intial credit balance is zero
	
	int option ;
	
	do
	{
		mainmenu(credits); // diplaying the mainmenu 
		cin >> option;
		
		
		switch (option)
		{
			case 1:
			topupcredits(credits);
			break;
			
			case 2:
			orderpizza(credits);
			break;
			
			case 0:
			cout << "Thank you, goodbye!\n";
			break;
			
			default:
			cout << "Invalid option.\n";
		}
		
	}
	while (option !=0); //loop continues until the user chooses to exit
	
 return 0;
}
