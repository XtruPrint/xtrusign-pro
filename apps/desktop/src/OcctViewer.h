#pragma once

#include <QWidget>
#include <QPoint>

#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>
#include <AIS_InteractiveContext.hxx>

class OcctViewer : public QWidget
{
public:
    explicit OcctViewer(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

    QPaintEngine* paintEngine() const override;

private:
    void initViewer();

    Handle(V3d_View) view;
    Handle(V3d_Viewer) viewer;
    Handle(AIS_InteractiveContext) context;

    QPoint lastPos;
};