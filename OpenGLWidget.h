#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QQuickItem>
#include <OpenGLRender.h>
#include <QQuickWindow>

class OpenGLWidget : public QQuickItem
{
    Q_OBJECT
public:
    OpenGLWidget();

public slots:
    void sync();
    void cleanup();

private slots:
    void handleWindowChanged(QQuickWindow *win);

private:
    OpenGLRender *render = nullptr;
};

#endif // OPENGLWIDGET_H
