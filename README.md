# 🚗 Car Rental Management System (C++)

A simple **Console-Based Car Rental Management System** developed in **C++** using **File Handling**. This project allows users to manage car records, rent cars, return cars, search for vehicles, and maintain rental information through a menu-driven interface.

---

## 📌 Features

- ➕ Add new cars
- 🚘 Display available cars
- 🔍 Search cars by Registration ID
- 📄 Rent a car
- 🔄 Return a rented car
- 📋 View rented cars
- ❌ Delete car records
- 💾 Permanent data storage using text files

---

## 🛠 Technologies Used

- C++
- File Handling (`fstream`)
- Structures (`struct`)
- Functions
- Menu Driven Programming
- Object Information Storage
- Input Validation
- Console I/O

---

## 📂 Project Structure

```
Car-Rental-System/
│
├── main.cpp
├── cars_detail.txt        # Stores all car records
├── README.md
```

---

## 📖 How It Works

### 1. Add Car
Stores the following information:

- Owner Name
- Owner Phone Number
- Owner ID
- Car Name
- Model
- Registration ID
- Color
- Rent Per Day

---

### 2. Available Cars

Displays all cars that are currently available for rent along with:

- Car Name
- Model
- Registration Number
- Color
- Rent Per Day

---

### 3. Rent a Car

The customer enters:

- Registration ID
- Customer Name
- Phone Number
- CNIC / ID Card Number
- Number of Rental Days

The system automatically:

- Calculates total rent
- Updates car status
- Stores customer information

---

### 4. Search Car

Allows searching for a car using its Registration ID.

Displays:

- Registration ID
- Rent Per Day
- Availability Status

---

### 5. Return Car

Returns a rented car by:

- Resetting customer details
- Making the car available again
- Clearing previous rental information

---

### 6. View Rented Cars

Displays:

- Car Name
- Customer Name
- Total Rent

---

### 7. Delete Car

Deletes a car record permanently from the database using its Registration ID.

---

## 💾 Data Storage

The project uses **Text File Handling**.

```
cars_detail.txt
```

Each record stores:

- Car Information
- Owner Information
- Customer Information
- Rental Status
- Rent Details

---

## ▶️ How to Run

### Compile

```bash
g++ main.cpp -o CarRental
```

### Run

```bash
./CarRental
```

For Windows:

```bash
g++ main.cpp -o CarRental.exe
CarRental.exe
```

---

## 📷 Sample Menu

```
========= Welcome to Metro Rent Autos =========

1. Add Car
2. Available Cars
3. Rent Car
4. Search Car
5. Return Car
6. View Rented Cars
7. Delete Car
8. Exit
```

---

## 📚 Concepts Used

- Structures
- Functions
- File Handling
- Conditional Statements
- Loops
- Menu Driven Programs
- Input/Output Streams
- Data Persistence

---

## 🚀 Future Improvements

- Login Authentication (Admin/User)
- Password Protection
- GUI Version
- Date & Time Based Rent Calculation
- Fine Calculation for Late Returns
- Search by Car Name or Model
- Sorting Cars
- Better Error Handling
- Database Integration (MySQL/SQLite)

---

## 👨‍💻 Author

**Talha Gillani**

BS Artificial Intelligence Student

---

## 📄 License

This project is developed for educational purposes and is free to use and modify.
