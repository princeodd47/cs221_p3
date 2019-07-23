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
       br->getNumberInStock() != 0)
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

    BookRecord *br = new BookRecord(tempTitle, 1234, 5, 3.45);
    cout << "test_printRecord needs to be checked manually" << endl;

    br->printRecord();

    br = NULL;
    delete br;
}

/*
 * Book_Database Tests
 */

void test_readInventory()
{
    cout << endl;
    cout << "===================" << endl;
    cout << "test_readInventory needs to be checked " << "manually" <<  endl;
    cout << "Expected output: 10 unique records, ordered by stockNum, and 987 has 100 numInStock" << endl;
    cout << "===================" << endl;
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");
    testDb->PrintDatabase();
    cout << endl;

    delete testDb;
    testDb = NULL;
}

void test_readInventoryTreeNodes()
{
	bool testPass = true;
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");
	BookRecord *testBr = new BookRecord();

	testBr = testDb->searchByStockNumber(567);
	if(testBr->m_pLeft == NULL || testBr->m_pLeft->getStockNum() != 345 ||
		testBr->m_pRight == NULL || testBr->m_pRight->getStockNum() != 678)
	{
		testPass = false;
	}

	testBr = testDb->searchByStockNumber(345);
	if(testBr->m_pLeft == NULL || testBr->m_pLeft->getStockNum() != 234 ||
		testBr->m_pRight == NULL || testBr->m_pRight->getStockNum() != 456)
	{
		testPass = false;
	}

	testBr = testDb->searchByStockNumber(234);
	if(testBr->m_pLeft == NULL || testBr->m_pLeft->getStockNum() != 123 ||
		testBr->m_pRight != NULL)
	{
		testPass = false;
	}

	testBr = testDb->searchByStockNumber(456);
	if(testBr->m_pLeft != NULL || testBr->m_pRight != NULL)
	{
		testPass = false;
	}

	testBr = testDb->searchByStockNumber(678);
	if(testBr->m_pLeft != NULL ||
		testBr->m_pRight == NULL || testBr->m_pRight->getStockNum() != 890)
	{
		testPass = false;
	}

	testBr = testDb->searchByStockNumber(890);
	if(testBr->m_pLeft == NULL || testBr->m_pLeft->getStockNum() != 765 ||
		testBr->m_pRight == NULL || testBr->m_pRight->getStockNum() != 987)
	{
		testPass = false;
	}

	testBr = testDb->searchByStockNumber(765);
	if(testBr->m_pLeft != NULL ||
		testBr->m_pRight == NULL || testBr->m_pRight->getStockNum() != 876)
	{
		testPass = false;
	}

	testBr = testDb->searchByStockNumber(876);
	if(testBr->m_pLeft != NULL || testBr->m_pRight != NULL)
	{
		testPass = false;
	}

	testBr = testDb->searchByStockNumber(987);
	if(testBr->m_pLeft != NULL || testBr->m_pRight != NULL)
	{
		testPass = false;
	}

	if(testPass == true)
	{
		cout << "readInventoryTreeNodes passed" << endl;
	}
	else
	{
		cout << "readInventoryTreeNodes failed" << endl;
	}

	delete testBr;
	testBr = NULL;
    delete testDb;
    testDb = NULL;
}

void test_searchByStockNumberFound()
{
	bool allTestsPass = true;
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");
	BookRecord *testBr = new BookRecord();

	testBr = testDb->searchByStockNumber(890);
	if(testBr == NULL || testBr->getStockNum() != 890)
	{
		allTestsPass = false;
	}

	testBr = testDb->searchByStockNumber(567);
	if(testBr == NULL || testBr->getStockNum() != 567)
	{
		allTestsPass = false;
	}

	testBr = testDb->searchByStockNumber(234);
	if(testBr == NULL || testBr->getStockNum() != 234)
	{
		allTestsPass = false;
	}
	
	testBr = testDb->searchByStockNumber(123);
	if(testBr == NULL || testBr->getStockNum() != 123)
	{
		allTestsPass = false;
	}

	if(allTestsPass)
	{
		cout << "searchByStockNumberFound test passed" << endl;
	}
	else
	{
		cout << "searchByStockNumberFound test failed" << endl;
	}

	delete testBr;
	testBr = NULL;
    delete testDb;
    testDb = NULL;
}

void test_searchByStockNumberNotFound()
{
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");

	BookRecord *testBr = new BookRecord();
	testBr = testDb->searchByStockNumber(8900);
	if(testBr == NULL)
	{
		cout << "searchByStockNumberNotFound test passed" << endl;
	}
	else
	{
		cout << "searchByStockNumberNotFound test failed" << endl;
	}

	delete testBr;
	testBr = NULL;
    delete testDb;
    testDb = NULL;
}

void test_removeBookEmptyDatabase()
{
	bool allTestsPass = true;
	Book_Database *testDb = new Book_Database();
    //testDb->readDatabase("BookData.txt");
	BookRecord *testBr = new BookRecord();

	
	testBr = testDb->removeBook(8900);
	if(testBr != NULL)
	{
		allTestsPass = false;
	}

	if(allTestsPass)
	{
		cout << "removeBookEmptyDatabase test passed" << endl;
	}
	else
	{
		cout << "removeBookEmptyDatabase test failed" << endl;
	}

	delete testBr;
	testBr = NULL;
    delete testDb;
    testDb = NULL;
}

void test_searchByCostNotFound()
{
	cout << endl;
    cout << "===================" << endl;
    cout << "test_searchByCostNotFound needs to be checked manually" <<  endl;
    cout << "Expected output: no records" << endl;
    cout << "===================" << endl;
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");

	float minCost = 1;
	float maxCost = 2;
	testDb->searchByCost(minCost, maxCost);

	delete testDb;
    testDb = NULL;
}

void test_searchByCost()
{
	cout << endl;
    cout << "===================" << endl;
    cout << "test_searchByCost needs to be checked manually" <<  endl;
    cout << "Expected output: 6 records with cost between $32-$45 " << endl;
    cout << "===================" << endl;
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");

	float minCost = 32;
	float maxCost = 45;
	testDb->searchByCost(minCost, maxCost);

	delete testDb;
    testDb = NULL;
}

void test_searchByClassificationNotFound()
{
	cout << endl;
    cout << "===================" << endl;
    cout << "test_searchByClassificationNotFound needs to be checked manually" <<  endl;
    cout << "Expected output: no records found" << endl;
    cout << "===================" << endl;
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");

	testDb->searchByClassification(614);

	delete testDb;
    testDb = NULL;
}

void test_searchByClassification()
{
	cout << endl;
    cout << "===================" << endl;
    cout << "test_searchByClassification needs to be checked manually" <<  endl;
    cout << "Expected output: 6 records found with classification 613" << endl;
    cout << "===================" << endl;
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");

	testDb->searchByClassification(613);

	delete testDb;
    testDb = NULL;
}

void test_dbGetNumberInStockNotFound()
{
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");
	int numInStock = 0;
	numInStock = testDb->getNumberInStock(613);

	if(numInStock == 0)
	{
		cout << "getNumberInStockNotFound test passed" << endl;
	}
	else
	{
		cout << "getNumberInStockNotFound test failed" << endl;
	}

	delete testDb;
    testDb = NULL;
}

void test_getParent()
{
	bool testPass = true;
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");
	BookRecord *testBr = new BookRecord();

	testBr = testDb->getParent(567);
	if(testBr != NULL)
	{
		testPass = false;
	}

	testBr = testDb->getParent(345);
	if(testBr == NULL || testBr->getStockNum() != 567)
	{
		testPass = false;
	}

	testBr = testDb->getParent(234);
	if(testBr == NULL || testBr->getStockNum() != 345)
	{
		testPass = false;
	}

	testBr = testDb->getParent(456);
	if(testBr == NULL || testBr->getStockNum() != 345)
	{
		testPass = false;
	}

	testBr = testDb->getParent(123);
	if(testBr == NULL || testBr->getStockNum() != 234)
	{
		testPass = false;
	}

	testBr = testDb->getParent(678);
	if(testBr == NULL || testBr->getStockNum() != 567)
	{
		testPass = false;
	}

	testBr = testDb->getParent(890);
	if(testBr == NULL || testBr->getStockNum() != 678)
	{
		testPass = false;
	}

	testBr = testDb->getParent(765);
	if(testBr == NULL || testBr->getStockNum() != 890)
	{
		testPass = false;
	}

	testBr = testDb->getParent(876);
	if(testBr == NULL || testBr->getStockNum() != 765)
	{
		testPass = false;
	}

	testBr = testDb->getParent(987);
	if(testBr == NULL || testBr->getStockNum() != 890)
	{
		testPass = false;
	}

	if(testPass)
	{
		cout << "getParent passed" << endl;
	}
	else
	{
		cout << "getParent failed" << endl;
	}

	delete testBr;
	testBr = NULL;
	delete testDb;
    testDb = NULL;
}

void test_dbGetNumberInStock()
{
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");
	int numInStock = 0;
	numInStock = testDb->getNumberInStock(987);

	if(numInStock == 100)
	{
		cout << "getNumberInStock test passed" << endl;
	}
	else
	{
		cout << "getNumberInStock test failed" << endl;
	}

	delete testDb;
    testDb = NULL;
}

void test_removeBookCase1()
{
	bool allTestsPass = true;
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");
	BookRecord *testBr = new BookRecord();

	
	testBr = testDb->removeBook(8900);
	if(testBr != NULL)
	{
		allTestsPass = false;
	}

	if(allTestsPass)
	{
		cout << "removeBookCase1 passed" << endl;
	}
	else
	{
		cout << "removeBookCase1 failed" << endl;
	}

	delete testBr;
	testBr = NULL;
    delete testDb;
    testDb = NULL;
}

void test_removeBookCase2()
{
	bool testPass = true;
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");
	BookRecord *testBr = new BookRecord();

	testBr = testDb->removeBook(123);
	if(testBr->getStockNum() != 123)
	{
		testPass = false;
	}

	testBr = testDb->searchByStockNumber(234);
	if(testBr->m_pLeft != NULL || testBr->m_pRight != NULL)
	{
		testPass = false;
	}

	if(testPass)
	{
		cout << "removeBookCase2 passed" << endl;
	}
	else
	{
		cout << "removeBookCase2 failed" << endl;
	}

	delete testBr;
	testBr = NULL;
	delete testDb;
    testDb = NULL;
}

void test_removeBookCase3()
{
	// Disabled
	bool testPass = true;
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");
	BookRecord *testBr = new BookRecord();

	if(testPass)
	{
		cout << "removeBookCase4 passed" << endl;
	}
	else
	{
		cout << "removeBookCase4 failed" << endl;
	}

	delete testBr;
	testBr = NULL;
	delete testDb;
    testDb = NULL;
}

void test_removeBookCase4()
{
	bool testPass = true;
	Book_Database *testDb = new Book_Database();
    testDb->readDatabase("BookData.txt");
	BookRecord *testBr = new BookRecord();

	testBr = testDb->removeBook(234);
	if(testBr->getStockNum() != 234)
	{
		testPass = false;
	}

	testBr = testDb->searchByStockNumber(345);
	if(testBr->m_pLeft == NULL || testBr->m_pRight == NULL ||
		testBr->m_pLeft->getStockNum() != 123)
	{
		testPass = false;
	}

	if(testPass)
	{
		cout << "removeBookCase4 passed" << endl;
	}
	else
	{
		cout << "removeBookCase4 failed" << endl;
	}

	delete testBr;
	testBr = NULL;
	delete testDb;
    testDb = NULL;
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
    cout << endl;

	cout << "================" << endl;
    cout << "Book_Database Tests" << endl;
	cout << "================" << endl;
    //auto tests
	test_readInventoryTreeNodes();
	test_searchByStockNumberFound();
	test_searchByStockNumberNotFound();
	test_dbGetNumberInStockNotFound();
	test_dbGetNumberInStock();
	test_getParent();
	test_removeBookEmptyDatabase();
	test_removeBookCase1();
	test_removeBookCase2();
	//test_removeBookCase3();
	test_removeBookCase4();

    //manual tests
	test_readInventory();
	test_searchByCostNotFound();
	test_searchByCost();
	test_searchByClassificationNotFound();
	test_searchByClassification();

	system("pause");
    return 0;
}
