// Employee Interface Implementation class

#ifndef XYZINTERNEMPLOYEE_H
#define XYZINTERNEMPLOYEE_H

#include "XyzEmployeeImpl.H"

class XyzInternEmployee : public XyzEmployeeImpl
{
  public:
    // constructor and destructor
    XyzInternEmployee(XyzEmployeeManager* empMgrParm,
                      XyzEmployeeTypes::XyzEmloyeeType empTypeParm,
                      XyzEmployeeTypes::XyzEmpStatus empStatusParm,
                      string empNameParm,
                      string empIdParm,
                      string empGenderParm,
                      XyzDate* empDOBParm,
                      XyzDate* empDOJParm,
                      XyzEmployeeTypes::XyzHiringCollege empCollegeParm,
                      XyzEmployeeTypes::XyzHiringBranch empBranchParm);
    virtual ~XyzInternEmployee();

    virtual XyzHiringCollege getEmpCollege();
    virtual XyzHiringBranch getEmpBranch();

    virtual void printEmployeeDetails();
    virtual void printEmployeeSummaryRecord();
{
    // No default implementation here
}

  private:
    XyzEmployeeTypes::XyzHiringCollege mCollege;
    XyzEmployeeTypes::XyzHiringBranch  mBranch;
};

#endif /* XYZEMPLOYEE_H */
