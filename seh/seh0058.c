// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for
// full license information.

#include <windows.h>
#include "seh.h"

char test[] = "SEH0058.c";
int perfect;

int main() {
  LONG Counter;

  Counter = 0;

  try {
    Counter += 1;
    RaiseException(EXCEPTION_INT_OVERFLOW, 0, /* no flags */
                   0, ((LPDWORD)0));
  }
  except(Counter) {
    try {
      Counter += 3;
      RaiseException(EXCEPTION_INT_OVERFLOW, 0, /* no flags */
                     0, ((LPDWORD)0));
    }
    except(Counter - 3) { Counter += 5; }
  }

  if (Counter != 9) {
    printf("TEST 58 FAILED.  Counter = %d\n\r", Counter);
    return -1;
  }

  return 0;
}
