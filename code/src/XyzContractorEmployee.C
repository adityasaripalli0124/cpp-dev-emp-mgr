
#include "XyzContractorEmployee.H"
using namespace std;

XyzContractorEmployee::XyzContractorEmployee(XyzEmployeeManager* empMgrParm,
                                             XyzEmployeeTypes::XyzEmloyeeType empTypeParm,
                                             XyzEmployeeTypes::XyzEmpStatus empStatusParm,
                                             string empNameParm,
                                             string empIdParm,
                                             string empGenderParm,
                                             XyzDate* empDOBParm,
                                             XyzDate* empDOJParm,
                                             XyzEmployeeTypes::XyzExtAgency empExtAgencyParm)
:XyzEmployeeImpl(empMgrParm,
                 empTypeParm,
                 empStatusParm,
                 empNameParm,
                 empIdParm,
                 empGenderParm,
                 empDOBParm,
                 empDOJParm)
,mExtAgency(empExtAgencyParm)
{
}

XyzContractorEmployee::~XyzContractorEmployee()
{
}

XyzEmployeeTypes::XyzExtAgency getEmpExtAgency();
{
    return mExtAgency;
}

void XyzContractorEmployee::printEmployeeDetails()
{
    cout << "External Agency : " << mExtAgency << endl;
}

void XyzContractorEmployee::printEmployeeSummaryRecord()
{
    XyzEmployeeImpl::printEmployeeSummaryRecord();
    cout << left << setw(XyzTestData::EmpExtAgencyLength) << "| Ext Agency" << flush;
    cout << "|" << endl;
}
