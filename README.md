Client and Account Management in a Bank
Overview
This project involves the development of a banking system application written in the C programming language. The system is designed to manage client information and accounts, facilitating essential banking operations such as creating, modifying, and deleting clients and accounts, as well as managing transactions such as withdrawals and transfers. The project emphasizes structured programming techniques and the use of standard libraries in C.

Objectives
Client Management:
Adding New Clients: Validates and stores essential client information.

Modifying Client Information: Allows updates to client details.

Deleting Clients: Removes client information when necessary.

Searching Clients: Enables client search based on various criteria (e.g., ID, name).

Account Management:
Creating New Accounts: Registers new accounts for clients with necessary details.

Consulting Account Balances: Allows users to check the current balance of accounts.

Closing Accounts: Facilitates the closure of accounts.

Handling Financial Transactions: Includes operations such as withdrawals and transfers between accounts.

Data Manipulation:
Data Storage: Organizes client and account data using appropriate structures and ensures data consistency.

Data Updates: Ensures that client and account information is updated properly during operations.

User Interface:
Input Functions: Provides user-friendly input methods for entering client and account data.

Display Functions: Displays client and account information in a clear and comprehensible manner.

Methodology
The development of this project followed an iterative approach:

Needs Analysis: Identified the core features required for client and account management.

Design: Structured data representation using C's structures for clients and accounts.

Development: Used modular development techniques with step-by-step improvements.

Testing & Debugging: Each feature was tested and debugged to ensure functionality and stability.

Key Libraries Used:
stdio.h: For input/output operations.

stdlib.h: For memory management and utilities.

string.h: For string manipulation functions.

Core Functions:
ajouterClient(): Adds a new client to the system.

modifierClient(): Modifies the details of an existing client.

supprimerClient(): Deletes a client from the system.

rechercherClient(): Searches for a client based on specified criteria.

nouveauCompte(): Creates a new account for a client.

consultationCompte(): Consults the details of an existing account.

fermetureCompte(): Closes an existing account.

virement(): Transfers money between two accounts.

menuGestionClients() & menuGestionComptes(): User interfaces for managing clients and accounts.

menuPrincipal(): Main menu for navigating the application.

Results
The application successfully meets all the objectives, providing a working system for managing clients, accounts, and transactions. The system features:

The ability to add, modify, and delete client records.

The ability to create, consult, and close accounts.

Functionality for performing withdrawals and transfers between accounts.

Screenshots:
Client Management: Screens for adding, modifying, and deleting clients.

Account Management: Screens for creating, viewing, and closing accounts.

Transaction Operations: Screens for withdrawals and transfers.
