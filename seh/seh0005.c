// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for
// full license information.

// RUN: %cxx -Z7 -EHsc -O2 %s -Fe%t.exe
// RUN: %t.exe

#include <windows.h>
#include "seh.h"

char test[] = "SEH0005.c";
int perfect;

int main() {
  PLONG BadAddress;
  PLONG BlackHole;
  LONG Counter;

  BadAddress = (PLONG)((PVOID)0);
  BlackHole = &Counter;

  Counter = 0;

  try {
    Counter += 1;
    *BlackHole += *BadAddress;
  }
  except(Counter)
  /* counter == 1 (EXECUTE HANDLER) */
  {
    Counter += 1;
  }

  if (Counter != 2) {
    printf("TEST 5 FAILED. Counter = %d\n\r", Counter);
    return -1;
  }

  return 0;
}
