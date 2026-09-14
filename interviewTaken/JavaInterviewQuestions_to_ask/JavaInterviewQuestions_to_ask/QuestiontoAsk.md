## Interview with the Gabriel Borges :
######  Here is the Evaluation report from my side for the interview scheduled with Gabriel Borges 
###  [on Mon 24 Aug 2024 9:30pm - 10:30pm]
-----------------------
## NOTE : 1 means answered, 0 mean he don't know, 2 Mean moderate
> RATING is out of **10**.

-----------------------
## Introduction/Communication Skills/Domains Knowledge based questions mentioned in resume
[RATING] interviewee : 
[RATING] Interviewer : 
>Kafka Concepts, producer consumer concepts , topics, paritions , replica and broker concepts  - 1
> REST VS GRPC , use case, workflow  - 2
> Maven and gradle use case - 2
> Work flow of promenthus and graffana - 1
> Php which framework - 1
> Kubernetes architecture related questions - 2

### OS Concepts
[RATING] interviewee : 
[RATING] Interviewer :
##### [QUESTION ASKED]
>Multiprocessing 
multi threading : 
Threading Vs multi Threading vs concurrency vs multi processing vs Parallelism vs async : 2
CPU and core concepts : 
Memory Management concepts (paging, segmentation) : 2
Inter proces cummunication methods
Monolithic , Microservices
Process scheduling : NO
Stack and heap memory : 
Process scheduling: 
Deadlock : 1
paging : 1
Mutex Vs semaphore : 2
-----------------------

### Database Concepts & SQL queries
[RATING] interviewee : 
[RATING] Interviewer :
##### [QUESTION ASKED]
> Primary key and a foreign key?
> normalization? Why is it important?
> retrieve the names of all employees whose salary is greater than 50,000?
- SELECT name FROM employees WHERE salary > 50000;
> ACID properties
> Transaction concept,commit rollback

> You have a database with two tables:
employees
employee_id (INT, Primary Key)
name (VARCHAR)
department (VARCHAR)
salaries
employee_id (INT, Foreign Key referencing employees.employee_id)
salary (DECIMAL)
employee_id (INT, Foreign Key referencing employees.employee_id)
salary (DECIMAL)
Write a SQL query to retrieve the names and salaries of employees who work in the 'Sales' department. The results should include:
The employee's name
The employee's salary
- SELECT e.name, s.salary
FROM employees e
JOIN salaries s ON e.employee_id = s.employee_id
WHERE e.department = 'Sales'
ORDER BY e.name;

>Write a SQL query to retrieve the product_name and price of products that are currently out of stock (i.e., stock_quantity is 0). The results should be sorted by product_name in alphabetical order.
SELECT product_name, price
FROM products
WHERE stock_quantity = 0
ORDER BY product_name;

----------------------------

### Computer Network Concepts
[RATING] interviewee : 
[RATING] Interviewer :
##### [QUESTION ASKED]
> OCI layers
> TCP and UDP?
> IP concepts, subnet mask
> DNS concepts
> SSL handshake steps and tcp
> Netstat command, find , top stats

----------------------------

# 12 Factor / SOLID principle / Design Patterns /oops
[RATING] interviewee :
[RATING] Interviewer :
##### [QUESTION ASKED]
> Deisgn pattern used 
    > Singleton design pattern, and when would you use it? 1
Observer design pattern, and how does it work?  1
Factory Method 1
 and Abstract Factory design patterns . NO
main principles of Object-Oriented Programming (OOP) : 1
what a “pure” abstract class is and how it differs from an abstract class with implementations? : NO
Oops concepts

-----------------------

### Data structure & Algorithms
[RATING] interviewee :
[RATING] Interviewer : 
##### [QUESTION ASKED]
>Basic defnition of all data strcutures, linear and non linear
When we should array , list, map, set
> Collections
> list 
List<String> myList = new ArrayList<>();
myList.add("Hello");
myList.add("World");

> set
Set<String> mySet = new HashSet<>();
mySet.add("Hello");
mySet.add("World");

> Map
Map<String, Integer> myMap = new HashMap<>();
Map<String, Integer> myMap = new HashMap<>();

>PriorityQueue
PriorityQueue<String> pq = new PriorityQueue<>();
pq.add("Element");

>Queue
Queue<String> queue = new LinkedList<>(); // or PriorityQueue
queue.add("Element"); // or offer() method

Yes

Implement a dynamic array in Java
singly linked lists and doubly linked lists difference
Difference in binary tree and a binary search tree (BST)  : 1
O(1), O(n), O(log n), and O(n^2) complexities? means : 1
Sorting algorithms
different data structures to solve specific design problems?
Types of data structure: 
Graph types : Moderate
types of tree:  Moderate.
TYpes of linear and non linear Ds: Moderate
use of stack : 
Recursive function vs call back: 
Set : , multi set : 1
Complexity and type : 
-----------------------

# Java Basics
[RATING] interviewee :
[RATING] Interviewer :
##### [QUESTION ASKED]
https://www.geeksforgeeks.org/java-multiple-choice-questions/
https://www.geeksforgeeks.org/quizzes/java-quiz/abstract-class-and-interface-in-java-gq/
> Version of java working : (feature worked based on java version or introduced) : Moderate
How does Java achieve platform independence? : 1
> difference between ArrayList and LinkedList : 1
knowledge of Java's memory model, heap, stack, and garbage collection process.
use of the final, finally, and finalize keywords in Java. : finalize don not know other know
 clarity on try-catch-finally blocks, exception hierarchy, and best practices. : 1
 What is Runnable in Java : 1

 
### Debugging and troubleshooting skils
[RATING] interviewee : 
[RATING] Interviewer :
##### [QUESTION ASKED]
> How to debug
> How to find dependency java classes for jar file
> Code analysis or Scanning tools
> Basic linux commands
----------------------------


### Basic to Medium Level Java Program Covering (Multithreading , Multiprocessing, Problem Solving)
[RATING] interviewee : 
[RATING] Interviewer : 
##### [QUESTION ASKED]
Core java one liner quick questions
https://enos.itcollege.ee/~jpoial/allalaadimised/reading/Java-Interview-Questions.pdf
https://leetcode.com/discuss/post/460599/blind-75-leetcode-questions-by-krishnade-9xev/
https://leetcode.com/problems/missing-number/description/
https://leetcode.com/problems/maximum-subarray/description/
> Bank depoist and withdraw with Executor and lock
> Increment decrement counter with atomic integer using threads
> Binary search with while loop and recursion
Oututputs of https://www.geeksforgeeks.org/output-of-java-program-set-1/
Outputs of https://www.geeksforgeeks.org/output-of-java-program-set-16-threads/
-----------------------
# Technical Challenges Faced and How did you tackle them
[RATING] interviewee :
[RATING] Interviewer :
##### [QUESTION ASKED]
>
-----------------------
## Final Puzzle Question to test the logic thinking:
You have an 8 litre jug full of water and two smaller jugs, one that contains 5 litres
and the other 3 litres. None of the jugs have markings on them, nor do you have any
additional measuring device.You have to divide the 8 litres of water equally between
your two best friends, so that each gets 4 litres of water. How can you do this?

8->5 5->3 3->8 5->3 8->5 5->3 Now 5 have 4 , 3 have 3 and 8 have 1