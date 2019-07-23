/*******************************************************************
*   Book_Database.cpp
*   Steven Powell
*   Programming Assignment 3 - Book Database
*   
*   This program is entirely my own work
*******************************************************************/
#include "Book_Database.h"
#include<cstring>

// Class constructor
Book_Database::Book_Database()
{
	m_pRoot = NULL;
}

// Class destuctor
Book_Database::~Book_Database()
{
	m_pRoot = NULL;
	//ClearDatabase();
}

// Add the given book to the list
bool Book_Database::addBook(BookRecord *br)
{
    if(m_pRoot == NULL)
    {
        m_pRoot = br;
        return true;
    }

    return addBook(br, m_pRoot);

    // DELETE THIS LATER
    // Was an interative attempt to add the record
    //BookRecord *curBr = new BookRecord;
    //curBr = m_pRoot;

    //while(curBr != NULL)
    //{
    //    if(br->getStockNum() < curBr->getStockNum())
    //    {
    //        //Go left
    //        if(curBr->getLeft() == NULL)
    //        {
    //            //curBr->set
    //        }
    //        curBr = curBr->m_pLeft;
    //    }
    //    else if(br->getStockNum() > curBr->getStockNum())
    //    {
    //        //Go right
    //        curBr = curBr->m_pRight;
    //    }
    //    else if(br->getStockNum() == curBr->getStockNum())
    //    {
    //        //already exists: combine NumberOfBooks
    //        break;
    //    }
    //}

    //delete curBr;
    //curBr = NULL;
	//return true;
}

// Add the given book to the list
bool Book_Database::addBook(BookRecord *br, BookRecord *curBr)
{
    bool retVal = false;
    //cout << br->getStockNum() << ": Add (" << curBr->getStockNum() << ")" << endl;
    if(br->getStockNum() < curBr->getStockNum())
    {
        //cout << br->getStockNum() << ": Go left" << endl;
        if(curBr->m_pLeft == NULL)
        {
            curBr->m_pLeft = br;
            retVal = true;
        }
        else
        {
            retVal = addBook(br, curBr->m_pLeft);
        }
    }
    else if(br->getStockNum() > curBr->getStockNum())
    {
        //cout << br->getStockNum() << ": Go right" << endl;
        if(curBr->m_pRight == NULL)
        {
            curBr->m_pRight = br;
            retVal = true;
        }
        else
        {
            retVal = addBook(br, curBr->m_pRight);
        }
    }
    else if(br->getStockNum() == curBr->getStockNum())
    {
        //already exists: combine NumberOfBooks
        //cout << br->getStockNum() << " found" << endl;
        //cout << "numInStock: " << curBr->getNumberInStock() << " + "
        //     << br->getNumberInStock() << endl;
        curBr->setNumberInStock(br->getNumberInStock() + curBr->getNumberInStock());
        retVal = true;
    }

	return retVal;
}

// Remove a book from the list
BookRecord *Book_Database::removeBook(long stockNum)
{
    // Do cool things here.
	if(m_pRoot == NULL)
	{
		cout << "Database is empty" << endl;
		return NULL;
	}

	BookRecord *curBr = new BookRecord();
	curBr = searchByStockNumber(stockNum);

	// Case 1: Not found
	if(curBr == NULL)
	{
		delete curBr;
		return NULL;
	}

	BookRecord *parBr = new BookRecord();
	parBr = getParent(stockNum);

	if(curBr->m_pLeft == NULL && curBr->m_pRight == NULL)
	{
		// Case 2: Leaf node, not root, with 0 children
		if(parBr->m_pLeft->getStockNum() == stockNum)
		{
			parBr->m_pLeft = NULL;
		}
		else
		{
			parBr->m_pRight = NULL;
		}
		curBr->m_pLeft = NULL;
		curBr->m_pRight = NULL;
		return curBr;
	}
	else if(parBr == NULL && curBr->m_pLeft == NULL && curBr->m_pRight == NULL)
	{
		// Case 3: Remove leaf node, root, last in tree

		// Do cool stuff here
		return curBr;
	}
	else if(curBr->m_pLeft != NULL && curBr->m_pRight == NULL)
	{
		// Case 4: Node not root, not leaf, only left child
		if(parBr->m_pLeft->getStockNum() == stockNum)
		{
			parBr->m_pLeft = curBr->m_pLeft;
			curBr->m_pLeft = NULL;
			curBr->m_pRight = NULL;
			return curBr;
		}
		else if(parBr->m_pRight->getStockNum() == stockNum)
		{
			parBr->m_pRight = curBr->m_pRight;
			curBr->m_pLeft = NULL;
			curBr->m_pRight = NULL;
			return curBr;
		}
	}
	else if(parBr == NULL && curBr->m_pLeft != NULL && curBr->m_pRight == NULL)
	{
		// Case 5: Root node, 1 left child
		m_pRoot = curBr->m_pLeft;
		curBr->m_pLeft = NULL;
		curBr->m_pRight = NULL;
		return curBr;
	}
	else if(curBr->m_pLeft == NULL && curBr->m_pRight != NULL)
	{
		// Case 6: Node not root, not leaf, only right child
		if(parBr->m_pLeft->getStockNum() == stockNum)
		{
			parBr->m_pLeft = curBr->m_pLeft;
			curBr->m_pLeft = NULL;
			curBr->m_pRight = NULL;
			return curBr;
		}
		else if(parBr->m_pRight->getStockNum() == stockNum)
		{
			parBr->m_pRight = curBr->m_pRight;
			curBr->m_pLeft = NULL;
			curBr->m_pRight = NULL;
			return curBr;
		}
	}
	else if(parBr == NULL && curBr->m_pLeft != NULL && curBr->m_pRight == NULL)
	{
		// Case 7: Root node, 1 right child
		m_pRoot = curBr->m_pRight;
		curBr->m_pLeft = NULL;
		curBr->m_pRight = NULL;
		return curBr;
	}
	else if(parBr != NULL && curBr->m_pLeft != NULL && curBr->m_pRight != NULL)
	{
		// Case 8: Root node, 2 children
		// This does not work. Change getMinStockNumFromNode to getBottomMostLeafFromNode
		long minStockNum = getMinStockNumFromNode(curBr);
		BookRecord *tempBr = new BookRecord();
		tempBr = removeBook(minStockNum);

		if(parBr->m_pLeft->getStockNum() == stockNum)
		{
			parBr->m_pLeft = tempBr;
			curBr->m_pLeft = NULL;
			curBr->m_pRight = NULL;
			return curBr;
		}
		else if(parBr->m_pRight->getStockNum() == stockNum)
		{
			parBr->m_pRight = tempBr;
			curBr->m_pLeft = NULL;
			curBr->m_pRight = NULL;
			return curBr;
		}
	}

    return NULL;
}

BookRecord *Book_Database::getParent(long stockNum)
{
	if(m_pRoot == NULL)
    {
        return NULL;
    }
    return getParent(stockNum, m_pRoot);
}

BookRecord *Book_Database::getParent(long stockNum, BookRecord *curBr)
{
	// If parent is not found or is root node
	if(curBr == NULL || curBr->getStockNum() == stockNum)
	{
		return NULL;
	}

	if(stockNum < curBr->getStockNum())
	{
		//Check left
		if(curBr->m_pLeft->getStockNum() == stockNum)
		{
			return curBr;
		}
		else
		{
			return getParent(stockNum, curBr->m_pLeft);
		}
	}

	if(stockNum > curBr->getStockNum())
	{
		//Check right
		if(curBr->m_pRight->getStockNum() == stockNum)
		{
			return curBr;
		}
		else
		{
			return getParent(stockNum, curBr->m_pRight);
		}
	}
}

// Search for a book by stock number
BookRecord *Book_Database::searchByStockNumber(long stockNum)
{
    if(m_pRoot == NULL)
    {
        cout << "Database is empty.";
        return NULL;
    }
    return searchByStockNumber(stockNum, m_pRoot);
}

BookRecord *Book_Database::searchByStockNumber(long stockNum, BookRecord *curBr)
{
	if(curBr == NULL)
	{
		return NULL;
	}

    if(stockNum < curBr->getStockNum())
    {
        //go left
        return searchByStockNumber(stockNum, curBr->m_pLeft);
    }
    else if(stockNum > curBr->getStockNum())
    {
        //go right
        return searchByStockNumber(stockNum, curBr->m_pRight);
    }
    else if(stockNum == curBr->getStockNum())
    {
        return curBr;
    }

    return NULL;
}

// Search for all books of the given classification
void Book_Database::searchByClassification(int cl)
{
    if(m_pRoot != NULL)
	{
		searchByClassification(cl, m_pRoot);
	}
}

// Recursive search by classification
void Book_Database::searchByClassification(int cl, BookRecord *rt)
{
    if(rt != NULL)
	{
		searchByClassification(cl, rt->m_pLeft);

		if(rt->getClassification() == cl)
		{
			rt->printRecord();
		}

		searchByClassification(cl, rt->m_pRight);
	}
}

// Search for all books whose cost is within the given range
void Book_Database::searchByCost(double min, double max)
{
    if(m_pRoot != NULL)
	{
		searchByCost(min, max, m_pRoot);
	}
}

// Recursive search by cost range
void Book_Database::searchByCost(double min, double max, BookRecord *rt)
{
	if(rt != NULL)
	{
		searchByCost(min, max, rt->m_pLeft);

		if(rt->getCost() >= min && rt->getCost() <= max)
		{
			rt->printRecord();
		}

		searchByCost(min, max, rt->m_pRight);
	}
}

// Get number of books of given stock number in stock 
int Book_Database::getNumberInStock(long sn)
{
    if(m_pRoot == NULL)
	{
		return 0;
	}
	else
	{
		BookRecord *tempBr = new BookRecord;
		tempBr = searchByStockNumber(sn);
		if(tempBr == NULL)
		{
			return 0;
		}
		else
		{
			return tempBr->getNumberInStock();
		}
	}
	return 0;
}

// Print all items in the database
void Book_Database::PrintDatabase()
{
    if(m_pRoot == NULL)
    {
        cout << "Database is empty." << endl;
    }
    else
    {
        PrintDatabase(m_pRoot);
    }
}

long Book_Database::getMinStockNumFromNode(BookRecord *curBr)
{
	if(curBr == NULL)
	{
		return NULL;
	}

	if(curBr->m_pLeft == NULL && curBr->m_pRight == NULL)
	{
		return curBr->getStockNum();
	}

	while(curBr->m_pLeft != NULL)
	{
		curBr = curBr->m_pLeft;
	}

	return curBr->getStockNum();
}

// Recursive print all
void Book_Database::PrintDatabase(BookRecord *rt)
{
    if(rt != NULL)
    {
        if(rt->m_pLeft != NULL)
        {
            PrintDatabase(rt->m_pLeft);
        }
        rt->printRecord();
        if(rt->m_pRight != NULL)
        {
            PrintDatabase(rt->m_pRight);
        }
    }
}

// Recursively remove any items from the list
void Book_Database::ClearDatabase(BookRecord *rt)
{
    // Do cool things here.
}

//--------------------------------------------
// Function: readDatabase()
// Purpose: Read the inventory data file and
//		build the list.
//--------------------------------------------
bool Book_Database::readDatabase(const char *filename)
{
    char     line[128];
    int      numBooks;
    // define other variables here as needed

    m_InFile.open(filename, ifstream::in); 
    if(!m_InFile.is_open())
    {
        // m_InFile.is_open() returns false if the file could not be found or
        //    if for some other reason the open failed.
        cout << "Unable to open file" << filename << "\nProgram terminating...\n";
        return false;
    }
    // Read number of books
    getNextLine(line, 127);
    numBooks = atoi(line);	// Convert the string to an int
         // Note: you can use atof(line) to convert a string to a double

    for(int i=0; i<numBooks; i++)
    {
        BookRecord *tempBr = new BookRecord();
        // stockNum
        getNextLine(line, 128);
        tempBr->setStockNum(atol(line));

        // title
        getNextLine(line, 128);
        char tempTitle[128];
        strcpy(tempTitle, line);
        tempBr->setTitle(tempTitle);

        // classification
        getNextLine(line, 128);
        tempBr->setClassification(atoi(line));

        // cost
        getNextLine(line, 128);
        tempBr->setCost(atof(line));

        // numInStock
        getNextLine(line, 128);
        tempBr->setNumberInStock(atoi(line));

        addBook(tempBr);

    }
    return true;
}

//-------------------------------------------------
// getNextLine() 
// Read a line from a data file.  
// Note: The second argument is of type size_t.
//       This is just an int but the compiler
//       will give you a warning if you use 
//       int instead of this #defined name
//       Another confusing example of Micro-soft
//       at work.
//-------------------------------------------------
bool Book_Database::getNextLine(char *line, int lineLen)
{
    int    done = false;
    while(!done)
    {
        m_InFile.getline(line, 128);
        
        if(m_InFile.good())    // If a line was successfully read
        {
            if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else return true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(line, "");	// Reached the end of the file
            return false;
        }
    } // end while
    return false;  // You can never get here but include the return anyway to keep the
                   // compiler from warning you that not all paths return a value.
}