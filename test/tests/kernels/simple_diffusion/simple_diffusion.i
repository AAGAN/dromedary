[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 10
[]

[Variables]
  [./bob]
  [../]
[]

[Kernels]
  [./diff]
    type = LaplaceYoung
    variable = bob
  [../]
[]

[BCs]
  [./all_sides]
    type = NeumannBC
    variable = bob
    boundary = 'left right top bottom'
    value = 0.2
  [../]
[]

[Executioner]
  type = Steady
  solve_type = 'PJFNK'
  #solve_type = 'NEWTON'
#  petsc_options_iname = '-pc_type -pc_hypre_type'
#  petsc_options_value = 'hypre boomeramg'
  petsc_options_iname = '-pc_type'
  petsc_options_value = 'lu'

[]

[Outputs]
  exodus = true
[]
