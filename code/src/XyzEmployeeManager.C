
#include "XyzEmployeeManager.H"
#include "XyzEmployeeTestUtils.H"
#include "XyzEmployeeIF.H"
#include "XyzEmployeeFullTime.H"
#include "XyzEmployeeContractor.H"
#include "XyzEmployeeIntern.H"
#include <iostream>
#include <iomanip>
using namespace std;

XyzEmployeeManager::XyzEmployeeManager()
:mEmpSeqNum(1)
,mMaxEmpNameFieldLength(XyzTestData::EmpNameLength)
{
    mEmpList = new DLL<XyzEmployee>();
    mNonEmpList = new DLL<XyzEmployee>();
}

XyzEmployeeManager::~XyzEmployeeManager()
{
    if (mEmpList != NULL)
    {
        delete(mEmpList);
    }
    if (mNonEmpList != NULL)
    {
        delete(mNonEmpList);
    }
}

// create and add a random employee (to the list)
void XyzEmployeeManager::addEmployee()
{
    XyzEmployee* sEmpPtr = pCreateEmployee();
    mEmpList->push_back(sEmpPtr);
}

// create and add an employee (to the list) based on type provided
void XyzEmployeeManager::addEmployee(XyzEmployeeTypes::XyzEmpType empTypeParm)
{
    XyzEmployee* sEmpPtr = pCreateEmployee(empTypeParm);
    mEmpList->push_back(sEmpPtr);
}

// Employee being terminated or resigned. In both the cases the status would be 'resigned'.
void XyzEmployeeManager::removeEmployee(string empIdParm)
{
    // first search for the employee with the given employee ID
    XyzEmployee* sEmpPtr = NULL:
    for (int idx=0; idx < mEmpList->size(); idx++)
    {
        sEmpPtr = mEmpList.at(idx);
        if (sEmpPtr->getEmpId() == empIdParm)
        {
            Node<XyzEmployee>* sNodePtr = mEmpList->removeNodeSoft(idx);
            if (sNodePtr != NULL)
            {
                XyzEmployeeTestUtils sEmpTestUtils;
                sNodePtr->mData->setEmpStatus(XyzEmployeeTypes::RESIGNED);
                sNodePtr->mData->setEmpDOL(sEmpTestUtils.getEmpDOL(sEmpPtr->getEmpDOJ()));
                mNonEmpList->push_back(sNodePtr);
                break;
            }
        }
    }
}

// Search an employee based on the any of the employee fields (like Name, Id, Type, Status etc).
XyzEmployee* XyzEmployeeManager::searchEmployee(XyzEmployeeTypes::XyzEmpFields empFieldParm,
                                                string keyParm)
{
    XyzEmployee* sEmpPtr = NULL;
    switch(empFieldParm)
    {
        case XyzEmployeeTypes::EMP_ID:
            for (int idx=0; idx < mEmpList->size(); idx++)
            {
                sEmpPtr = mEmpList.at(idx);
                if (sEmpPtr->getEmpId() == keyParm)
                {
                    break;
                }
            }
        break;
        default:
            cout << "[ERROR] No valid field to search." << endl;
    }
    return sEmpPtr;
}

// Add some leaves to all the full-time employees.
void XyzEmployeeManager::addLeaves(int leavesCountParm)
{
    XyzEmployee* sEmpPtr = NULL;
    for (int idx=0; idx < mEmpList->size(); idx++)
    {
        sEmpPtr = mEmpList.at(idx);
        if (sEmpPtr != NULL && XyzEmployeeTypes::FULL_TIME == sEmpPtr->getEmpType())
        {
            sEmpPtr->setEmpLeaveBalance(getEmpLeaveBalance() + leavesCountParm);
        }
    }
}

// Convert an intern to a full-time employee.
void XyzEmployeeManager::convertToFullTimeEmployee(string empIdParm)
{
    // search for this employee
    XyzEmployee* sEmpPtr = NULL;
    for (int idx=0; idx < mEmpList->size(); idx++)
    {
        sEmpPtr = mEmpList.at(idx);
        if (XyzEmployeeTypes::FULL_TIME != sEmpPtr->getEmpTypes() &&
            keyParm == sEmpPtr->getEmpId())
        {
            break;
        }
    }

    if (sEmpPtr != NULL)
    {
        // Create a Full-Time emplopyee using the credentials of current employee (Intern/Contractor)
        string sEmpId = sEmpPtr->getEmpId();
        sEmpId.replace(sEmpId.size()-1, 1, "F");
        XyzEmployee* sNewEmpPtr = new XyzFullTimeEmployee(this,
                                                          XyzEmployeeTypes::FULL_TIME,
                                                          sEmpPtr->getEmpStatus(),
                                                          sEmpPtr->getEmpName(),
                                                          sEmpId,
                                                          sEmpPtr->getEmpGender(),
                                                          sEmpPtr->getEmpDOBPtr(),
                                                          sEmpPtr->getEmpDOLPtr(), // DOL = DOJ (as FTE) for Intern/Contractor
                                                          XyzTestData::MaxLeavesBalance);
        // In-place replacement of the employee node in DLL
        XyzEmployee* sEmpOldPtr = sEmpPtr;
        sEmpPtr = sNewEmpPtr;
        delete(sEmpOldPtr);
    }
}

// printing functions
void XyzEmployeeManager::printEmployeeSummary()
{
    bool isHeaderPrinted = false;
    XyzEmployee* sEmpPtr = NULL;
    for (int idx=0; idx < mEmpList->size(); idx++)
    {
        sEmpPtr = mEmpList.at(idx);
        if (sEmpPtr != NULL)
        {
            if (!isHeaderPrinted)
            {
                sEmpPtr->printEmployeeSummaryHeader();
                isHeaderPrinted = true;
            }
            sEmpPtr->printEmployeeSummaryRecord();
        }
    }
    printEmployeeSummaryFooter();
}

void XyzEmployeeManager::printEmployeeSummary(XyzEmployeeTypes::XyzEmpType empTypeParm)
{
    bool isHeaderPrinted = false;
    XyzEmployee* sEmpPtr = NULL;
    for (int idx=0; idx < mEmpList->size(); idx++)
    {
        sEmpPtr = mEmpList.at(idx);
        if (sEmpPtr != NULL && sEmpPtr->getEmpType() == empTypeParm)
        {
            if (!isHeaderPrinted)
            {
                sEmpPtr->printEmployeeSummaryHeader(empTypeParm);
                isHeaderPrinted = true;
            }
            sEmpPtr->printEmployeeSummaryRecord(empTypeParm);
        }
    }
    printEmployeeSummaryFooter(empTypeParm);
}

void XyzEmployeeManager::printEmployeeSummary(XyzEmployeeTypes::XyzEmpStatus empStatusParm)
{
    bool isHeaderPrinted = false;
    XyzEmployee* sEmpPtr = NULL;
    for (int idx=0; idx < mEmpList->size(); idx++)
    {
        sEmpPtr = mEmpList.at(idx);
        if (sEmpPtr != NULL && sEmpPtr->getEmpStatus() == empStatusParm)
        {
            if(!isHeaderPrinted)
            {
                sEmpPtr->printEmployeeSummaryHeader(empStatusParm);
                isHeaderPrinted = true;
            }
            sEmpPtr->printEmployeeSummaryRecord(empStatusParm);
        }
    }
    printEmployeeSummaryFooter(empStatusParm);
}

// Protected functions
XyzEmployee* XyzEmployeeManager::pCreateEmployee(XyzEmployeeTypes::XyzEmpType empTypeParm)
{
    XyzEmployee* sEmpPtr = NULL;
    XyzEmployeeTypes::XyzEmpType sEmpType = empTypeParm;
    if (XyzEmployeeTypes::INVALID == sEmpType)
    {
        sEmpType = getEmpType();
    }

    XyzEmployeeTypes::XyzEmpStatus sEmpStatus = getEmpStatus();
    string sEmpName = getEmpName();
    string sEmpId = getEmpId(mEmpSeqNum, sEmpType);
    string sEmpGender = getEmpGender();
    XyzDate* sEmpDOBPtr = getEmpDOB();
    XyzDate* sEmpDOJPtr = getEmpDOJ();

    if (XyzEmployeeTypes::FULL_TIME == sEmpType)
    {
        uint64 sEmpLeaveBalance = getEmpLeavesBalance();
        sEmpPtr = new XyzFullTimeEmployee(this,
                                          sEmpType,
                                          sEmpStatus,
                                          sEmpName,
                                          sEmpId,
                                          sEmpGender,
                                          sEmpDOBPtr,
                                          sEmpDOJPtr,
                                          sEmpLeaveBalance);
    }
    else if (XyzEmployeeTypes::CONTRACTOR == sEmpType)
    {
        XyzEmployeeTypes::XyzEmpExtAgency sEmpExtAgency = getEmpExtAgency();
        sEmpPtr = new XyzContractorEmployee(this,
                                            sEmpType,
                                            sEmpStatus,
                                            sEmpName,
                                            sEmpId,
                                            sEmpGender,
                                            sEmpDOBPtr,
                                            sEmpDOJPtr,
                                            sEmpExtAgency);
        sEmpPtr->setEmpDOL(sEmpDOJPtr->addYears(1)); // 1 year contract
    }
    else if (XyzEmployeeTypes::CONTRACTOR == sEmpType)
    {
        XyzEmployeeTypes::XyzHiringCollege sEmpCollege = getEmpCollege();
        XyzEmployeeTypes::XyzHiringBranch sEmpBranch = getEmpBranch();
        sEmpPtr = new XyzInternEmployee(this,
                                        sEmpType,
                                        sEmpStatus,
                                        sEmpName,
                                        sEmpId,
                                        sEmpGender,
                                        sEmpDOBPtr,
                                        sEmpDOJPtr,
                                        sEmpCollege,
                                        sEmpBranch);
        sEmpPtr->setEmpDOL(sEmpDOJPtr->addMonths(6)); // 6 months of internship
    }
    else
    {
        // Invalid type cannot create an employee
    }

    // update the employee name field length for summary record
    if (mMaxEmpNameFieldLength < sEmpName.size())
    {
        mMaxEmpNameFieldLength = sEmpName.size()
    }

    return sEmpPtr;
}

void XyzEmployeeManager::pDisplaySummaryHeader()
{
    int sHeaderLength = mMaxEmpNameFieldLength + XyzTestData::EmpRecordLength;
    drawLine(sHeaderLength);
    cout << left << setw(mMaxEmpNameFieldLength) << "| Employee name" << flush;
    cout << left << setw(XyzTestData::EmpIdLength) << "| ID" << flush;
    cout << left << setw(XyzTestData::EmpTypeLength) << "| Type" << flush;
    cout << left << setw(XyzTestData::EmpStatusLength) << "| Status" << flush;
    cout << left << setw(XyzTestData::EmpGenderLength) << "| Gender" << flush;
    cout << left << setw(XyzTestData::EmpDateLength) << "| DOB" << flush;
    cout << left << setw(XyzTestData::EmpDateLength) << "| DOJ" << flush;
    cout << left << setw(XyzTestData::EmpDateLength) << "| DOL" << flush;
    cout << left << setw(XyzTestData::EmpLeavesLength) << "| Leaves Balance" << flush;
    cout << left << setw(XyzTestData::EmpExtAgencyLength) << "| Ext Agency" << flush;
    cout << left << setw(XyzTestData::EmpCollegeLength) << "| College" << flush;
    cout << left << setw(XyzTestData::EmpBranchLength) << "| Branch" << flush;
    cout << "|" << endl;
    drawLine(sHeaderLength);
}

void XyzEmployeeManager::pDisplaySummaryFooter()
{
    int sFooterLength = mMaxEmpNameFieldLength + XyzTestData::EmpRecordLength;
    drawLine(sFooterLength);
}

