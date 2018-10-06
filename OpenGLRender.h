#ifndef OPENGLRENDER_H
#define OPENGLRENDER_H

#include <QOpenGLFunctions>

class OpenGLRender : public QObject, public QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGLRender(QObject *parent = nullptr);

    void initializeGL();

public slots:
    void paintGL();
    void resizeGL(const int w, const int h);

private:
	bool inited = false;
};

#endif // OPENGLRENDER_H
