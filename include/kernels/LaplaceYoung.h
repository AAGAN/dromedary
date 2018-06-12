#ifndef LAPLACEYOUNG_H
#define LAPLACEYOUNG_H

#include "Kernel.h"

class LaplaceYoung;

template <>
InputParameters validParams<LaplaceYoung>();

class LaplaceYoung : public Kernel
{
public:
  LaplaceYoung(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;
};

#endif /* LAPLACEYOUNG */
