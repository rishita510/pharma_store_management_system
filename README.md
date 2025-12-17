Pharma Store Management System
This project is a C-based application designed to automate inventory management and customer billing for pharmaceutical stores. It aims to replace manual record-keeping with an efficient digital system that reduces human error, provides real-time stock alerts, and streamlines the customer checkout process.





📌 Project Overview
The Pharma Store Management System bridges the gap between store operations and customer service. It allows administrators to manage medicine data while providing customers with a simple interface to search for remedies based on health conditions, view pricing, and receive itemized receipts.





🚀 Key Features

Inventory Automation: Easily handle inputs, updates, and deletion of medicine information, including names, expiry dates, and prices.




Low-Stock Alerts: Automatically notifies the user when medicine levels fall below a specific threshold or are no longer available.



Categorized Search: Medicines are organized by health conditions, allowing customers to find recommended treatments quickly.



Automated Billing: Calculates total costs in real-time and generates itemized receipts containing customer details like name and age.





Persistent Data Storage: Uses file handling to ensure that inventory and medicine details are saved and can be retrieved later.

🛠️ Technical Implementation
The system is built using C and leverages several fundamental computer science concepts to ensure efficiency and reliability:



Data Structures (struct): Used to define complex types for medications, customers, and orders.


File Handling: Enables reading and writing data to files for persistent storage.


Dynamic Memory Management: Utilizes malloc, calloc, and free for efficient memory allocation.


Algorithms: Implements linear and binary search algorithms to quickly locate inventory items.


Modular Programming: Reusable functions and recursion are used to optimize code and manage operations like stock updates.


📂 System Modules

Inventory Management Module: Manages the lifecycle of medicine records, from adding new stock to deleting records.



Billing Module: Handles customer inputs, quantity selection, and price calculation.




Search and Display Module: Provides a user-facing interface to find medicines by name or batch number.



File Management Module: Ensures all system data is saved to disk for long-term use.


📖 How to Use

Run the application to access the main interface.


Inventory Side: Add or update medicines with their name, price, expiry date, and current stock levels.



Customer Side: Enter a health condition to view recommended medicines and their availability.


Checkout: Provide customer details (name, age) to generate an itemized bill
