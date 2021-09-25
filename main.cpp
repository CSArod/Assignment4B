/* Name:Alejandro_Rodriquez,2001889172,AS4
* Description: Zoo_Admissions
* Input: Number_of_People
* Output: Price_of_admissions
*/
//use proper libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//const variable ticket values
const double adultTicket = 34.99;
//adult ticket
const double seniorTicket = 24.99;
//senior
const double youngATicket = 19.99;
//young adult
const double childTicket = 9.99;
//child
const double infantTicket = 0;
//infant
int main(){
//initial prompt containing zoo menu/pricing
    std::cout << "*******************************"<<std::endl;
    std::cout << "Welcome to the Zoo Ticket Kiosk" << std::endl;
    std::cout << "Ticket Purchase Menu" << std::endl;
    std::cout << "Adults: $34.99 \n";
    std::cout << "Seniors: $24.99 \n";
    std::cout << "Young Adults: $19.99 \n";
    std::cout << "Children: $9.99 \n";
    std::cout << "Infants: Free \n";
//discount menu
    std::cout << "\nDiscounts" << std::endl;
    std::cout << "Zoo member: 30% \n";
    std::cout << "Coupon: 10% ";
//variables that will contain userInputs
double adultNum;
double seniorNum;
double youngAdultNum;
double childrenNum;
int infantNum = 1;;
    //prompt userInput for # people in party
    //adults
    std::cout << "\nHow many adults: ";
    std::cin >> adultNum;
    //seniors
    std::cout << "How many seniors: ";
    std::cin >> seniorNum;
    //young adults
    std::cout << "How many young adults: ";
    std::cin >> youngAdultNum;
    //Children
    std::cout << "How many children: ";
    std::cin >> childrenNum;
    //Infants
    std::cout << "How many infants: ";
    std::cin >> infantNum;
//ticket variables containing total cost
/*This formula for total cost gathers the number of tickets
* and multiplies it by the variable containing constant cost above.
*/
double adultCost = adultNum*adultTicket;
double seniorCost = seniorNum*seniorTicket;
double yngAdultCost = youngAdultNum*youngATicket;
double childCost = childrenNum*childTicket;
//variables containing total amount of ticket cost
/*Initialized variables get the accurate about of ticket cost by
* adding up all the input user values into one.
*/
const double totalTick=(adultNum+seniorNum+youngAdultNum+childrenNum);
const double totalCost=(adultCost+seniorCost+yngAdultCost+childCost);
//discount code prompt variable
char discountCode;
//prompt user for dicount code input
    std::cout << "\nDo you have a discount code? (y/n):";
    std::cin >> discountCode;
//initial discount variables
double memberDiscount;
double couponDiscount;
//if statements containing customer discount status
    if (discountCode == 'y' || discountCode == 'Y'){
    int inputCode;
        std::cout << "Please enter your discount code: ";
        std::cin >> inputCode;
//if statement/within primary if statement to check mod
        if (inputCode % 3 == 0){
            memberDiscount = (totalCost * .30 + totalCost);
        }else if(inputCode % 4 == 0){
            couponDiscount = (totalCost * .40 + totalCost);
        }else{
        std::cout << "Error - Invalid discount code\n";   
        }
    }
    else if (discountCode == 'n' || discountCode == 'N'){
        std::cout << "No discount code" << std::endl;
    }
//error statment for invalid value inputs
    else
    std::cout << "Error - Invalid discount code\n";
//if statements outputing calculations of ticket costs
//recipt label head
    std::cout << "\nReceipt" << std::endl;
    if (adultNum > 0){
        std::cout<< "Adults:"<<setw(9)<<adultNum<<" @ ";
        std::cout<< setw(6) << adultTicket << " ea =";
        std::cout<< setw(7) << adultCost << "\n";
    };
    if (seniorNum > 0){
        std::cout<<"Seniors:"<<setw(8)<<seniorNum<<" @ ";
        std::cout<< setw(6) << seniorTicket << " ea =";
        std::cout<< setw(7) << seniorCost << "\n";
    };
    if (youngAdultNum > 0){
        std::cout<<"Young Adults:"<<setw(3)<<youngAdultNum<<" @ ";
        std::cout<< setw(6) << youngATicket << " ea =";
        std::cout<< setw(7) << yngAdultCost << "\n";
    };
    if (childrenNum > 0){
        std::cout<<"Children:"<<setw(7)<<childrenNum<<" @ ";
        std::cout<< setw(6) << childTicket << " ea =";
        std::cout<< setw(7) << childCost << "\n";
    };
    if (infantNum > 0){
        std::cout<< fixed << showpoint << setprecision(2);
        std::cout<<"Infants:"<<setw(8)<< infantNum;
        std::cout<< setw(21) << "free" << std::endl;
    };
        std::cout<< fixed << showpoint << setprecision(2);    
        std::cout<< "\n" << setw(23) << "Subtotal";
        std::cout<< setw(8) <<"$";
        std::cout.width(2);std::cout<<std::right<<totalCost<<"\n";
//variable calculation for discount percentage
char discountValue = discountCode;
int ten = 10;
//if statement to check group discount rate
    //30% member discount Value
    if (totalTick < ten && discountValue == 'y'){
        if (couponDiscount < memberDiscount){
            double z =(totalCost * .30);
            double newValue1 = (-totalCost * .30 + totalCost);
            std::cout << "\n"<< "Coupon Discount of 15.00% applied\n";
            std::cout <<"\n"<< setw(23) << "Discount";
            std::cout << setw(9) <<"$-";
            std::cout.width(2);std::cout<<std::right<< z <<"\n";
            std::cout << "\n"<< setw(23) << "Total";
            std::cout << setw(8) <<"$";
            std::cout << setw(6)<< newValue1 <<"\n"; 
        //10% coupon discount
        }else if (couponDiscount > memberDiscount){
            double newValue4 = (-totalCost * .15 + totalCost);
            std::cout <<"\ngroup discount of 15.00% applied\n";
            std::cout <<"no discounts apply\n";
            std::cout << "\n"<< setw(23) << "Total";
            std::cout << setw(8) <<"$";
            std::cout << newValue4<<"\n";
        } else{
            std::cout << "No discounts apply" << std::endl;
            std::cout << "\n" << setw(23) << "Total";
            std::cout << setw(10) <<"$";
            std::cout.width(2);std::cout<<std::right<<totalCost<<"\n"; 
        }
    }
    //30% percent member discount
    else if (totalTick >= ten && discountValue == 'y'){
        if (totalCost > memberDiscount && totalCost > couponDiscount){
            double y =(totalCost * .30);
            double newValue2 = (-totalCost * .30 + totalCost);
            std::cout <<"\n Coupon Discount of 15.00% applied\n";
            std::cout << "\n"<< setw(23) << "Discount";
            std::cout << setw(10) <<"$-";
            std::cout.width(2);std::cout<<std::right<< y <<"\n";
            std::cout << "\n"<< setw(23) << "Total";
            std::cout << setw(9) <<"$";
            std::cout << setw(6) << newValue2 <<"\n";
        //30% member discount
        }else if(totalCost < memberDiscount && memberDiscount > couponDiscount){
            double x =(totalCost * .15);
            double newValue3 = (-totalCost * .15 + totalCost);
            std::cout <<"\n group discount of 15.00% applied\n";
            std::cout << "\n" << setw(23) << "Discount";
            std::cout << setw(8) <<"$-";
            std::cout.width(2);std::cout<<std::right<< x <<"\n";
            std::cout << "\n"<< setw(23) << "Total";
            std::cout << setw(9) <<"$";
            std::cout << setw(6) << newValue3<<"\n";
        //10% group discount
        }else if(totalCost < couponDiscount && totalCost > memberDiscount){
            double a =(totalCost * .30);
            double newValue4 = (-totalCost * .30 + totalCost);
            std::cout <<"\n zoo member discount of 30.00% applied\n";
            std::cout <<"\n"<< setw(23) << "Discount";
            std::cout << setw(9) <<"$-";
            std::cout.width(2);std::cout<<std::right<< a <<"\n";
            std::cout <<"\n"<< setw(23) << "Total";
            std::cout << setw(8) <<"$";
            std::cout << newValue4<<"\n";
        } else{
            while (totalCost ==0)
            std::cout << "No discounts apply" << std::endl;
            std::cout << "\n" << setw(23) << "Total";
            std::cout << setw(8) <<"$";
            std::cout.width(2);std::cout<<std::right<<totalCost<<"\n"; 
            return 0;
        }
    }
    //15% group discount
    else if(totalTick >= 10 && discountValue == 'n'){
        double b =(totalCost * .15);
        double newValue5 = (-totalCost * .15 + totalCost);
        std::cout << "\n"<< "Coupon Discount of 15.00% applied\n";
        std::cout <<"\n"<< setw(23) << "Discount";
        std::cout << setw(9) <<"$-";
        std::cout.width(2);std::cout<<std::right<< b <<"\n";
        std::cout << "\n"<< setw(23) << "Total";
        std::cout << setw(8) <<"$";
        std::cout.width(2);std::cout<<std::right<< newValue5 <<"\n"; 
    }
    else if(totalTick > 10 && discountValue == 'y'){
        std::cout << "No discounts apply" << std::endl;
        std::cout << "\n" << setw(23) << "Total";
        std::cout << setw(8) <<"$";
        std::cout.width(2);std::cout<<std::right<<totalCost<<"\n";
        }
    //returns total output if no discounts apply
    else{
        std::cout << "No discounts apply" << std::endl;
        std::cout << "\n" << setw(23) << "Total";
        std::cout << setw(8) <<"$";
        std::cout.width(2);std::cout<<std::right<<totalCost<<"\n";
    }
    return 0;
}
