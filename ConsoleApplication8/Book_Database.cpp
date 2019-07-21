/*******************************************************************
*   Book_Database.cpp
*   Steven Powell
*   Programming Assignment 3 - Book Database
*   
*   This program is entirely my own work
*******************************************************************/
#include "Book_Database.h"

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
	br->printRecord();
	return true;
}

// Remove a book from the list
BookRecord *Book_Database::removeBook(long stockNum)
{
	BookRecord *tempBr = new BookRecord;
	return tempBr;
}

// Search for a book by stock number
BookRecord *Book_Database::searchByStockNumber(long stockNum)
{
	BookRecord *tempBr = new BookRecord;
	return tempBr;
}

// Search for all books of the given classification
void Book_Database::searchByClassification(int cl)
{
}

// Search for all books whose cost is within the given range
void Book_Database::searchByCost(double min, double max)
{
}

// Get number of books of given stock number in stock 
int Book_Database::getNumberInStock(long sn)
{
	return 1;
}

// Print all items in the database
void Book_Database::PrintDatabase()
{
}

// Recursively remove any items from the list
void Book_Database::ClearDatabase(BookRecord *rt)
{
}

// Recursive search by classification
void Book_Database::searchByClassification(int cl, BookRecord *rt)
{
}

// Recursive search by cost range
void Book_Database::searchByCost(double min, double max, BookRecord *rt)
{
}

// Recursive print all
void Book_Database::PrintDatabase(BookRecord *rt)
{
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