# Project Overview

The **Bank System** project is a console-based application that simulates banking operations. It provides functionalities for clients, employees, and administrators, ensuring secure transactions and user management. The system follows **Object-Oriented Programming (OOP)** principles and implements file handling for data persistence.

## Features

### 1. **Client Module**
- **Login** with ID and password.
- **Deposit** money.
- **Withdraw** money.
- **Check balance.**
- **Transfer** money to another client.

### 2. **Employee Module**
- **Login** with ID and password.
- **Add new clients.**
- **Search** for clients by ID.
- **List** all clients.
- **Edit** client information.
- **View** employee details.

  ### 3. **Admin Module**
- All **employee functionalities**.
- **Add new employees.**
- **Search** for employees.
- **Edit** employee details.
- **List** all employees.
  # How It Works

## **Object-Oriented Design**

- **Person Base Class** → Inherited by **Client** and **Employee**.
- **Employee Class** → Inherited by **Admin**.
- **Validation Class** → Provides static validation functions.
- **FileManager Class** → Handles data storage and retrieval.

## **File Handling**

- **Client**, **Employee**, and **Admin** data are stored in **.txt** files.
- **FileManager class** reads and writes data efficiently.

## **Contribution**

Feel free to contribute by creating a pull request or reporting issues.

## **License**

This project is open-source and available under the **MIT License**.
