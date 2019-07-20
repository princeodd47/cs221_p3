/*******************************************************************
*   BookRecord.h
*   Steven Powell
*   Programming Assignment 2 - Book Inventory
*   
*   This program is entirely my own work
*******************************************************************/
#ifndef RECORD_H
#define RECORD_H
#endif

class BookRecord {
    private:
        char m_sTitle[128];
        long m_lStockNum;
        int m_iClassification;
        double m_dCost;
        int m_iCount;
        BookRecord *m_pNext;
    public:
		BookRecord *m_pLeft;
		BookRecord *m_pRight;
        BookRecord();
        BookRecord(const char *title, long sn, int cl, double cost);
        ~BookRecord();
        void getTitle(char *title);
        void setTitle(const char *title);
        long getStockNum();
        void setStockNum(long sn);
        int getClassification();
        void setClassification(int cl);
        double getCost();
        void setCost(double c);
        int getNumberInStock();
        void setNumberInStock(int count);
        void printRecord();
        void setNext(BookRecord *next);
        BookRecord *getNext();
};
