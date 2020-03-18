// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for
// full license information.

// RUN: %cxx -Z7 -EHsc -O2 %s -Fe%t.exe
// RUN: %t.exe

#include <windows.h>
#include "seh.h"

#define faill()
#define startest()
#define finish()

char test[] = "SEH0035.c";
int perfect;

int main() {
  ULONG Index1;
  LONG Counter;

  Counter = 0;

  for (Index1 = 0; Index1 < 10; Index1 += 1) {
    try {
      try {
        if ((Index1 & 0x1) == 0) {
          /* add 1 to counter if INdex1 is odd */
          Counter += 1;
        }
      }
      finally {
        /* always add 2 to counter */
        Counter += 2;
        continue;
      }
      /* never get here due to continue */
      Counter += 4;
    }
    finally {
      /* always add 5 to counter */
      Counter += 5;
    }
    /* never get here due to continue */
    Counter += 6;
  }

  if (Counter != 75) {
    printf("TEST 35 FAILED. Counter = %d\n\r", Counter);
    return -1;
  }

  return 0;
}
