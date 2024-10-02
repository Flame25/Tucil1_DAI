#include "steep_ascent.hpp"
#include <cube.hpp>
#include <open_gl_utils.hpp>

int main(int argc, char **argv) {
  std::srand(
      static_cast<unsigned int>(std::time(nullptr))); // Seed for randomness

  // Initialize GLUT
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Magic Cube 5x5x5");

  // Initialize OpenGL settings and cube data
  open_gl_utils::init();

  // Register callback functions
  glutDisplayFunc(open_gl_utils::display);
  glutReshapeFunc(open_gl_utils::reshape);
  glutMouseFunc(
      open_gl_utils::mouseButton); // Register mouse button event handler
  glutMotionFunc(
      open_gl_utils::mouseMotion); // Register mouse motion event handler
  std::thread cubeUpdater(steep_ascent::hill_climbing); // Different thread for
  // updating cube

  // Enter the main loop
  glutMainLoop();

  cubeUpdater.join(); // Wait for the updateCube thread to finish before
  // exiting
  return 0;
}
