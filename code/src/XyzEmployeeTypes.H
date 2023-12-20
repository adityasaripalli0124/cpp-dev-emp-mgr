// A class to store all the types and structures

#ifndef XYZEMPLOYEETYPES_H
#define XYZEMPLOYEETYPES_H

typedef unsigned short     uint16;
typedef unsigned long      uint32;
typedef unsigned long long uint64;

namespace XyzEmployeeTypes
{
    enum
    {
        INVALID    = 0x00,
    };

    enum XyzEmpFields
    {
        EMP_NAME       = 0x01,
        EMP_ID         = 0x02,
        EMP_TYPE       = 0x03,
        EMP_STATUS     = 0x04,
        EMP_GENDER     = 0x05,
        EMP_DOB        = 0x06,
        EMP_DOJ        = 0x07,
        EMP_DOL        = 0x08,
        EMP_LEAVE_BAL  = 0x09,
        EMP_COLLEGE    = 0x0A,
        EMP_BRANCH     = 0x0B,
        EMP_EXT_AGENCY = 0x0C,
    };

    enum XyzEmpType
    {
        FULL_TIME  = 0x01,
        CONTRACTOR = 0x02,
        INTERN     = 0x03,
    };

    enum XyzEmpStatus
    {
        ACTIVE   = 0x01,
        INACTIVE = 0x02,
        RESIGNED = 0x03,
    };

    enum XyzExtAgency
    {
        AVENGERS       = 0x01,
        JUSTICE_LEAGUE = 0x02,
        X_MEN          = 0x03,
    };

    enum XyzHiringCollege
    {
        IIT_DELHI      = 0x01,
        IIT_MUMBAI     = 0x02,
        IIT_KANPUR     = 0x03,
        IIT_HYDERABAD  = 0x04,
        NIT_WARANGAL   = 0x05,
        NIT_TIRUCHI    = 0x06,
        IIIT_HYDERABAD = 0x07,
    };

    enum XyzHiringBranch
    {
        CSE  = 0x01,
        CSIT = 0x02,
        ECE  = 0x03,
    };
};


class XyzDate
{
  public:
    union Date_t
    {
        uint32 mValue;
        struct
        {
            uint64 mDay:16;
            uint64 mMon:16;
            uint64 mYear:32;
        }fields;
    };

    enum Month
    {
        JAN = 0x01,
        FEB = 0x02,
        MAR = 0x03,
        APR = 0x04,
        MAY = 0x05,
        JUN = 0x06,
        JUL = 0x07,
        AUG = 0x08,
        SEP = 0x09,
        OCT = 0x0A,
        NOV = 0x0B,
        DEC = 0x0C,
    };

    string mMonthStr[] = {"Invalid Month", "January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};
    inline XyzDate();
    inline XyzDate(uint16 dayParm, uint16 monParm, uint32 yearParm);

    inline uint16 getDayVal();
    inline uint16 getMonVal();
    inline uint32 getYearVal();
    inline void setDayVal(uint16 dayParm);
    inline void setMonVal(uint16 monParm);
    inline void setYearVal(uint32 yearParm);
    inline void XyzDate::setAllFields(uint16 dayParm,
                                      uint16 monParm,
                                      uint32 yearParm);
    inline string getDateStr();

    void addMonths(uint16 numParm);
    void addYears(uint32 numParm);

  private:
    Date_t mDate;
};

XyzDate::XyzDate()
{
    mDate.mValue = 0;
}

XyzDate::XyzDate(uint16 dayParm,
                 uint16 monParm,
                 uint32 yearParm)
{
    mDate.fields.mDay  = dayParm;
    mDate.fields.mMon  = monParm;
    mDate.fields.mYear = yearParm;
}

uint16 XyzDate::getDayVal()
{
    return mDate.fields.mDay;
}

uint16 XyzDate::getMonVal()
{
    return mDate.fields.mMon;
}

uint32 XyzDate::getYearVal()
{
    return mDate.fields.mYear;
}

void XyzDate::setDayVal(uint16 dayParm)
{
    mDate.fields.mDay = dayParm;
}

void XyzDate::setMonVal(uint16 monParm)
{
    mDate.fields.mMon = monParm;
}

void XyzDate::setYearVal(uint32 yearParm)
{
    mDate.fields.mYear = yearParm;
}

void XyzDate::setAllFields(uint16 dayParm,
                           uint16 monParm,
                           uint32 yearParm)
{
    mDate.fields.mDay = dayParm;
    mDate.fields.mMon = monParm;
    mDate.fields.mYear = yearParm;
}

string XyzDate::getDateStr()
{
    return (to_string(mDate.fields.mDay)
            + mMonthStr[mDate.fields.mMon]
            + string(", ")
            + to_string(mDate.fields.mYear));
}

void XyzDate::addMonths(uint16 numParm)
{
    mDate.fields.mMon = (mDate.fields.mMon + numParm) % 12;
    mDate.fields.mYear += (mDate.fields.mMon + numParm) / 12;
}

void XyzDate::addYears(uint32 numParm)
{
    mDate.fields.mYear += numParm;
}

#endif /* XyzEmployeeTypes */
