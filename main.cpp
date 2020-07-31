//Put your C++ code 
//Name: Alexander Connolly
//Date: 7/29/20
//Source: Tutor Jack Davis explained that arrays can be used for different types of information, not just integers
//Source: 

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

//function that displays the menu
int showMenu(char menu){
    
    ifstream file;
    
    //declare an array with space for 10 strings
    string s[10];
    
    //declare an array with space for 10 sets of the number of items ordered
    int numOrdered[10];
    
    //declare an array with space for 10 sets of prices of the items
    double itemPrice[10];
    
    //set total to 0
    double total = 0;
    
//functions that show a text file based on the users choice between normal, kids and special


//if the user chooses n or N, open the normal_menu text file
if(menu == 'n' || menu == 'N'){
    
    //the .txt files are hosted outside of main.cpp
    file.open("normal_menu.txt");

}

//if the user chooses k or K, open the kids_menu text file
else if(menu == 'k' || menu == 'K'){
    
    file.open("kids_menu.txt");
    
}


//if the user chooses s or S, open the special_menu text file
else if(menu == 's' || menu == 'S'){
    
    file.open("special_menu.txt");
    
}

//otherwise, the user has made an invalid choice, let them know

else{
    
    cout << "Invalid Menu Selection" << endl;
    
    return 0;
}

//output the meniu
cout << endl << "MENU: " << endl;

//declare a string called prodName

string prodName;

//getline gets the file, the string prodName and a comma

getline(file,prodName,',');

//declare and initialize integer c as equal to 0

int c = 0;

//assign product name to s sub c

s[c] = prodName;

//while loop that runs while file
while(file) {
    
    //declare a double called price
    double price;
    
    //insert file into price
    file >> price;
    
    //assign price to itemPrice
    itemPrice[c] = price;
    
    //increment to the next product name
    c++;
    
    //output the product name and $
    cout << prodName << ": " << "$";
    
    //output price set to include the change up to two digits after the decimal point
    cout << fixed << setprecision(2) << price << endl;
    
    file.ignore();
    
    getline(file, prodName, ',');
    
    //set prodName to s sub c
    s[c] = prodName;
    
    }
    
    //close the file
    file.close();
    
    
    //prompt the user to enter their order
    cout << endl << "Please enter your order..." << endl << endl;
    
    //for loop that iterates through the list of items and asks the user how many they want of each item
    
    for(int i = 0; i < c; i++){
        
        //ask the user how many of each item they want
        cout << "How many " << s[i] << " ($" << (itemPrice[i]) << ")" << " do you want? ";
        
        //input the number of items they ordered
        cin >> numOrdered[i];
        
    }
    
    //present the user with their receipt
    cout << endl << "Here is your RECEIPT: " << endl;
    
    for(int i = 0; i < c; i++){
        
        //if the number ordered is 0, output the 0 on the line without the '$' sign or the price
        
        if(numOrdered[i] == 0){
            
            cout << right << s[i] << ": " << numOrdered[i] << endl;
            
        }
        
        else{
            
            //otherwise, output the number of items ordered and the corresponding price
            
            cout << setw(7) << right << s[i] << ": " << setw(3) << numOrdered[i] << " at " << "$" << itemPrice[i] << right << setw(3) << " = $" << numOrdered[i]*itemPrice[i] << endl;
            
            //assign total and the number of the item ordered multiplied by the price of that item to the variable total
            
            total = total + numOrdered[i] * itemPrice[i];
            
            }
        
    }
    
    //output the total price of the customers purchase
    
    cout << "TOTAL " << setw(36) << " $ " << total << endl;
    
    //output the sales tax calculated based on the total value of the users items
    //in this case, tax is 8 percent
    
    cout << "Tax (8.0%) " << setw(31) << " $ " << total*.08 << endl;
    
    cout << "===============================================" << endl;
    
    //ouput the grand total of items and the price total after tax is calculated and added to the "TOTAL"
    
    cout << "GRAND TOTAL " << setw(17) << c << " items" << setw(7) << " $ " << (total*1.08) << endl;
    
    return 0;
} 

//main function

int main(){

//Greet the user to Fredrick's Fast Foods

cout << "WELCOME TO Fredrick's Fast Foods Reloaded!" << endl;

char menu;

//ask user which menu they would like

cout << "Which menu would you like Normal or Kids or Special? (N or K or S) ";

//input their choice of menu
cin >> menu;

showMenu(menu);

string s[10];

s[1] = "someString";

s[2] = "anotherString";

}