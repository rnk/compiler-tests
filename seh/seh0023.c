// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for
// full license information.

// RUN: %cxx -Z7 -EHsc -O2 %s -Fe%t.exe
// RUN: %t.exe

#include <windows.h>
#include <setjmp.h>
#include "seh.h"

char test[] = "SEH0023.c";
int perfect;

int main() {
  jmp_buf JumpBuffer;
  LONG Counter;

  Counter = 0;

  if (_setjmp(JumpBuffer) == 0) {
    try {
      try {
        /* set counter = 1 */
        (volatile LONG) Counter += 1;
        RaiseException(EXCEPTION_INT_OVERFLOW, 0, /*no flags*/ 0, 0);
      }
      finally {
        /* set counter = 2 */
        (volatile LONG) Counter += 1;
        longjmp(JumpBuffer, 1);
      }
    }
    except(1)
    /* should never get here */
    {
      (volatile LONG) Counter += 1;
    }
  } else {
    /* set counter = 3 */
    (volatile LONG) Counter += 1;
  }

  if (Counter != 3) {
    printf("TEST 23 FAILED. Counter = %d\n\r", Counter);
    return -1;
  }

  return 0;
}
