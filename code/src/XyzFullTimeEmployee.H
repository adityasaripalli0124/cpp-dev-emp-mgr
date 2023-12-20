// Full-Time Employee class

#ifndef XYZFULLTIMEEMPLOYEE_H
#define XYZFULLTIMEEMPLOYEE_H

#include "XyzEmployeeImpl.H"

class XyzFullTimeEmployee : public XyzEmployeeImpl
{
  public:

    enum
    {
        MAX_LEAVES = 22  // maximum number of leaves per employee
    };

    // constructor and destructor
    XyzFullTimeEmployee(XyzEmployeeManager* empMgrParm,
                        XyzEmployeeTypes::XyzEmloyeeType empTypeParm,
                        XyzEmployeeTypes::XyzEmpStatus empStatusParm,
                        string empNameParm,
                        string empIdParm,
                        string empGenderParm,
                        XyzDate* empDOBParm,
                        XyzDate* empDOJParm,
                        uint32 empLeaveBalanceParm);
    virtual ~XyzFullTimeEmployee();

    // getter functions
    virtual uint32 getEmpLeaveBalance();
    // setter functions
    virtual setEmpLeaveBalance(uint32 leaveBalanceParm);

    virtual void printEmployeeDetails();
    virtual void printEmployeeSummaryRecord();

  private:
    uint32 mLeaveBalance;
};

#endif /* XYZEMPLOYEE_H */
