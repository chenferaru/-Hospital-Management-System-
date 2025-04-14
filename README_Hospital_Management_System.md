# Hospital Management System

A comprehensive console-based Hospital Management System developed in C++ as a final project for Object-Oriented Programming coursework. This application simulates core hospital operations, demonstrating the application of object-oriented principles in a healthcare context.

## Features

- **Patient Management**: Register and manage patient information, including personal details and medical history.
- **Staff Management**: Handle data for various hospital staff members such as doctors, nurses, and researchers.
- **Departmental Organization**: Structure hospital departments and assign staff accordingly.
- **Appointment Scheduling**: Facilitate scheduling of patient appointments with appropriate medical personnel.
- **Research Integration**: Manage research activities and associate them with relevant staff members.
- **Modular Design**: Utilize separate classes and headers for different entities to promote code maintainability and scalability.

## Technologies Used

- C++
- Object-Oriented Programming (OOP) principles

## Getting Started

### Prerequisites

- A C++ compiler (e.g., GCC, Clang, or MSVC)
- An IDE or text editor (e.g., Visual Studio, Code::Blocks, or VS Code)

### Running the Application

1. **Clone the repository**:
   ```bash
   git clone https://github.com/chenferaru/-Hospital-Management-System-.git
   ```
2. **Navigate to the project directory**:
   ```bash
   cd -Hospital-Management-System-
   ```
3. **Compile the source code**:
   - If using the command line:
     ```bash
     g++ -std=c++11 -o HospitalManagementSystem *.cpp
     ```
   - Alternatively, open the project in your preferred IDE and build the solution.
4. **Run the executable**:
   ```bash
   ./HospitalManagementSystem
   ```

## Project Structure

- `Main.cpp`: Entry point of the application.
- `Hospital.cpp` / `Hospital.h`: Core hospital management functionalities.
- `Doctor.cpp` / `Doctor.h`: Doctor-related operations and data.
- `Nurse.cpp` / `Nurse.h`: Nurse-related operations and data.
- `PatientForSurg.cpp` / `PatientForSurg.h`: Surgical patient management.
- `Research.cpp` / `Research.h`: Research activities and associations.
- Additional headers and source files for other entities like departments, employees, and visit cards.

## Known Issues

- Some functionalities may be incomplete or require further refinement.
- Error handling and input validation need enhancement for robustness.

## Future Enhancements

- Implement a graphical user interface (GUI) for improved user interaction.
- Integrate a database system for persistent data storage.
- Expand functionalities to cover more comprehensive hospital operations.

## License

This project is open-source and available under the [MIT License](LICENSE).
