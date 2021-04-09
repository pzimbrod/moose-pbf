#include "lpbfApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
lpbfApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

lpbfApp::lpbfApp(InputParameters parameters) : MooseApp(parameters)
{
  lpbfApp::registerAll(_factory, _action_factory, _syntax);
}

lpbfApp::~lpbfApp() {}

void
lpbfApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"lpbfApp"});
  Registry::registerActionsTo(af, {"lpbfApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
lpbfApp::registerApps()
{
  registerApp(lpbfApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
lpbfApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  lpbfApp::registerAll(f, af, s);
}
extern "C" void
lpbfApp__registerApps()
{
  lpbfApp::registerApps();
}
