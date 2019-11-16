#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <vector>
#include <Colors.h>

bool drawPixel(
	const int width,
  const int height,
  const int x,
  const int y,
  const TypeDef_Color color,
  std::vector<unsigned char>&image);

void getPixel(
  const int width,
  const int height,
  const int x,
  const int y,
  TypeDef_Color & color_ref,
  std::vector<unsigned char>&image);

#endif /* FIGURE_H */
