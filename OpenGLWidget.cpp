#include "OpenGLWidget.h"

OpenGLWidget::OpenGLWidget()
{
    connect(this, &QQuickItem::windowChanged, this, &OpenGLWidget::handleWindowChanged);
}

void OpenGLWidget::sync()
{
    if (render == nullptr)
    {
        render = new OpenGLRender();
        connect(window(), &QQuickWindow::beforeRendering,
                render, &OpenGLRender::paintGL);
    }

	if (window()->size() != oldSize)
	{
		render->resizeGL(window()->width(), window()->height());
		oldSize = window()->size();
	}
}

void OpenGLWidget::cleanup()
{
    if (render)
    {
        delete render;
        render = nullptr;
    }
}

void OpenGLWidget::handleWindowChanged(QQuickWindow *win)
{
    if (win)
    {
        connect(win, &QQuickWindow::beforeSynchronizing, this, &OpenGLWidget::sync);
        connect(win, &QQuickWindow::sceneGraphInvalidated, this, &OpenGLWidget::cleanup);

        win->setClearBeforeRendering(false);
    }
}
