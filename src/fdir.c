#include "fdir.h"
void fdir_init(fdir_ctx_t* c, uint32_t t, uint8_t r){
  c->state=STATE_NOMINAL; c->elapsed_ms=0; c->timeout_ms=t; c->retry_count=0; c->max_retries=r;
}
void fdir_raise(fdir_ctx_t* c, const char* e){ (void)e;
  if(c->state==STATE_NOMINAL) c->state=STATE_DEGRADED;
}
void fdir_tick(fdir_ctx_t* c, uint32_t dt){
  c->elapsed_ms += dt;
  if(c->elapsed_ms>c->timeout_ms){
    if(c->retry_count++>=c->max_retries) c->state=STATE_SAFE;
    else c->state=STATE_RECOVERY;
    c->elapsed_ms=0;
  }
}
