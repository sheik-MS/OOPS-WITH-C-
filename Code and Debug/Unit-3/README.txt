UNIT III - COMPLETE SOLUTIONS (REBUILT FROM LATEST UPLOAD)

Includes:
- UNIT3_Fully_Solved_Answers.docx (answers, corrected full C++ programs, traces and pseudocode)
- cpp/A1...A5 .cpp (5 independently compilable and executable correction programs)
- pseudocode/B1...B5 .txt (5 structured class algorithms, main routines, tables)
- VERIFIED_OUTPUTS.txt (exact captured output for each C++ program)
- ORIGINAL_QUESTIONS.docx (unmodified uploaded source document)

Build in a terminal:
  g++ -std=c++17 -Wall -Wextra -Wpedantic cpp/A1_DynamicString.cpp -o A1
  ./A1
Repeat with A2-A5 source filenames.

Review notes:
A2 uses deterministic allocation IDs in output because pointer addresses change each run.
The compiler error text for the original buggy code varies by toolchain.
See DOCX for details and conceptual memory traces.
