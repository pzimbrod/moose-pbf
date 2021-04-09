//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "lpbfTestApp.h"
#include "lpbfApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
lpbfTestApp::validParams()
{
  InputParameters params = lpbfApp::validParams();
  return params;
}

lpbfTestApp::lpbfTestApp(InputParameters parameters) : MooseApp(parameters)
{
  lpbfTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

lpbfTestApp::~lpbfTestApp() {}

void
lpbfTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  lpbfApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"lpbfTestApp"});
    Registry::registerActionsTo(af, {"lpbfTestApp"});
  }
}

void
lpbfTestApp::registerApps()
{
  registerApp(lpbfApp);
  registerApp(lpbfTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
lpbfTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  lpbfTestApp::registerAll(f, af, s);
}
extern "C" void
lpbfTestApp__registerApps()
{
  lpbfTestApp::registerApps();
}
