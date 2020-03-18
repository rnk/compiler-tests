// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for
// full license information.

// RUN: %cxx -Z7 -EHsc -O2 %s -Fe%t.exe
// RUN: %t.exe

#include <windows.h>
#include "seh.h"

char test[] = "SEH0019.c";
int perfect;

void fret(PLONG Counter) {
  try {
    try {
      /* set counter = 2 */
      *Counter += 1;
    }
    finally {
      /* set counter = 3 */
      *Counter += 1;
      return;
    }
  }
  finally {
    /* set counter = 4 */
    *Counter += 1;
  }
  return;
}

int main() {
  LONG Counter;

  Counter = 0;

  try {
    /* set counter = 1 */
    Counter += 1;
    fret(&Counter);
  }
  finally {
    /* set counter = 5 */
    Counter += 1;
  }

  if (Counter != 5) {
    printf("TEST 19 FAILED. Counter = %d\n\r", Counter);
    return -1;
  }

  return 0;
}
