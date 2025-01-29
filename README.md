
---

#### **Introduction**
" It is a **Patient Management System** implemented in C. This program is designed to manage patient records and their associated bills efficiently. It uses a **queue** to manage patients and a **stack** to handle bills, ensuring a structured and organized approach to healthcare management."

---

#### **Overview of the Program**
"The program has the following key features:
1. **Add Patient**: Adds a new patient to the system.
2. **Delete Patient**: Removes a patient from the system.
3. **Display Patients**: Shows all patients currently in the system.
4. **Search Patient**: Allows searching for a specific patient by name.
5. **Manage Bills**: Handles billing operations, including adding bills, notifying dues, and generating payment receipts.
6. **Exit**: Exits the program."

---

#### **Data Structures Used**
1. **Patient Queue**:
   - The program uses a **queue** to manage patients. A queue follows the **First-In-First-Out (FIFO)** principle, which is ideal for handling patients in the order they arrive.
   - The `Patient` structure contains fields like `name`, `age`, `date`, `condition`, and a pointer to the next patient.

2. **Bill Stack**:
   - Bills are managed using a **stack**. A stack follows the **Last-In-First-Out (LIFO)** principle, which is useful for managing bills where the most recent bill is processed first.
   - The `Bill` structure contains fields like `patientID`, `amount`, and a pointer to the next bill."

---

#### **Key Functions**
1. **`addPatient()`**:
   - Adds a new patient to the queue.
   - Takes input for the patient's name, age, admission date, and condition.
   - If the queue is empty, the new patient is set as both the front and rear. Otherwise, the new patient is added to the rear.

2. **`deletePatient()`**:
   - Removes the patient at the front of the queue.
   - If the queue becomes empty after deletion, both `front` and `rear` are set to `NULL`.

3. **`displayPatients()`**:
   - Displays all patients in the queue in a tabular format.
   - If the queue is empty, it shows a message indicating no patients are available.

4. **`searchPatient()`**:
   - Searches for a patient by name.
   - If found, it displays the patient's details; otherwise, it shows a "Patient not found" message.

5. **`manageBills()`**:
   - Handles billing operations.
   - Allows adding a bill, notifying dues, and generating payment receipts.
   - Applies a **25% discount** for patients above 50 years of age.

6. **`paymentReceipt()`**:
   - Generates a payment receipt for a specific patient by searching the bill stack.

---

#### **Demonstration**
"Now, I will demonstrate the program step by step."

1. **Add Patients**:
   - "I will add a few patients to the system. For example:
     - Name: John Doe, Age: 45, Date: 2023-10-01, Condition: Fever.
     - Name: Jane Smith, Age: 55, Date: 2023-10-02, Condition: Fracture."

2. **Display Patients**:
   - "Let’s display all patients. As you can see, the patients are listed in the order they were added."

3. **Search Patient**:
   - "I will search for a patient by name, say 'Jane Smith'. The program will display her details."

4. **Manage Bills**:
   - "Now, I will add a bill for Jane Smith. Since she is above 50, she gets a 25% discount on her bill."
   - "I will add a General Checkup and an X-Ray to her bill. The total amount after discount is calculated and displayed."

5. **Notify Dues**:
   - "The program can notify dues for patients who haven’t paid their bills. Let’s check for dues."

6. **Generate Payment Receipt**:
   - "Finally, I will generate a payment receipt for Jane Smith. The receipt shows her patient ID, total amount, and payment status."

7. **Delete Patient**:
   - "I will delete a patient from the system. For example, John Doe is removed from the queue."

---

#### **Defense**
1. **Why use a queue for patients?**
   - "A queue ensures that patients are handled in the order they arrive, which is fair and efficient for a healthcare system."

2. **Why use a stack for bills?**
   - "A stack allows us to process the most recent bills first, which is useful for managing payments and receipts."

3. **How are discounts applied?**
   - "The program checks the patient’s age. If the patient is above 50, a 25% discount is applied to their bill."

4. **What are the limitations of this program?**
   - "Currently, the program uses static arrays for discounts and payment status, which limits scalability. In a real-world scenario, we could use dynamic data structures or a database for better management."

5. **How can this program be improved?**
   - "We can add features like saving data to a file, handling multiple queues for different departments, and integrating with a payment gateway for real-time payments."

---

#### **Conclusion**
"In conclusion, this Patient Management System is a simple yet effective program for managing patient records and bills. It demonstrates the use of fundamental data structures like queues and stacks in a real-world application."

---

