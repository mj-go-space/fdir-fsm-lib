#include "fdir.h"
#include <assert.h>
int main(void){
  fdir_ctx_t x; fdir_init(&x, 100, 1);
  fdir_raise(&x,"sensor_fault");  assert(x.state==STATE_DEGRADED);
  fdir_tick(&x,150);              /* RECOVERY or SAFE */
  return 0;
}
