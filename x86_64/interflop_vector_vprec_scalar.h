/*****************************************************************************\
 *                                                                           *\
 *  This file is part of the Verificarlo project,                            *\
 *  under the Apache License v2.0 with LLVM Exceptions.                      *\
 *  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception.                 *\
 *  See https://llvm.org/LICENSE.txt for license information.                *\
 *                                                                           *\
 *                                                                           *\
 *  Copyright (c) 2015                                                       *\
 *     Universite de Versailles St-Quentin-en-Yvelines                       *\
 *     CMLA, Ecole Normale Superieure de Cachan                              *\
 *                                                                           *\
 *  Copyright (c) 2018                                                       *\
 *     Universite de Versailles St-Quentin-en-Yvelines                       *\
 *                                                                           *\
 *  Copyright (c) 2019-2023                                                  *\
 *     Verificarlo Contributors                                              *\
 *                                                                           *\
 ****************************************************************************/

#ifndef __INTERFLOP_VECTOR_VPREC_SCALAR_H__
#define __INTERFLOP_VECTOR_VPREC_SCALAR_H__


#define INTERFLOP_VECTOR_VPREC_API(name) interflop_vector_vprec_##name##_##scalar

void INTERFLOP_VECTOR_VPREC_API(add_float_1)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(add_float_4)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(add_float_8)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(add_float_16)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(sub_float_1)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(sub_float_4)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(sub_float_8)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(sub_float_16)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(mul_float_1)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(mul_float_4)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(mul_float_8)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(mul_float_16)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(div_float_1)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(div_float_4)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(div_float_8)(float *a, float *b, float *c,
                                          void *context);
void INTERFLOP_VECTOR_VPREC_API(div_float_16)(float *a, float *b, float *c,
                                          void *context);
struct interflop_vector_type_t INTERFLOP_VECTOR_VPREC_API(init)(void *context);

#endif