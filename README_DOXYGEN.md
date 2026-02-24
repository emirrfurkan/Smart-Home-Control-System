# Doxygen Documentation (SmartHomeProject)

## Generate HTML documentation
1. Install Doxygen (and optionally Graphviz).
2. Open a terminal in the project folder (where `Doxyfile` is).
3. Run:
   ```bash
   doxygen Doxyfile
   ```
4. Open:
   - `docs/html/index.html`

## Notes
- Build artifacts are excluded via `EXCLUDE_PATTERNS`.
- The source files contain Doxygen-style comments in English.
