# 🍽️ Restaurant Order Management System (C Project)
### 🚀 Priority Queue Based | VIP System | Menu-Driven Console App

A modern and efficient **Restaurant Order Management System** built in **C**, using **Priority Queues** to handle *VIP* and *Normal* customer orders. This project simulates a real-world restaurant workflow — ensuring VIP orders always get served first.

---

## ⭐ Features

### 🥇 1. Priority Handling (VIP > Normal)
VIP orders are always served before regular customers.

### 🧾 2. Add New Orders
Each order includes:
- Customer Name
- Food Item
- Auto-generated Order ID
- Priority (VIP / Normal)

### 🍴 3. Serve Next Order
Automatically picks:
- VIP queue first  
- Normal queue next  

### 📜 4. View Pending Orders
Displays both queues:
- 🔶 VIP Orders
- 🔹 Normal Orders

### 🔍 5. Search Order by ID  
Find any order in the system instantly.

---

## 🧠 Concepts Used

| Concept | Used For |
|--------|----------|
| **Structs** | Order representation |
| **Array-based Queue** | VIP & Normal orders |
| **Priority Queues** | Serving VIP customers first |
| **Menu System** | User interaction |
| **String Handling** | Names & items |

---

## 🖥️ Sample Output

```
=============================================
     RESTAURANT ORDER MANAGEMENT SYSTEM      
         (VIP & NORMAL PRIORITY)             
=============================================

1. Place New Order
2. Serve Next Order
3. Show All Pending Orders
4. Search Order by ID
5. Exit
---------------------------------------
Enter your choice (1-5): 1

--- Place New Order ---
Customer Name: Rahul
Order Item: Paneer Butter Masala
Priority Type (1 = VIP, 0 = Normal): 1

[VIP ORDER PLACED]
Generated Order ID: 1
```

---

## 🛠️ Installation & Running

### Compile:
```bash
gcc restaurant_order_system.c -o restaurant
```

### Run:
```bash
./restaurant
```

---

## 📁 Project Structure
```
📦 Restaurant-Order-Management
├── restaurant_order_system.c
└── README.md
```

---

## 🎯 Learning Outcomes
- Priority queue logic  
- Queue operations (enqueue/dequeue)  
- Real-world service system simulation  
- Clean C programming structure  

---

## 🧑‍💻 Author
**Sameer Kumar**  
SRM University AP  

---

## ⭐ Support
If you like this project, consider giving it a star on GitHub!
