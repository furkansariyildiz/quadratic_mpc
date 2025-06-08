#include "quadratic_mpc/quadratic_mpc.hpp"
#include <iostream>

int main(int argc, char** argv)
{
  std::cout << "Quadratic MPC Example" << std::endl;

  quadratic_mpc::QuadraticMPC mpc;
  mpc.run();

  return 0;
}