#ifndef XYZEMPLOYEETESTUTILS_H
#define XYZEMPLOYEETESTUTILS_H

#include "XyzEmployeeTypes.H"
#include <string>
using namespace std;

namespace XyzTestData
{
    enum
    {
        NamesFirstIdx    = 0,    // Starting index of first/last names
        FNamesLastIdx    = 34,   // Total 35 first names
        LNamesLastIdx    = 24,   // Total 25 last names
        DOBStartYear     = 1965,
        DOBEndYear       = 2002,
        DOJStartYear     = 1986,
        DOJEndYear       = 2023,
        MinLeavesBalance = 0,
        MaxLeavesBalance = 22,

        // Summary record field lengths
        EmpNameLength      = 16,  // | Employee name |
        EmpIdLength        = 11,  // | XYZ0001I |
        EmpTypeLength      = 13,  // | Contractor |
        EmpStatusLength    = 11,  // | Resigned |
        EmpGenderLength    = 9,   // | Female |
        EmpDateLength      = 20,  // | 24 September 1984 |
        EmpLeavesLength    = 17,  // | Leaves Balance |
        EmpExtAgencyLength = 13,  // | Ext Agency |
        EmpCollegeLength   = 17,  // | IIIT Hyderabad |
        EmpBranchLength    = 9,   // | CSIT |
        EmpRecordLength    = 160, // adding all above values + 2 * 20
    };

    string mFirstName[] = {"Aditya", "Shiva", "Ramakrishna", "Vijayanand", "Suresh",
                           "Swathi", "Anusha", "Keerthi", "Shivani", "Ujwala",
                           "Rajesh", "Somanath", "Praveen", "Arun", "Ajay",
                           "Sravani", "Udayasri", "Usha", "Karthika", "Vani",
                           "Amit", "Manish", "Phani", "Vinod", "Naveen",
                           "Sowjanya", "Preethi", "Sirisha", "Priya", "Kavitha",
                           "Chaitanya", "Karthik", "Mohan", "Vishwanath", "Ravi"};
    string mLastName[] = {"Sharma", "Kulkarni", "Reddy", "Naidu", "Sastry",
                          "Bhagavathula", "Josyula", "Chatterjee", "Choudhary", "Roy",
                          "Deshmukh", "Gupta", "Desai", "Singh", "Patel",
                          "Shah", "Agarwal", "Chopra", "Khan", "Thakur",
                          "Mukherjee", "Mishra", "Mehta", "Ghosh", "Kumar"};
    string mEmpStatus[] = {"NA", "Active", "Inactive", "Resigned"};
    string mEmpType[] = {"NA", "Full-Time", "Contractor", "Intern"};
    string mEmpTypeKeyword = {"X", "F", "C", "I"};
    string mExtAgency[] = {"NA", "Avengers", "Justice League", "X-Men"};
    string mCollege[] = {"NA", "IIT Delhi", "IIT Mumbai", "IIT Kanpur", "IIT Hyderabad",
                         "NIT Warangal", "NIT Tiruchi", "IIIT Hyderabad"};
    string mBranch[] = {"NA", "CSE", "CSIT", "ECE"};
};

string getEmpName();
string getEmpId(uint64 empSeqNumParm,
                XyzEmployeeTypes::XyzEmpType empTypeParm);
XyzEmployeeTypes::XyzEmpType getEmpType();
XyzEmployeeTypes::XyzEmpStatus getEmpStatus();
XyzDate* getEmpDOB();
XyzDate* getEmpDOJ();
XyzDate* getEmpDOL(XyzDate* dojParm);
uint64 getEmpLeavesBalance();
XyzEmployeeTypes::XyzExtAgency getEmpExtAgency();
XyzEmployeeTypes::XyzHiringCollege getEmpCollege();
XyzEmployeeTypes::XyzHiringBranch getEmpBranch();

// helper functions
// get a random number between the start and end numbers (including them)
int getRandomNumber(int startNumParm,
                      int endNumParm);
// Fill the Date structure with random values for day/month/year
XyzDate* pGetDate(uint32 minYearParm,
                  uint32 maxYearParm);
string getPaddedSequenceNumber(uint64 empSeqNumParm);
void drawLine(int numParm);

#endif
