# XtruSign Pro Architecture

## Overview

XtruSign Pro is a modular CAD-style application for designing and generating 3D channel letters and signage geometry.

The architecture separates the **geometry engine**, **application logic**, and **user interfaces** to ensure maintainability, portability, and future expansion to web and hybrid environments.

The core geometry engine is written in **C++** and remains independent of any UI framework.

---

## Architectural Layers

```
+---------------------------------------------------+
|                 Desktop UI (Qt)                   |
|                 apps/desktop                      |
+---------------------------------------------------+
|               Application Layer                   |
|               application/                        |
|  Document management, workflow, commands         |
+---------------------------------------------------+
|               Geometry Engine                     |
|               engine/                             |
|  Topology, operations, parametric rebuild logic  |
+---------------------------------------------------+
|           Geometry Kernel Adapter                 |
|           Open CASCADE integration                |
+---------------------------------------------------+
```

---

## Module Structure

```
xtrusign-pro/
│
├── apps/
│   ├── desktop/         # Qt desktop UI
│   └── web/             # Future web interface
│
├── engine/              # Core geometry engine
│   └── src/
│
├── application/         # Business logic
│
├── commands/            # Command pattern (undo/redo)
│
├── ui_interface/        # UI abstraction layer
│
├── tests/               # Unit and regression tests
│
├── docs/                # Documentation and specs
│
├── third_party_licenses/
│
└── CMakeLists.txt
```

---

## Layer Responsibilities

### Geometry Engine (`engine/`)

Responsibilities:

* Core geometry operations
* Topology management
* Shape validation
* Parametric rebuild logic
* Geometry generation algorithms

Constraints:

* Must **not depend on Qt**
* Must remain **UI independent**
* Must remain **portable**

---

### Application Layer (`application/`)

Responsibilities:

* Document management
* Feature execution
* Command orchestration
* High-level workflow logic

The application layer connects the UI with the geometry engine.

---

### Commands (`commands/`)

Implements the **Command Pattern**.

Responsibilities:

* Undo / Redo support
* Feature execution
* Action history tracking

Example commands:

```
SweepCommand
LoftCommand
WallThicknessCommand
```

---

### UI Interface (`ui_interface/`)

Defines abstract UI interfaces so the engine can remain independent from any specific UI framework.

Examples:

```
IViewport
IPanel
ICommandUI
```

---

### Desktop UI (`apps/desktop/`)

Qt-based desktop interface responsible for:

* 3D visualization
* User interaction
* Panels and toolbars
* Debug visualization

The UI layer must never contain geometry algorithms.

---

### Web UI (`apps/web/`)

Future interface for hybrid or web deployment.

The geometry engine may be compiled to WebAssembly to support browser-based workflows.

---

## Dependency Rules

Dependencies must follow this direction:

```
Desktop UI
    ↓
Application Layer
    ↓
Geometry Engine
```

Forbidden dependencies:

```
engine → Qt
engine → desktop UI
application → UI frameworks
```

These rules ensure that the engine remains portable.

---

## Geometry Kernel

The geometry engine uses **Open CASCADE Technology (OCCT)** as its underlying geometry kernel.

Responsibilities handled by OCCT include:

* Boundary representation (BRep)
* Boolean operations
* Surface generation
* Topology validation

The engine provides a wrapper layer around OCCT to keep implementation details isolated.

---

## Testing Strategy

Tests are located in:

```
tests/
```

Types of tests:

* Unit tests for geometry utilities
* Topology validation tests
* Operation tests
* Regression geometry tests

Testing framework: **Catch2**

Tests must depend only on:

```
engine/
application/
```

and never on the UI.

---

## Future Expansion

The architecture supports future features including:

* WebAssembly build of the engine
* Hybrid cloud workflows
* Plugin system
* Advanced parametric modeling

Maintaining strict layer separation will allow these expansions without major refactoring.

---

## Design Principles

The following principles guide development:

* Modular architecture
* Clear layer separation
* Engine portability
* Test-driven geometry development
* Deterministic geometry generation
* Robust topology validation

---

## Summary

XtruSign Pro is designed with a layered architecture to keep the geometry engine stable and portable while allowing multiple UI frontends.

Strict adherence to module boundaries ensures long-term maintainability and scalability of the platform.
