# Feature: Sweep Letter

## Objective
Enable creation of 3D channel letter via sweep operation.

## Inputs
- Profile (TopoDS_Wire)
- Height (double, mm)
- DraftAngle (degrees)

## Process
- Extrude along Z-axis
- Apply draft angle outward
- Generate inner offset for wall thickness
- Subtract internal cavity

## Output
- TopoDS_Solid

## Validation Rules
- Must be valid manifold
- No self-intersection
- Constant wall thickness ±0.05mm
- Volume > 0

## Error Cases
- Profile not closed
- Negative height
- Draft angle > 10° (restricted)

## Performance Target
- < 500ms on 200mm letter
