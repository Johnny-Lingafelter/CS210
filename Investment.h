/*       CS210 - Project2 - Airgead Banking 
*
*     Investment.h
*        header file for the Investment class
*
*  date: 9/30/2021
*  author: johnny lingafelter
*********************************************/
#ifndef PROJECT2_INVESTMENT_H
#define PROJECT2_INVESTMENT_H

class Investment {
   public:
      Investment() 
         :  m_initialInvestment(-1.0),
            m_monthlyDeposit(-1.0),
            m_compInterestRate(-1.0),
            m_numYears(0) {}

      Investment(double t_initialInvestment, double t_monthlyDeposit,
         double t_compInterestRate, int t_numYears)
         :  m_initialInvestment(t_initialInvestment),
            m_monthlyDeposit(t_monthlyDeposit),
            m_compInterestRate(t_compInterestRate),
            m_numYears(t_numYears) {}

      void SetInitialInvestment(double t_initialInvestment);
      void SetMonthlyDeposit(double t_monthlyDeposit);
      void SetInterestRate(double t_compInterestRate);
      void SetInvestmentYears(int t_numYears);

      double GetInitialInvestment() const;
      double GetMonthlyDeposit() const;
      double GetInterestRate() const;
      int GetInvestmentYears() const;

      void DisplayReport(bool t_monthlyDeposit = false);

      void GetUserInput();
      bool GetUserAction();

   private:
      double m_initialInvestment;
      double m_monthlyDeposit;
      double m_compInterestRate;
      int m_numYears;

      void getInitialInvestmentInput();
      void getMonthlyDepositInput();
      void getInterestRateInput();
      void getInvestmentYearsInput();
};

#endif // !PROJECT2_INVESTMENT_H