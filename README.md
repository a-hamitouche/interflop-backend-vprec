# interflop-backend-vprec

## Arguments
The VPREC backend simulates any floating-point formats that can fit into
the IEEE-754 double precision format with a round to the nearest.
The backend allows modifying the bit length of the exponent (range) and the
pseudo-mantissa (precision).

```bash
Usage: libinterflop_vprec.so [OPTION...]

  -m, --mode=MODE            select VPREC mode among {ieee, full, ib, ob}
      --precision-binary32=PRECISION
                             select precision for binary32 (PRECISION >= 0)
      --precision-binary64=PRECISION
                             select precision for binary64 (PRECISION >= 0)
      --range-binary32=RANGE select range for binary32 (0 < RANGE && RANGE <=
                             8)
      --range-binary64=RANGE select range for binary64 (0 < RANGE && RANGE <=
                             11)
      --error-mode=ERR_MODE  select error mode among (rel, abs, all)
      --max-abs-error-exponent=ERR_EXPONENT
                             select the magnitude of the maximum allowed
                             absolute error (this option is only used when
                             error-mode={abs, all})
  -d, --daz                  denormals-are-zero: sets denormals inputs to zero
  -f, --ftz                  flush-to-zero: sets denormal output to zero
  -?, --help                 Give this help list
      --usage                Give a short usage message
```

Three options control the behavior of the VPREC backend.

The option `--mode=MODE` controls the arithmetic error mode. It accepts the following case insensitive values:

 * `ieee`: the program uses standard IEEE arithmetic, no rounding are introduced
 * `ib`: InBound precision only
 * `ob`: OutBound precision only (*default mode*)
 * `full`: Inbound and outbound mode combined

The option `--precision-binary64=PRECISION` controls the pseudo-mantissa bit length of
the new tested format for floating-point operations in double precision
(respectively for single precision with --precision-binary32).
It accepts an integer value that represents the precision at which
the rounding will be done.

The option `--range-binary64=PRECISION` controls the exponent bit length of
the new tested format for floating-point operations in double precision
(respectively for single precision with --range-binary32).
It accepts an integer value that represents the magnitude of the numbers.

The option `--error-mode=ERR_MODE` controls the way in which the error is
interpreted. It accepts the following modes:

 * `rel`: (default mode) the error is specified relative to the magnitude of
 the floating-point number
 * `abs`: the error threshold is specified as an absolute value, independent of
the value of the floating-point number, to be interpreted as 2<sup>ERR_EXPONENT</sup>
 * `all`: both relative and absolute modes are active simultaneously

The option `--max-abs-error-exponent=ERR_EXPONENT` is used only when the option
`--error-mode=ERR_MODE` is active and controls the magnitude of the error
threshold, when in absolute error mode or all mode. The error thershold is set
to 2<sup>ERR_EXPONENT</sup>.

A detailed description of the backend is given [here](https://hal.archives-ouvertes.fr/hal-02564972/document).

The following example shows the computation with single precision and the simulation of the `bfloat16` format with VPREC:

```bash
   $ VFC_BACKENDS="libinterflop_vprec.so --precision-binary32=23 --range-binary32=8" ./a.out
   (2.903225*2.903225)*16384.000000 = 138096.062500
   $ VFC_BACKENDS="libinterflop_vprec.so --precision-binary32=10 --range-binary32=5" ./a.out
   (2.903225*2.903225)*16384.000000 = inf
```