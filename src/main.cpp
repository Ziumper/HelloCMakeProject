#include <cmath>
#include <iostream>
#include <string>
#include <GLFW/glfw3.h>
#include "MathFunctions.h"
#include "HelloConfig.h"

int main()
{
  std::cout << "Testing Hello Project" << std::endl;

  GLFWwindow* window;
  int width, height;

  if( !glfwInit() )
  {
      fprintf( stderr, "Failed to initialize GLFW\n" );
      exit( EXIT_FAILURE );
  }

  // glfwWindowHint(GLFW_DEPTH_BITS, 16);
  // glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

  window = glfwCreateWindow( 300, 300, "Hello Window", NULL, NULL );
  if (!window)
  {
      fprintf( stderr, "Failed to open GLFW window\n" );
      glfwTerminate();
      exit( EXIT_FAILURE );
  }

  // Main loop
  while( !glfwWindowShouldClose(window) )
  {
      // Swap buffers
      glfwSwapBuffers(window);
      glfwPollEvents();
  }

  // Terminate GLFW
  glfwTerminate();

  // Exit program
  exit( EXIT_SUCCESS );


  return 0;
}
