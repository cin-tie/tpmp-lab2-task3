# Laboratory Work 2, Task 3

## Overview
A C program for managing transport routes. The program implements:
- Input of route information
- Finding the route with minimum length
- Sorting routes by length
- Searching for routes by start or end point

## Author
Neyfeld Kirill
GitHub: cin-tie

## Usage

### Prerequisites
- GCC compiler
- Make utility

### Build and Run

1. **Clone the repository:**
```bash
git clone git@github.com:cin-tie/tpmp-lab2-task3.git
cd tpmp-lab2-task3
```
2. **Build the program:**
```bash
make
```
3. **Run the program:**
```bash
make run
```
or directly:
```bash
./bin/marshrut_program
```

4. **Clean build files:**
```bash
make clean
```

## Additional Notes

### Technical Details
- **Maximum routes:** 10 (defined by MAX_MARSHUTS constant)
- **String length limit:** 50 characters for point names (defined by MAX_NAME_LEN)
- **Programming language:** C (C99 standard)
- **Build system:** Make
- **Code style:** Follows K&R indentation style
