
#include "XyzFullTimeEmployee.H"
using namespace std;

XyzFullTimeEmployee::XyzFullTimeEmployee(XyzEmployeeManager* empMgrParm,
                                         XyzEmployeeTypes::XyzEmloyeeType empTypeParm,
                                         XyzEmployeeTypes::XyzEmpStatus empStatusParm,
                                         string empNameParm,
                                         string empIdParm,
                                         string empGenderParm,
                                         XyzDate* empDOBParm,
                                         XyzDate* empDOJParm,
                                         uint32 empLeaveBalanceParm)
:XyzEmployeeImpl(empMgrParm,
                 empTypeParm,
                 empStatusParm,
                 empNameParm,
                 empIdParm,
                 empGenderParm,
                 empDOBParm,
                 empDOJParm)
,mLeaveBalance(empLeaveBalanceParm)
{
}

XyzFullTimeEmployee::~XyzFullTimeEmployee()
{
}

uint32 XyzFullTimeEmployee::getEmpLeaveBalance()
{
    return mLeaveBalance;
}
void XyzFullTimeEmployee::::setEmpLeaveBalance(uint32 leaveBalanceParm)
{
    if (mLeaveBalance + leaveBalanceParm > XyzFullTimeEmployee::MAX_LEAVES)
    {
        mLeaveBalance = leaveBalanceParm;
    }
}

void XyzFullTimeEmployee::printEmployeeDetails()
{
    XyzEmployeeImpl::printEmployeeDetails();
    cout << "Leaves Balance  : " << mLeaveBalance << endl;
}

void XyzContractorEmployee::printEmployeeSummaryRecord()
{
    XyzEmployeeImpl::printEmployeeSummaryRecord();
    cout << left << setw(XyzTestData::EmpLeavesLength) << "| Leaves Balance" << flush;
    cout << "|" << endl;
}
