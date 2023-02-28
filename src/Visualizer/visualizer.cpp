#include "visualizer.hpp"
#include "../matplotlibcpp.h"

namespace plt = matplotlibcpp;

void visualizeDots(DotCollection &dc, ClosestPairData &closest)
{
  // create figure
  auto fig = plt::figure();
  plt::subplot("3d");

  // vector of coordinates
  vector<double> x, y, z;
  for (int i = 0; i < dc.length(); i++)
  {
    Dot &dot = dc[i];

    // if not two closest dots, push to main vector
    if (&dot != &closest.getFirstDot() && &dot != &closest.getSecondDot())
    {
      x.push_back(dot[0]);
      y.push_back(dot[1]);
      z.push_back(dot[2]);
    }
    else
    {
      // create vector to scatter differently
      vector<double> x, y, z;
      x.push_back(dot[0]);
      y.push_back(dot[1]);
      z.push_back(dot[2]);
      plt::scatter(x, y, z, 1.0, {{"color", "red"}}, fig);
    }
  }
  // scatter main vector
  plt::scatter(x, y, z, 1.0, {{"color", "blue"}}, fig, 0.25);
  plt::xlabel("X");
  plt::ylabel("Y");
  plt::set_zlabel("Z");

  plt::show();
}