/*       CS210 - Project2 - Airgead Banking 
*
*     Investment.cpp
*        implementation file for the Investment class
*
*  date: 9/30/2021
*  author: johnny lingafelter
******************************************************************************/
#include "Investment.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>

using namespace std;

/*       GetUserInput
* 
*  This function prompts the user for input using exceptions, storing input in
*  current object
********************************************************************************/
void Investment::GetUserInput() {

   cout << "+--------------------------------+" << endl;
   cout << "|           Data Input           |" << endl;
   cout << "+--------------------------------+" << endl;

   // get user input and validate input
   this->getInitialInvestmentInput();
   this->getMonthlyDepositInput();
   this->getInterestRateInput();
   this->getInvestmentYearsInput();

   cout << endl << endl << "        Your input              " << endl;
   cout << "********************************" << endl;
   cout << "+ Initial Investment Amount:   $" << this->GetInitialInvestment() << endl;
   cout << "+ Monthly Deposit:   $" << this->GetMonthlyDeposit() << endl;
   cout << "+ Annual Interest:   %" << this->GetInterestRate() << endl;
   cout << "+ Number of years:   " << this->GetInvestmentYears() << endl;

   // display "Press any key to continue..." prompt
   system("pause");
}

/*       GetUserAction
* 
*  This function displays a menu for the user and gets the users command.
*  Once command is obtained the proper action is taken
* 
********************************************************************************/
bool Investment::GetUserAction() {
   char command = 'a';

   // display menu
   cout << endl << "User commands: " << endl;
   cout << "  i: edit initial deposit amount" << endl;
   cout << "  m: edit monthly deposit amount" << endl;
   cout << "  r: edit yearly interest rate" << endl;
   cout << "  y: edit number of years to invest" << endl;
   cout << "  q: quit program" << endl;
   cout << "Select an option: ";

   // get command
   cin >> command;

   // validate command
   while (!strchr("qyrim", command)) {
      cout << endl << "Invalid option. Please select a valid option: ";
      cin >> command;
   }

   // process command
   switch (command) {
      case 'i': this->getInitialInvestmentInput(); break;
      case 'm': this->getMonthlyDepositInput(); break;
      case 'r': this->getInterestRateInput(); break;
      case 'y': this->getInvestmentYearsInput(); break;
   }

   // return true unless command equals 'q' or quit
   return !(command == 'q');
}
/*       DisplayReport
* 
*  This function displays a report based on the private members of the current object
* 
* parameters
*     t_monthlyDeposit <bool> - if set to true report will include monthly deposits
********************************************************************************/
void Investment::DisplayReport(bool t_monthlyDeposit) {

   int months = this->GetInvestmentYears() * 12;            // get total months
   double openingAmount = this->GetInitialInvestment();     // set opening amount 
   double monthlyInterestRate = (this->GetInterestRate() / 100) / 12; // monthly interest rate
   double monthlyInterestEarned = 0.0;    // running total of monthly interest
   double yearlyInterestEarned = 0.0;     // running total of yearly interes

   // special string for report with/without monthly deposits
   string strMonthly = (t_monthlyDeposit ? "With" : "Without");

   cout << endl << endl;

   cout << "    Balance and Interest " << strMonthly << " Additional Monthly Deposits    " << endl;
   cout << "================================================================" << endl;
   cout << "  Year        Year End Balance     Year End Earned Interest     " << endl;
   cout << "----------------------------------------------------------------" << endl;

   // loop over every month
   for (int i = 1; i <= months; ++i) {

      // if processing monthly deposits, add the monthly deposit amount to the opening amount
      if (t_monthlyDeposit) {
         openingAmount += this->GetMonthlyDeposit();
      }

      // calculate interest earned this month
      monthlyInterestEarned = openingAmount * monthlyInterestRate;
      yearlyInterestEarned += monthlyInterestEarned;  // accumulated interest
      openingAmount += monthlyInterestEarned; // colsing balance

      // every 12 months, 1 year
      if (i % 12 == 0) {   // output report

         // use a string stream to get a "$" in front of the amount
         stringstream ssOpeningAmount, ssYearlyInterest;
         ssOpeningAmount << fixed << setprecision(2) << "$" << openingAmount;
         ssYearlyInterest << fixed << setprecision(2) << "$" << yearlyInterestEarned;

         cout << setw(6) << (i / 12)      // year number
            << setw(24) << ssOpeningAmount.str()  // opening amount
            << setw(29) << ssYearlyInterest.str() << endl; // yearly interest earned

         // reset yearly interest
         yearlyInterestEarned = 0;
      }
   }
}
/*       getInitialInvestmentInput
* 
*  private member function to get and validate input from console
*
********************************************************************************/
void Investment::getInitialInvestmentInput() {
   bool validInput = false;
   double input;
   while (!validInput) {
      cout << "+ Initial Investment Amout:   $";
      cin >> input;

      if (!cin || input < 0) {
         cout << "Input must be a non-negative number." << endl;
         cin.clear();
         cin.ignore(256, '\n');
      }
      else {
         validInput = true;
      }
   }

   this->SetInitialInvestment(input);
}
/*       getMonthlyDepositInput
* 
*  private member function to get and validate input from console
*
********************************************************************************/
void Investment::getMonthlyDepositInput() {
   bool validInput = false;
   double input;
   while (!validInput) {
      cout << "+ Monthly Deposit:   $";
      cin >> input;

      if (!cin || input < 0) {
         cout << "Input must be a non-negative number." << endl;
         cin.clear();
         cin.ignore(256, '\n');
      }
      else {
         validInput = true;
      }
   }

   this->SetMonthlyDeposit(input);
}
/*       getInterestRateInput
* 
*  private member function to get and validate input from console
*
********************************************************************************/
void Investment::getInterestRateInput() {
   bool validInput = false;
   double input;
   while (!validInput) {
      cout << "+ Annual Interest:   %";
      cin >> input;

      if (!cin || input < 0 || input > 100) {
         cout << "Interest rate must be a number between 0-100." << endl;
         cin.clear();
         cin.ignore(256, '\n');
      }
      else {
         validInput = true;
      }
   }

   this->SetInterestRate(input);
}
/*       getInvestmentYearsInput
* 
*  private member function to get and validate input from console
*
********************************************************************************/
void Investment::getInvestmentYearsInput() {
   bool validInput = false;
   int input;
   while (!validInput) {
      cout << "+ Number of years:   ";
      cin >> input;

      if (!cin || input < 0) {
         cout << "Input must be a non-negative number." << endl;
         cin.clear();
         cin.ignore(256, '\n');
      }
      else {
         validInput = true;
      }
   }

   this->SetInvestmentYears(input);
}
/*       SetInitialInvestment
* 
*  This function sets the m_initialInvestment member of the object
********************************************************************************/
void Investment::SetInitialInvestment(double t_initialInvestment) {
   this->m_initialInvestment = t_initialInvestment;
}
/*       SetMonthlyDeposit
* 
*  This function sets the m_monthlyDeposit member of the object
********************************************************************************/
void Investment::SetMonthlyDeposit(double t_monthlyDeposit) {
   this->m_monthlyDeposit = t_monthlyDeposit;
}
/*       SetInterestRate
* 
*  This function sets the m_compInterestRate member of the object
********************************************************************************/
void Investment::SetInterestRate(double t_compInterestRate) {
   this->m_compInterestRate = t_compInterestRate;
}
/*       SetInvestmentYears
* 
*  This function sets the m_numYears member of the object
********************************************************************************/
void Investment::SetInvestmentYears(int t_numYears) {
   this->m_numYears = t_numYears;
}
/*       GetInitialInvestment
* 
*  This function gets the m_initialInvestment member of the object
********************************************************************************/
double Investment::GetInitialInvestment() const {
   return this->m_initialInvestment;
}
/*       GetMonthlyDeposit
* 
*  This function gets the m_monthlyDeposit member of the object
********************************************************************************/
double Investment::GetMonthlyDeposit() const {
   return this->m_monthlyDeposit;
}
/*       GetInterestRate
* 
*  This function gets the m_compInterestRate member of the object
********************************************************************************/
double Investment::GetInterestRate() const {
   return this->m_compInterestRate;
}
/*       GetInvestmentYears
* 
*  This function gets the m_numYears member of the object
********************************************************************************/
int Investment::GetInvestmentYears() const {
   return this->m_numYears;
}
