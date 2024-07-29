#include "e.h"


int main() {
  int i;
  /* This is misusing the error checking macros since they
   * assume you are making calls that set errno, but these
   * constants obviously do not. As a result, the final
   * ENULL test will fail, but the error descriptor will
   * be "Success". */
  EOK0(0);
  EOK1(1);
  EM1(0);
  ENULL(&i);
  ENULL(NULL);

  return 0;
}
