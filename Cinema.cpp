#include <iostream>
#include <string>
using namespace std;

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

class Movie 
{
private:
    string name_movie1, name_movie2, name_movie3;
    int time_slot1, time_slot2, time_slot3;
    int time_duration1, time_duration2, time_duration3;

public:
    Movie(string n1, string n2, string n3, int ts1, int ts2, int ts3, int td1, int td2, int td3)
        : name_movie1(n1), name_movie2(n2), name_movie3(n3),
          time_slot1(ts1), time_slot2(ts2), time_slot3(ts3),
          time_duration1(td1), time_duration2(td2), time_duration3(td3) {}

    Movie() {}

    void display_info_movie() {
        cout << BLUE << "--- WELCOME TO CINEMA ---" << RESET << endl;
        cout << GREEN << "1. " << name_movie1 << " || Time : " << time_slot1 << ":00 || Duration : " << time_duration1 << ":00" << RESET << endl;
        cout << GREEN << "2. " << name_movie2 << " || Time : " << time_slot2 << ":00 || Duration : " << time_duration2 << ":00" << RESET << endl;
        cout << GREEN << "3. " << name_movie3 << " || Time : " << time_slot3 << ":00 || Duration : " << time_duration3 << ":00" << RESET << endl;
    }

    string get_name1() { return name_movie1; }
    string get_name2() { return name_movie2; }
    string get_name3() { return name_movie3; }

    void input_choice() 
	{
        int choice;
        while (true) {
            cout << YELLOW << "\nEnter Choice (1,2,3): " << RESET;
            cin >> choice;

            if (choice == 1) {
            	cout << endl;
                cout << CYAN << "You Selected: " << get_name1() << RESET << endl;
                break;
            } else if (choice == 2) {
                cout << endl;
				cout << CYAN << "You Selected: " << get_name2() << RESET << endl;
                break;
            } else if (choice == 3) {
                cout << endl;
				cout << CYAN << "You Selected: " << get_name3() << RESET << endl;
                break;
            } else {
                cout << endl;
				cout << RED << "Invalid. Try Again." << RESET << endl;
            }
        }
    }
};


class Booking 
{
protected:
    int price_of_ticket;
    int quantity_of_ticket;
    int final_total_price;

public:
    Booking() : price_of_ticket(1100), quantity_of_ticket(0), final_total_price(0) {}

    virtual void input_ticket() 
	{
        cout << MAGENTA << "--- Booking Tickets ---" << RESET << endl;
    }

    int get_total_price() 
	{
        return final_total_price;
    }
};


class Ticket : public Booking 
{
public:
    Ticket() : Booking() {}

    void input_ticket() override 
	{
        int quantity;
        cout << CYAN << "Price Of Ticket Is : " << GREEN << price_of_ticket << RESET << endl;
        cout << YELLOW << "How Many Tickets : " << RESET;
        cin >> quantity;
        quantity_of_ticket = quantity;

        string yes_no, ID;
        cout << YELLOW << "Are You A Student ? (YES / NO) : " << RESET;
        cin >> yes_no;
        if (yes_no == "YES" || yes_no == "yes" || yes_no == "Yes" || yes_no == "y") 
		{
            cout << GREEN << "\nYou Get A 45% Discount!" << RESET << endl;
            cout << YELLOW << "Enter Your Student ID: " << RESET;
            cin >> ID;
            final_total_price = (price_of_ticket - 500) * quantity_of_ticket;
     
		}
		else 
		{
            final_total_price = price_of_ticket * quantity_of_ticket;
        }

        cout << CYAN << "Total Price: " << GREEN << final_total_price << " RS" << RESET << endl;
    }
};


class Person
{
protected:
    string name_of_customer;
    int age;

public:
    Person() : name_of_customer("Default"), age(0) {}

    virtual void input_customer() 
	{
        cout << GREEN << "--- Customer Info ---" << RESET << endl;
    }
};


class Customer : public Person 
{
private:
    Movie movie;
    Ticket ticket;

public:
    Customer(string cname, int a, Movie mov, Ticket tic)
        : movie(mov), ticket(tic)
	{
        name_of_customer = cname;
        age = a;
    }

    Customer() {}

    void input_customer() override 
	{
        cout << GREEN << "--- ENTER CUSTOMER DETAILS ---" << RESET << endl;
        cout << YELLOW << "Enter Name: " << RESET;
        getline(cin >> ws, name_of_customer);
        cout << YELLOW << "Enter Age: " << RESET;
        cin >> age;

        if (age <= 8) {
            cout << RED << "You Are Too Young For Cinema. Entry Denied." << RESET << endl;
            return;
        }

        movie.display_info_movie();
        movie.input_choice();
        ticket.input_ticket();

        cout << GREEN << "-------------------------" << RESET << endl;
        cout << CYAN << "RECEIPT:" << RESET << endl;
        cout << GREEN << "NAME  : " << name_of_customer << endl;
        cout << "AGE   : " << age << endl;
        cout << "PRICE : " << ticket.get_total_price() << " RS" << RESET << endl;
        cout << YELLOW << "\nTHANKS FOR COMING, " << name_of_customer << "!" << RESET << endl;
    }
};
int main() 
{
    Movie mov("Interstellar", "Final Destination ; Bloodlines", "Spiderman", 12, 2, 6, 2, 3, 2);
    Ticket tic;
    Customer c("Default", 0, mov, tic);
    c.input_customer();

    string another;
    cout << YELLOW << "\nWould you like to buy a ticket for another movie? (yes/no): " << RESET;
    cin >> another;

    if (another == "yes" || another == "YES" || another == "Yes" || another == "y") 
    {
        Movie new_mov("Oppenheimer", "The Batman", "Kung Fu Panda 4", 1, 4, 9, 3, 2, 2);
        Ticket new_tic;
        Customer new_customer("Default", 0, new_mov, new_tic);
        new_customer.input_customer();
    }

    cout << CYAN << "\nGoodbye!" << RESET << endl;
    return 0;
}

