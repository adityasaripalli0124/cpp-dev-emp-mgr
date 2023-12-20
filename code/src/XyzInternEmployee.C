

#include "XyzInternEmployee.H"
using namespace std;

XyzInternEmployee::XyzInternEmployee(XyzEmployeeManager* empMgrParm,
                                     XyzEmployeeTypes::XyzEmloyeeType empTypeParm,
                                     XyzEmployeeTypes::XyzEmpStatus empStatusParm,
                                     string empNameParm,
                                     string empIdParm,
                                     string empGenderParm,
                                     XyzDate* empDOBParm,
                                     XyzDate* empDOJParm,
                                     XyzEmployeeTypes::XyzHiringCollege empCollegeParm,
                                     XyzEmployeeTypes::XyzHiringBranch empBranchParm)
:XyzEmployeeImpl(empMgrParm,
                 empTypeParm,
                 empStatusParm,
                 empNameParm,
                 empIdParm,
                 empGenderParm,
                 empDOBParm,
                 empDOJParm)
,mCollege(empCollegeParm)
,mBranch(empBranchParm)
{
}

XyzInternEmployee::~XyzInternEmployee()
{
}

XyzEmployeeTypes::XyzHiringCollege XyzInternEmployee::getEmpCollege()
{
    return mCollege;
}
XyzEmployeeTypes::XyzHiringBranch XyzInternEmployee::::getEmpBranch()
{
    return mBranch;
}

void XyzInternEmployee::printEmployeeDetails()
{
    cout << "College         : " << mCollege << endl;
    cout << "Branch          : " << mBranch << endl;
}

void XyzInternEmployee::printEmployeeSummaryRecord()
{
    XyzEmployeeImpl::printEmployeeSummaryRecord();
    cout << left << setw(XyzTestData::EmpCollegeLength) << "| College" << flush;
    cout << left << setw(XyzTestData::EmpBranchLength) << "| Branch" << flush;
    cout << "|" << endl;
}