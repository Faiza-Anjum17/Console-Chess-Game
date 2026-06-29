# Console-Based Chess Game (C++)

A fully functional, turn-based console chess game implemented in C++ using core Object-Oriented Programming (OOP) design patterns. The game features an interactive colored 8×8 grid board, movement validation for all standard chess pieces, and dynamic memory management.

## 🚀 Features
- **Polymorphic Piece Movement:** Complete move validation logic unique to each piece type (Pawn, Rook, Knight, Bishop, Queen, King).
- **Interactive UI:** A custom, visually clear 8×8 board rendered directly in the Windows terminal with alternating square background colors.
- **Algebraic Notation Parser:** Supports standard algebraic-style coordinates (e.g., `e2 e4`) for clean gameplay mechanics.
- **Robust Move Validation:** Prevents players from moving their opponent's pieces, landing on their own pieces, or making illegal paths.
- **System Check Tracking:** Scans the board state dynamically to recognize check conditions ("king in danger").
- **Automatic Memory Cleanup:** Utilizes secure constructors and destructors to safely free memory when pieces are captured or when the game instance finishes.

---

## 🛠️ System Architecture & OOP Implementation

This project was built to showcase clean, scalable architecture utilizing four core pillars of Object-Oriented Programming:

### 1. Inheritance & Polymorphism
The design centers around an abstract base class `Piece`, which defines the contract for all specific chess components via pure virtual functions:
- `virtual bool canMove(...) const = 0;`
- `virtual char getSymbol() const = 0;`

Six concrete classes inherit from `Piece`: `Pawn`, `Rook`, `Knight`, `Bishop`, `Queen`, and `King`. Polymorphism allows the `Board` grid to manage an array of base pointers (`Piece*`), resolving exact movement mechanics dynamically at runtime.

### 2. Encapsulation
State mutation rules are tightly restricted. Piece positions, operational matrices, and color characteristics are kept safe within their respective boundaries, accessible only via public getters and setters (e.g., `getColor()`, `isKilled()`).

### 3. Composition
The `Board` class maintains a structural "has-a" composite relation with the `Piece` objects, managing an internal `Piece* grid[8][8]` grid array. It controls configuration initialization, move deployment, and terminal visualization, keeping piece logic distinct from positional state tracking.

---

## 📂 Project Structure

```text
├── Main.cpp             # Game initialization, coordinates parser, and main driver execution
├── Game.h / Game.cpp     # Encapsulates core turn-alternation game mechanics and verification loops
├── Board.h / Board.cpp   # Manages grid composition setup, terminal drawing, and state analysis
├── Piece.h              # Abstract Base class detailing universal metrics for derived elements
├── Pawn.h / Pawn.cpp     # Pawn specific validation logic (Double steps, diagonal strikes)
├── Rook.h / Rook.cpp     # Rook validation logic (Straight row/column sliding with path block evaluation)
├── Knight.h / Knight.cpp # Knight specific translation calculations (Unblocked L-shape leaping)
├── Bishop.h / Bishop.cpp # Bishop validation rules (Diagonal sliding trajectory scanning)
├── Queen.h / Queen.cpp   # Queen system logic (Combined behavior patterns of both Rook and Bishop)
└── King.h / King.cpp     # King movement bounds check (Single index range evaluation)
