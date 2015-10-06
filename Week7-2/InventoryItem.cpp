/******************************************************************************
 Week 7 - Assignment 2
 Cash Register
 CISS 242-B
 
 <description> Constructors, accessor functions and mutators for the
 Circle Class. Circle can either be declared with no
 arguments as Circle or with a double as Circle(double)
 
 <author> John Carty
 <date> 4 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/


#include "InventoryItem.h"

// Private member function.
void InventoryItem::createDescription(int size, char *value)
{
    // Allocate the default amount of memory for description.
    description = new char [size];
    
    // Store a value in the memory.
    strcpy(description, value);
}

// Constructor #1
InventoryItem::InventoryItem()
{
    // Store an empty string in the description
    // attribute.
    createDescription(DEFAULT_SIZE, "");
    
    // Initialize cost and units.
    cost = 0.0;
    units = 0;
}

// Constructor #2
InventoryItem::InventoryItem(char *desc)
{
    // Allocate memory and store the description.
    createDescription(strlen(desc), desc);
    
    // Initialize cost and units.
    cost = 0.0;
    units = 0;
}

// Constructor #3
InventoryItem::InventoryItem(char *desc, double c, int u)
{
    // Allocate memory and store the description.
    createDescription(strlen(desc), desc);
    
    // Assign values to cost and units.
    cost = c;
    units = u;
}

// Destructor
InventoryItem::~InventoryItem()
{
    delete [] description;
}

// Mutator functions
void InventoryItem::setDescription(char *d)
{
    strcpy(description, d);
}

void InventoryItem::setCost(double c)
{
    cost = c;
}

void InventoryItem::setUnits(int u)
{
    units = u;
}

void InventoryItem::adjustUnits(int u){
    units -= u;
}

// Accessor functions
const char *InventoryItem::getDescription() const
{
    return description;
}

double InventoryItem::getCost() const
{
    return cost;
}

int InventoryItem::getUnits() const
{
    return units;
}