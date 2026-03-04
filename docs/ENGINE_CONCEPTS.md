# Engine Concepts

This document explains important architecture concepts used in XtruSign Pro.

## Operations

Operations are geometry algorithms that generate or modify shapes.

Examples:

- Sweep
- Loft
- Boolean
- Offset

Operations belong to the geometry engine.

Example:

engine/operations/Sweep.cpp

Operations must be independent from the UI.

---

## Commands

Commands represent user actions triggered from the UI.

Commands usually support undo/redo functionality.

Examples:

- SweepCommand
- LoftCommand
- DeleteCommand

Commands belong to the application layer.

Example:

application/commands/SweepCommand.cpp

---

## Features

Features represent parametric modeling elements stored in the feature tree.

Examples:

- SweepFeature
- FilletFeature
- WallThicknessFeature

Features store parameters and can rebuild geometry.

Features are part of the parametric modeling system.

---

## Topology

Topology represents the structural definition of shapes.

Examples:

- Vertex
- Edge
- Wire
- Face
- Shell
- Solid

Topology is managed by the geometry engine.
