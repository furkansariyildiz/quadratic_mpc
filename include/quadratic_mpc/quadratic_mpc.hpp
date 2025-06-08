#ifndef QUADRATIC_MPC_HPP
#define QUADRATIC_MPC_HPP

#include <symengine/symengine_rcp.h>
#include <symengine/symbol.h>
#include <symengine/derivative.h>
#include <symengine/eval_double.h>
#include <symengine/functions.h>

namespace quadratic_mpc
{
using namespace SymEngine;
class QuadraticMPC
{
  public:
    QuadraticMPC();
    ~QuadraticMPC();
    void run();

    private:
    RCP<const Basic> x_;
    RCP<const Basic> y_;
    RCP<const Basic> theta_;
    
    RCP<const Basic> f_;
    RCP<const Basic> dfdx_;
    RCP<const Basic> dfdy_;
    RCP<const Basic> dfdtheta_;
    void initializeVariables();
};
}

#endif // QUADRATIC_MPC_HPP