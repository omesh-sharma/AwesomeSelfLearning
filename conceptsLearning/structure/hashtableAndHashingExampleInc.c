#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Define the hashtable structure
typedef struct Entry {
    char *key;
    int value;
    struct Entry *next;
} Entry;

Entry *hashtable[TABLE_SIZE];

// Hash function to compute the index for a key
unsigned int hash(char *key) {
    unsigned long int hashval = 0;
    while (*key) {
        hashval = (hashval << 5) + *key++;
    }
    return hashval % TABLE_SIZE;
}

// Insert key-value pair into the hashtable
void insert(char *key, int value) {
    unsigned int index = hash(key);
    Entry *new_entry = malloc(sizeof(Entry));
    new_entry->key = strdup(key);
    new_entry->value = value;
    new_entry->next = hashtable[index];
    hashtable[index] = new_entry;
}

// Search for a value by key
int search(char *key) {
    unsigned int index = hash(key);
    Entry *entry = hashtable[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1; // Indicate that the key was not found
}

// Display the hashtable contents
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *entry = hashtable[i];
        printf("Index %d: ", i);
        while (entry != NULL) {
            printf("(%s: %d) -> ", entry->key, entry->value);
            entry = entry->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Initialize the hashtable
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable[i] = NULL;
    }

    // Insert some key-value pairs
    insert("apple", 10);
    insert("banana", 20);
    insert("orange", 30);

    // Display the hashtable
    display();

    // Search for a key
    printf("Value for 'banana': %d\n", search("banana"));
    printf("Value for 'grape': %d\n", search("grape")); // Not found

    // Cleanup omitted for brevity

    return 0;
}




 //Another example

//  High-Level Steps
// Define a Hashtable Structure: Create a structure to hold session information, including fields like login time, expiry time, etc.

// Hash Function: Implement a hash function to map user names or session IDs to indices in the hashtable.

// Hashtable Operations: Implement functions to insert, retrieve, and delete session information based on the hashed key.

 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 100

typedef struct Session {
    char username[50];
    time_t login_at;
    time_t expiry_at;
    struct Session* next;
} Session;

typedef struct Hashtable {
    Session* table[TABLE_SIZE];
} Hashtable;

// Hash function
unsigned int hash(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % TABLE_SIZE;
}

// Create a new session
Session* create_session(const char* username, time_t login_at, time_t expiry_at) {
    Session* new_session = (Session*)malloc(sizeof(Session));
    if (new_session == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strncpy(new_session->username, username, sizeof(new_session->username) - 1);
    new_session->login_at = login_at;
    new_session->expiry_at = expiry_at;
    new_session->next = NULL;
    return new_session;
}

// Initialize hashtable
void init_hashtable(Hashtable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

// Insert a session into the hashtable
void insert_session(Hashtable* ht, const char* username, time_t login_at, time_t expiry_at) {
    unsigned int index = hash(username);
    Session* new_session = create_session(username, login_at, expiry_at);
    new_session->next = ht->table[index];
    ht->table[index] = new_session;
}

// Retrieve a session from the hashtable
Session* get_session(Hashtable* ht, const char* username) {
    unsigned int index = hash(username);
    Session* current = ht->table[index];
    while (current) {
        if (strcmp(current->username, username) == 0 && current->expiry_at > time(NULL)) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Delete a session
void delete_session(Hashtable* ht, const char* username) {
    unsigned int index = hash(username);
    Session* current = ht->table[index];
    Session* prev = NULL;
    while (current) {
        if (strcmp(current->username, username) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                ht->table[index] = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Clean up hashtable
void cleanup_hashtable(Hashtable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Session* current = ht->table[i];
        while (current) {
            Session* to_delete = current;
            current = current->next;
            free(to_delete);
        }
    }
}

// Example usage
int main() {
    Hashtable ht;
    init_hashtable(&ht);

    time_t now = time(NULL);
    time_t expiry = now + 3600;  // Session expires in 1 hour

    insert_session(&ht, "user1", now, expiry);

    Session* session = get_session(&ht, "user1");
    if (session) {
        printf("User: %s\n", session->username);
        printf("Login At: %s", ctime(&session->login_at));
        printf("Expires At: %s", ctime(&session->expiry_at));
    } else {
        printf("Session not found or expired.\n");
    }

    // Clean up
    delete_session(&ht, "user1");
    cleanup_hashtable(&ht);

    return 0;
}
