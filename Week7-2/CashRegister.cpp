/******************************************************************************
 Week 7 - Assignment 2
 Cash Register
 CISS 242-B
 
 <description>  Constructors, accessor functions and mutators for the
                CashRegister Class.
 
 <author> John Carty
 <date> 4 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/

#include "CashRegister.h"

CashRegister::CashRegister(){
    
    cost = 0;
    quantity = 0;
    taxRate = .06;
    tax = 0;
    profitRate = .3;
    subtotal = 0;
    total = 0;
    
};

void CashRegister::setFields(double c, int q){
    cost = c*q;
    quantity = q;
    tax = cost*taxRate;
    subtotal = (cost*profitRate) + cost;
    total = subtotal + tax;
    
}

double CashRegister::getTax(){
    return tax;
}
double CashRegister::getSubtotal(){
    return subtotal;
}
double CashRegister::getTotal(){
    return total;
}

