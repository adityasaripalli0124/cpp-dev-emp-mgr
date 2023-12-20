
#include "XyzEmployeeTestUtils.H"
#include <iostream>
#include <random>
using namespace std;

string getEmpName()
{
    return to_string(XyzTestData::mFirstName[getRandomNumber(XyzTestData::NamesFirstIdx,
                                                             XyzTestData::FNamesLastIdx)])
           + string(" ")
           + to_string(XyzTestData::mLastName[getRandomNumber(XyzTestData::NamesFirstIdx,
                                                              XyzTestData::LNamesLastIdx)]);
}

XyzEmployeeTypes::XyzEmpType getEmpType()
{
    return XyzTestData::mEmpType[getRandomNumber(XyzEmployeeTypes::FULL_TIME,
                                                 XyzEmployeeTypes::INTERN)];
}

string getEmpId(uint64 empSeqNumParm,
                XyzEmployeeTypes::XyzEmpType empTypeParm)
{
    return string("XYZ")
           + getPaddedSequenceNumber(empSeqNumParm)
           + string(XyzTestData::mEmpTypeKeyword[empTypeParm]);
}

XyzEmployeeTypes::XyzEmpStatus getEmpStatus()
{
    return XyzTestData::mEmpStatus[getRandomNumber(XyzEmployeeTypes::ACTIVE,
                                                   XyzEmployeeTypes::RESIGNED)];
}

XyzDate* getEmpDOB()
{
    return getDate(XyzTestData::DOBStartYear,
                   XyzTestData::DOBEndYear);
}

XyzDate* getEmpDOJ()
{
    return getDate(XyzTestData::DOJStartYear,
                   XyzTestData::DOJEndYear);
}

XyzDate* getEmpDOL(XyzDate* dojParm)
{
    return getDate(dojParm->getYearVal() + 1,
                   dojParm->getYearVal() + 30);
}

uint64 getEmpLeavesBalance()
{
    return getRandomNumber(XyzTestData::MinLeavesBalance,
                           XyzTestData::MaxLeavesBalance);
}

XyzEmployeeTypes::XyzExtAgency getEmpExtAgency()
{
    return XyzTestData::mExtAgency[getRandomNumber(XyzEmployeeTypes::AVENGERS,
                                                   XyzEmployeeTypes::X_MEN)];
}

XyzEmployeeTypes::XyzHiringCollege getEmpCollege()
{
    return XyzTestData::mCollege[getRandomNumber(XyzEmployeeTypes::IIT_DELHI,
                                                 XyzEmployeeTypes::IIIT_HYDERABAD)];
}

XyzEmployeeTypes::XyzHiringBranch getEmpBranch()
{
    return XyzTestData::mBranch[getRandomNumber(XyzEmployeeTypes::CSE,
                                                XyzEmployeeTypes::ECE)];
}

int getRandomNumber(int startNumParm,
                     int endNumParm)
{
    std::random_device sRandomDevice;
    std::mt19937 sRandomNumberGenerator(sRandomDevice());
    std::uniform_int_distribution<int> sGenerate(startNumParm, endNumParm);
    int sRandomNumber = sGenerate(sRandomNumberGenerator);
    return sRandomNumber;
}

XyzDate* getDate(uint32 minYearParm,
                  uint32 maxYearParm)
{
    XyzDate* sDatePtr = new XyzDate();
    uint16 sMonthVal = getRandomNumber(XyzDate::JAN, XyzDate::DEC);
    uint16 sMinDayVal = 1;
    uint16 sMaxDayVal = 30;
    if (XyzDate::JAN == sMonthVal
        || XyzDate::MAR == sMonthVal
        || XyzDate::MAY == sMonthVal
        || XyzDate::JUL == sMonthVal
        || XyzDate::AUG == sMonthVal
        || XyzDate::OCT == sMonthVal
        || XyzDate::DEC == sMonthVal)
    {
        sMaxDayVal = 31;
    }
    else if (XyzDate::FEB)
    {
        sMaxDayVal = 28;
    }
    uint16 sDayVal = getRandomNumber(sMinDayVal, sMaxDayVal);
    uint32 sYearVal = getRandomNumber(minYearParm, maxYearParm);

    sDatePtr->setAllFields(sDayVal,
                           sMonthVal,
                           sYearVal);
    return sDatePtr;
}

string getPaddedSequenceNumber(uint64 empSeqNumParm)
{
    string sSeqString = to_string(empSeqNumParm);
    if (sSeqString.size() < 4)
    {
        sSeqString.insert(0, 4 - sSeqString.size(), '0');
    }
    return sSeqString;
}

void drawLine(int numParm)
{
    for (int idx=0; idx < numParm+1; idx++)
    {
        cout << "-";
    }
    cout << endl;
}
