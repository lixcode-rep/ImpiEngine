#include "OpenGLRender.h"

OpenGLRender::OpenGLRender(QObject *parent) : QObject(parent)
{
}

void OpenGLRender::initializeGL()
{
    initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void OpenGLRender::paintGL()
{
	glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1000.0f, 0.0f, 0.0f);
		glVertex3f(100.0f, 1000.0f, 0.0f);
		glVertex3f(0.0f, 100.0f, 0.0f);
    glEnd();

	glFinish();
}

void OpenGLRender::resizeGL(const int w, const int h)
{
	if (!inited)
	{
		initializeGL();
		inited = true;
	}

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, h, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
