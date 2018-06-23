void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
  int i;
  int triangleAmount = 1000; 
  GLfloat twicePi = 2.0f * PI;

  glEnable(GL_LINE_SMOOTH);
  glLineWidth(5.0);

  glBegin(GL_LINES);
  glColor4f(1.0, 0.0, 0.0, 1.0);
  for(i = 0; i <= triangleAmount; i++)
  {
  glVertex2f( x, y);
  glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
  }
  glEnd();
}
