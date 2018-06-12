#include "LaplaceYoung.h"

registerMooseObject("DromedaryApp", LaplaceYoung);

template <>
InputParameters
validParams<LaplaceYoung>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("The Laplacian operator ($-\\nabla \\cdot \\nabla u$), with the weak "
                             "form of $(\\nabla \\phi_i, \\nabla u_h)$.");
  return params;
}

LaplaceYoung::LaplaceYoung(const InputParameters & parameters) : Kernel(parameters) {}

Real
LaplaceYoung::computeQpResidual()
{
  Real k = 1. / std::sqrt(1. + _grad_u[_qp] * _grad_u[_qp]);
  Real kappa = 1.;
  return k * _grad_u[_qp] * _grad_test[_i][_qp] + 
    kappa * _u[_qp] * _test[_i][_qp];
}

Real
LaplaceYoung::computeQpJacobian()
{
  Real k = 1. / std::sqrt(1. + _grad_u[_qp] * _grad_u[_qp]);
  Real kappa = 1.;
  return k * _grad_phi[_j][_qp] * _grad_test[_i][_qp] +
    kappa * _phi[_j][_qp] * _test[_i][_qp];
}
