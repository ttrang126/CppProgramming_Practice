# CppProgramming_Practice

## Excerise 2: CGPA Calculator
A CGPA Calculator is a simple yet useful C++ project that helps students calculate their Cumulative Grade Point Average (CGPA) based on their subject grades and credits. The program takes input for multiple subjects, applies the CGPA formula, and displays the final result in a user-friendly format.

### Feature
1. Input Subjects by Semester – Users can enter the number of semesters and for each semester, provide subject details (name, grade point, credit hours).

2. Calculate GPA – For every semester, the program calculates GPA as the weighted average of grade points.

3. Calculate CGPA – After all semesters are entered, the program computes CGPA as the overall weighted average.

4. Display Results – The program displays GPA for each semester or the final CGPA.

### Algorithm

**Step 1: Start**

**Step 2: Display Menu Options**
Show the user options:

1. Calculate GPA for a new semester
2. Calculate CGPA these semester
3. Exit

**Step 3: Take User Input for Choice**
Read the user's choice.

**Step 4: Perform Actions Based on Choice**

Case 1: Calculate GPA for a new semester
1. Ask User for Number of subjects in this semester**
2. For each subject: Read Subject Name, Grade Point, Credit Hours.
3. Compute GPA for this semester:

   ```GPA = Total Grade Points / Total Credit Hours```

   Save GPA result along with total credit hours for this semester to a list for later CGPA computation.

4. Confirm GPA has been saved.

Case 2: Calculate CGPA these semester
1. If no semesters saved yet → display message: "No GPA data available."
2. Else:
   - Display a list of all saved semesters with their GPA.
   - Ask the user to select which semesters to include in CGPA calculation (e.g., by semester numbers).
   - Compute CGPA:

     ```CGPA = (Sum of (GPA × credit hours) for selected semesters) / (Sum of credit hours for selected semesters)```

   - Display the computed CGPA.

Case 5: Exit Program
1. Display a thank-you message.
2. Terminate the program
