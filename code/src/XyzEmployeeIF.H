// Employee Interface class

#ifndef XYZEMPLOYEEIF_H
#define XYZEMPLOYEEIF_H

#include "XyzEmloyeeTypes.H"
using namespace std;

class XyzEmployee
{
  public:
    // constructor and destructor
    XyzEmployee();
    virtual ~XyzEmployee();

    // getter functions
    virtual string getEmpName() = 0;
    virtual string getEmpId() = 0;
    virtual XyzEmployeeTypes::XyzEmpType getEmpType() = 0;
    virtual XyzEmployeeTypes::XyzEmpStatus getEmpStatus() = 0;
    virtual string getEmpGender() = 0;
    virtual XyzDate* getEmpDOB() = 0;
    virtual XyzDate* getEmpDOJ() = 0;
    virtual XyzDate* getEmpDOL() = 0;
    virtual XyzEmployeeTypes::XyzExtAgency getEmpExtAgency() = 0;
    virtual uint32 getEmpLeaveBalance() = 0;
    virtual XyzEmployeeTypes::XyzHiringCollege getEmpCollege() = 0;
    virtual XyzEmployeeTypes::XyzHiringBranch getEmpBranch() = 0;

    // setter functions
    virtual setEmpType(XyzEmployeeTypes::XyzEmpType empTypeParm) = 0;
    virtual setEmpStatus(XyzEmployeeTypes::XyzEmpStatus empStatusParm) = 0;
    virtual setEmpDOL(XyzDate* empDOLParm) = 0;
    virtual getEmpExtAgency(XyzEmployeeTypes::XyzExtAgency empAgencyParm) = 0;
    virtual setEmpLeaveBalance(uint32 leaveBalanceParm) = 0;

    virtual void printEmployeeDetails() = 0;

    // summary of all the employees
    virtual void printEmployeeSummaryHeader() = 0;
    virtual void printEmployeeSummaryFooter() = 0;
    virtual void printEmployeeSummaryRecord() = 0;

    // summary of employees based on employee type (F/C/I)
    virtual void printEmployeeSummaryHeader(XyzEmployeeTypes::XyzEmpType empTypeParm) = 0;
    virtual void printEmployeeSummaryFooter(XyzEmployeeTypes::XyzEmpType empTypeParm) = 0;
    virtual void printEmployeeSummaryRecord(XyzEmployeeTypes::XyzEmpType empTypeParm) = 0;

    // summary of employees based on employee type (Active/Inactive/Resigned)
    virtual void printEmployeeSummaryHeader(XyzEmployeeTypes::XyzEmpStatus empStatusParm) = 0;
    virtual void printEmployeeSummaryFooter(XyzEmployeeTypes::XyzEmpStatus empStatusParm) = 0;
    virtual void printEmployeeSummaryRecord(XyzEmployeeTypes::XyzEmpStatus empStatusParm) = 0;

    // summary of employees based on employee type (Male/Female)
    virtual void printEmployeeSummaryHeader(string genderParm) = 0;
    virtual void printEmployeeSummaryFooter(string genderParm) = 0;
    virtual void printEmployeeSummaryRecord(string genderParm) = 0;
};

#endif /* XYZEMPLOYEEIF_H */
