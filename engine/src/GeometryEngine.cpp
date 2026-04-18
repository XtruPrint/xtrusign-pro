#include "GeometryEngine.h"
#include <BRepPrimAPI_MakeBox.hxx>
#include <TopoDS_Shape.hxx>
#include <iostream>

void GeometryEngine::createBox() {
    TopoDS_Shape box = BRepPrimAPI_MakeBox(100.0, 50.0, 30.0).Shape();
    std::cout << "Box created using OCCT" << std::endl;
}