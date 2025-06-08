#include "quadratic_mpc/quadratic_mpc.hpp"

namespace quadratic_mpc
{
QuadraticMPC::QuadraticMPC()
{
 
}

QuadraticMPC::~QuadraticMPC()
{
  
}

void QuadraticMPC::initializeVariables()
{
    x_ = symbol("x");
    y_ = symbol("y");
    theta_ = symbol("theta");

    f_ = add(mul(x_, sin(theta_)), mul(y_, cos(theta_)));

    dfdx_ = diff(f_, rcp_static_cast<const Symbol>(x_));
    dfdy_ = diff(f_, rcp_static_cast<const Symbol>(y_));
    dfdtheta_ = diff(f_, rcp_static_cast<const Symbol>(theta_));

    std::cout << "f: " << f_->__str__() << std::endl;
    std::cout << "df/dx: " << dfdx_->__str__() << std::endl;
    std::cout << "df/dy: " << dfdy_->__str__() << std::endl;
    std::cout << "df/dtheta: " << dfdtheta_->__str__() << std::endl;
}

void QuadraticMPC::run()
{
  initializeVariables();
}
}