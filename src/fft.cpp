//-----------------------------------------------------------------------------
// Copyright 2012 Masanori Morise
// Author: mmorise [at] yamanashi.ac.jp (Masanori Morise)
// Last update: 2017/02/01
//
// This file represents the functions about FFT (Fast Fourier Transform)
// implemented by Mr. Ooura, and wrapper functions implemented by M. Morise.
// We can use these wrapper functions as well as the FFTW functions.
// Please see the FFTW web-page to show the usage of the wrapper functions.
// Ooura FFT:
//   (Japanese) http://www.kurims.kyoto-u.ac.jp/~ooura/index-j.html
//   (English) http://www.kurims.kyoto-u.ac.jp/~ooura/index.html
// FFTW:
//   (English) http://www.fftw.org/
// 2012/08/24 by M. Morise
//-----------------------------------------------------------------------------
#include "world/fft.h"
#include <fftw3.h>

fft_plan fft_plan_dft_1d(int n, fft_complex *in, fft_complex *out, int sign, unsigned int flags)
{
  return fftw_plan_dft_1d(n, in, out, sign, flags);
}

fft_plan fft_plan_dft_c2r_1d(int n, fft_complex *in, double *out, unsigned int flags)
{
  return fftw_plan_dft_c2r_1d(n, in, out, flags);
}

fft_plan fft_plan_dft_r2c_1d(int n, double *in, fft_complex *out, unsigned int flags)
{
  return fftw_plan_dft_r2c_1d(n, in, out, flags);
}

void fft_execute(fft_plan p)
{
  fftw_execute(p);
}

void fft_execute_dft_r2c(const fftw_plan p, double *in, fftw_complex *out)
{
  fftw_execute_dft_r2c(p, in, out);
}

void fft_destroy_plan(fft_plan p)
{
  fftw_destroy_plan(p);
}

double* fft_alloc_real(std::size_t n)
{
  return fftw_alloc_real(n);
}

fft_complex* fft_alloc_complex(std::size_t n)
{
  return fftw_alloc_complex(n);
}

void fft_free(void *p)
{
  fftw_free(p);
}
