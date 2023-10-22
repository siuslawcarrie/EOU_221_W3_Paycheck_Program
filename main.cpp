/*
Carrie Bailey
CS221 Fall 2023
October 15, 2023
Program #6: Week 3, Paycheck Program
This program asks the user for their employee ID # and their monthly gross pay. It then uses standard percentages and flat rates, as indicted,
 to calculate payroll deductions such as taxes and insurance. It then displays and itemized pay advice with the employee profile and detailing
 each deduction as well as the net pay and the % of net pay to gross pay. All itemizations are lined up, using periods and spaces to fully justify each line
 item.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

/*
 Paycheck Program:
 --USER INPUT
 1.Ask for employee ID - 4 digits
 2. Ask for employee name
 3. Ask for employee monthly salary - display employee name
 --END USER INPUT


 --VARIABLES
 TYPE string
 employee name: emp_name

 TYPE integer
 employee ID: emp_id

 --Pay
 TYPE float? 2 decimals
 monthly salary: gross_pay
net income: net_income

 * --Deductions
 * TYPE float %
 * retirement: retire_ded
 * federal tax: fed_tax
 * state tax: state_tax
 * Medicare tax: medicare_tax
 * social security: soc_sec_tax
 * total taxes: sum_taxes
 * take home pay %: take_home_percent
 *  *
 * TYPE float? flat amount 2 decimals
 * health insurance: health_ins
 * life insurance: life_ins
 * total deductions: total_deductions
 *
 * --END VARIABLES
 *  *
 * --MATH
 * 1. Calculate retirement amount from gross pay
 * 2 *Calculate federal tax from gross pay
 * 5. Calculate state tax from gross pay
 * 6. Calculate Medicare tax from gross pay
 * 7. Calculate social security tax from gross pay
 * 8. Sum all taxes = total taxes
 * 10. Add all taxes, health insurance and life insurance = total deductions
 * 11. Deduct total deductions from gross pay = net pay
 * 12. Divide net pay by gross pay = take home pay %
 * --END MATH
 *
 * --DISPLAY
*/


//functions
int validation_integer(int min, int max);//validate integer ee ID
float validation_float(float min, float max);//validate gross pay
void greeting();//welcome & name
float gross_pay_func();//deductions from gross pay
int emp_id_func();

int main() {

    //VARIABLES
    int width_output_1 = 29;//user's employee ID, width of paycheck printout lines, left side justified
    int width_output_2 = 10; //right side justified
    int emp_id;//user's employee ID

    float gross_pay; //user's gross pay
//taxes & retirement - rates
    float state_tax_rate, medicare_tax_rate, soc_sec_tax_rate,
            take_home_percent, retire_ded_perc;
    float fed_tax_rate;
//taxes & retirement - totals
    float fed_tax, state_tax, medicare_tax, soc_sec_tax, retire_ded;
//flat amount deductions
    float life_ins_amt, health_ins_amt;
//totals
    float sum_deductions, net_pay;
//END VARIABLES

//PROGRAM
    //greeting();
    emp_id = emp_id_func();
    cout<<emp_id<<endl;
    gross_pay = gross_pay_func();

    //tax rates
    fed_tax_rate = 0.175;
    state_tax_rate = 0.091;
    medicare_tax_rate = 0.0145;
    soc_sec_tax_rate = 0.062;
//deductions
    retire_ded_perc = 0.0929;
//flat rate deductions
    life_ins_amt = 3.71;
    health_ins_amt = 51.48;

//tax totals
    fed_tax = fed_tax_rate * gross_pay;
    state_tax = state_tax_rate * gross_pay;
    medicare_tax = medicare_tax_rate * gross_pay;
    soc_sec_tax = soc_sec_tax_rate * gross_pay;

//% deductions
    retire_ded = retire_ded_perc * gross_pay;


    sum_deductions = state_tax + medicare_tax + soc_sec_tax + retire_ded  + life_ins_amt + health_ins_amt;
    net_pay = gross_pay - sum_deductions;
    take_home_percent = net_pay / gross_pay;

    cout << left << setw(30) << setfill('.') << "state tax" << "$" << setw(11) << setfill(' ') << right
         << fixed << setprecision(2) << state_tax << endl;
    cout << "+ " << setw(2)  << endl;
    // display dashes underneath 2nd number and answer

    cout << "Sum deductions " <<setfill('.') << setw(width_output_1) << "." << "$" << " " << sum_deductions<< endl;
    return 0;
}
//FUNCTION DEFINITIONS

void greeting() {
    string user_name;
    cout << "Hi! Welcome to Carrie's Calculator! What is your name? ";
    cin >> user_name;
    cout << "Hi " << user_name << "! Let's play!" << endl;
}

float gross_pay_func() {

    cout << "Please enter your monthly gross pay in dollars and cents; do not include commas. For example: 50500.00. "
         << endl;
    //ask for user gross monthly salary
       float min = 1;
    float max = 99999999;
    return validation_float(min, max);
}

int emp_id_func() {

    cout << "Please enter your employee ID: ";


    int min = 0, max = 9999;
    return validation_integer(min, max);
}


int validation_integer(int min, int max) //function to validate integers
{
    int number;
    cin >> number;
    while (!cin or (number < min) or (number > max)) {
// Explain error not entering an integer
        cout << "I'm sorry that's not a valid entry. Please enter a number between " << min << "and " << max << ": ";
// Clear input stream
        cin.clear();
// Discard previous input
        cin.ignore(123, '\n');
        cin >> number;
        cout << endl;
    }
    return number;
}

float validation_float(float min, float max) //function to validate integers
{
    float number;
    cin >> number;

    while (!cin or (number < min) or (number > max)) {
// Explain error not entering an integer
        cout << "I'm sorry that's not a valid entry. Please enter a number between " << min << "and " << max << ": ";
// Clear input stream
        cin.clear();
// Discard previous input
        cin.ignore(123, '\n');
        cin >> number;
        cout << endl;

    }
    return number;
}






