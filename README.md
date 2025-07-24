# CppProgramming_Practice

## Excerise 2: CGPA Calculator
A CGPA Calculator is a simple yet useful C++ project that helps students calculate their Cumulative Grade Point Average (CGPA) based on their subject grades and credits. The program takes input for multiple subjects, applies the CGPA formula, and displays the final result in a user-friendly format.

### Feature
1. Input Subjects by Semester – Users can input subjects for each semester including name, midterm score, final score, and credit hours.

2. 10-to-4 GPA Conversion – The program calculates the average score using 40% midterm + 60% final, and maps it to the 4.0 GPA scale with letter grades (A+, B, C, etc.).

3. Calculate GPA – GPA is computed as a weighted average of all subject grade points in the semester.

4. Calculate CGPA – CGPA is calculated as the overall weighted average GPA across all entered semesters.

5. Display Results – Output includes a subject report for each semester and a semester list for CGPA summary.

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
2. For each subject: 
    - Input: Subject name, credit hours, midterm score, final score.
    - Compute:
        ```AverageScore = 0.4 × Midterm + 0.6 × Final```
    - Convert to GPA and letter grade using a grading table.
3. Compute GPA for this semester:

   ```GPA = Total Grade Points / Total Credit Hours```

4. Store semester GPA and total credits to a list.

5. Display the subject table and GPA for the semester.

Case 2: Calculate CGPA these semester
1. If no semesters saved yet → display message: "No semester available."
2. Else:
   - Display a list of all saved semesters (name, credits, GPA)
   - Compute CGPA:

     ```CGPA = (Sum of (GPA × credit hours) for selected semesters) / (Sum of credit hours for selected semesters)```

   - Display the computed CGPA.

Case 5: Exit Program
1. Display a thank-you message.
2. Terminate the program
