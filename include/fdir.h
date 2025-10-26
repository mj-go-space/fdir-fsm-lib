#ifndef FDIR_H
#define FDIR_H
#include <stdint.h>
typedef enum { STATE_NOMINAL, STATE_DEGRADED, STATE_SAFE, STATE_RECOVERY } fdir_state_t;
typedef struct {
  fdir_state_t state; uint32_t elapsed_ms, timeout_ms; uint8_t retry_count, max_retries;
} fdir_ctx_t;
void fdir_init(fdir_ctx_t* c, uint32_t timeout_ms, uint8_t max_retries);
void fdir_raise(fdir_ctx_t* c, const char* event_id);
void fdir_tick(fdir_ctx_t* c, uint32_t dt_ms);
#endif
