
// This class is the one which would manage all the operations on the employee objects.

#ifndef XYZEMPLOYEEMANAGER_H
#define XYZEMPLOYEEMANAGER_H

#include "XyzEmployeeIF.H"
#include "DLL.H"
using namespace std;

class XyzEmployeeManager
{
  public:
    XyzEmployeeManager();
    ~XyzEmployeeManager();

    // create a random employee
    void addEmployee();
    // add an employee based on type provided
    void addEmployee(XyzEmployeeTypes::XyzEmpType empTypeParm);
    // Employee being terminated or resigned. In both the cases the status would be 'resigned'.
    void removeEmployee(string empIdParm);
    // Search an employee based on the any of the employee fields (like Name, Id, Type, Status etc).
    // Returns the employee pointer if a match is found.
    // Returns NULL is not found
    XyzEmployee* searchEmployee(XyzEmployeeTypes::XyzEmpFields empFieldParm,
                                string keyParm);
    // Add some leaves to all the full-time employees.
    void addLeaves(int leavesCountParm);
    // Convert an intern/contractor to a full-time employee.
    void convertToFullTimeEmployee(string empIdParm);

    // get the max field length for printing employee name
    inline uint64 getMaxEmpFieldLength() {return mMaxEmpNameFieldLength;}

    // functions for printing employee summaries
    // Print summary of all the employees
    void printEmployeeSummary();
    // Print summary of all the employees with specific type (F/C/I)
    void printEmployeeSummary(XyzEmployeeTypes::XyzEmpType empTypeParm);
    // Print summary of all the employees with specific status
    void printEmployeeSummary(XyzEmployeeTypes::XyzEmpStatus empStatusParm);

  protected:
    XyzEmployee* pCreateEmployee(XyzEmployeeTypes::XyzEmpType empTypeParm = XyzEmployeeTypes::INVALID);

  private:
    DLL<XyzEmployee>* mEmpList;
    DLL<XyzEmployee>* mNonEmpList;
    uint64 mEmpSeqNum;
    uint64 mMaxEmpNameFieldLength;
};

#endif
