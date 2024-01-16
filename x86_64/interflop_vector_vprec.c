#include "../interflop_vprec.h"

#ifdef VECT128
#include "interflop_vector_vprec_sse.h"
#else
#include "interflop_vector_vprec_scalar.h"
#endif


/******************** VPREC ARITHMETIC FUNCTIONS ********************
 * The following set of functions perform the VPREC operation. Operands
 * are first correctly rounded to the target precison format if inbound
 * is set, the operation is then perform using IEEE hw and
 * correct rounding to the target precision format is done if outbound
 * is set.
 *******************************************************************/

#define PERFORM_FMA(A, B, C)                                                   \
  _Generic(A, float                                                            \
           : interflop_fma_binary32, double                                    \
           : interflop_fma_binary64, __float128                                \
           : interflop_fma_binary128)(A, B, C)

/* perform_binary_op: applies the binary operator (op) to (a) and (b) */
/* and stores the result in (res) */
#define perform_binary_op(op, res, a, b)                                       \
  switch (op) {                                                                \
  case vprec_add:                                                              \
    res = (a) + (b);                                                           \
    break;                                                                     \
  case vprec_mul:                                                              \
    res = (a) * (b);                                                           \
    break;                                                                     \
  case vprec_sub:                                                              \
    res = (a) - (b);                                                           \
    break;                                                                     \
  case vprec_div:                                                              \
    res = (a) / (b);                                                           \
    break;                                                                     \
  default:                                                                     \
    logger_error("invalid operator %c", op);                                   \
  };

static inline float _vprec_binary32_binary_op(float a, float b,
                                              const vprec_operation op,
                                              void *context) {
  vprec_context_t *ctx = (vprec_context_t *)context;
  float res = 0;

  if ((ctx->mode == vprecmode_full) || (ctx->mode == vprecmode_ib)) {
    a = _vprec_round_binary32(a, 1, context, ctx->binary32_range,
                              ctx->binary32_precision);
    b = _vprec_round_binary32(b, 1, context, ctx->binary32_range,
                              ctx->binary32_precision);
  }

  perform_binary_op(op, res, a, b);

  if ((ctx->mode == vprecmode_full) || (ctx->mode == vprecmode_ob)) {
    res = _vprec_round_binary32(res, 0, context, ctx->binary32_range,
                                ctx->binary32_precision);
  }

  return res;
}

void INTERFLOP_VECTOR_VPREC_API(add_float_1)(float *a, float *b, float *c, void *context) {
  *c = _vprec_binary32_binary_op(*a, *b, vprec_add, context);
}

void INTERFLOP_VECTOR_VPREC_API(add_float_4)(float *a, float *b, float *c, void *context) {
  for(int i = 0; i < 4; i++) {
    *(c+i) = _vprec_binary32_binary_op(*(a+i), *(b+i), vprec_add, context);
  }
}

void INTERFLOP_VECTOR_VPREC_API(add_float_8)(float *a, float *b, float *c, void *context) {
  for(int i = 0; i < 8; i++) {
    *(c+i) = _vprec_binary32_binary_op(*(a+i), *(b+i), vprec_add, context);
  }
}

void INTERFLOP_VECTOR_VPREC_API(add_float_16)(float *a, float *b, float *c, void *context) {
  for(int i = 0; i < 16; i++) {
    *(c+i) = _vprec_binary32_binary_op(*(a+i), *(b+i), vprec_add, context);
  }
}


void INTERFLOP_VECTOR_VPREC_API(sub_float_1)(float *a, float *b, float *c, void *context) {
  *c = _vprec_binary32_binary_op(*a, *b, vprec_sub, context);
}

void INTERFLOP_VECTOR_VPREC_API(sub_float_4)(float *a, float *b, float *c, void *context) {
  for(int i = 0; i < 4; i++) {
    *(c+i) = _vprec_binary32_binary_op(*(a+i), *(b+i), vprec_sub, context);
  }
}

void INTERFLOP_VECTOR_VPREC_API(sub_float_8)(float *a, float *b, float *c, void *context) {
  for(int i = 0; i < 8; i++) {
    *(c+i) = _vprec_binary32_binary_op(*(a+i), *(b+i), vprec_sub, context);
  }
}

void INTERFLOP_VECTOR_VPREC_API(sub_float_16)(float *a, float *b, float *c, void *context) {
  for(int i = 0; i < 16; i++) {
    *(c+i) = _vprec_binary32_binary_op(*(a+i), *(b+i), vprec_sub, context);
  }
}


void INTERFLOP_VECTOR_VPREC_API(mul_float_1)(float *a, float *b, float *c, void *context) {
  *c = _vprec_binary32_binary_op(*a, *b, vprec_mul, context);
}

void INTERFLOP_VECTOR_VPREC_API(mul_float_4)(float *a, float *b, float *c, void *context) {
  for(int i = 0; i < 4; i++) {
    *(c+i) = _vprec_binary32_binary_op(*(a+i), *(b+i), vprec_mul, context);
  }
}

void INTERFLOP_VECTOR_VPREC_API(mul_float_8)(float *a, float *b, float *c, void *context) {
  for(int i = 0; i < 8; i++) {
    *(c+i) = _vprec_binary32_binary_op(*(a+i), *(b+i), vprec_mul, context);
  }
}

void INTERFLOP_VECTOR_VPREC_API(mul_float_16)(float *a, float *b, float *c, void *context) {
  for(int i = 0; i < 16; i++) {
    *(c+i) = _vprec_binary32_binary_op(*(a+i), *(b+i), vprec_mul, context);
  }
}


void INTERFLOP_VECTOR_VPREC_API(div_float_1)(float *a, float *b, float *c, void *context) {
  *c = _vprec_binary32_binary_op(*a, *b, vprec_div, context);
}

void INTERFLOP_VECTOR_VPREC_API(div_float_4)(float *a, float *b, float *c, void *context) {
  for(int i = 0; i < 4; i++) {
    *(c+i) = _vprec_binary32_binary_op(*(a+i), *(b+i), vprec_div, context);
  }
}

void INTERFLOP_VECTOR_VPREC_API(div_float_8)(float *a, float *b, float *c, void *context) {
  for(int i = 0; i < 8; i++) {
    *(c+i) = _vprec_binary32_binary_op(*(a+i), *(b+i), vprec_div, context);
  }
}

void INTERFLOP_VECTOR_VPREC_API(div_float_16)(float *a, float *b, float *c, void *context) {
  for(int i = 0; i < 16; i++) {
    *(c+i) = _vprec_binary32_binary_op(*(a+i), *(b+i), vprec_div, context);
  }
}

struct interflop_vector_type_t INTERFLOP_VECTOR_VPREC_API(init)(void *context) {
  struct interflop_vector_type_t vbackend = {
    add : {
      op_vector_float_1 : INTERFLOP_VECTOR_VPREC_API(add_float_1),
      op_vector_float_4 : INTERFLOP_VECTOR_VPREC_API(add_float_4),
      op_vector_float_8 : INTERFLOP_VECTOR_VPREC_API(add_float_8),
      op_vector_float_16 : INTERFLOP_VECTOR_VPREC_API(add_float_16)
    },
    sub : {
      op_vector_float_1 : INTERFLOP_VECTOR_VPREC_API(sub_float_1),
      op_vector_float_4 : INTERFLOP_VECTOR_VPREC_API(sub_float_4),
      op_vector_float_8 : INTERFLOP_VECTOR_VPREC_API(sub_float_8),
      op_vector_float_16 : INTERFLOP_VECTOR_VPREC_API(sub_float_16)
    },
    mul : {
      op_vector_float_1 : INTERFLOP_VECTOR_VPREC_API(mul_float_1),
      op_vector_float_4 : INTERFLOP_VECTOR_VPREC_API(mul_float_4),
      op_vector_float_8 : INTERFLOP_VECTOR_VPREC_API(mul_float_8),
      op_vector_float_16 : INTERFLOP_VECTOR_VPREC_API(mul_float_16)
    },
    div : {
      op_vector_float_1 : INTERFLOP_VECTOR_VPREC_API(div_float_1),
      op_vector_float_4 : INTERFLOP_VECTOR_VPREC_API(div_float_4),
      op_vector_float_8 : INTERFLOP_VECTOR_VPREC_API(div_float_8),
      op_vector_float_16 : INTERFLOP_VECTOR_VPREC_API(div_float_16)
    }
  };
  return vbackend;
}
