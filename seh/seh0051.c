// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for
// full license information.

// RUN: %cxx -Z7 -EHsc -O2 %s -Fe%t.exe
// RUN: %t.exe

#include <windows.h>
#include "seh.h"

char test[] = "SEH0051.c";
int perfect;

LONG Echo(LONG Value) { return Value; }

int main() {
  LONG Counter;

  Counter = 0;

  try {
    if (Echo(Counter) == Counter) {
      Counter += 3;
      leave;
    } else {
      Counter += 100;
    }
  }
  finally {
    if (AbnormalTermination() == 0) {
      Counter += 5;
    }
  }

  if (Counter != 8) {
    printf("test 51 failed.  Counter = %d\n", Counter);
    return -1;
  }

  return 0;
}
