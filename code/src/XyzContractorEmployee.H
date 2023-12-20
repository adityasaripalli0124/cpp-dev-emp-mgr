// Employee Interface Implementation class

#ifndef XYZCONTRACTOREMPLOYEE_H
#define XYZCONTRACTOREMPLOYEE_H

#include "XyzEmployeeImpl.H"

class XyzContractorEmployee : public XyzEmployeeImpl
{
  public:
    // constructor and destructor
    XyzContractorEmployee(XyzEmployeeManager* empMgrParm,
                          XyzEmployeeTypes::XyzEmloyeeType empTypeParm,
                          XyzEmployeeTypes::XyzEmpStatus empStatusParm,
                          string empNameParm,
                          string empIdParm,
                          string empGenderParm,
                          XyzDate* empDOBParm,
                          XyzDate* empDOJParm,
                          XyzEmployeeTypes::XyzExtAgency empExtAgencyParm);
    virtual ~XyzContractorEmployee();

    virtual XyzExtAgency getEmpExtAgency();

    virtual void printEmployeeDetails();
    virtual void printEmployeeSummaryRecord();

  private:
    XyzEmployeeTypes::XyzExtAgency mExtAgency;
};

#endif /* XYZEMPLOYEE_H */
