# **Project Overview**  

The **Bank System** is a console-based application that simulates banking operations for **clients, employees, and administrators**. It follows **Object-Oriented Programming (OOP)** principles and implements **file handling** for data persistence.  

## **# Features**  

### **## Client Module (Managed by ClientManager)**  
- **Secure Login** using ID and password.  
- **Deposit & Withdraw** money.  
- **Check balance.**  
- **Transfer** money to another client.  
- **Update password securely.**  

### **## Employee Module (Managed by EmployeeManager)**  
- **Login** as an employee.  
- **Create & manage client accounts.**  
- **Search for clients** by ID.  
- **View and update client details.**  
- **List all registered clients.**  

### **## Admin Module (Managed by AdminManager)**  
- **All employee functionalities.**  
- **Create & manage employee accounts.**  
- **Search for employees.**  
- **Edit employee details.**  
- **List all employees.**  

## **# How It Works**  

### **## Object-Oriented Design Enhancements**  
- **Screens Class** → Manages all user interface screens.  
- **ClientManager, EmployeeManager, AdminManager** → Handle respective functionalities.  
- **Person Base Class** → Parent of **Client** and **Employee**.  
- **Employee Class** → Inherited by **Admin**.  
- **Validation Class** → Provides input validation.  
- **FileManager Class** → Handles all file operations.  

### **## File Handling Improvements**  
- Now handled by **FilesHelper** for better efficiency.  
- All data updates (**clients, employees, admins**) are **automatically saved** after changes.  

## **# Contribution**  
- Fork the repository and create a **new feature branch**.  
- Follow **OOP principles** and ensure **proper separation of concerns**.  
- Test changes before submitting a **pull request**.  

## **# License**  
This project is open-source and available under the **MIT License**.  
