/******************************************************************************
 Week 7 - Assignment 2
 Cash Register
 CISS 242-B
 
 <description>  Header file for the CashRegister Class
 
 <author> John Carty
 <date> 4 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/

#ifndef CashRegister_h
#define CashRegister_h


class CashRegister
{
private:
    double cost;
    double taxRate;
    int quantity;
    double profitRate;
    double tax;
    double total;
    double subtotal;
    
public:
    CashRegister();
    void setFields(double c, int q);
    double getSubtotal();
    double getTax();
    double getTotal();
};

#endif /* CashRegister_h */
