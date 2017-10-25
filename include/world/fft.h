//-----------------------------------------------------------------------------
// Copyright 2012 Masanori Morise
// Author: mmorise [at] yamanashi.ac.jp (Masanori Morise)
// Last update: 2017/02/01
//
// These functions and variables are defined to use FFT as well as FFTW
// Please see fft.cpp to show the detailed information
//-----------------------------------------------------------------------------
#ifndef WORLD_FFT_H_
#define WORLD_FFT_H_

#include "world/macrodefinitions.h"
#include "fftw3.h"

WORLD_BEGIN_C_DECLS

// Commands for FFT (This is the same as FFTW)
#define FFT_FORWARD FFTW_FORWARD
#define FFT_BACKWARD FFTW_BACKWARD
#define FFT_ESTIMATE FFTW_ESTIMATE

// Complex number for FFT
#define fft_complex fftw_complex
//typedef double fft_complex[2];
// Struct used for FFT
/*
typedef struct {
  int n;
  int sign;
  unsigned int flags;
  fft_complex *c_in;
  double *in;
  fft_complex *c_out;
  double *out;
  double *input;
  int *ip;
  double *w;
} fft_plan;
 */
#define fft_plan fftw_plan
#define fft_plan_dft_1d fftw_plan_dft_1d
#define fft_plan_dft_c2r_1d fftw_plan_dft_c2r_1d
#define fft_plan_dft_r2c_1d fftw_plan_dft_r2c_1d
#define fft_execute fftw_execute
#define fft_destroy_plan fftw_destroy_plan
/*
fft_plan fft_plan_dft_1d(int n, fft_complex *in, fft_complex *out, int sign,
  unsigned int flags);
fft_plan fft_plan_dft_c2r_1d(int n, fft_complex *in, double *out,
  unsigned int flags);
fft_plan fft_plan_dft_r2c_1d(int n, double *in, fft_complex *out,
  unsigned int flags);
void fft_execute(fft_plan p);
void fft_destroy_plan(fft_plan p);
*/
WORLD_END_C_DECLS

#endif  // WORLD_FFT_H_
