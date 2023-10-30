#include "MathFunctions.h"
#include "mysqrt.h"

namespace MathFunctions
{
  double sqrt(double x)
  {
    return detail::mysqrt(x);
  }
}
