#include "Book_Database.h"
#include <cstring>
#include <iostream>
using namespace std;


void test_BookRecordDefault()
{
    BookRecord *br = new BookRecord();
    char tempTitle[32];
    br->getTitle(tempTitle);

    if(strcmp(tempTitle, "") != 0 ||
       br->getStockNum() != 0 ||
       br->getClassification() != 0 ||
       br->getCost() != 0.00 ||
       br->getNumberInStock() != 0 ||
       br->getNext() != NULL)
    {
        cout << "BookRecordDefault cosntructor test failed" << endl;
    }
    else
    {
        cout << "BookRecordDefault cosntructor test passed" << endl;
    }

    br = NULL;
    delete br;
}

void test_getTitle()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    char tempTitle[32];
    br->getTitle(tempTitle);
    if(strcmp(tempTitle, "foo bar") == 0)
    {
        cout << "getTitle test passed" << endl;
    } else {
        cout << "getTitle test failed" << endl;
    }

    br = NULL;
    delete br;
}

void test_setTitle()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    char tempTitle[128];
    br->setTitle("baz quz");
    br->getTitle(tempTitle);
    if(strcmp(tempTitle, "baz quz") == 0)
    {
        cout << "setTitle test passed" << endl;
    } else {
        cout << "setTitle test failed" << endl;
    }

    br = NULL;
    delete br;
}

void test_getStockNum()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    if(br->getStockNum() == 123456)
    {
        cout << "getStockNum test passed" << endl;
    } else {
        cout << "getStockNum test failed" << endl;
    }

    br = NULL;
    delete br;
}

void test_setStockNum()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    br->setStockNum(789012);
    if(br->getStockNum() == 789012)
    {
        cout << "setStockNum test passed" << endl;
    } else {
        cout << "setStockNum test failed" << endl;
    }

    br = NULL;
    delete br;
}

void test_getClassification()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    if(br->getClassification() == 1)
    {
        cout << "getClassification test passed" << endl;
    } else {
        cout << "getClassification test failed" << endl;
    }

    br = NULL;
    delete br;
}

void test_setClassification()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    br->setClassification(4);
    if(br->getClassification() == 4)
    {
        cout << "getClassification test passed" << endl;
    } else {
        cout << "getClassification test failed" << endl;
    }

    br = NULL;
    delete br;
}

void test_getCost()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    double expected_cost = 3.45;
    if(br->getCost() == expected_cost)
    {
        cout << "getCost test passed" << endl;
    } else {
        cout << "getCost test failed: ";
        cout << "cost should = " << expected_cost << ", cost = " << br->getCost() << endl;
    }

    br = NULL;
    delete br;
}

void test_setCost()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    double cost = 54.54;
    br->setCost(cost);
    if(cost == 54.54)
    {
        cout << "setCost test passed" << endl;
    } else {
        cout << "setCost test failed" << endl;
    }

    br = NULL;
    delete br;
}

void test_getNumberInStock()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 5, 3.45);
    if(br->getNumberInStock() == 1)
    {
        cout << "getNumberInStock test passed" << endl;
    } else {
        cout << "getNumberInStock test failed" << endl;
    }

    br = NULL;
    delete br;
}

void test_setNumberInStock()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 5, 3.45);
    br->setNumberInStock(14);
    if(br->getNumberInStock() == 14)
    {
        cout << "setNumberInStock test passed" << endl;
    } else {
        cout << "setNumberInStock test failed" << endl;
    }

    br = NULL;
    delete br;
}

void test_printRecord()
{
    char tempTitle[32];
    strcpy(tempTitle , "foo bar");

    BookRecord *br = new BookRecord(tempTitle, 123456, 5, 3.45);
    cout << "test_printRecord needs to be checked manually" << endl;

    br->printRecord();

    br = NULL;
    delete br;
}

void test_setNext_getNext()
{
    
    BookRecord *br_1 = new BookRecord("foo", 123456, 5, 3.45);
    BookRecord *br_2 = new BookRecord("bar", 654321, 1, 2.12);
    br_1->setNext(br_2);
    BookRecord *test_br = br_1->getNext();

    char tempTitle[32];
    test_br->getTitle(tempTitle);
    if(strcmp(tempTitle, "bar") == 0)
    {
        cout << "setNext_getNext test passed" << endl;
    } else {
        cout << "setNext_getNext test failed" << endl;
    }

    br_1 = NULL;
    delete br_1;
    br_2 = NULL;
    delete br_2;
}


int main()
{
	cout << "================" << endl;
    cout << "BookRecord Tests" << endl;
	cout << "================" << endl;
    test_BookRecordDefault();
    test_getTitle();
    test_setTitle();
    test_getStockNum();
    test_setStockNum();
    test_getClassification();
    test_setClassification();
    test_getCost();
    test_setCost();
    test_getNumberInStock();
    test_setNumberInStock();
    test_printRecord();
    test_setNext_getNext();
    cout << endl;

	cout << "================" << endl;
    cout << "Book_DatabaseTests" << endl;
	cout << "================" << endl;
    //auto tests

    //manual tests


	system("pause");
    return 0;
}
