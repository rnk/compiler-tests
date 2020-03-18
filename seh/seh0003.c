// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for
// full license information.

// RUN: %cxx -Z7 -EHsc -O2 %s -Fe%t.exe
// RUN: %t.exe

#include <windows.h>
#include "seh.h"

char test[] = "SEH0003.c";
int perfect;

int main() {
  LONG Counter;

  Counter = 0;

  try {
    Counter -= 1;
    RaiseException(EXCEPTION_INT_OVERFLOW, 0, /* no flags */
                   0, ((LPDWORD)0));
  }
  except(Counter)
  /* counter should be negative, indicating "CONTINUE EXECUTE" */
  {
    Counter -= 1;
  }

  if (Counter != -1) {
    printf("TEST 3 FAILED.  Counter = %d\n\r", Counter);
    return -1;
  }

  return 0;
}
