# Compiler 
https://www.jdoodle.com/online-java-compiler

Question 1 :
        Write a Java program that simulates a bank account with concurrent deposit and withdrawal operations using multithreading. Your program should implement the following requirements:

        Bank Account Class:

        Implement a BankAccount class that has:
        A private field for the account balance.
        Methods to deposit and withdraw money.
        Ensure that these methods are thread-safe to handle simultaneous deposits and withdrawals by multiple threads.
        Implement proper synchronization to prevent race conditions.
        Task Class:

        Implement a class called AccountTask that implements Runnable.
        This class should be able to either deposit or withdraw a specified amount from the bank account, based on its parameters.
        Main Class:

        In the main method:
        Create an instance of BankAccount with an initial balance.
        Use ExecutorService to create a fixed thread pool.
        Submit multiple AccountTask instances to the executor service to perform both deposits and withdrawals.
        Ensure proper shutdown of the executor service and wait for all tasks to complete.
        Print the final balance of the account after all tasks are complete.
        Note: Pay attention to the synchronization of access to the bank account to ensure that the balance is updated correctly without any inconsistencies.

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class BankAccountSimulation {
    // Bank account class
    static class BankAccount {
        private int balance;
        private final Lock lock = new ReentrantLock();

        public BankAccount(int initialBalance) {
            this.balance = initialBalance;
        }

        public void deposit(int amount) {
            lock.lock();
            try {
                if (amount > 0) {
                    balance += amount;
                    System.out.println("Deposited " + amount + ", new balance: " + balance);
                } else {
                    System.out.println("Invalid deposit amount: " + amount);
                }
            } finally {
                lock.unlock();
            }
        }

        public void withdraw(int amount) {
            lock.lock();
            try {
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    System.out.println("Withdrew " + amount + ", new balance: " + balance);
                } else {
                    System.out.println("Insufficient funds or invalid withdrawal amount: " + amount);
                }
            } finally {
                lock.unlock();
            }
        }

        public int getBalance() {
            return balance;
        }
    }

    // Task to perform deposit or withdrawal
    static class AccountTask implements Runnable {
        private final BankAccount account;
        private final boolean isDeposit;
        private final int amount;

        public AccountTask(BankAccount account, boolean isDeposit, int amount) {
            this.account = account;
            this.isDeposit = isDeposit;
            this.amount = amount;
        }

        @Override
        public void run() {
            if (isDeposit) {
                account.deposit(amount);
            } else {
                account.withdraw(amount);
            }
        }
    }

    public static void main(String[] args) {
        final int INITIAL_BALANCE = 1000;
        final int NUM_THREADS = 10;
        final int DEPOSIT_AMOUNT = 200;
        final int WITHDRAWAL_AMOUNT = 150;

        BankAccount account = new BankAccount(INITIAL_BALANCE);
        ExecutorService executor = Executors.newFixedThreadPool(NUM_THREADS);

        // Submit deposit tasks
        for (int i = 0; i < NUM_THREADS / 2; i++) {
            executor.submit(new AccountTask(account, true, DEPOSIT_AMOUNT));
        }

        // Submit withdrawal tasks
        for (int i = 0; i < NUM_THREADS / 2; i++) {
            executor.submit(new AccountTask(account, false, WITHDRAWAL_AMOUNT));
        }

        executor.shutdown(); // Initiates an orderly shutdown
        while (!executor.isTerminated()) {
            // Wait for all tasks to complete
        }

        System.out.println("Final account balance: " + account.getBalance());
    }
}




















# Question 2
    1. Design a Thread-safe Counter
    Question:

    "Implement a thread-safe counter in Java. Your counter should support the following operations:

    increment(): Increases the counter by 1.
    decrement(): Decreases the counter by 1.
    getValue(): Returns the current value of the counter.
    Make sure your implementation is thread-safe and can handle concurrent access from multiple threads."



import java.util.concurrent.atomic.AtomicInteger;

public class ThreadSafeCounter {
    private AtomicInteger counter = new AtomicInteger(0);

    public void increment() {
        counter.incrementAndGet();
    }

    public void decrement() {
        counter.decrementAndGet();
    }

    public int getValue() {
        return counter.get();
    }

    public static void main(String[] args) {
        ThreadSafeCounter counter = new ThreadSafeCounter();

        Runnable incrementTask = () -> {
            for (int i = 0; i < 1000; i++) {
                counter.increment();
            }
        };

        Runnable decrementTask = () -> {
            for (int i = 0; i < 1000; i++) {
                counter.decrement();
            }
        };

        Thread t1 = new Thread(incrementTask);
        Thread t2 = new Thread(decrementTask);
        t1.start();
        t2.start();
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        System.out.println("Final counter value: " + counter.getValue());
    }
}








Question 3:
BInary search with loop

    public class BinarySearch {

        // Iterative binary search using while loop
        public static int binarySearchIterative(int[] arr, int target) {
            int left = 0;
            int right = arr.length - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                // Check if target is present at mid
                if (arr[mid] == target) {
                    return mid;
                }

                // If target greater, ignore left half
                if (arr[mid] < target) {
                    left = mid + 1;
                }
                // If target smaller, ignore right half
                else {
                    right = mid - 1;
                }
            }

            // Target is not present in the array
            return -1;
        }

        public static void main(String[] args) {
            int[] arr = {2, 3, 4, 10, 40};
            int target = 10;

            // Testing iterative approach
            int resultIterative = binarySearchIterative(arr, target);
            System.out.println("Iterative: Element found at index " + resultIterative);
        }
    }

# With Recusrion:

public class BinarySearch {

    // Recursive binary search
    public static int binarySearchRecursive(int[] arr, int target, int left, int right) {
        if (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if target is present at mid
            if (arr[mid] == target) {
                return mid;
            }

            // If target greater, ignore left half
            if (arr[mid] < target) {
                return binarySearchRecursive(arr, target, mid + 1, right);
            }
            // If target smaller, ignore right half
            else {
                return binarySearchRecursive(arr, target, left, mid - 1);
            }
        }

        // Target is not present in the array
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 10, 40};
        int target = 10;

        // Testing recursive approach
        int resultRecursive = binarySearchRecursive(arr, target, 0, arr.length - 1);
        System.out.println("Recursive: Element found at index " + resultRecursive);
    }
}
