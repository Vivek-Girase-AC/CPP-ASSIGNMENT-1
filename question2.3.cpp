#include <iostream>
using namespace std;

int main()
{
    int statusReg  = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg    = 0b11001010;

    // ================= PTR1 =================

    cout << "==== ptr1 ====" << endl;

    const int* regPtr1 = &statusReg;

    cout << *regPtr1 << endl;

    // *regPtr1 = 30;
    // ERROR: cannot modify the value through regPtr1
    // because regPtr1 points to const int.

    regPtr1 = &dataReg;
    // ALLOWED: regPtr1 itself is NOT const.
    // Therefore, it can point to another int.

    cout << *regPtr1 << endl;


    // ================= PTR2 =================

    cout << "==== ptr2 ====" << endl;

    int* const regPtr2 = &controlReg;

    cout << *regPtr2 << endl;

    *regPtr2 = 100;
    // ALLOWED: the value can be modified.

    cout << *regPtr2 << endl;

    // regPtr2 = &dataReg;
    // ERROR: regPtr2 is a const pointer.
    // Therefore, it cannot be repointed.


    // ================= PTR3 =================

    cout << "==== ptr3 ====" << endl;

    const int* const regPtr3 = &statusReg;

    cout << *regPtr3 << endl;

    // *regPtr3 = 50;
    // ERROR: cannot modify the value because it is const.

    // regPtr3 = &dataReg;
    // ERROR: cannot change the address because the pointer is const.


    return 0;

}
