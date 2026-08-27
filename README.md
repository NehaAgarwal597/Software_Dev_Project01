# TripMate – Smart Travel & Budget Planner

A console-based C++ application for planning trips, managing travel packages, and getting a smart, budget-matched destination recommendation. Built using file handling (no database) as part of Software Development Lab I.

## Overview

TripMate has two roles:

- **Admin** manages travel packages (add, view, search, update, delete).
- **User** can register/login, explore destinations, plan a trip within a budget, book/cancel tours, view booking history, and get a smart recommendation for the best-matching destination based on budget and trip type.

All data (packages, users, bookings) is stored in plain `.txt` files inside the `data/` folder.

## Features

### Admin
- Add / View / Search / Update / Delete travel packages
- Duplicate Package ID check on add

### User
- Register and Login (username-based)
- Explore all available destinations
- Plan a Trip — enter destination, number of travelers and budget; system checks if the estimated cost fits the budget and books it automatically if it does
- View My Trips (booking history)
- Cancel Booking
- **Smart Tour Recommendation** — enter budget, preferred trip type (Beach/Mountain/Historical/Nature), and number of travelers. The system calculates a **Budget Fit %** and **Trip Type Match %** for every package, combines them into a **Total Match Score**, lists all packages with their scores, and highlights the single best match. Built using STL `vector`.

## Tech Stack

- **Language:** C++
- **Compiler:** TDM-GCC-64 (g++)
- **Storage:** Plain text files (`data/packages.txt`, `data/users.txt`, `data/bookings.txt`)
- **STL used:** `vector`

## Project Structure

```
TripMate/
 ├── main.cpp
 ├── Package.h / Package.cpp
 ├── User.h / User.cpp
 ├── Booking.h / Booking.cpp
 └── data/
      ├── packages.txt
      ├── users.txt
      └── bookings.txt
```

## Build Instructions

```bash
g++ main.cpp Package.cpp User.cpp Booking.cpp -o main
```

## Run Instructions

```bash
.\main.exe
```
(On the first run, make sure a `data/` folder exists in the project directory — the program writes its `.txt` files there.)

## Usage Guide

1. From the main menu, choose **Admin Login** (password: `admin789`) to add travel packages first — the system needs at least one package before a user can plan a trip.
2. Choose **Register** to create a user account, then **Login** with that username.
3. From the User Menu, try **Plan a Trip** to book directly, or **Get Recommendation** to compare all packages by budget fit and trip type before deciding.
4. **My Trips** shows booking history; **Cancel Booking** cancels by Booking ID.

## Future Improvements

- **Weather-aware planning:** show typical weather for each destination and suggest the best time of year to visit, ideally pulled from a live weather API (e.g. OpenWeatherMap) instead of static data
- **Food recommendations:** curated list of good local food/restaurants per destination
- **Transport comparison:** compare available transport options (bus/train/flight) by cost and travel time, and factor the cheapest option into the budget/recommendation calculation instead of using package price alone
- **Hotel recommendations:** suggest hotels per destination at different budget tiers
- **API integration:** move from static `.txt` files toward live APIs (weather, currency, maybe hotel pricing) for more accurate, real-time cost estimation — this would also be a natural point to migrate storage from text files to a proper database (e.g. SQLite)
- **Security improvements:** add real password-based authentication for users (currently username-only) and hash/encrypt the admin password instead of a hardcoded plaintext check
- Filter packages by budget/country without full recommendation scoring