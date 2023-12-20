// Employee Interface Implementation class definitions
// This class will have default implementations of the interfaces

#include "XyzEmployeeImpl.H"
#include "XyzEmployeeTypes.H"
#include "XyzEmployeeManager.H"
using namespace std;

XyzEmployeeImpl::XyzEmployeeImpl(XyzEmployeeManager* empMgrParm,
                                 XyzEmloyeeType empTypeParm,
                                 XyzEmpStatus empStatusParm,
                                 string empNameParm,
                                 string empIdParm,
                                 string empGenderParm,
                                 XyzDate* empDOBParm,
                                 XyzDate* empDOJParm)
:mEmpMgr(empMgrParm)
,mEmpType(empTypeParm)
,mEmpStatus(empStatusParm)
,mEmpName(empNameParm)
,mEmpId(empIdParm)
,mEmpGender(empGenderParm)
,mEmpDOBPtr(empDOBParm)
,mEmpDOJPtr(empDOJParm)
,mEmpDOLPtr(NULL)
{
}

XyzEmployeeImpl::~XyzEmployeeImpl()
{
}

string XyzEmployeeImpl::getEmpName()
{
    return mEmpName;
}

string XyzEmployeeImpl::getEmpId()
{
    return mEmpId;
}

XyzEmpType XyzEmployeeImpl::getEmpType()
{
    return mEmpType;
}

XyzEmpStatus XyzEmployeeImpl::getEmpStatus()
{
    return mEmpStatus;
}

string XyzEmployeeImpl::getEmpGender()
{
    return mEmpGender;
}

XyzDate* XyzEmployeeImpl::getEmpDOB()
{
    return mEmpDOBPtr;
}

XyzDate* XyzEmployeeImpl::getEmpDOJ()
{
    return mEmpDOJPtr;
}

XyzDate* XyzEmployeeImpl::getEmpDOL()
{
    return mEmpDOLPtr;
}

XyzEmployeeTypes::XyzExtAgency getEmpExtAgency()
{
    return XyzEmployeeTypes::INVALID_AGENCY;
}

uint32 XyzEmployeeImpl::getEmpLeaveBalance()
{
    return 0;
}

XyzEmployeeTypes::XyzHiringCollege XyzEmployeeImpl::getEmpCollege()
{
    return XyzEmployeeTypes::INVALID_COLLEGE:
}

XyzEmployeeTypes::XyzHiringBranch XyzEmployeeImpl::getEmpBranch()
{
    return XyzEmployeeTypes::INVALID_BRANCH;
}

XyzEmployeeImpl::setEmpType(XyzEmployeeTypes::XyzEmpType empTypeParm);
{
    mEmpType = empTypeParm;
}

XyzEmployeeImpl::setEmpStatus(XyzEmployeeTypes::XyzEmpStatus empStatusParm)
{
    mEmpStatus = empStatusParm;
}

XyzEmployeeImpl::setEmpDOL(XyzDate* empDOLParm)
{
    mEmpDOLPtr = empDOLParm;
}

XyzEmployeeImpl::setEmpExtAgency(XyzEmployeeTypes::XyzExtAgency empAgencyParm)
{
    // default empty implementation -- see derived class for implementation
}

XyzEmployeeImpl::setEmpLeaveBalance(uint32 leaveBalanceParm)
{
    // default empty implementation -- see derived class for implementation
}

void XyzEmployeeImpl::printEmployeeDetails()
{
    cout << "Employee Name   : " << mEmpName << endl;
    cout << "Employee ID     : " << mEmpId << endl;
    cout << "Employee Type   : " << mEmpType << endl;
    cout << "Employee Status : " << mEmpStatus << endl;
    cout << "Gender          : " << mEmpGender << endl;
    cout << "Date of Birth   : " << mEmpDOBPtr->getDateStr() << endl;
    cout << "Date of Joining : " << mEmpDOJPtr->getDateStr() << endl;
}

// summary of all the employees
void XyzEmployeeImpl::printEmployeeSummaryHeader()
{
    uint64 sMaxEmpFieldLength = mEmpMgr->getMaxEmpFieldLength();
    uitn64 sHeaderLength = sMaxEmpFieldLength + XyzTestData::EmpRecordLength;
    drawLine(sHeaderLength);
    cout << left << setw(sMaxEmpFieldLength) << "| Employee name" << flush;
    cout << left << setw(XyzTestData::EmpIdLength) << "| ID" << flush;
    cout << left << setw(XyzTestData::EmpTypeLength) << "| Type" << flush;
    cout << left << setw(XyzTestData::EmpStatusLength) << "| Status" << flush;
    cout << left << setw(XyzTestData::EmpGenderLength) << "| Gender" << flush;
    cout << left << setw(XyzTestData::EmpDateLength) << "| Date of Birth" << flush;
    cout << left << setw(XyzTestData::EmpDateLength) << "| Date of Joining" << flush;
    cout << left << setw(XyzTestData::EmpDateLength) << "| Date of Leaving" << flush;
    cout << left << setw(XyzTestData::EmpLeavesLength) << "| Leaves Balance" << flush;
    cout << left << setw(XyzTestData::EmpExtAgencyLength) << "| Ext Agency" << flush;
    cout << left << setw(XyzTestData::EmpCollegeLength) << "| College" << flush;
    cout << left << setw(XyzTestData::EmpBranchLength) << "| Branch" << flush;
    cout << "|" << endl;
    drawLine(sHeaderLength);
}
void XyzEmployeeImpl::printEmployeeSummaryRecord()
{
    uint32 sMaxEmpFieldLength = mEmpMgr->getMaxEmpFieldLength();
    cout << left << setw(sMaxEmpFieldLength) << "| Employee name" << flush;
    cout << left << setw(XyzTestData::EmpIdLength) << "| ID" << flush;
    cout << left << setw(XyzTestData::EmpTypeLength) << "| Type" << flush;
    cout << left << setw(XyzTestData::EmpStatusLength) << "| Status" << flush;
    cout << left << setw(XyzTestData::EmpGenderLength) << "| Gender" << flush;
    cout << left << setw(XyzTestData::EmpDateLength) << "| DOB" << flush;
    cout << left << setw(XyzTestData::EmpDateLength) << "| DOJ" << flush;
    cout << left << setw(XyzTestData::EmpDateLength) << "| DOL" << flush;
    cout << "|" << endl;
}
void XyzEmployeeImpl::printEmployeeSummaryFooter()
{

}

// summary of employees based on employee type (F/C/I)
void XyzEmployeeImpl::printEmployeeSummaryHeader(XyzEmployeeTypes::XyzEmpType empTypeParm)
{

}
void XyzEmployeeImpl::printEmployeeSummaryFooter(XyzEmployeeTypes::XyzEmpType empTypeParm)
{

}
void XyzEmployeeImpl::printEmployeeSummaryRecord(XyzEmployeeTypes::XyzEmpType empTypeParm)
{

}

// summary of employees based on employee type (Active/Inactive/Resigned)
void XyzEmployeeImpl::printEmployeeSummaryHeader(XyzEmployeeTypes::XyzEmpStatus empStatusParm)
{

}
void XyzEmployeeImpl::printEmployeeSummaryFooter(XyzEmployeeTypes::XyzEmpStatus empStatusParm)
{

}
void XyzEmployeeImpl::printEmployeeSummaryRecord(XyzEmployeeTypes::XyzEmpStatus empStatusParm)
{

}

// summary of employees based on employee type (Male/Female)
void XyzEmployeeImpl::printEmployeeSummaryHeader(string genderParm)
{

}
void XyzEmployeeImpl::printEmployeeSummaryFooter(string genderParm)
{

}
void XyzEmployeeImpl::printEmployeeSummaryRecord(string genderParm)
{

}
