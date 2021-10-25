/*       CS210 - Project2 - Airgead Banking 
*
*     main.cpp
*        driver program for Investment class
*
*  date: 9/30/2021
*  author: johnny lingafelter
******************************************************************************/
#include "Investment.h"
#include <iostream>        // for make_unique

int main() {
   // declare an instance of our class using garbage collection
   auto myInvestment = std::make_unique<Investment>();

   myInvestment->GetUserInput();       // get input from the command line

   // always display reports once, so use do...while()
   do {
      myInvestment->DisplayReport();         // display without monthly deposit
      myInvestment->DisplayReport(true);     // display with monthly deposit
   } while (myInvestment->GetUserAction());  // show menu and get user action

   return 0;
}
