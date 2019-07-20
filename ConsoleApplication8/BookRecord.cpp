/*******************************************************************
*   BookRecord.cpp
*   Steven Powell
*   Programming Assignment 2 - Book Inventory
*   
*   This program is entirely my own work
*******************************************************************/
#include "BookRecord.h"
#include <cstring>
#include <iostream>
using namespace std;

//--------------------------------------------------------
// Default class constructor
//--------------------------------------------------------
BookRecord::BookRecord() {
    strcpy(m_sTitle, "");
    m_lStockNum = 0;
    m_iClassification = 0;
    m_dCost = 0.0;
    m_iCount = 0;
    m_pNext = NULL;
}

//--------------------------------------------------------
// Overloaded class constructor
//--------------------------------------------------------
BookRecord::BookRecord(const char *title, long sn, int cl, double cost)
{
    strcpy(m_sTitle, title);
    m_lStockNum = sn;
    m_iClassification = cl;
    m_dCost = cost;
    m_iCount = 1;
    m_pNext = NULL;
}

//--------------------------------------------------------
// Default class destructor
//--------------------------------------------------------
BookRecord::~BookRecord() {
}

//--------------------------------------------------------
// Sets character array pointer argument title to m_stitle
//--------------------------------------------------------
void BookRecord::getTitle(char *title)
{
    strcpy(title, m_sTitle);
}

//--------------------------------------------------------
// Sets m_sTitle to array pointer argument
//--------------------------------------------------------
void BookRecord::setTitle(const char *title)
{
    strcpy(m_sTitle, title);
}

//--------------------------------------------------------
// Returns m_lStockNum
//--------------------------------------------------------
long BookRecord::getStockNum()
{
    return m_lStockNum;
}

//--------------------------------------------------------
// Sets m_lStockNum to sn argument
//--------------------------------------------------------
void BookRecord::setStockNum(long sn)
{
    m_lStockNum = sn;
}

//--------------------------------------------------------
// Sets integer argument cl to m_iClassification
//--------------------------------------------------------
int BookRecord::getClassification()
{
    return m_iClassification;
}

//--------------------------------------------------------
// Sets m_iClassification to argument cl
//--------------------------------------------------------
void BookRecord::setClassification(int cl)
{
    m_iClassification = cl;
}

//--------------------------------------------------------
// 
//--------------------------------------------------------
double BookRecord::getCost()
{
    return m_dCost;
}
//--------------------------------------------------------
// Sets m_dCost to argument c
//--------------------------------------------------------
void BookRecord::setCost(double c)
{
    m_dCost = c;
}

//--------------------------------------------------------
// Returns m_iCount
//--------------------------------------------------------
int BookRecord::getNumberInStock()
{
    return m_iCount;
}

//--------------------------------------------------------
// Sets m_iCount to argument count
//--------------------------------------------------------
void BookRecord::setNumberInStock(int count)
{
    m_iCount = count;
}

//--------------------------------------------------------
// Prints BookRecord object
// 
// Title   Stock_Num   Classification    Cost   In Stock
// For example:
// Introduction to C++   12345    613   49.95   5
//--------------------------------------------------------
void BookRecord::printRecord()
{
    cout << m_sTitle << " " << m_lStockNum << " " << m_iClassification << " " << m_dCost << " " << m_iCount << endl;
}

//--------------------------------------------------------
//
//--------------------------------------------------------
void BookRecord::setNext(BookRecord *next)
{
    m_pNext = next;
}

//--------------------------------------------------------
//
//--------------------------------------------------------
BookRecord *BookRecord::getNext()
{
    return m_pNext;
}

