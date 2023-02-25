#include "visualizer.hpp"
#include "../matplotlibcpp.h"

namespace plt = matplotlibcpp;

void visualizeDots(DotCollection &dc, ClosestPairData &closest)
{
  auto fig = plt::figure();
  plt::subplot("3d");
  vector<vector<double>> x, y, z;
  vector<double> x_row, y_row, z_row;
  for (int i = 0; i < dc.length(); i++)
  {
    Dot &dot = dc[i];
    if (&dot != &closest.getFirstDot() && &dot != &closest.getSecondDot())
    {
      x_row.push_back(dot[0]);
      y_row.push_back(dot[1]);
      z_row.push_back(dot[2]);
    }
    else
    {
      vector<double> x_row, y_row, z_row;
      x_row.push_back(dot[0]);
      y_row.push_back(dot[1]);
      z_row.push_back(dot[2]);
      plt::scatter(x_row, y_row, z_row, 1.0, {{"color", "red"}}, fig);
    }
  }
  plt::scatter(x_row, y_row, z_row, 1.0, {{"color", "blue"}}, fig);
  plt::show();
}