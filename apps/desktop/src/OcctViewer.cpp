#include "OcctViewer.h"

#include <OpenGl_GraphicDriver.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Cocoa_Window.hxx>

#include <BRepPrimAPI_MakeBox.hxx>
#include <AIS_Shape.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Graphic3d_RenderingParams.hxx>

#include <QMouseEvent>
#include <QWheelEvent>

// =============================
// Constructor
// =============================
OcctViewer::OcctViewer(QWidget* parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_NativeWindow);
    setAttribute(Qt::WA_PaintOnScreen);

    initViewer();
}

// =============================
// Init Viewer
// =============================
void OcctViewer::initViewer()
{
    // 🔧 Display + Driver
    Handle(Aspect_DisplayConnection) display =
        new Aspect_DisplayConnection();

    Handle(OpenGl_GraphicDriver) driver =
        new OpenGl_GraphicDriver(display);

    // 🔧 Viewer
    viewer = new V3d_Viewer(driver);
    viewer->SetDefaultLights();
    viewer->SetLightOn();

    // 🔧 Context
    context = new AIS_InteractiveContext(viewer);

    // 🔧 View
    view = viewer->CreateView();

    // ✅ Anti-aliasing (smooth edges)
    Graphic3d_RenderingParams& params = view->ChangeRenderingParams();
    params.IsAntialiasingEnabled = Standard_True;
    params.NbMsaaSamples = 8;

    // 🔧 Attach to Qt window (macOS)
    Handle(Cocoa_Window) wind =
        new Cocoa_Window((NSView*)this->winId());

    view->SetWindow(wind);

    if (!wind->IsMapped())
        wind->Map();

    view->MustBeResized();

    // 🎨 Background + shading
    view->SetBgGradientColors(
        Quantity_NOC_BLACK,
        Quantity_NOC_GRAY30,
        Aspect_GFM_VER
    );

    view->SetShadingModel(V3d_PHONG);
    view->SetImmediateUpdate(Standard_True);

    // =============================
    // 📦 Create Geometry (BOX)
    // =============================
    TopoDS_Shape box =
        BRepPrimAPI_MakeBox(100, 100, 100).Shape();

    Handle(AIS_Shape) aisBox = new AIS_Shape(box);
    aisBox->SetDisplayMode(AIS_Shaded);
    aisBox->SetColor(Quantity_NOC_GOLD);

    // Optional: edge outline
    aisBox->Attributes()->SetFaceBoundaryDraw(true);
    aisBox->Attributes()->SetFaceBoundaryAspect(
        new Prs3d_LineAspect(
            Quantity_NOC_BLACK,
            Aspect_TOL_SOLID,
            1.0
        )
    );

    context->Display(aisBox, Standard_True);

    // 📷 Camera
    view->SetProj(V3d_Zpos);
    view->SetPerspectiveProjection(Standard_True);

    view->FitAll(0.01);
    view->ZFitAll();

    view->Redraw();
}

// =============================
// Disable Qt paint engine
// =============================
QPaintEngine* OcctViewer::paintEngine() const
{
    return nullptr;
}

// =============================
// Resize
// =============================
void OcctViewer::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    if (!view.IsNull())
        view->MustBeResized();
}

// =============================
// Mouse Press
// =============================
void OcctViewer::mousePressEvent(QMouseEvent* event)
{
    auto pos = event->position();
    int x = static_cast<int>(pos.x());
    int y = static_cast<int>(pos.y());

    lastPos = QPoint(x, y);

    if (!view.IsNull() && event->button() == Qt::LeftButton) {
        view->StartRotation(x, y);
    }
}

// =============================
// Mouse Move
// =============================
void OcctViewer::mouseMoveEvent(QMouseEvent* event)
{
    if (view.IsNull())
        return;

    auto pos = event->position();
    int x = static_cast<int>(pos.x());
    int y = static_cast<int>(pos.y());

    if (event->buttons() & Qt::LeftButton) {
        view->Rotation(x, y);
    }
    else if (event->buttons() & Qt::MiddleButton) {
        int dx = x - lastPos.x();
        int dy = y - lastPos.y();
        view->Pan(dx, -dy);
    }

    lastPos = QPoint(x, y);
    view->Redraw();
}

// =============================
// Mouse Wheel (Zoom)
// =============================
void OcctViewer::wheelEvent(QWheelEvent* event)
{
    if (view.IsNull())
        return;

    auto pos = event->position();
    int x = static_cast<int>(pos.x());
    int y = static_cast<int>(pos.y());

    view->StartZoomAtPoint(x, y);

    if (event->angleDelta().y() > 0) {
        view->ZoomAtPoint(x, y, x - 50, y - 50);
    } else {
        view->ZoomAtPoint(x, y, x + 50, y + 50);
    }

    view->Redraw();
}