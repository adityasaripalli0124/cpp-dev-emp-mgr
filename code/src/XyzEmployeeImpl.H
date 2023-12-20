// Employee Interface Implementation class
// This class will have default implementations of the interfaces

#ifndef XYZEMPLOYEEIMPL_H
#define XYZEMPLOYEEIMPL_H

#include "XyzEmployeeIF.H"
#include "XyzEmployeeTestUtils.H"
using namespace std;

class XyzEmployeeManager;

class XyzEmployeeImpl : public XyzEmployee
{
  public:
    // constructor and destructor
    XyzEmployeeImpl(XyzEmployeeManager* empMgrParm,
                    XyzEmployeeTypes::XyzEmloyeeType empTypeParm,
                    XyzEmployeeTypes::XyzEmpStatus empStatusParm,
                    string empNameParm,
                    string empIdParm,
                    string empGenderParm,
                    XyzDate* empDOBParm,
                    XyzDate* empDOJParm);
    virtual ~XyzEmployeeImpl();

    // common getter functions
    virtual string getEmpName();
    virtual string getEmpId();
    virtual XyzEmployeeTypes::XyzEmpType getEmpType();
    virtual XyzEmployeeTypes::XyzEmpStatus getEmpStatus();
    virtual string getEmpGender();
    virtual XyzDate* getEmpDOB();
    virtual XyzDate* getEmpDOJ();
    virtual XyzDate* getEmpDOL();

    // employee specific getter functions
    virtual XyzEmployeeTypes::XyzExtAgency getEmpExtAgency();
    virtual uint32 getEmpLeaveBalance();
    virtual XyzEmployeeTypes::XyzHiringCollege getEmpCollege();
    virtual XyzEmployeeTypes::XyzHiringBranch getEmpBranch();

    // setter functions
    virtual setEmpType(XyzEmployeeTypes::XyzEmpType empTypeParm);
    virtual setEmpStatus(XyzEmployeeTypes::XyzEmpStatus empStatusParm);
    virtual setEmpDOL(XyzDate* empDOLParm);
    virtual setEmpExtAgency(XyzEmployeeTypes::XyzExtAgency empAgencyParm);
    virtual setEmpLeaveBalance(uint32 leaveBalanceParm);

    virtual void printEmployeeDetails();

    // summary of all the employees
    virtual void printEmployeeSummaryHeader();
    virtual void printEmployeeSummaryFooter();
    virtual void printEmployeeSummaryRecord();

    // summary of employees based on employee type (F/C/I)
    virtual void printEmployeeSummaryHeader(XyzEmployeeTypes::XyzEmpType empTypeParm);
    virtual void printEmployeeSummaryFooter(XyzEmployeeTypes::XyzEmpType empTypeParm);
    virtual void printEmployeeSummaryRecord(XyzEmployeeTypes::XyzEmpType empTypeParm);

    // summary of employees based on employee type (Active/Inactive/Resigned)
    virtual void printEmployeeSummaryHeader(XyzEmployeeTypes::XyzEmpStatus empStatusParm);
    virtual void printEmployeeSummaryFooter(XyzEmployeeTypes::XyzEmpStatus empStatusParm);
    virtual void printEmployeeSummaryRecord(XyzEmployeeTypes::XyzEmpStatus empStatusParm);

    // summary of employees based on employee type (Male/Female)
    virtual void printEmployeeSummaryHeader(string genderParm);
    virtual void printEmployeeSummaryFooter(string genderParm);
    virtual void printEmployeeSummaryRecord(string genderParm);

  private:
    XyzEmpType   mEmpType;
    XyzEmpStatus mEmpStatus;
    string       mEmpName;
    string       mEmpId;
    string       mEmpGender;
    XyzDate*     mEmpDOBPtr;
    XyzDate*     mEmpDOJPtr;
    XyzDate*     mEmpDOLPtr;
    XyzEmployeeManager* mEmpMgr;
};

#endif /* XYZEMPLOYEE_H */
