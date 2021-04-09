[Mesh]
  type = GeneratedMesh
  xmax = 2
  xmin =
  ymax = 0.3
  ymin =
  zmin = -0.5
  ymax = 0.5
[]

[Variables]
  [./u]
    family = LAGRANGE
    order = FIRST
  [../]
[]

[Kernels]
  [./diff]
    type = Diffusion
    variable = u
  [../]
[]

[BCs]
  [./inflow]
    type = InflowBC
    boundary = rear
    variable = u
    velocity = '1 0 0'
  [../]
[]

[Executioner]
  type = Transient
  [./TimeIntegrator]
    type = ExplicitTVDRK2
  [../]
  solve_type = 'PJFNK'
[]

[Outputs]
  exodus = true
[]
