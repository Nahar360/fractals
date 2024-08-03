add_executable(fractals
  Bitmap.cpp
  Bitmap.hpp
  BitmapFileHeader.hpp
  BitmapInfoHeader.hpp
  FractalCreator.hpp
  FractalCreator.cpp
  Mandelbrot.cpp
  Mandelbrot.hpp
  Zoom.hpp
  ZoomList.cpp
  ZoomList.hpp
  main.cpp
)

target_link_libraries(fractals PRIVATE)
